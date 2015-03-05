#pragma once
#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "RenderObject.h"

/**
 * @class	PhysicsObject
 *
 * @brief	The physical representation of a object
 * 			Holds a rigid body and collision shape used by bullet
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class PhysicsObject
{
public:

	/**
	 * @fn	PhysicsObject::PhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass);
	 *
	 * @brief	Constructor for physical object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param [in,out]	renderObject	If non-null, the render object.
	 * @param	pos						The position.
	 * @param	mass					The mass.
	 */

	PhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass);
	virtual ~PhysicsObject();

	/**
	 * @fn	btRigidBody* PhysicsObject::getBody() const;
	 *
	 * @brief	Gets the rigid body of the object
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	null if it fails, else the body.
	 */

	btRigidBody* getBody() const;

	/**
	 * @fn	virtual void PhysicsObject::updateRenderObject() = 0;
	 *
	 * @brief	Updates the render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 */

	virtual void updateRenderObject() = 0;

	/**
	 * @fn	bool PhysicsObject::hasRenderObject();
	 *
	 * @brief	Query if this object has render object.
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @return	true if render object, false if not.
	 */

	bool hasRenderObject();

protected:

	btRigidBody* body;
	btCollisionShape* shape;
	float mass;

	RenderObject *ro;
	Vector3 position;

};

