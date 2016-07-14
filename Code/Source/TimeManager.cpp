#include <cmath>
#include <thread>
#include "../Include/TimeManager.h"

namespace TimingPlusPlus {
    double TimeManager::GetFPS() const {
        if (this->m_TotalElapsedSeconds <= 0)
            return 0;

        return this->m_Frames / this->m_TotalElapsedSeconds;
    }

    double TimeManager::GetTPS() const {
        if (this->m_TotalElapsedSeconds <= 0)
            return 0;

        return this->m_Ticks / this->m_TotalElapsedSeconds;
    }

    void TimeManager::Run() {
        bool draw;
        auto afterDrawing = CURRENT_TIME;

        this->m_Running = true;

        while (this->m_Running) {
            auto currentTick = CURRENT_TIME;
            draw = true;

            //Update variables
            this->m_TotalElapsedSeconds = (double) std::chrono::duration_cast<std::chrono::milliseconds>(
                    currentTick - this->m_tpStart).count() / 1000.0;
            this->m_ElapsedSeconds = (double) std::chrono::duration_cast<std::chrono::milliseconds>(
                    currentTick - this->m_tpLast).count() / 1000.0;

            //Perform logic
            if (this->m_cbLogic != nullptr) {
                this->m_cbLogic(this->m_TotalElapsedSeconds, this->m_ElapsedSeconds);
                this->m_Ticks++;
            }

            if (this->m_DropFrames) {
                if (this->m_cbDrawing == nullptr)
                    //Drawing-Callback isn't set: Skip drawing
                    draw = false;
                else if (std::chrono::duration_cast<std::chrono::milliseconds>(afterDrawing - this->m_tpLast).count() >= this->m_TickDuration)
                    //The last tick took too long: Skip drawing
                    draw = false;
            }

            //Perform drawing
            if (draw) {
                if (this->m_cbDrawing != nullptr) {
                    this->m_cbDrawing(this->m_TotalElapsedSeconds, this->m_ElapsedSeconds);
                    this->m_Frames++;
                }
            } else {
                m_FramesDropped++;
            }
            afterDrawing = CURRENT_TIME;

            //Limit frames
            if (this->m_LimitFrames) {
                auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(afterDrawing - currentTick).count();
                if (ms < this->m_TickDuration)
                    std::this_thread::sleep_for(std::chrono::milliseconds(this->m_TickDuration - ms));
            }
            this->m_tpLast = currentTick;
        }
    }

    void TimeManager::SetDesiredFramerate(std::uint16_t p_Framerate) {
        this->m_Framerate = p_Framerate;
        this->m_TickDuration = (std::uint16_t) ceil(1000.0 / (double) this->m_Framerate);
    }

    void TimeManager::ResetStats() {
        this->m_tpStart = CURRENT_TIME;
        this->m_tpLast = CURRENT_TIME;
        this->m_Frames = 0;
        this->m_Ticks = 0;
        this->m_FramesDropped = 0;
    }

    TimeManager::TimeManager() :
            m_tpStart(CURRENT_TIME),
            m_tpLast(CURRENT_TIME),
            m_cbDrawing(nullptr),
            m_cbLogic(nullptr),
            m_Frames(0),
            m_FramesDropped(0),
            m_Ticks(0),
            m_TickDuration(0),
            m_LimitFrames(true),
            m_DropFrames(true),
            m_Running(false),
            m_Framerate(60),
            m_ElapsedSeconds(0.0),
            m_TotalElapsedSeconds(0.0) {

    }


}