#include <iostream>
#include "UserInterface/HomePage.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello world!" << std::endl;
    
    HomePage homePage = HomePage();
    homePage.show();
    
    return 0;
}