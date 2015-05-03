#pragma once
#include <vector>
#include "Singleton.h"
#include <SFML\Window.hpp>
#include "PlayerGameObject.h"

class InputManager : public Singleton<InputManager>
{
public:

	friend class Singleton<InputManager>;

	enum ControlSets { WASD, ARROWS };

	int getControlSet();

	bool MovePlayerForward(const int playerControlSet);
	bool MovePlayerBackward(const int playerControlSet);
	bool MovePlayerLeft(const int playerControlSet);
	bool MovePlayerRight(const int playerControlSet);
	bool JumpPlayer(const int playerControlSet);

protected:

	InputManager();
	~InputManager();

private:
	int controlSetTracker = 0;

	std::vector<PlayerGameObject*> players;

};

