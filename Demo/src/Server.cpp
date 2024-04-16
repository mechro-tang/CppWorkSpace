#include <iostream>
#include <WinUser.h>
#include <windows.h>

int main()
{
    COPYDATASTRUCT send_message;

    HWND hWnd  = ::FindWindow(NULL, "UnrealWindow");

    SendMessage();
}