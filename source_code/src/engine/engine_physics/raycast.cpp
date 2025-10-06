#include "raycast.h"

bool Raycast::raycast_collsion(glm::vec3 origin, glm::vec3 direction, Collider* collider)
{
    std::vector<ColliderFace> colliderMesh = collider->returnColliderMesh();

    for(int i=0; i<colliderMesh.size(); i++)
    {
        glm::vec3 v0 = colliderMesh[i].v0.Position;
        glm::vec3 v1 = colliderMesh[i].v1.Position;
        glm::vec3 v2 = colliderMesh[i].v2.Position;
        glm::vec3 normal = colliderMesh[i].normal.Position;

        // Step 2: Check if ray is parallel to triangle plane
        float denom = glm::dot(normal, direction);
        if (fabs(denom) < 0.0001f) continue; // parallel → no intersection

        // Step 3: Find distance t along the ray to the plane
        float t = glm::dot(v0 - origin, normal) / denom;
        if (t < 0) continue; // intersection is behind the ray

        // Step 4: Compute intersection point
        glm::vec3 P = origin + t * direction;

        // Step 5: Check if P is inside the triangle using edge-cross method
        glm::vec3 edge0 = v1 - v0;
        glm::vec3 vp0   = P - v0;
        if (glm::dot(glm::cross(edge0, vp0), normal) < 0) continue;

        glm::vec3 edge1 = v2 - v1;
        glm::vec3 vp1   = P - v1;
        if (glm::dot(glm::cross(edge1, vp1), normal) < 0) continue;

        glm::vec3 edge2 = v0 - v2;
        glm::vec3 vp2   = P - v2;
        if (glm::dot(glm::cross(edge2, vp2), normal) < 0) continue;

        return true;
    }

    return false;
};