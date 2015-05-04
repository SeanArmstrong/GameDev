#pragma once
#include "SinglePlayerLevel.h"

class Level2 : public SinglePlayerLevel
{
public:
	Level2(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level2();

	virtual void Initialise();
	virtual void GameLogic();

protected: 

	virtual void SetView();
	virtual void LoadResources();
	virtual void LoadMap();
	virtual void LoadObjects();
	virtual void LoadPlayer();

private:
	
};

