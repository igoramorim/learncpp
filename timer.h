#pragma once

#include <chrono>

class Timer
{
private:
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_type> m_beg;

public:
	Timer();

	void reset();

	double elapsed() const;
};
