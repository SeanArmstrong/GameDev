#pragma once
#include "Level.h"

class Level1 : public Level {
public:

	/*
	* This is the first submission demo level
	*/

	Level1(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level1();
	virtual void Initialise();

	virtual void GameLogic();

	virtual void SetView();
	virtual void LoadResources();
	virtual void LoadMap();
	virtual void LoadObjects();
	virtual void LoadPlayer();
};

