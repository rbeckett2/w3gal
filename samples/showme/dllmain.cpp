#include "stdafx.h"
#include "dllmain.h"

class CShowMeModule : public CAtlDllModuleT<CShowMeModule>
{
public:
	BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) throw()
	{
		return __super::DllMain(dwReason, lpReserved);
	}
};

CShowMeModule _AtlModule;

BEGIN_HANDLER_MAP()
	HANDLER_ENTRY("Default", CShowMeHandler)
END_HANDLER_MAP()


// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return TRUE;
}
