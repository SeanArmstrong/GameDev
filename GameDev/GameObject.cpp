#include "GameObject.h"

GameObject::GameObject(){

}


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

void GameObject::update(){
	po->updateRenderObject();
}

RenderObject* GameObject::getRenderObject(){
	return ro;
}

PhysicsObject* GameObject::getPhysicsObject(){
	return po;
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