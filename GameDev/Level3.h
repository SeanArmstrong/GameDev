#pragma once
#include "SinglePlayerLevel.h"

class Level3 : public SinglePlayerLevel
{
public:
	Level3(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~Level3();

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

