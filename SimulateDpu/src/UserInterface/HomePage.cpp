#include <iostream>
#include "HomePage.h"

HomePage::HomePage()
{

}

HomePage::~HomePage()
{

}

void HomePage::show()
{
    // ��ʾ����
    Element content = 
        ftxui::hbox({
            text("Home Page") | border,
            separator(),
            text(L"Welcome to the Home Page")  | border
        });

    // ��Ļ
    Screen screen = 
        Screen::Create(
            Dimension::Full(), 
            Dimension::Fit(content)
        );

    Render(screen, content);
    screen.Print();

    return;
}