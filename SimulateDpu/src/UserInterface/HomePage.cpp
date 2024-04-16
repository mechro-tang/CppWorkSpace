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
    // ÏÔÊ¾ÄÚÈÝ
    Element content = 
        ftxui::hbox({
            text("Home Page") | border,
            separator(),
            text(L"Welcome to the Home Page")  | border
        });

    // ÆÁÄ»
    Screen screen = 
        Screen::Create(
            Dimension::Full(), 
            Dimension::Fit(content)
        );

    Render(screen, content);
    screen.Print();

    return;
}