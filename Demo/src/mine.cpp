// #include <iostream>
// #include <string>

// // 添入的字符
// #define CHAR_INSERT 'n'

// // 字符是否为数字
// bool IsDigit(const char& ch)
// {
//     return (ch >= '0' && ch <= '9');
// }
// // cout字符串的size和capacity信息
// void Display(const std::string& str, const std::string::iterator &itor)
// {
//     std::cout << "str.size() : " << str.size() << std::endl;
//     std::cout << "str.capacity() : " << str.capacity() << std::endl;
//     std::cout << "itor - str.begin() : " << (itor - str.begin()) << std::endl;
//     std::cout << "str.end() - itor : " << (str.end() - itor) << std::endl;
// }

// int main() 
// {
//     std::string str_recv = "Y1^*6**26*";   // 输入字符串
//     std::cout << "str_recv_before : " << str_recv << std::endl;

//     std::string::iterator i = str_recv.begin(); // 字符串的迭代器
//     while (i != str_recv.end()) 
//     {
//         if (IsDigit(*i) && i == str_recv.begin()) 
//         {
//             /* 首字符为数字 */
//             i = str_recv.insert(i, CHAR_INSERT);
//         }
//         else if (i == str_recv.end() - 1) 
//         {
//             if (IsDigit(*i)) {
//                 /* 末字符为数字*/
//                 i = str_recv.insert(i + 1, CHAR_INSERT);
//             }
//             //break;
//         }
//         else if (IsDigit(*i) && !IsDigit(*(i+1)) ) 
//         {
//             /* 当前字符数字，后一字符非数字*/
//             Display(str_recv, i);
//             ++i;
//             Display(str_recv, i);
//             i = str_recv.insert(i, CHAR_INSERT);
//             Display(str_recv, i);
//         }
//         else if (!IsDigit(*i) && IsDigit(*(i+1))) 
//         {
//             /* 当前字符非数字，后一字符为数字*/
//             ++i;
//             i = str_recv.insert(i, CHAR_INSERT);
//         }
//         ++i;
//     }

//     std::cout << "str_recv_after : " << str_recv << std::endl;
//     return 0;
// }