#include "../Include/StopWatch.h"

namespace TimingPlusPlus {
    StopWatch::StopWatch()
            : m_Start(CURRENT_TIME), m_End(CURRENT_TIME),
              m_ElapsedMilliseconds(0) {

    }

    void StopWatch::Start() {
        this->m_Start = CURRENT_TIME;
        this->m_End = CURRENT_TIME;
        this->m_ElapsedMilliseconds = 0;
    }

    void StopWatch::Stop() {
        this->m_End = CURRENT_TIME;
        this->m_ElapsedMilliseconds = (uint32_t) std::chrono::duration_cast<std::chrono::milliseconds>(
                this->m_End - this->m_Start).count();
    }
}

