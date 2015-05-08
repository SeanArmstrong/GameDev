#include "GameObject.h"

GameObject::~GameObject(){
	// Render Object Deleted by SFML Renderer
	delete po;
}

void GameObject::addPhysicsObjectToWorld(btDynamicsWorld& world){
	world.addRigidBody(po->getBody());
}
void GameObject::addRenderObjectToWorld(SFMLRenderer& renderer){
	renderer.AddRenderObject(*ro);
}
void GameObject::addTransparentRenderObjectToWorld(SFMLRenderer& renderer){
	renderer.AddTransparentRenderObject(*ro);
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