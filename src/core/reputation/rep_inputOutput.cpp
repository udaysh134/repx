// Headers
#include "repEngine.hpp"

#include <windows.h>
#include <shobjidl.h>
#include <string>


// ----------------------------------------------------------------------------------------------------
// Directory Implementations
// ----------------------------------------------------------------------------------------------------

// Select Directory ---------------------------------------- >>

std::string RepEngine::select_directory() {
    std::string result;
    IFileDialog* dialog = nullptr;

    // Create File Dialog COM object
    if (SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&dialog)))) {
        DWORD options;
        dialog->GetOptions(&options);

        // Enable folder selection mode
        dialog->SetOptions(options | FOS_PICKFOLDERS);

        // Show dialog to user
        if (SUCCEEDED(dialog->Show(nullptr))) {
            IShellItem* item = nullptr;

            // Retrieve selected item
            if (SUCCEEDED(dialog->GetResult(&item))) {
                PWSTR path = nullptr;

                // Get filesystem path
                if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &path))) {
                    // Convert UTF-16 (Windows) → UTF-8 (std::string)
                    int size = WideCharToMultiByte(CP_UTF8, 0, path, -1, nullptr, 0, nullptr, nullptr);

                    std::string str(size, 0);
                    WideCharToMultiByte(CP_UTF8, 0, path, -1, str.data(), size, nullptr, nullptr);
                    result = str;
                    CoTaskMemFree(path);
                }

                item->Release();
            }
        }

        dialog->Release();
    }

    return result;
}


// Select File ---------------------------------------- >>

std::string RepEngine::select_file() {
    std::string result;
    IFileDialog* dialog = nullptr;

    // Create File Dialog COM object
    if (SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&dialog)))) {

        // Optional : Set file filters (you can customize later)
        COMDLG_FILTERSPEC filters[] = {
            { L"RepX Files (*.repx)", L"*.repx" }
        };

        dialog->SetFileTypes(2, filters);
        dialog->SetFileTypeIndex(1);

        // Show dialog
        if (SUCCEEDED(dialog->Show(nullptr))) {
            IShellItem* item = nullptr;

            if (SUCCEEDED(dialog->GetResult(&item))) {
                PWSTR path = nullptr;

                if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &path))) {
                    int size = WideCharToMultiByte(CP_UTF8, 0, path, -1, nullptr, 0, nullptr, nullptr);
                    std::string str(size, 0);
                    WideCharToMultiByte(CP_UTF8, 0, path, -1, str.data(), size, nullptr, nullptr);
                    result = str;
                    CoTaskMemFree(path);
                }

                item->Release();
            }
        }

        dialog->Release();
    }

    return result;
}