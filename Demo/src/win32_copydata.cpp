#include <windows.h>
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main() {
    // 创建控制台窗口
    HWND hwndConsole = GetConsoleWindow();
    if (hwndConsole == NULL) {
        std::cerr << "Failed to get console window handle." << std::endl;
        return 1;
    }

    // 创建一个隐藏窗口来处理消息
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"ConsoleWindow";
    RegisterClass(&wc);
    HWND hwndHidden = CreateWindow(wc.lpszClassName, L"", 0, 0, 0, 0, 0, NULL, NULL, wc.hInstance, NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COPYDATA: {
            COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
            if (pcds->dwData == 1) {
                // 处理 WM_COPYDATA 消息
                std::cout << "Received message: " << (char*)pcds->lpData << std::endl;

                // 返回消息
                std::wstring reply = L"Message received successfully.";
                COPYDATASTRUCT cds;
                cds.dwData = 2;
                cds.cbData = (DWORD)(reply.length() + 1) * sizeof(wchar_t);
                cds.lpData = (LPVOID)reply.c_str();
                SendMessage((HWND)pcds->dwData, WM_COPYDATA, (WPARAM)hwnd, (LPARAM)&cds);
            }
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
