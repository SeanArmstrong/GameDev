#pragma once
#include "Singleton.h"
#include "Mesh.h"
#include <string>
#include <map>

class MeshManager : public Singleton<MeshManager>
{
public:

	// Friend can access protected Constructors
	friend class Singleton<MeshManager>;

	Mesh* GetMesh(const std::string meshName);
	Mesh* AddMeshFile(const std::string meshName, const int type, const std::string fileName = "");
	Mesh* AddMeshFromMethod(const std::string meshName, const std::string methodName);

protected:

	MeshManager();
	~MeshManager();

private:

	std::map<std::string, Mesh*> meshes;


};

