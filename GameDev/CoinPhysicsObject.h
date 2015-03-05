#pragma once
#include "SpherePhysicsObject.h"

/**
 * @class	CoinPhysicsObject
 *
 * @brief	A coin physics object inherits from sphere physics object
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class CoinPhysicsObject : public SpherePhysicsObject
{
public:

	/**
	 * @fn	CoinPhysicsObject::CoinPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	 *
	 * @brief	Constructor for coin physics object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param	pos						The position.
	 * @param	mass					The mass.
	 * @param	radius					The radius.
	 */

	CoinPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius);
	virtual ~CoinPhysicsObject();

	/**
	 * @fn	virtual void CoinPhysicsObject::updateRenderObject();
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void updateRenderObject();

private:
};

