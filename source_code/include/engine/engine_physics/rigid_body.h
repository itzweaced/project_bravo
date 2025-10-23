#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "entity.h"

class RigidBody
{
private:
    Entity* entity;

public:
    RigidBody(Entity* entity);

public:
    void applySimpleForce(glm::vec3 setVelocity);
};

#endif