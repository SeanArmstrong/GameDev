#pragma once
#include "CoreEngine.h"

int main() {
	CoreEngine ce(1024, 768, 120);
	ce.run();
	return 0;
}