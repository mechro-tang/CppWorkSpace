#include <iostream>
#include <string>
#include "UserInterface/HomePage.h"
#include "json/json.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello world!" << std::endl;
    
    //HomePage homePage = HomePage();
    //homePage.show();

    Json::Value root;
    root["name"] = "John";
    root["age"] = "30";

    Json::StyledWriter writer;
    
    std::cout << writer.write(root) << std::endl;
    
    return 0;
}