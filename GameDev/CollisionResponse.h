#pragma once

#include "ResourceManager.h"
#include "GameObject.h"
#include "PlayerGameObject.h"
#include "CoinGameObject.h"


class CollisionResponse
{
public:
	CollisionResponse();
	~CollisionResponse();

	static void handleCollision(PlayerGameObject& player, PlaneGameObject& plane);

	static void handleCollision(PlayerGameObject& player, CoinGameObject& coin);

	static void handleCollision(PlaneGameObject& plane, PlayerGameObject& player);

	static void handleCollision(CoinGameObject& coin, PlayerGameObject& player);
};

