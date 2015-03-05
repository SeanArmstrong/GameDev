#pragma once
#include "Singleton.h"
#include "Mesh.h"
#include <string>
#include <map>

/**
 * @class	MeshManager
 *
 * @brief	Manager for meshes.
 *
 * @author	Sean Armstrong
 * @date	05/03/2015
 */

class MeshManager : public Singleton<MeshManager>
{
public:
	// Friend can access protected Constructors
	friend class Singleton<MeshManager>;

	/**
	 * @fn	Mesh* MeshManager::GetMesh(const std::string meshName);
	 *
	 * @brief	Gets a mesh from given mesh name
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	meshName	Name of the mesh.
	 *
	 * @return	null if it fails, else the mesh.
	 */

	Mesh* GetMesh(const std::string meshName);

	/**
	 * @fn	Mesh* MeshManager::AddMeshFile(const std::string meshName, const int type, const std::string fileName = "");
	 *
	 * @brief	Adds a mesh to the system if it does not already exists
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	meshName	Name of the mesh.
	 * @param	type		The type: 1 = obj, 2 = ascii
	 * @param	fileName	Filename of the file.
	 *
	 * @return	null if it fails, else a Mesh*.
	 */

	Mesh* AddMeshFile(const std::string meshName, const int type, const std::string fileName = "");

	/**
	 * @fn	Mesh* MeshManager::AddMeshFromMethod(const std::string meshName, int method);
	 *
	 * @brief	Adds a mesh from a generate method
	 * 			method int types found in ResourceManager
	 *
	 * @author	Sean Armstrong
	 * @date	05/03/2015
	 *
	 * @param	meshName	Name of the mesh.
	 * @param	method  	The method.
	 *
	 * @return	null if it fails, else a Mesh*.
	 */

	Mesh* AddMeshFromMethod(const std::string meshName, int method);

protected:

	MeshManager();
	~MeshManager();

private:

	std::map<std::string, Mesh*> meshes;


};

