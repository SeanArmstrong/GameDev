#include "MeshManager.h"


MeshManager::MeshManager(){

}


MeshManager::~MeshManager(){
	for (std::map<string, Mesh*>::iterator i = meshes.begin(); i != meshes.end(); ++i){
		delete i->second;
	}
}

Mesh* MeshManager::GetMesh(const std::string meshName){
	std::map<string, Mesh*>::iterator i = meshes.find(meshName);

	if (i != meshes.end()){
		return i->second;
	}

	return NULL;
}

Mesh* MeshManager::AddMeshFile(const std::string meshName, const int type, const std::string fileName){
	Mesh* mesh = GetMesh(meshName);

	if (mesh == NULL){
		if (type == 1){ // obj
			const string PATH = "assets/Models/";
			mesh = Mesh::LoadMeshObj(PATH + fileName);

		}
		else if (type == 2){ // asciimesh
			const string PATH = "assets/Models/";
			mesh = Mesh::LoadMeshFile(PATH + fileName);
		}
		meshes.insert(make_pair(meshName, mesh));
	}
	return mesh;
}

Mesh* MeshManager::AddMeshFromMethod(const std::string meshName, int method){
	Mesh* mesh = GetMesh(meshName);

	if (mesh == NULL){

		if (method == 1){
			mesh = Mesh::GenerateTriangle();
		}
		else if (method == 2){
			mesh = Mesh::GenerateQuad();
		}
		else if (method == 3){
			// Needs Vectors
			//mesh = Mesh::GenerateLine();
		}
	}
	return mesh;
}
