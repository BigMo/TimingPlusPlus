cmake_minimum_required(VERSION 3.5)
project(TimingPlusPlus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Code/Source/TimeManager.cpp Code/Include/TimeManager.h Code/Source/TimeManager.cpp Code/Include/TimeManager.h Code/Source/StopWatch.cpp Code/Include/StopWatch.h Code/Include/Types.h)
add_executable(TimingPlusPlus ${SOURCE_FILES})