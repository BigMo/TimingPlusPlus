#pragma once

#include <chrono>

namespace TimingPlusPlus {
    #define CURRENT_TIME std::chrono::steady_clock::now()
    typedef std::chrono::steady_clock::time_point TimePoint;
    typedef void (*Callback)(double p_Total, double p_LastCall) ;
}