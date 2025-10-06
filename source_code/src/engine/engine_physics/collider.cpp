#include "collider.h"

Collider::Collider(GameObject* setGameobject, Model* setModel, Geometry* setGeometry)
{ 
    gameobject = setGameobject;

    if(setModel != nullptr)
    {
        this->model = setModel;
        this->AABB = setModel->returnBoundingBox();
    }
    if(setGeometry != nullptr)
    {
        this->geometry = setGeometry;
        this->AABB = setGeometry->returnBoundingBox();


        //////////////////////////////////
        /// !!! Create Collider Mesh !!!
        //////////////////////////////////

        std::vector<unsigned int> indices = geometry->returnIndices();

        /*

        Index: 0
        -1 , -1 , 10
        1 , -1 , 10
        -1 , -1 , -1
        0 , 1 , 0
        Index: 1
        -1 , -1 , -1
        1 , -1 , -1
        1 , -1 , 1
        0 , -1 , 0
        Index: 2
        -1 , 1 , 1
        1 , 1 , 1
        -1 , 1 , -1
        0 , 1 , 0
        Index: 3
        -1 , 1 , -1
        1 , 1 , -1
        1 , 1 , 1
        0 , -1 , 0
        Index: 4
        -1 , -1 , 1
        1 , -1 , 1
        -1 , 1 , 1
        0 , 0 , 1
        Index: 5
        -1 , 1 , 1
        1 , 1 , 1
        1 , -1 , 1
        0 , 0 , -1
        Index: 6
        -1 , -1 , -1
        1 , -1 , -1
        -1 , 1 , -1
        0 , 0 , 1
        Index: 7
        -1 , 1 , -1
        1 , 1 , -1
        1 , -1 , -1
        0 , 0 , -1
        Index: 8
        -1 , -1 , 1
        -1 , -1 , -1
        -1 , 1 , 1
        1 , -0 , 0
        Index: 9
        -1 , 1 , 1
        -1 , 1 , -1
        -1 , -1 , -1
        -1 , 0 , -0
        Index: 10
        1 , -1 , 1
        1 , -1 , -1
        1 , 1 , 1
        1 , -0 , 0
        Index: 11
        1 , 1 , 1
        1 , 1 , -1
        1 , -1 , -1
        -1 , 0 , -0

        indices = {
        0, 1, 2,
        2, 3, 1,
        4, 5, 6,
        6, 7, 5,
        0, 1, 4,
        4, 5, 1,
        2, 3, 6,
        6, 7, 3,
        0, 2, 4,
        4, 6, 2,
        1, 3, 5,
        5, 7, 3
        };

        for(int i=0; i<indices.size(); i+=3)
        {
            ColliderFace triangleFace;

            triangleFace.v0 = AABB[indices[i]];
            triangleFace.v1 = AABB[indices[i+1]];
            triangleFace.v2 = AABB[indices[i+2]];


            glm::vec3 edge1 = triangleFace.v1 - triangleFace.v0;
            glm::vec3 edge2 = triangleFace.v2 - triangleFace.v0;
            glm::vec3 normal = glm::normalize( glm::cross(edge1 , edge2) );
            triangleFace.normal = normal;

            colliderMesh.push_back(triangleFace);
        }
        
        */

        for(int i=0; i<indices.size(); i+=3)
        {
            ColliderFace triangleFace;

            triangleFace.v0 = AABB[indices[i]];
            triangleFace.v1 = AABB[indices[i+1]];
            triangleFace.v2 = AABB[indices[i+2]];


            glm::vec3 edge1 = triangleFace.v1.Position - triangleFace.v0.Position;
            glm::vec3 edge2 = triangleFace.v2.Position - triangleFace.v0.Position;
            glm::vec3 normal = glm::normalize( glm::cross(edge1 , edge2) );
            triangleFace.normal.Position = normal;

            colliderMesh.push_back(triangleFace);
        }

        //////////////////////////////////
        /// !!! Create Collider Mesh !!!
        //////////////////////////////////
    }
};

std::vector<Vertex> Collider::returnAABB()
{
    float pi = 3.14159265358979323846;

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, gameobject->returnPosition() );
    model = glm::rotate(model, gameobject->returnRotation().x * ( pi/180) , glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, gameobject->returnRotation().y * ( pi/180) , glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, gameobject->returnRotation().z * ( pi/180) , glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, gameobject->returnScale());
    
    std::vector<Vertex> tempAABB;

    for(int i=0; i<AABB.size(); i++)
    {
        glm::vec4 worldVertex = model * glm::vec4(AABB[i].Position, 1.0f);

        Vertex tempVertex;
        tempVertex.Position.x = worldVertex.x;
        tempVertex.Position.y = worldVertex.y;
        tempVertex.Position.z = worldVertex.z;

        tempAABB.push_back(tempVertex);
    }

    return tempAABB;
};

std::vector<ColliderFace> Collider::returnColliderMesh()
{
    float pi = 3.14159265358979323846;

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, gameobject->returnPosition() );
    model = glm::rotate(model, gameobject->returnRotation().x * ( pi/180) , glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, gameobject->returnRotation().y * ( pi/180) , glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, gameobject->returnRotation().z * ( pi/180) , glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, gameobject->returnScale());

    glm::mat4 normalModel = glm::mat4(1.0f);
    normalModel = glm::rotate(normalModel, gameobject->returnRotation().x * ( pi/180) , glm::vec3(1.0f, 0.0f, 0.0f));
    normalModel = glm::rotate(normalModel, gameobject->returnRotation().y * ( pi/180) , glm::vec3(0.0f, 1.0f, 0.0f));
    normalModel = glm::rotate(normalModel, gameobject->returnRotation().z * ( pi/180) , glm::vec3(0.0f, 0.0f, 1.0f));
    normalModel = glm::scale(normalModel, gameobject->returnScale());
    glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(normalModel)));

    std::vector<ColliderFace> worldCollider;

    for(int i=0; i<colliderMesh.size(); i++)
    {
        glm::vec4 worldV0 = model * glm::vec4(colliderMesh[i].v0.Position, 1.0f);
        glm::vec4 worldV1 = model * glm::vec4(colliderMesh[i].v1.Position, 1.0f);
        glm::vec4 worldV2 = model * glm::vec4(colliderMesh[i].v2.Position, 1.0f);
        glm::vec3 worldNormal = glm::normalize( normalMatrix * colliderMesh[i].normal.Position);

        ColliderFace tempColliderFace;
        tempColliderFace.v0.Position = worldV0;
        tempColliderFace.v1.Position = worldV1;
        tempColliderFace.v2.Position = worldV2;
        tempColliderFace.normal.Position = worldNormal;

        worldCollider.push_back(tempColliderFace);
    }

    return worldCollider;
};