/*
* 日志类
*/

//#ifndef LOGGER_H
//#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include "../Utility/Singleton.hpp"

#define system_time_point std::chrono::system_clock::time_point

// 日志等级
enum class LogLevel
{
    ALL,        // 最低等级，打开所有日志记录
    TRACE,      // 
    DEBUG,      // 开发调试应用程序      
    INFO,       // 应用程序的运行过程,记录系统正常运行状态
    WARNING,    // 表明会出现潜在错误的情形,例如传参、磁盘使用量超过阈值、存储配额快用完
    ERROR,      // 指出虽然发生错误事件，已经影响了用户的正常访问，但仍然不影响系统的继续运行
    FATAL,      // 致命错误，该进程遇到无法恢复的错误而退出，系统管理员需要立即介入
    OFF         // 最高等级,关闭所有日志记录
};

// 日志输出目标
enum class LogTarget
{
    file,
    console,
    both_file_console
};

// 日志记录
class LogRecord
{
public:
    LogRecord();
    LogRecord(const std::string& str_content);
    LogRecord(const std::string& str_content, const LogLevel& level = LogLevel::DEBUG);
    ~LogRecord();

private:
    std::string log_content;    
    system_time_point log_time;
    LogLevel    log_level;
    LogTarget   log_target;
};


class Logger : public Singleton<Logger>
{
public:
    bool add_log_record(const LogRecord& log_record);

private:
    Logger();
    ~Logger();
    void log_thread_func();             // 日志线程函数

    std::vector<LogRecord> log_vector;    // 日志缓存               
    std::string log_file;                 // 日志输出文件 
    std::ofstream log_file_stream;        // 日志文件流      
    std::thread log_thread;               // 日志线程
    std::mutex log_mutex;                 // 日志互斥锁
    //std::condition_variable log_cv;     // 条件变量
    bool log_thread_exit;                 // 线程退出标志
};
