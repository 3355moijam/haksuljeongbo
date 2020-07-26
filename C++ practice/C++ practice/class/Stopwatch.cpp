#include "Stopwatch.h"



Stopwatch::Stopwatch()
{
	startTime = clock();
}


Stopwatch::~Stopwatch()
{
}

void Stopwatch::start()
{
	startTime = clock();
}

void Stopwatch::stop()
{
	endTime = clock();
}