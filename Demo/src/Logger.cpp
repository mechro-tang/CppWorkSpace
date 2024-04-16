#include "Logger.h"

LogRecord::LogRecord()
    : log_content(""),
    log_level(LogLevel::DEBUG),
    log_time(std::chrono::system_clock::now()),
    log_target(LogTarget::file)
{}

LogRecord::LogRecord(const std::string& str_content)
    : log_content(str_content),
    log_level(LogLevel::DEBUG),
    log_time(std::chrono::system_clock::now()),
    log_target(LogTarget::file)
{}

LogRecord::LogRecord(const std::string& str_content, const LogLevel& level)
    : log_content(str_content),
    log_level(level),
    log_time(std::chrono::system_clock::now()),
    log_target(LogTarget::file)
{}

Logger::Logger()
    : log_vector(std::vector<LogRecord>()),
    log_file(""),
    log_file_stream(),
    log_thread(std::thread(&Logger::log_thread_func, this)),
    log_thread_exit(log_thread.joinable() == false)
{}

Logger::~Logger()
{
    log_mutex.lock();

    if (log_file_stream.is_open())
    {
        log_file_stream.close();
    }

    // if (log_console_stream.is_open())
    // {
    //     log_console_stream.close();
    // }
    
    if (this->log_thread_exit == false)
    {
        this->log_thread_exit = true;
    }

    log_mutex.unlock();
    
    if (this->log_thread.joinable())
    {
            
        this->log_thread.join();
    }
}

bool Logger::add_log_record(const LogRecord& log_record)
{
    log_mutex.lock();

    try
    {
        this->log_vector.push_back(log_record);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        log_mutex.unlock();
        return false;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "[Logger::add_log_record]Failed to push_back: " << e.what() << std::endl;
        // 检查是否是因为容器空间不足
        if (e.what() == "container overflow") {
            // 处理container overflow
        }
        log_mutex.unlock();
        return false;
    }
    
    

    log_mutex.unlock();

    return true;
}