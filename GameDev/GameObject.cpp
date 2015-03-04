#include "GameObject.h"

GameObject::~GameObject(){
	delete ro;
	delete po;
}

void GameObject::addPhysicsObjectToWorld(btDynamicsWorld& world){
	world.addRigidBody(po->getBody());
}
void GameObject::addRenderObjectToWorld(SFMLRenderer& renderer){
	renderer.AddRenderObject(*ro);
}

void GameObject::removePhysicsObjectFromWorld(btDynamicsWorld& world){
	world.removeRigidBody(po->getBody());
}
void GameObject::removeRenderObjectFromWorld(SFMLRenderer& renderer){
	renderer.RemoveRenderObject(*ro);
}

void GameObject::update(){
	if (po->hasRenderObject()){
		po->updateRenderObject();
	}
}

RenderObject* GameObject::getRenderObject(){
	return ro;
}

PhysicsObject* GameObject::getPhysicsObject(){
	return po;
}

bool GameObject::getExistsInWorld(){
	return existsInWorld;
}

void GameObject::setExistsInWorld(bool status){
	existsInWorld = status;
}















/*
void GameObject::addChild(const GameObject& child){
	children.push_back(child);
}

void GameObject::input(){

	std::vector<GameObject>::iterator comp;
	for (comp = children.begin(); comp < children.end(); ++comp) {
		comp->input();
	}

	std::vector<GameObject>::iterator obj;
	for (obj = children.begin(); obj < children.end(); ++obj) {
		obj->input();
	}
}

void GameObject::update(){

	std::vector<GameObject>::iterator comp;
	for (comp = children.begin(); comp < children.end(); ++comp) {
		comp->update();
	}

	std::vector<GameObject>::iterator obj;
	for (obj = children.begin(); obj < children.end(); ++obj) {
		obj->update();
	}
}

void GameObject::render(){

	std::vector<GameObject>::iterator comp;
	for (comp = children.begin(); comp < children.end(); ++comp) {
		comp->render();
	}

	std::vector<GameObject>::iterator obj;
	for (obj = children.begin(); obj < children.end(); ++obj) {
		obj->render();
	}
}*/