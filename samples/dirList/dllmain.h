
class CDirListHandler : public CRequestHandlerT<CDirListHandler>
{
public:
	HANDLE m_hFindFile;
	WIN32_FIND_DATAA m_findFileData;
	int m_iFileCount;
	BEGIN_REPLACEMENT_METHOD_MAP(CDirListHandler)
		REPLACEMENT_METHOD_ENTRY("HasMoreFiles", OnHasMoreFiles)
		REPLACEMENT_METHOD_ENTRY("FileName", OnFileName)
		REPLACEMENT_METHOD_ENTRY("FileSize", OnFileSize)
		REPLACEMENT_METHOD_ENTRY("FileModified", OnFileModified)
		REPLACEMENT_METHOD_ENTRY("FileColor", OnFileColor)
	END_REPLACEMENT_METHOD_MAP()

	HTTP_CODE ValidateAndExchange()
	{
		CAtlStringA strScriptFileName, strScriptDir;
		m_HttpRequest.GetServerVariable("x-script-filename", strScriptFileName);
		int nFoundSlash = strScriptFileName.ReverseFind('\\');
		strScriptDir = strScriptFileName.Left(nFoundSlash+1);
		strScriptDir += "*";
		m_hFindFile = NULL;
		m_findFileData = { 0 };
		m_hFindFile = FindFirstFileExA(strScriptDir, FindExInfoStandard, &m_findFileData, FindExSearchNameMatch, 0, 0);
		if (m_hFindFile != INVALID_HANDLE_VALUE)
			return HTTP_SUCCESS;
		else
			return HTTP_S_FALSE;
	}

	HTTP_CODE OnHasMoreFiles()
	{
		m_iFileCount++;
		if (m_iFileCount == 1048576)
		{
			//break on 1000000 files
			return HTTP_S_FALSE;
		}
		return (TRUE == FindNextFileA(m_hFindFile, &m_findFileData)) ? HTTP_SUCCESS : HTTP_S_FALSE;
	}
	HTTP_CODE OnFileName()
	{
		m_HttpResponse << m_findFileData.cFileName;	
		return HTTP_SUCCESS;
	}
	HTTP_CODE OnFileSize()
	{
		if (!FILE_ATTRIBUTE_DIRECTORY == (m_findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			ULONG theSize = (m_findFileData.nFileSizeHigh * (MAXDWORD + 1)) + m_findFileData.nFileSizeLow;
			if (theSize / 1024)
				m_HttpResponse << theSize / 1024 << " Kb";
			else
				m_HttpResponse << theSize << " bytes";
		}
		else
			m_HttpResponse << "&nbsp;";
		return HTTP_SUCCESS;
	}
	HTTP_CODE OnFileModified()
	{
		if (!FILE_ATTRIBUTE_DIRECTORY == (m_findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			CTime t(m_findFileData.ftLastWriteTime);
			m_HttpResponse << t.Format(_T("%H:%M:%S  %a, %b %d, %Y"));
		}
		else
			m_HttpResponse << "&nbsp;";
		return HTTP_SUCCESS;
	}
	HTTP_CODE OnFileColor()
	{
		if ((m_iFileCount + 2) % 2)
			m_HttpResponse << "LemonChiffon";
		return HTTP_SUCCESS;
	}
}; // class CDirListHandler