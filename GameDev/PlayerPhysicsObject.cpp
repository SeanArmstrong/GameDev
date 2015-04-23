#include "PlayerPhysicsObject.h"



PlayerPhysicsObject::PlayerPhysicsObject(RenderObject* renderObject, const Vector3& pos, const float mass, const float radius) 
		: SpherePhysicsObject(renderObject, pos, mass, radius)
{	
	//body->setRestitution(0.8f);
	body->setFriction(1.0f);
	body->setActivationState(DISABLE_DEACTIVATION); // always active
	//body->setAngularFactor(0.0f); // Keep upright
}


PlayerPhysicsObject::~PlayerPhysicsObject()
{
}

void PlayerPhysicsObject::updateRenderObject(){
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	//std::cout << "(" << trans.getOrigin().getX() << ", " << trans.getOrigin().getY() << ", " << trans.getOrigin().getZ() << std::endl;
	ro->SetModelMatrix(trans);
	ro->SetModelMatrix(ro->GetModelMatrix() * Matrix4::Scale(Vector3(radius, radius, radius)));
}
