class CShowMeHandler : public CRequestHandlerT<CShowMeHandler>
{
public:
	CAtlStringA m_strPlace;
	BEGIN_REPLACEMENT_METHOD_MAP(CShowMeHandler)
		REPLACEMENT_METHOD_ENTRY("ShowMe", OnShowMe)
	END_REPLACEMENT_METHOD_MAP()

	HTTP_CODE ValidateAndExchange()
	{
		const CHttpRequestParams *requestParams = &(this->m_HttpRequest.GetQueryParams());
		m_HttpResponse.SetContentType("text/html");
		unsigned long ulC = requestParams->GetCount();
		if (ulC != 0)
			m_strPlace = requestParams->Lookup("Place");
		else
			m_strPlace = "";
		return HTTP_SUCCESS;
	}

protected:
	// Here is an example of how to use a replacement tag with the stencil processor
	HTTP_CODE OnShowMe(void)
	{
		if (m_strPlace.GetLength())
			m_HttpResponse << "You chose " << m_strPlace;
		else
			m_HttpResponse << "Pick a place";
		return HTTP_SUCCESS;
	}
}; // class CHelloWorldHandler