#ifndef COLLIDER_H
#define COLLIDER_H

#include <vector>
#include "entity.h"
#include "model.h"
#include "geometry.h"
#include "mesh.h"
#include <thread>

struct ColliderFace
{
    Vertex v0;
    Vertex v1;
    Vertex v2;

    Vertex normal;
};

class Collider
{
private:
    Entity* entity;
    Model* model;
    Geometry* geometry;

    std::vector<Vertex> AABB;

    glm::vec3 boundingSphereCenter;
    glm::vec3 boundingSphereRadius;

    std::vector<ColliderFace> colliderMesh;

public:
    Collider(Entity* setEntity, Model* setModel, Geometry* setGeometry);
    
    std::vector<Vertex> returnAABB();
    glm::vec3 returnBoundingSphereCenter();
    glm::vec3 returnBoundingSphereRadius();
    std::vector<ColliderFace> returnColliderMesh();

};

#endif