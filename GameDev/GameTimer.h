#pragma once

#include <time.h>
#include <Windows.h>
#include <iostream>

class GameTimer
{
public:
	static float getTime();
	static float getDelta();
	static void setDelta(const float& d);

private:
	static float delta;
	static bool initialised;
	static float freq;
};
