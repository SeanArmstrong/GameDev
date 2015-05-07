#pragma once
#include "PlaneGameObject.h"

/**
* @class	PlaneGameObject
*
* @brief	A specific PlaneGameObject that adds multiple textures for haze effect
*			inherits from PlaneGameObject
*
* @author	Sean Armstrong
* @date	07/05/2015
*/
class HazeGameObject : public PlaneGameObject
{
public:

	/**
	* @fn	HazeGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	*
	* @brief	Constructor.
	*
	* @author	Sean Armstrong
	* @date	07/05/2015
	*
	* @param [in,out]	normal		The normal that defines the plane
	* @param	mass		  		The mass. Set to 0 so plane doesn't move
	* @param	distance	  		The distance down the normal
	* @param [in,out]	s	  		If non-null, object shader used when creating the render object
	* @param	t			  		Plane Texture for render object
	* @param PlayerContact Action	Action to take on collision with player
	*/
	HazeGameObject(Vector3& normal, const float mass, const float distance, Shader*s = NULL, GLuint t = 0, PlayerContactAction tca = Deadly);
	virtual ~HazeGameObject();
};

