#include <afxwin.h>
#include <iostream>

class CMyConsoleApp : public CWinApp {
public:
    virtual BOOL InitInstance() {
        // 创建一个隐藏的窗口来处理消息
        m_pMainWnd = new CWnd;
        return TRUE;
    }

    virtual int Run() {
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return (int)msg.wParam;
    }

    afx_msg LRESULT OnCopyData(WPARAM wParam, LPARAM lParam) {
        // 处理 WM_COPYDATA 消息
        COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
        if (pcds->dwData == 1) {
            // 返回消息
            std::cout << "Received message: " << (char*)pcds->lpData << std::endl;
            CString reply = _T("Message received successfully.");
            ::SendMessage((HWND)pcds->dwData, WM_COPYDATA, (WPARAM)m_pMainWnd->m_hWnd, (LPARAM)(LPVOID)&reply);
        }
        return 0;
    }

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyConsoleApp, CWinApp)
    ON_MESSAGE(WM_COPYDATA, &CMyConsoleApp::OnCopyData)
END_MESSAGE_MAP()

CMyConsoleApp theApp;

int main() {
    // 初始化 MFC 应用程序
    if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0)) {
        std::cerr << "MFC initialization failed" << std::endl;
        return 1;
    }

    std::cout << "Console Application Running..." << std::endl;

    // 运行控制台应用程序的消息循环
    return theApp.Run();
}
