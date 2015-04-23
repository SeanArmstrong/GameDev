#pragma once
#include "Level.h"
#include "SphereGameObject.h"
#include "PoolBallGameObject.h"

class PoolLevel : public Level
{
public:
	PoolLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~PoolLevel();

	virtual void Initialise();
	virtual void GameLogic();

protected:

	virtual void SetView();
	virtual void LoadResources();
	virtual void LoadMap();
	virtual void LoadObjects();
	virtual void LoadPlayer();
};

