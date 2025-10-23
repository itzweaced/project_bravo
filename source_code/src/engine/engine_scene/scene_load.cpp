#include "scene_load.h"

std::vector<std::vector<std::string>> SceneLoad::loadEntities()
{
    std::vector<std::vector<std::string>> files;

    for (const auto& entry : std::filesystem::directory_iterator("./scene/entities"))
    {
        std::vector<std::string> file;
        
        std::ifstream file_read("./scene/entities/" + entry.path().filename().string());
        if(file_read.is_open())
        {
            std::string line;
            while(getline(file_read, line)){
                file.push_back(line);
            }
            file_read.close();
        }
        else
        {
            std::cerr << "ERROR::LOADING_Entity" << std::endl;
        }
        files.push_back(file);
    }

    return files;
};

std::vector<Entity*> SceneLoad::generateEntities(std::vector<std::vector<std::string>> files, std::vector<Shader*> loaded_shaders, std::vector<Model*> loaded_models, std::vector<Geometry*> loaded_geometry, Camera* camera)
{
    std::vector<Entity*> entities;

    for(int index=0; index < files.size() ; index++)
    {

        std::string type = "";
        std::string name = "";
        std::string tag = "";

        std::string pathVertexShader = "";
        std::string pathFragmentShader = "";

        int shader_id = 0;
        int model_id = 0;

        std::string pathImage = "";

        std::string geometryType = "";
        
        float colorRed = 0.0f;
        float colorGreen = 0.0f;
        float colorBlue = 0.0f;

        float xPos = 0.0f;
        float yPos = 0.0f;
        float zPos = 0.0f;

        float xScale = 0.0f;
        float yScale = 0.0f;
        float zScale = 0.0f;

        float xRotation = 0.0f;
        float yRotation = 0.0f;
        float zRotation = 0.0f;

        bool enableRender = false;
        bool enableBoundingBox = false;
        bool enableCollider = false;

        for(int subIndex=0; subIndex<files[index].size(); subIndex++)
        {
            size_t pos = files[index][subIndex].find('=');

            if(pos != std::string::npos)
            {
                std::string key = files[index][subIndex].substr(0, pos);
                std::string value = files[index][subIndex].substr(pos + 1);

                if(key=="TYPE")
                    type = value;
                if(key=="NAME")
                    name = value;
                if(key=="TAG")
                    tag = value;

                if(type=="camera")
                {
                    if(key=="POSITIONX")
                        xPos = std::stof(value);
                    if(key=="POSITIONY")
                        yPos = std::stof(value);
                    if(key=="POSITIONZ")
                        zPos = std::stof(value);
                }
                
                if(type=="model")
                {
                    if(key=="SHADERID")
                        shader_id = std::stoi(value);
                    if(key=="MODELID")
                        model_id = std::stoi(value);

                    if(key=="POSITIONX")
                        xPos = std::stof(value);
                    if(key=="POSITIONY")
                        yPos = std::stof(value);
                    if(key=="POSITIONZ")
                        zPos = std::stof(value);

                    if(key=="SCALEX")
                        xScale = std::stof(value);
                    if(key=="SCALEY")
                        yScale = std::stof(value);
                    if(key=="SCALEZ")
                        zScale = std::stof(value);

                    if(key=="ROTATIONX")
                        xRotation = std::stof(value);
                    if(key=="ROTATIONY")
                        yRotation = std::stof(value);
                    if(key=="ROTATIONZ")
                        zRotation = std::stof(value);

                    if(key=="ENABLERENDER")
                        enableRender = std::stoi(value);
                    if(key=="ENABLEBOUNDINGBOX")
                        enableBoundingBox = std::stoi(value);
                }

                if(type=="geometry")
                {
                    if(key=="SHADERID")
                        shader_id = std::stoi(value);
                    if(key=="MODELID")
                        model_id = std::stoi(value);

                    if(key=="POSITIONX")
                        xPos = std::stof(value);
                    if(key=="POSITIONY")
                        yPos = std::stof(value);
                    if(key=="POSITIONZ")
                        zPos = std::stof(value);

                    if(key=="GEOMETRYTYPE")
                        geometryType = value;
                    if(key=="GEOMETRYCOLORRED")
                        colorRed = std::stof(value);
                    if(key=="GEOMETRYCOLORGREEN")
                        colorGreen = std::stof(value);
                    if(key=="GEOMETRYCOLORBLUE")
                        colorBlue = std::stof(value);

                    if(key=="SCALEX")
                        xScale = std::stof(value);
                    if(key=="SCALEY")
                        yScale = std::stof(value);
                    if(key=="SCALEZ")
                        zScale = std::stof(value);

                    if(key=="ROTATIONX")
                        xRotation = std::stof(value);
                    if(key=="ROTATIONY")
                        yRotation = std::stof(value);
                    if(key=="ROTATIONZ")
                        zRotation = std::stof(value);

                    if(key=="ENABLERENDER")
                        enableRender = std::stoi(value);
                    if(key=="ENABLEBOUNDINGBOX")
                        enableBoundingBox = std::stoi(value);
                    if(key=="ENABLECOLLIDER")
                        enableCollider = std::stoi(value);
                }

                if(type=="overlay")
                {
                    if(key=="VERTEXPATH")
                        pathVertexShader = value;
                    if(key=="FRAGMENTPATH")
                        pathFragmentShader = value;
                    if(key=="MODELID")
                        model_id = std::stoi(value);

                    if(key=="POSITIONX")
                        xPos = std::stof(value);
                    if(key=="POSITIONY")
                        yPos = std::stof(value);
                    if(key=="POSITIONZ")
                        zPos = std::stof(value);

                    if(key=="SCALEX")
                        xScale = std::stof(value);
                    if(key=="SCALEY")
                        yScale = std::stof(value);
                    if(key=="SCALEZ")
                        zScale = std::stof(value);

                    if(key=="ROTATIONX")
                        xRotation = std::stof(value);
                    if(key=="ROTATIONY")
                        yRotation = std::stof(value);
                    if(key=="ROTATIONZ")
                        zRotation = std::stof(value);

                    if(key=="ENABLERENDER")
                        enableRender = std::stoi(value);
                    if(key=="ENABLEBOUNDINGBOX")
                        enableBoundingBox = std::stoi(value);
                }
                
            }
        }

        Entity* tempGameObj = new Entity();

        if(type=="camera")
        {
            tempGameObj->setCamera(camera);
            tempGameObj->setName(name);
            tempGameObj->setTag(tag);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            entities.push_back(tempGameObj);
        }

        if(type=="model")
        {
            for(int subIndex=0; subIndex<loaded_shaders.size(); subIndex++)
            {
                if(shader_id == loaded_shaders[subIndex]->assetShaderId)
                    tempGameObj->setShader(loaded_shaders[subIndex]);
            }

            for(int subIndex=0; subIndex<loaded_models.size(); subIndex++)
            {
                if(model_id == loaded_models[subIndex]->id)
                    tempGameObj->setModel(loaded_models[subIndex]);

            }

            tempGameObj->setName(name);
            tempGameObj->setTag(tag);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            entities.push_back(tempGameObj);
        }

        if(type=="overlay")
        {
            for(int subIndex=0; subIndex<loaded_shaders.size(); subIndex++)
            {
                if(pathVertexShader == loaded_shaders[subIndex]->vertex_path && pathFragmentShader == loaded_shaders[subIndex]->fragment_path)
                    tempGameObj->setShader(loaded_shaders[subIndex]);
            }

            for(int subIndex=0; subIndex<loaded_models.size(); subIndex++)
            {
                if(model_id == loaded_models[subIndex]->id)
                    tempGameObj->setModel(loaded_models[subIndex]);
            }

            tempGameObj->setName(name);
            tempGameObj->setTag(tag);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            entities.push_back(tempGameObj);
        }

        if(type=="geometry")
        {
            for(int subIndex=0; subIndex<loaded_shaders.size(); subIndex++)
            {
                if(shader_id == loaded_shaders[subIndex]->assetShaderId)
                    tempGameObj->setShader(loaded_shaders[subIndex]);
            }

            tempGameObj->setGeometry(loaded_geometry[0]);
            tempGameObj->setName(name);
            tempGameObj->setTag(tag);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            tempGameObj->setEnableCollider(enableCollider);
            tempGameObj->setColor( glm::vec3( colorRed, colorGreen, colorBlue) );
            entities.push_back(tempGameObj);
        }

    }

    return entities;
};