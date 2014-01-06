// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "process.h"

unsigned __stdcall start(void*);
unsigned __stdcall finish(void*);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_beginthreadex(NULL,NULL,start,NULL,NULL,NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		_beginthreadex(NULL,NULL,finish,NULL,NULL,NULL);
		break;
	}
	return TRUE;
}