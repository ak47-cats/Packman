#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

class Timer {
private:
    const int interval_; // in ms
    std::chrono::_V2::steady_clock::time_point startTime_;

public:
    Timer(const int interval): interval_(interval) {};

    void Start() {
        startTime_ = std::chrono::steady_clock::now();
    }

    bool IsTimeOut() {
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - 
                                                                            startTime_).count();
        return (elapsedTime >= interval_);
    }
};

#endif // TIMER_HPP