#include "StopWatch.h"
#include <ctime>

clock_t StopWatch::getST()
{
    return startTime;
}

clock_t StopWatch::endET()
{
    return endTime;
}

StopWatch::StopWatch()
{
    startTime = clock();
}

void StopWatch::start()
{
    startTime = clock();
}

void StopWatch::stop()
{
    endTime = clock();
}

double StopWatch::getElapsedTime()
{
    return (double)(endTime - startTime)/1000;
}
