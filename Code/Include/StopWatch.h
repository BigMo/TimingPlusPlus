#pragma once

#include <chrono>
#include "Types.h"

namespace TimingPlusPlus {
    class StopWatch {
    public:
        //Constructors
        StopWatch();

        //Methods
        void Start();

        void Stop();

        //Getters
        uint32_t GetElapsedMilliseconds() { return this->m_ElapsedMilliseconds; }

    private:
        //Variables
        TimePoint m_Start;
        TimePoint m_End;
        uint32_t m_ElapsedMilliseconds;
    };
}

