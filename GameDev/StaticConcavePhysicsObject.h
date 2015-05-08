#pragma once
#include "PhysicsObject.h"

/**
* @class	StaticConcavePhysicsObject
*
* @brief	A static concave physics object is generated from the vertices
* 			of the mesh and passes them into a btTriangleMesh where
* 			a collision object is made. This shape must be static
* 			
* @author	Sean Armstrong
* @date	07/05/2015
*/
class StaticConcavePhysicsObject : public PhysicsObject
{
public:
	/**
	* @fn	StaticConcavePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	*
	* @brief	Constructor
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	renderObject	If non-null, the render object.
	* @param	pos						The position.
	* @param	mass					The mass.
	* @param	m					    The mesh containing the vertices
	* @param	scale					The scale of the object.
	*/
	StaticConcavePhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, Mesh* m, const float scale);
	~StaticConcavePhysicsObject();

	/**
	* @fn	virtual void StaticConcavePhysicsObject::updateRenderObject();
	*
	* @brief	Updates the render object.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*/
	void updateRenderObject();

private: 

	// Triangle Mesh containing the vertices
	btTriangleMesh* tMesh;

	// Scale of the object
	float scale;

	// Mesh passed from game object
	Mesh* mesh;
};

