#pragma once
#include "Level.h"
class MultiPlayerLevel : public Level
{
public:
	MultiPlayerLevel(sf::RenderWindow* w, SFMLRenderer* r);
	virtual ~MultiPlayerLevel();

	virtual void Initialise() = 0;
	virtual void UpdateLevel();
	virtual void RenderLevel();
	virtual void GameLogic() = 0;
	virtual void GeneralGameLogic();

	virtual void SetView() = 0;
	virtual void LoadResources() = 0;
	virtual void LoadMap() = 0;
	virtual void LoadObjects() = 0;
	virtual void LoadPlayer() = 0;

	virtual std::string getControlText() const;

protected:

	bool allPlayersDead();
	virtual void setObjectiveHUDText() = 0;

	MultiPlayerGameHUD hud;

private:

};

