#include "gameobject.h"


void GameObject::setCamera(Camera* handleCamera){gameobject_camera = handleCamera;};
void GameObject::setShader(Shader* handleShader){gameobject_shader = handleShader;};
void GameObject::setModel(Model* handleModel){gameobject_model = handleModel;};
void GameObject::setGeometry(Geometry* handleGeometry){gameobject_geometry = handleGeometry;};

void GameObject::setType(std::string type){gameobject_type = type;};
void GameObject::setID(int id){gameobject_id = id;};
void GameObject::setName(std::string name){gameobject_name = name;};
void GameObject::setTag(std::string tag){gameobject_tag = tag;};
void GameObject::setPosition(glm::vec3 position){gameobject_position = position;};
void GameObject::setScale(glm::vec3 scale){gameobject_scale = scale;};
void GameObject::setRotation(glm::vec3 rotation){gameobject_rotation = rotation;};
void GameObject::setVelocity(glm::vec3 velocity){gameobject_velocity = velocity;};

void GameObject::setColor(glm::vec3 setColor){gameobject_color = setColor;};

void GameObject::setEnableRender(bool enable){enableRender = enable;};
void GameObject::setEnableBoundingBox(bool enable){enableBoundingBox = enable;};
void GameObject::setEnableCollider(bool enable){enableCollider = enable;};

///////////////////////////////////////////////////////////////////////////////////////

Camera* GameObject::returnCamera(){return gameobject_camera;};
Shader* GameObject::returnShader(){return gameobject_shader;};
Model* GameObject::returnModel(){return gameobject_model;};
Geometry* GameObject::returnGeometry(){return gameobject_geometry;};

int GameObject::returnID(){return gameobject_id;};
std::string GameObject::returnType(){return gameobject_type;};
std::string GameObject::returnName(){return gameobject_name;};
std::string GameObject::returnTag(){return gameobject_tag;};
glm::vec3 GameObject::returnPosition(){return gameobject_position;};
glm::vec3 GameObject::returnScale(){return gameobject_scale;};
glm::vec3 GameObject::returnRotation(){return gameobject_rotation;};
glm::vec3 GameObject::returnVelocity(){return gameobject_velocity;};
glm::vec3 GameObject::returnColor(){return gameobject_color;};

bool GameObject::returnEnableRender(){return enableRender;};
bool GameObject::returnEnableBoundingBox(){return enableBoundingBox;};
bool GameObject::returnEnableCollider(){return enableCollider;};