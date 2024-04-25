/*
* 
*/
#ifdef _WIN32

#include <iostream>
#include <windows.h>
#include <tlhelp32.h> // 必要的头文件用于遍历进程列表
//#include <afx.h>

// 函数声明
HWND GetConsoleWindowHandle(const wchar_t* processName);
bool SendMessageToProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main() {
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8 字符集
    const wchar_t* targetProcessName = L"receive.exe"; // 目标进程名称
    std::wcout << L"START " << targetProcessName << std::endl;
    // 获取目标进程的窗口句柄
    HWND hWnd = GetConsoleWindowHandle(targetProcessName);

    if (hWnd == NULL) {
        std::wcout << L"can not find target Process:" << targetProcessName << std::endl;
        return 1;
    }

    // 向目标进程发送消息
    if (!SendMessageToProcess(hWnd, WM_COPYDATA, 0, 0)) {
        std::cerr << "发送消息失败。" << std::endl;
        return 1;
    }

    std::cout << "消息已成功发送到目标进程。" << std::endl;

    return 0;
}

HWND GetConsoleWindowHandle(const wchar_t* processName) {
    // 创建一个快照，获取系统中所有进程的信息
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::wcout << "cn not get Snapshot" << std::endl;
        return NULL;
    }

    // 遍历进程列表，查找目标控制台程序的进程
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);
    BOOL bResult = Process32First(hSnapshot, &pe);
    while (bResult) {
        std::wcout << L"compare with [" << pe.szExeFile << L"] - [" << processName << L"]" << std::endl;
        if (wcsncmp((wchar_t*)pe.szExeFile, (wchar_t*)processName, wcslen(processName)) == 0) {
            // 找到目标进程，获取其主模块句柄
            std::wcout << "find target process" << std::endl;
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe.th32ProcessID);
            if (hProcess != NULL) {
                // 获取进程的控制台窗口句柄
                HWND hWnd = GetConsoleWindow();
                CloseHandle(hProcess);
                return hWnd;
            }
        }
        bResult = Process32Next(hSnapshot, &pe);
    }

    CloseHandle(hSnapshot);
    return NULL; // 没有找到匹配的控制台窗口句柄
}

bool SendMessageToProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // 向窗口发送消息
    LRESULT result = SendMessage(hWnd, msg, wParam, lParam);
    return (result != 0);
}

/**************/

// #include <iostream>
// #include <windows.h>

// int main() {
//     HWND hWnd = FindWindow((LPCWSTR)NULL, (LPCSTR) L"receive"); // 根据标题找到接收消息的控制台程序的窗口句柄

//     if (hWnd == NULL) {
//         std::cerr << "Failed to find window." << std::endl;
//         return 1;
//     }

//     // 使用 PostMessage 向目标窗口发送消息
//     if (!PostMessage(hWnd, WM_USER, 0, 0)) {
//         std::cerr << "Failed to send message." << std::endl;
//         return 1;
//     }

//     std::cout << "Message sent successfully." << std::endl;

//     return 0;
// }
#endif