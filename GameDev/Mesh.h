#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "GL/glew.h"
#include <SFML/OpenGL.hpp>
#include "SOIL.h"

#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Quaternion.h"
#include "Matrix4.h"

using std::ifstream;
using std::string;

//A handy enumerator, to determine which member of the bufferObject array
//holds which data
enum MeshBuffer {
	VERTEX_BUFFER	=0,
	COLOUR_BUFFER	=1, 
	TEXTURE_BUFFER	,
	NORMAL_BUFFER	, 
	TANGENT_BUFFER	,
	INDEX_BUFFER	,
	MAX_BUFFER
};

/**
 * @class	Mesh
 *
 * @brief	A mesh adapted from nclgl to include obj loader
 * 			and other generation methods
 *
 * @author	Richard Davidson
 * @Edited  Sean Armstrong
 * @date	05/03/2015
 */

class Mesh	{
public:
	friend class MD5Mesh;
	Mesh(void);
	virtual ~Mesh(void);

	virtual void Draw();

	//Generates a single triangle, with RGB colours
	static Mesh*	GenerateTriangle();
	static Mesh*	GenerateQuad();
	static Mesh*	GenerateLine(const Vector3 &from, const Vector3 &to, const Vector3 c0, const Vector3 c1);
	static Mesh*	LoadMeshFile(const string &filename);
	static Mesh*	LoadMeshObj(const string &filename);
	void			GenerateNormals();

	GLuint	type;	//Primitive type for this mesh (GL_TRIANGLES...etc)

	Vector3* getVertices() const {
		return vertices;
	}

	unsigned int* getIndices() const {
		return indices;
	}

	int getNumberOfIndices() const {
		return numIndices;
	}

	int getNumberOfVertices() const {
		return numVertices;
	}



protected:
	//Buffers all VBO data into graphics memory. Required before drawing!
	void	BufferData();

	//VAO for this mesh
	GLuint	arrayObject;
	//VBOs for this mesh
	GLuint	bufferObject[MAX_BUFFER];
	//Number of vertices for this mesh
	GLuint	numVertices;

	//Number of indices for this mesh
	GLuint			numIndices;

	//Pointer to vertex position attribute data (badly named...?)
	Vector3*		vertices;
	//Pointer to vertex colour attribute data
	Vector4*		colours;
	//Pointer to vertex texture coordinate attribute data
	Vector2*		textureCoords;
	//Pointer to vertex normals attribute data
	Vector3*		normals;
	//Pointer to vertex tangents attribute data
	Vector3*		tangents;
	//Pointer to vertex indices attribute data
	unsigned int*	indices;
};

