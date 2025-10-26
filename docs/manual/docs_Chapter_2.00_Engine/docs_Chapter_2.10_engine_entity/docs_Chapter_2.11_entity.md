`void setShader(Shader* handleShader);`
`void setModel(Model* handleModel);`
`void setGeometry(Geometry* handleGeometry);`

`void setID(int id);`
`void setType(std::string type);`
`void setName(std::string name);`
`void setTag(std::string tag);`
`void setPosition(glm::vec3 position);`
`void setScale(glm::vec3 scale);`
`void setRotation(glm::vec3 rotation);`
`void setVelocity(glm::vec3 velocity);`
`void setColor(glm::vec3 setColor);`

`void setEnableRender(bool enable);`
`void setEnableBoundingBox(bool enable);`
`void setEnableCollider(bool enable);`

`int returnID();`
`std::string returnType();`
`std::string returnName();`
`std::string returnTag();`
`glm::vec3 returnPosition();`
`glm::vec3 returnScale();`
`glm::vec3 returnRotation();`
`glm::vec3 returnVelocity();`
`glm::vec3 returnColor();`

`bool returnEnableRender();`
`bool returnEnableBoundingBox();`
`bool returnEnableCollider();`