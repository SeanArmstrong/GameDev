#pragma once
#include "CoreEngine.h"
#include "btBulletCollisionCommon.h"

int main() {
	btVector3 a(1, 2, 3);
	btBoxShape * box = new btBoxShape(btVector3(1, 1, 1));
	delete box;

	CoreEngine ce(640, 480, 120);
	ce.run();

	return 0;
}