#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
<<<<<<< HEAD
#include "print.h"
 
int main(void) {

   //using namespace ftxui;
 
  // Define the document
//   Element document =
//     hbox({
//       text("left")   | border,
//       text("middle") | border | flex,
//       text("right")  | border,
//     });
 
//   auto screen = Screen::Create(
//     Dimension::Full(),       // Width
//     Dimension::Full()        // Height
//   );
//   //Render(screen, document);
//   screen.Print();
    print();
    return EXIT_SUCCESS;
}
=======
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
>>>>>>> 15543f1a1417205d5a38bf60c05e09e1f2904272
