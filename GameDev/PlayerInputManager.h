#pragma once
#include <vector>
#include "Singleton.h"
#include <SFML\Window.hpp>
#include "PlayerGameObject.h"

// Deals with player input during game levels
class PlayerInputManager : public Singleton<PlayerInputManager>
{
public:

	friend class Singleton<PlayerInputManager>;

	enum ControlSets { WASD, ARROWS };

	int getControlSet();

	bool MovePlayerForward(const int playerControlSet);
	bool MovePlayerBackward(const int playerControlSet);
	bool MovePlayerLeft(const int playerControlSet);
	bool MovePlayerRight(const int playerControlSet);
	bool JumpPlayer(const int playerControlSet);

protected:

	PlayerInputManager();
	~PlayerInputManager();

private:
	int controlSetTracker = 0;

	std::vector<PlayerGameObject*> players;

};

