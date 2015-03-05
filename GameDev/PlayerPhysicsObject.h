#pragma once
#include "SpherePhysicsObject.h"
#include "RenderObject.h"

/**
 * @class	PlayerPhysicsObject
 *
 * @brief	A player physics object inherits sphere physics object
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class PlayerPhysicsObject : public SpherePhysicsObject
{
public:

	/**
	 * @fn	PlayerPhysicsObject::PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	 *
	 * @brief	Constructor for player physics object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param	pos						The position.
	 * @param	mass					The mass.
	 * @param	radius					The radius.
	 */

	PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~PlayerPhysicsObject();

	/**
	 * @fn	void PlayerPhysicsObject::updateRenderObject();
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	void PlayerPhysicsObject::updateRenderObject();

private:

	float deceleration;
	float maxSpeed;
	float jumpImpulse;
	float jumpRechargeTime;

};

