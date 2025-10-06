#include "collision.h"


bool Collision::checkCollisionAABB(Collider* currentCollider, Collider* checkedCollider )
{
    if(
        
        // Need to apply transformation if geometry is rotated

        // X Axis
        currentCollider->returnAABB()[0].Position.x <= checkedCollider->returnAABB()[1].Position.x && 
        currentCollider->returnAABB()[1].Position.x >= checkedCollider->returnAABB()[0].Position.x && 
        // Y Axis
        currentCollider->returnAABB()[0].Position.y <= checkedCollider->returnAABB()[4].Position.y &&
        currentCollider->returnAABB()[4].Position.y >= checkedCollider->returnAABB()[0].Position.y && 
        // Z Axis
        currentCollider->returnAABB()[2].Position.z <= checkedCollider->returnAABB()[0].Position.z && 
        currentCollider->returnAABB()[0].Position.z >= checkedCollider->returnAABB()[2].Position.z 

    )
    {
        return true;
    }
    
    return false;
};



bool Collision::checkCollisionAABB_inside(Collider* insideCollider, Collider* checkedCollider )
{
    if(
        
        // X Axis
        insideCollider->returnAABB()[0].Position.x >= checkedCollider->returnAABB()[0].Position.x &&
        insideCollider->returnAABB()[0].Position.x <= checkedCollider->returnAABB()[1].Position.x &&
        insideCollider->returnAABB()[1].Position.x >= checkedCollider->returnAABB()[0].Position.x &&
        insideCollider->returnAABB()[1].Position.x <= checkedCollider->returnAABB()[1].Position.x &&
        insideCollider->returnAABB()[2].Position.x >= checkedCollider->returnAABB()[2].Position.x &&
        insideCollider->returnAABB()[2].Position.x <= checkedCollider->returnAABB()[3].Position.x &&
        insideCollider->returnAABB()[3].Position.x >= checkedCollider->returnAABB()[2].Position.x &&
        insideCollider->returnAABB()[3].Position.x <= checkedCollider->returnAABB()[3].Position.x &&

        // Y Axis
        insideCollider->returnAABB()[0].Position.y >= checkedCollider->returnAABB()[0].Position.y &&
        insideCollider->returnAABB()[0].Position.y <= checkedCollider->returnAABB()[4].Position.y &&
        insideCollider->returnAABB()[4].Position.y >= checkedCollider->returnAABB()[0].Position.y &&
        insideCollider->returnAABB()[4].Position.y <= checkedCollider->returnAABB()[4].Position.y &&
        insideCollider->returnAABB()[1].Position.y >= checkedCollider->returnAABB()[1].Position.y &&
        insideCollider->returnAABB()[1].Position.y <= checkedCollider->returnAABB()[5].Position.y &&
        insideCollider->returnAABB()[5].Position.y >= checkedCollider->returnAABB()[1].Position.y &&
        insideCollider->returnAABB()[5].Position.y <= checkedCollider->returnAABB()[5].Position.y &&

        // Z Axis
        insideCollider->returnAABB()[0].Position.z <= checkedCollider->returnAABB()[0].Position.z &&
        insideCollider->returnAABB()[0].Position.z >= checkedCollider->returnAABB()[2].Position.z &&
        insideCollider->returnAABB()[2].Position.z <= checkedCollider->returnAABB()[0].Position.z &&
        insideCollider->returnAABB()[2].Position.z >= checkedCollider->returnAABB()[2].Position.z &&
        insideCollider->returnAABB()[1].Position.z <= checkedCollider->returnAABB()[1].Position.z &&
        insideCollider->returnAABB()[1].Position.z >= checkedCollider->returnAABB()[3].Position.z &&
        insideCollider->returnAABB()[3].Position.z <= checkedCollider->returnAABB()[1].Position.z &&
        insideCollider->returnAABB()[3].Position.z >= checkedCollider->returnAABB()[3].Position.z

    )
    {
        return true;
    }
    else
    {
        return false;
    }
};