#include <windows.h>
#include <urlmon.h>
#include <iostream>

#pragma comment(lib, "urlmon.lib") 

typedef void (*ShowMessageBoxFunc)();

bool DownloadFile(const wchar_t* url, const wchar_t* filename) {
    HRESULT hr = URLDownloadToFileW(NULL, url, filename, 0, NULL);
    return SUCCEEDED(hr);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t* dllUrl = L"https://github.com/InfernoTsugikuni/Testing_a_dll_downloader/raw/main/mydll.dll"; // if you are here from my github, just create a rep drop the dll there open it and right click the view raw button, copy the url and replace it with my rep
    const wchar_t* dllPath = L"mydll.dll";

    if (!DownloadFile(dllUrl, dllPath)) {
        MessageBoxW(NULL, L"Failed to download DLL!", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    HMODULE hDll = LoadLibraryW(dllPath);
    if (hDll == NULL) {
        MessageBoxW(NULL, L"Failed to load DLL!", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowMessageBoxFunc ShowMessageBox = (ShowMessageBoxFunc)GetProcAddress(hDll, "ShowMessageBox");
    if (ShowMessageBox == NULL) {
        MessageBoxW(NULL, L"Failed to find the function!", L"Error", MB_OK | MB_ICONERROR);
        FreeLibrary(hDll);
        return 1;
    }

    ShowMessageBox(); 

    FreeLibrary(hDll);

    return 0;
}
