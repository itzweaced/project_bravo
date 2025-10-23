#ifndef RAYCAST_H
#define RAYCAST_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "entity.h"
#include "camera.h"
#include "collider.h"

class Raycast
{
public:
    bool raycast_collsion( glm::vec3 origin, glm::vec3 direction, Collider* collider);
    float raycast_distance();
    glm::vec3 raycast_intersectionPoint();
};

#endif