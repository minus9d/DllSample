#include <Windows.h>

static HINSTANCE g_hInst = 0;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL rc = TRUE;
    switch (fdwReason)
    {
    // ê≥ÇµÇ≠èàóùÇ™èIÇÌÇ¡ÇΩèÍçáÇÕTRUEÇï‘Ç∑ïKóvÇ†ÇË
    case DLL_PROCESS_ATTACH:
        g_hInst = hinstDLL;
        break;
    case DLL_PROCESS_DETACH:
        g_hInst = 0;
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    }
    return rc;
}
