#include <iostream>
#include <thread>
#include "Code/Include/Types.h"
#include "Code/Include/TimeManager.h"
#include "Code/Include/StopWatch.h"

TimingPlusPlus::TimeManager m;

void LogicCallback(double p_TotalElapsedSeconds, double p_ElapsedSeconds) {
    std::cout << "[-] Tick #" << m.GetTicks() << " (" << p_TotalElapsedSeconds << " / " << p_ElapsedSeconds << ")" << std::endl;

    if (p_TotalElapsedSeconds >= 5)
        m.SetRunning(false);
}

void DrawingCallback(double p_TotalElapsedSeconds, double p_ElapsedSeconds) {
    auto ms = rand() % m.GetMSPerTick();
    std::cout << "[+] Frame #" << m.GetTicks() << ", sleeping " << ms << "ms (" << p_TotalElapsedSeconds << " / " << p_ElapsedSeconds << ")" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    std::cout << "Launching TimeManager!" << std::endl;

    TimingPlusPlus::StopWatch stopWatch;
    stopWatch.Start();

    m.SetDesiredFramerate(60);
    m.SetLogicCallback(&LogicCallback);
    m.SetDrawingCallback(&DrawingCallback);
    m.Run();

    stopWatch.Stop();

    std::cout << "Time: " << (stopWatch.GetElapsedMilliseconds() / 1000.0) << "s" << std::endl;

    std::cout << "Stats:" << std::endl;
    std::cout << "Ticks: " << m.GetTicks() << std::endl;
    std::cout << "Frames: " << m.GetFrames() << std::endl;
    std::cout << "Seconds: " << m.GetTotalElapsedSeconds() << std::endl;
    std::cout << "TPS/FPS: " << m.GetTPS() << "/" << m.GetFPS() << std::endl;
    std::cout << "Dropped frames: " << m.GetFramesDropped() << std::endl;

    return 0;
}