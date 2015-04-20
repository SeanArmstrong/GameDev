#pragma once
class Level
{
public:
	Level();
	~Level();

	void Initialise();
	void Pause();
	void Resume();
	void Update();
	void GameLogic();
	void Render();
	void LoadMap();
	void LoadObjects();
	void LoadPlayer();
private:

	void removeDeletedObjects();
};

