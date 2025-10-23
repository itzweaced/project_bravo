#include "rigid_body.h"

RigidBody::RigidBody(Entity* entity)
{
    entity = entity;
};

void RigidBody::applySimpleForce(glm::vec3 setVelocity)
{
    entity->setPosition( entity->returnPosition() + setVelocity);
};