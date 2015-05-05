#pragma once
#include "SinglePlayerLevel.h"
#include "SphereGameObject.h"
#include "PoolBallGameObject.h"
#include "AerialCamera.h"

class PoolLevel : public SinglePlayerLevel
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

	virtual void setObjectiveHUDText();

private:

	Camera* cameras[2];
	int cameraTracker;
	float timeSinceCameraChanged;
	float CAMERA_RESET_TIME = 1.0f;
};

