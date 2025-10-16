#include "scene_load.h"

std::string SceneLoad::loadShaderVertexDir(std::string path_root_directory, std::string shaderDir){

    std::string shaderVertexPath;

    for (const auto& entry : std::filesystem::directory_iterator(path_root_directory + "/" + shaderDir))
    {
        if(std::filesystem::is_regular_file(entry.status())){
            std::string file = entry.path().filename().string();

            if( file.find(".vert") != std::string::npos)
            {
                shaderVertexPath = path_root_directory + "/" + shaderDir + "/" + file;
            }
        }
    }

    return shaderVertexPath;
};

std::string SceneLoad::loadShaderFragmentDir(std::string path_root_directory, std::string shaderDir){

    std::string shaderFragmentPath;

    for (const auto& entry : std::filesystem::directory_iterator(path_root_directory + "/" + shaderDir))
    {
        if(std::filesystem::is_regular_file(entry.status())){
            std::string file = entry.path().filename().string();

            if( file.find(".frag") != std::string::npos)
            {
                shaderFragmentPath = path_root_directory + "/" + shaderDir + "/" + file;
            }
        }
    }

    return shaderFragmentPath;
};

std::string SceneLoad::loadModelDir(std::string path_root_directory, std::string modelDir){

    std::string modelPath;

    for (const auto& entry : std::filesystem::directory_iterator(path_root_directory + "/" + modelDir))
    {
        if(std::filesystem::is_regular_file(entry.status())){
            std::string file = entry.path().filename().string();

            if( file.find(".obj") != std::string::npos)
            {
                modelPath = path_root_directory + "/" + modelDir + "/" + file;
            }
        }
    }

    return modelPath;
};

//

// Will need to add a loadShaders()
std::vector<Shader*> SceneLoad::loadShaders()
{
    std::vector<Shader*> loaded_shaders;
    std::string path_root_directory = "./project/assets/shaders";

    for(const auto& entry : std::filesystem::directory_iterator(path_root_directory))
    {
        if(std::filesystem::is_directory(entry.status()))
        {
            std::string shaderDir = entry.path().filename().string();
            std::string shaderVertexPath = loadShaderVertexDir( path_root_directory, shaderDir);
            std::string shaderFragmentPath = loadShaderFragmentDir( path_root_directory, shaderDir);

            //loaded_shaders.push_back(new Shader(shaderVertexPath, shaderFragmentPath));
        }
    }
    return loaded_shaders;
}
  

std::vector<Model*> SceneLoad::loadModels()
{
    std::vector<Model*> loaded_models;
    std::string path_root_directory = "./project/assets/models";

    for (const auto& entry : std::filesystem::directory_iterator(path_root_directory))
    {
        if(std::filesystem::is_directory(entry.status()))
        {
            std::string modelDir = entry.path().filename().string();
            std::string modelPath = loadModelDir( path_root_directory, modelDir);
            loaded_models.push_back(new Model(modelPath));
        }
    }
    return loaded_models;
};

std::vector<std::vector<std::string>> SceneLoad::loadGamobjects()
{
    std::vector<std::vector<std::string>> files;

    for (const auto& entry : std::filesystem::directory_iterator("./project/gameobjects"))
    {
        std::vector<std::string> file;
        
        std::ifstream file_read("./project/gameobjects/" + entry.path().filename().string());
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
            std::cerr << "ERROR::LOADING_GAMEOBJECTS" << std::endl;
        }
        files.push_back(file);
    }

    return files;
};

std::vector<GameObject*> SceneLoad::generateGameobjects(std::vector<std::vector<std::string>> files, std::vector<Shader*> loaded_shaders, std::vector<Model*> loaded_models, std::vector<Geometry*> loaded_geometry, Camera* camera)
{
    std::vector<GameObject*> gameobjects;

    for(int index=0; index < files.size() ; index++)
    {

        std::string type = "";
        std::string name = "";

        std::string pathVertexShader = "";
        std::string pathFragmentShader = "";
        std::string pathModel = "";

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
                    if(key=="VERTEXPATH")
                        pathVertexShader = value;
                    if(key=="FRAGMENTPATH")
                        pathFragmentShader = value;
                    if(key=="MODELPATH")
                        pathModel = value;

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

                if(type=="collider")
                {
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
                }

                if(type=="geometry")
                {
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
                }

                // Need to add UI type reader so I can save it
                // Ima commit here
 
                if(type=="overlay")
                {
                    if(key=="VERTEXPATH")
                        pathVertexShader = value;
                    if(key=="FRAGMENTPATH")
                        pathFragmentShader = value;
                    if(key=="MODELPATH")
                        pathModel = value;

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

        GameObject* tempGameObj = new GameObject();

        if(type=="camera")
        {
            tempGameObj->setCamera(camera);
            tempGameObj->setName(name);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            gameobjects.push_back(tempGameObj);
        }

        if(type=="model")
        {
            for(int subIndex=0; subIndex<loaded_shaders.size(); subIndex++)
            {
                if(pathVertexShader == loaded_shaders[subIndex]->vertex_path && pathFragmentShader == loaded_shaders[subIndex]->fragment_path)
                    tempGameObj->setShader(loaded_shaders[subIndex]);
            }

            for(int subIndex=0; subIndex<loaded_models.size(); subIndex++)
            {
                if(pathModel == loaded_models[subIndex]->returnModelPath())
                    tempGameObj->setModel(loaded_models[subIndex]);
            }

            tempGameObj->setName(name);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            gameobjects.push_back(tempGameObj);
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
                if(pathModel == loaded_models[subIndex]->returnModelPath())
                    tempGameObj->setModel(loaded_models[subIndex]);
            }

            tempGameObj->setName(name);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            gameobjects.push_back(tempGameObj);
        }

        if(type=="geometry")
        {
            tempGameObj->setShader(loaded_shaders[1]);
            tempGameObj->setGeometry(loaded_geometry[0]);
            tempGameObj->setName(name);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            tempGameObj->setColor( glm::vec3( colorRed, colorGreen, colorBlue) );
            gameobjects.push_back(tempGameObj);
        }

        if(type=="collider")
        {
            tempGameObj->setShader(loaded_shaders[1]);
            tempGameObj->setGeometry(loaded_geometry[0]);
            tempGameObj->setName(name);
            tempGameObj->setType(type);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            tempGameObj->setColor( glm::vec3( colorRed, colorGreen, colorBlue) );
            gameobjects.push_back(tempGameObj);
        }

    }

    return gameobjects;
};