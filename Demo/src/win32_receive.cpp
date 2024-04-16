// #include <iostream>
// #include <windows.h>

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// HWND GetHwndProc()
// {
//    HWND hwnd = GetTopWindow(NULL);
//    DWORD currentPID = GetCurrentProcessId();
//    do
//    {
//        char title[256];
//        if ((GetWindowText(hwnd, title, 256) > 0) && (IsWindowVisible(hwnd)))
//        {
//            DWORD procId;
//            GetWindowThreadProcessId(hwnd, &procId);

//            if (procId == currentPID)   
//            {
//                MessageBox(hwnd, title, "", MB_OK);
//                return hwnd;
//            }
//        }

//        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
//    } while (hwnd);
   
//    return NULL;
// }




// int main() {

//     DWORD currentPID = GetCurrentProcessId();
//     std::cout << "Current Process ID: " << currentPID << std::endl;

//    HWND hWnd = GetForegroundWindow();
//    // GetForegroundWindow  要获取当前进程的顶层窗口句柄
//    // GetConsoleWindow(); // 获取当前控制台窗口的句柄
//    // GetHwndProc();
//    // GetTopWindow(NULL);  // 指定窗口的顶层窗口句柄，而不是当前进程的顶层窗口句柄

//    if (hWnd == NULL) {
//        std::cerr << "Failed to get console window handle." << std::endl;
//        return 1;
//    }

//    if (!SetConsoleTitle((LPCSTR) L"Console Receiver")) {
//        std::cerr << "Failed to set console title." << std::endl;
//        return 1;
//    }

//    // 设置消息钩子，用于接收消息
//    if (!SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)WindowProc)) {
//        DWORD dwError = GetLastError();
// 		std::cerr << "Failed to set window procedure. Error code: " << dwError << std::endl;
// 		return 1;
//    }

//    MSG msg;
//    // 消息循环
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }

//    return 0;
// }

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//        case WM_COPYDATA: {
//            COPYDATASTRUCT* cds = (COPYDATASTRUCT*)lParam;
//            // 接收到 WM_COPYDATA 消息
//            std::cout << "Received WM_COPYDATA message." << std::endl;
//            // 输出接收到的数据
//            std::wcout << "Data: " << (wchar_t*)cds->lpData << std::endl;
//            return 0;
//        }
//        default:
//            // 调用默认的窗口过程
//            return DefWindowProc(hwnd, uMsg, wParam, lParam);
//    }
// }
/***************************/
// #include <Windows.h>
// #include <iostream>

// LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//     if (msg == WM_COPYDATA) {
//         COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
//         char* message = (char*)pcds->lpData;
//         std::cout << "Received message: " << message << std::endl;
//     }

//     return DefWindowProc(hwnd, msg, wParam, lParam);
// }

// int main() {
//     WNDCLASS wc = { 0 };
//     wc.lpfnWndProc = WndProc;
//     wc.hInstance = GetModuleHandle(NULL);
//     wc.lpszClassName = "MessageReceiver";
//     RegisterClass(&wc);

//     HWND hwnd = CreateWindow("MessageReceiver", "Message Receiver", 0, 0, 0, 0, 0, NULL, NULL, NULL, NULL);

//     MSG msg;
//     while (GetMessage(&msg, NULL, 0, 0)) {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//     }

//     return 0;
// }
/**************************/
#include <iostream>
#include <windows.h>

int main() {
    HWND hWnd = GetConsoleWindow(); // 获取控制台窗口句柄

    MSG msg;
    // 消息循环
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_USER) {
            std::cout << "Received message." << std::endl;
            // 处理接收到的消息
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
