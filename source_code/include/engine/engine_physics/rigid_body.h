#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "gameobject.h"

class RigidBody
{
private:
    GameObject* gameobject;

public:
    RigidBody(GameObject* gameObject);

public:
    void applySimpleForce(glm::vec3 setVelocity);
};

#endif