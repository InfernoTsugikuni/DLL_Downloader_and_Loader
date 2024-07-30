// dll.cpp
#include <windows.h>

// This function will be exported and can be called from an executable.
extern "C" __declspec(dllexport) void ShowMessageBox() {
    MessageBoxW(NULL,
     L"hi from a dll",
      L"ONLY TESTING",
       MB_ICONWARNING | MB_YESNOCANCEL);
}

// DLL entry point (optional for this example, but good practice to include)
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
