#include "stdafx.h"
#include "dllmain.h"

class CRedirModule : public CAtlDllModuleT<CRedirModule>
{
public:
	BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) throw()
	{
		return __super::DllMain(dwReason, lpReserved);
	}
};

CRedirModule _AtlModule;

BEGIN_HANDLER_MAP()
	HANDLER_ENTRY("Default", CRedirHandler)
END_HANDLER_MAP()

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return TRUE;
}