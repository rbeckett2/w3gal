// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "test.h"

class CHelloWorldModule : public CAtlDllModuleT<CHelloWorldModule>
{
public:
	BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) throw()
	{
		return __super::DllMain(dwReason, lpReserved);
	}
};

CHelloWorldModule _AtlModule;

BEGIN_HANDLER_MAP()
	HANDLER_ENTRY("Default", CHelloWorldHandler)
END_HANDLER_MAP()


// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return TRUE;
}
