#pragma once
#include <ctime>

class Stopwatch
{
private:
	time_t startTime;
	time_t endTime;
public:
	Stopwatch();
	~Stopwatch();
	void start();
	void stop();
	time_t getElapsedTime() { return endTime - startTime; }
};

