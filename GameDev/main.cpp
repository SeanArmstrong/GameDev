#pragma once
#include "CoreEngine.h"
#include "btBulletCollisionCommon.h"

int main() {
	CoreEngine ce(640, 480, 120);
	ce.run();

	return 0;
}