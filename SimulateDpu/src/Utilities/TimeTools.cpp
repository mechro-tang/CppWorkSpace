#include <iostream>
#include "TimeTools.h"
#include <ctime>
#include <chrono>

// 获取当前时间
void Timer::get_current_time()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now(); 
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);
}

// 获取时间间隔,单位 : ms
double Timer::elapsed() const
{
    std::chrono::high_resolution_clock::time_point timer;
    std::chrono::duration<double> elapsed_seconds = timer - this->m_start_time;
    return elapsed_seconds.count() * 1000.0f;
}

// 重新计时
void Timer::relock()
{
    this->m_start_time = std::chrono::high_resolution_clock::now();
}