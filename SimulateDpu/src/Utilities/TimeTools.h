#pragma once
#include <chrono>

/*
*   时间获取、计时器工具
*   初始化时，开始计时
*/
class Timer
{
public:
    // 初始化时，开始计时
    Timer() : m_start_time(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {}

    // 获取时间间隔
    double elapsed() const;
    // 重新计时,单位 : ms
    void relock();
    // 获取当前时间
    static void get_current_time();

private:  
    // 开始计时时间
    std::chrono::high_resolution_clock::time_point m_start_time;
};



