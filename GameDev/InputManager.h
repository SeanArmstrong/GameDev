#pragma once
#include <vector>

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Update();

	void KeyPressed(int key);
	void KeyPressed(std::vector<int> keys);
	void KeyReleased(int key);
	void KeyReleased(std::vector<int> keys);

private:


};

