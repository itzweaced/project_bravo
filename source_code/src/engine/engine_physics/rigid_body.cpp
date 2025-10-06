#include "rigid_body.h"

RigidBody::RigidBody(GameObject* gameObject)
{
    gameobject = gameObject;
};

void RigidBody::applySimpleForce(glm::vec3 setVelocity)
{
    gameobject->setPosition( gameobject->returnPosition() + setVelocity);
};