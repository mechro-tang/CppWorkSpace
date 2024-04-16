#include <iostream>
#include <windows.h>
#include <tlhelp32.h> // ��Ҫ��ͷ�ļ����ڱ��������б�
//#include <afx.h>

// ��������
HWND GetConsoleWindowHandle(const wchar_t* processName);
bool SendMessageToProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main() {
    SetConsoleOutputCP(CP_UTF8); // ���ÿ���̨���Ϊ UTF-8 �ַ���
    const wchar_t* targetProcessName = L"receive.exe"; // Ŀ���������
    std::wcout << L"START " << targetProcessName << std::endl;
    // ��ȡĿ����̵Ĵ��ھ��
    HWND hWnd = GetConsoleWindowHandle(targetProcessName);

    if (hWnd == NULL) {
        std::wcout << L"can not find target Process:" << targetProcessName << std::endl;
        return 1;
    }

    // ��Ŀ����̷�����Ϣ
    if (!SendMessageToProcess(hWnd, WM_COPYDATA, 0, 0)) {
        std::cerr << "������Ϣʧ�ܡ�" << std::endl;
        return 1;
    }

    std::cout << "��Ϣ�ѳɹ����͵�Ŀ����̡�" << std::endl;

    return 0;
}

HWND GetConsoleWindowHandle(const wchar_t* processName) {
    // ����һ�����գ���ȡϵͳ�����н��̵���Ϣ
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::wcout << "cn not get Snapshot" << std::endl;
        return NULL;
    }

    // ���������б�����Ŀ�����̨����Ľ���
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);
    BOOL bResult = Process32First(hSnapshot, &pe);
    while (bResult) {
        std::wcout << L"compare with [" << pe.szExeFile << L"] - [" << processName << L"]" << std::endl;
        if (wcsncmp((wchar_t*)pe.szExeFile, (wchar_t*)processName, wcslen(processName)) == 0) {
            // �ҵ�Ŀ����̣���ȡ����ģ����
            std::wcout << "find target process" << std::endl;
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe.th32ProcessID);
            if (hProcess != NULL) {
                // ��ȡ���̵Ŀ���̨���ھ��
                HWND hWnd = GetConsoleWindow();
                CloseHandle(hProcess);
                return hWnd;
            }
        }
        bResult = Process32Next(hSnapshot, &pe);
    }

    CloseHandle(hSnapshot);
    return NULL; // û���ҵ�ƥ��Ŀ���̨���ھ��
}

bool SendMessageToProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // �򴰿ڷ�����Ϣ
    LRESULT result = SendMessage(hWnd, msg, wParam, lParam);
    return (result != 0);
}

/**************/

// #include <iostream>
// #include <windows.h>

// int main() {
//     HWND hWnd = FindWindow((LPCWSTR)NULL, (LPCSTR) L"receive"); // ���ݱ����ҵ�������Ϣ�Ŀ���̨����Ĵ��ھ��

//     if (hWnd == NULL) {
//         std::cerr << "Failed to find window." << std::endl;
//         return 1;
//     }

//     // ʹ�� PostMessage ��Ŀ�괰�ڷ�����Ϣ
//     if (!PostMessage(hWnd, WM_USER, 0, 0)) {
//         std::cerr << "Failed to send message." << std::endl;
//         return 1;
//     }

//     std::cout << "Message sent successfully." << std::endl;

//     return 0;
// }
