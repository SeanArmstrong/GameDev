#pragma once
#include "SinglePlayerLevel.h"

class Level4 : public SinglePlayerLevel
{
public:
	Level4(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level4();

	virtual void Initialise();
	virtual void GameLogic();

protected:

	virtual void SetView();
	virtual void LoadResources();
	virtual void LoadMap();
	virtual void LoadObjects();
	virtual void LoadPlayer();
	virtual void setObjectiveHUDText();
	virtual std::string getControlText() const;

};

