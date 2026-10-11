#include <Windows.h>

// Dummy virtual method table / singleton data buffer
// Satisfies client checks when resolving NGClient ordinals
static unsigned char g_dummySecurityTable[256] = { 0 };

extern "C" {
    // NGClient Ordinals 1 ~ 7
    // hw.dll statically imports Ordinal 1 and Ordinal 2 from NGClient.aes
    void* __cdecl NGClientEntry1(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry2(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry3(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry4(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry5(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry6(void)
    {
        return g_dummySecurityTable;
    }

    void* __cdecl NGClientEntry7(void)
    {
        return g_dummySecurityTable;
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
    }
    return TRUE;
}
