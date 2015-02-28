#include "GameTimer.h"

bool GameTimer::initialised;
float GameTimer::delta;
float GameTimer::freq;

float GameTimer::getTime(){
	if (!initialised)
	{
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li))
			std::cout << "QueryPerformanceFrequency failed in timer initialization" << std::endl;

		freq = float(li.QuadPart);
		initialised = true;
	}

	LARGE_INTEGER li;
	if (!QueryPerformanceCounter(&li))
		std::cerr << "QueryPerformanceCounter failed in get time!" << std::endl;

	return 1000.0f * float(li.QuadPart) / freq;
}
float GameTimer::getDelta(){
	return delta;
}
void  GameTimer::setDelta(const float& d){
	delta = d;
}
