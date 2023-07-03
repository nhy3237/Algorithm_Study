#pragma once
#include <ctime>

class StopWatch
{
private:
	clock_t startTime, endTime;

public:
	clock_t getST();
	clock_t endET();
	
	StopWatch();
	
	void start();
	void stop();
	double getElapsedTime();
};
