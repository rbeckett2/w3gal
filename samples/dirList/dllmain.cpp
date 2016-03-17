#include "stdafx.h"
#include "dllmain.h"

class CDirListModule : public CAtlDllModuleT<CDirListModule>
{
public:
	BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) throw()
	{
		return __super::DllMain(dwReason, lpReserved);
	}
};

CDirListModule _AtlModule;

BEGIN_HANDLER_MAP()
	HANDLER_ENTRY("Default", CDirListHandler)
END_HANDLER_MAP()

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
	return TRUE;
}