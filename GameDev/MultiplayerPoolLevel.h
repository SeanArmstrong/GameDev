#pragma once
#include "Level.h"
#include "AerialCamera.h"

class MultiplayerPoolLevel : public Level
{
public:
	MultiplayerPoolLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~MultiplayerPoolLevel();

	virtual void Initialise();
	virtual void GameLogic();

protected:

	virtual void SetView();
	virtual void LoadResources();
	virtual void LoadMap();
	virtual void LoadObjects();
	virtual void LoadPlayer();

private:

	PlayerGameObject* player2;
};

