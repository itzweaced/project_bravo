#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "model.h"
#include "camera.h"
#include "geometry.h"


class GameObject
{

private:
    Camera* gameobject_camera;
    Shader* gameobject_shader;
    Model* gameobject_model;
    Geometry* gameobject_geometry;

    int gameobject_id;
    std::string gameobject_type;
    std::string gameobject_name;
    glm::vec3 gameobject_position;
    glm::vec3 gameobject_scale;
    glm::vec3 gameobject_rotation;
    glm::vec3 gameobject_velocity;

    glm::vec3 gameobject_color;

    bool enableRender;
    bool enableBoundingBox;

public:
    void setCamera(Camera* handleCamera);
    void setShader(Shader* handleShader);
    void setModel(Model* handleModel);
    void setGeometry(Geometry* handleGeometry);

    void setID(int id);
    void setType(std::string type);
    void setName(std::string name);
    void setPosition(glm::vec3 position);
    void setScale(glm::vec3 scale);
    void setRotation(glm::vec3 rotation);
    void setVelocity(glm::vec3 velocity);
    void setColor(glm::vec3 setColor);
    
    void setEnableRender(bool enable);
    void setEnableBoundingBox(bool enable);

public:
    Camera* returnCamera();
    Shader* returnShader();
    Model* returnModel();
    Geometry* returnGeometry();
    
    int returnID();
    std::string returnType();
    std::string returnName();
    glm::vec3 returnPosition();
    glm::vec3 returnScale();
    glm::vec3 returnRotation();
    glm::vec3 returnVelocity();
    glm::vec3 returnColor();

    bool returnEnableRender();
    bool returnEnableBoundingBox();
};

#endif