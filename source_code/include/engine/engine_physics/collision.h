#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

#include <iostream>
#include <string>
#include <entity.h>
#include <model.h>
#include <geometry.h>
#include <collider.h>


#define PI 3.14159265358979323846f


class Collision
{
private:
    std::vector<Collider*> colliders;

public:
    
    bool checkCollisionAABB(Collider* currentCollider, Collider* checkedCollider );
    bool checkCollisionAABB_inside(Collider* insideCollider, Collider* checkedCollider );
};

#endif