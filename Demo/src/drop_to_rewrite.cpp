#include <iostream>
//#include <windows.h>
#include <fstream>
#include <filesystem>
#include <string>

//===============
// 功能：重写文件，以接触文件加密
//      需要重新打开并写入，所以读与写文件分开执行
//===============
bool rewrite_file(const char *file_name, std::string &tip);

// 读取文件内容
bool read_file(const std::string &file_name, std::string &data);

// 写入文件
bool write_file(const std::string &file_name, const std::string &data);

std::string UtfToGbk(std::string strValue);

/* 拖拽文件至该程序，程序进行重写以实现文件解密*/
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        /* 存在拖入文件 */
        std::cout << "Droped files: " << std::endl;
        int result = false;
        std::string tip;
        for (int i = 1; i < argc; ++i)
        {
            result = rewrite_file(argv[i], tip);
            printf("\t[%s%s] %s\n",
                   result ? "FINISH :)" : "REEOR | ",
                   result ? "" : tip.c_str(),
                   argv[i]);
        }
    }
    else
    {
        std::cout << "None of file droped" << std::endl;
    }

    system("pause");
    return 0;
}

bool rewrite_file(const char *file_path, std::string &tip)
{
    bool result = false;
    tip.clear();

    std::string file_name(file_path);
    //file_name = UtfToGbk(file_name);    // 转GBK
    std::string file_data;

    if (read_file(file_name, file_data))
    {
        // 读取成功，则执行写入
        result = write_file(file_name, file_data);
        if (!result)
        {
            tip = "Failed to write file";
        }
    }
    else
    {
        tip = "Failed to read file";
        result = false;
    }

    return result;
}

bool read_file(const std::string &file_name, std::string &data)
{
    bool result = false;
    if (std::filesystem::is_regular_file(file_name))
    {
        // 创建 fstream 对象
        std::fstream file(file_name, std::ios::in);

        // 检查文件是否成功打开
        if (file.is_open())
        {
            // 获取文件大小
            file.seekg(0, std::ios::end);
            std::streampos file_size = file.tellg();
            file.seekg(0, std::ios::beg);

            // 创建原始数组
            char *buffer = new char[file_size];
            file.read(buffer, sizeof(buffer));
            data = std::string(buffer, sizeof(buffer));
            // 释放数组内存
            delete[] buffer;
            // 关闭文件
            file.close();
            result = true;
        }
    }
    return result;
}

bool write_file(const std::string &file_name, const std::string &data)
{
    bool result = false;
    if (std::filesystem::is_regular_file(file_name))
    {
        std::fstream file(file_name, std::ios::out | std::ios::trunc);
        if (file.is_open())
        {
            file.seekg(0, std::ios::beg);
            file.write(data.c_str(), data.size());
            file.close();
            result = true;
        }
    }
    return result;
}

std::string UtfToGbk(std::string strValue)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strValue.c_str(), -1, NULL, 0);
    wchar_t *wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_UTF8, 0, strValue.c_str(), -1, wstr, len);
    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
    char *str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
    if (wstr)
        delete[] wstr;
    return std::string(str);
}