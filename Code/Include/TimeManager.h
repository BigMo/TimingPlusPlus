#pragma once

#include <chrono>
#include "Types.h"

namespace TimingPlusPlus {
    class TimeManager {
    public:
        //Constructors
        TimeManager();

        //Getters
        const TimePoint &GetStart() const { return this->m_tpStart; }

        const TimePoint &GetLastCall() const { return this->m_tpLast; }

        //const uintptr_t GetLogicCallback() const { return reinterpret_cast<const uintptr_t>(this->m_cbLogic); }

        //const uintptr_t GetDrawingCallback() const { return reinterpret_cast<const uintptr_t>(this->m_cbDrawing); }

        uint16_t GetDesiredFramerate() const { return this->m_Framerate; }

        uint32_t GetFrames() const { return this->m_Frames; }

        uint32_t GetTicks() const { return this->m_Ticks; }

        uint16_t GetMSPerTick() const { return this->m_TickDuration; }

        double GetFPS() const;

        double GetTPS() const;

        bool GetRunning() const { return this->m_Running; }

        bool GetDropFrames() const { return this->m_DropFrames; }

        bool GetLimitFrames() const { return this->m_LimitFrames; }

        double GetElapsedSeconds() const { return this->m_ElapsedSeconds; }

        double GetTotalElapsedSeconds() const { return this->m_TotalElapsedSeconds + this->m_ElapsedSeconds; }

        uint32_t GetFramesDropped() const { return this->m_FramesDropped; }

        //Setters
        void SetLogicCallback(Callback p_Callback) { this->m_cbLogic = p_Callback; }

        void SetDrawingCallback(Callback p_Callback) { this->m_cbDrawing = p_Callback; }

        void SetDesiredFramerate(std::uint16_t p_Framerate);

        void SetRunning(bool p_Running) { this->m_Running = p_Running; }

        void SetDropFrames(bool p_DropFrames) { this->m_DropFrames = p_DropFrames; }

        void SetLimitFrames(bool p_LimitFrames) { this->m_LimitFrames = p_LimitFrames; }

        //Methods
        void Run();

        void ResetStats();

    private:
        //Methods


        //Variables
        TimePoint m_tpStart;
        TimePoint m_tpLast;
        Callback m_cbLogic;
        Callback m_cbDrawing;
        uint16_t m_Framerate;
        uint32_t m_Frames;
        uint32_t m_FramesDropped;
        uint32_t m_Ticks;
        uint16_t m_TickDuration;
        double m_ElapsedSeconds;
        double m_TotalElapsedSeconds;
        bool m_DropFrames;
        bool m_Running;
        bool m_LimitFrames;
    };
}

