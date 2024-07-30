#include <windows.h>

extern "C" __declspec(dllexport) void ShowMessageBox() {
    MessageBoxW(NULL,
     L"hi from a dll",
      L"ONLY TESTING",
       MB_ICONWARNING | MB_YESNOCANCEL);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
