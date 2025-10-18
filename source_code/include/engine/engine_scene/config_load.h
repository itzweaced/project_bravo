#ifndef CONFIG_LOAD_H
#define CONFIG_LOAD_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>

#include "gameobject.h"
#include "shader.h"
#include "model.h"
#include "camera.h"

class ConfigLoad
{
public:
    // Note to future self, instead creating the config files manually create a system where it
    // does a pre check, and if new model is detected auto genrate model_x.config file
    // not necessary now
    std::vector<Model*> loadModels()
    {
        std::vector<Model*> loaded_models;

        // 1. Load Files
        std::vector<std::vector<std::string>> files;

        for (const auto& entry : std::filesystem::directory_iterator("./scene/config/model"))
        {
            std::vector<std::string> file;
            
            std::ifstream file_read("./scene/config/model/" + entry.path().filename().string());
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
                std::cerr << "ERROR::LOADING_CONFIG" << std::endl;
            }
            files.push_back(file);
        }

        // 2. Read Files
        for(int index=0; index < files.size() ; index++)
        {
            std::string id = "";
            std::string name = "";
            std::string directoryRoot = "";
            std::string directory = "";
            std::string fileName = "";
            std::string fileType = "";


            for(int subIndex=0; subIndex<files[index].size(); subIndex++)
            {
                size_t pos = files[index][subIndex].find('=');

                if(pos != std::string::npos)
                {
                    std::string key = files[index][subIndex].substr(0, pos);
                    std::string value = files[index][subIndex].substr(pos + 1);

                    if(key=="MODELID")
                        id = value;
                    if(key=="DIRECTORYROOT")
                        directoryRoot = value;
                    if(key=="DIRECTORY")
                        directory = value;
                    if(key=="FILENAME")
                        fileName = value;
                    if(key=="FILETYPE")
                        fileType = value;
                }
            }

            // 3. Create Models
            // a> testing this first, should create models with no errors
            // b> but will need to add ID as parameter as well as create a variable inside the class to store it.
            // -_-
            loaded_models.push_back(new Model(directoryRoot + directory + fileName, std::stoi(id)));
        }

        // 4. Return Models
        return loaded_models;
    };





    std::vector<Shader*> loadShaders()
    {
        std::vector<Shader*> loaded_shaders;

        // 1. Load Files
        std::vector<std::vector<std::string>> files;

        for (const auto& entry : std::filesystem::directory_iterator("./scene/config/shaders"))
        {
            std::vector<std::string> file;
            
            std::ifstream file_read("./scene/config/shaders/" + entry.path().filename().string());
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
                std::cerr << "ERROR::LOADING_CONFIG" << std::endl;
            }
            files.push_back(file);
        }

        // 2. Read Files
        for(int index=0; index < files.size() ; index++)
        {
            std::string id = "";
            std::string name = "";

            std::string directoryRoot = "";
            std::string directory = "";

            std::string fileNameVertex = "";
            std::string fileNameFragment = "";

            for(int subIndex=0; subIndex<files[index].size(); subIndex++)
            {
                size_t pos = files[index][subIndex].find('=');

                if(pos != std::string::npos)
                {
                    std::string key = files[index][subIndex].substr(0, pos);
                    std::string value = files[index][subIndex].substr(pos + 1);

                    if(key=="SHADERID")
                        id = value;
                    if(key=="DIRECTORYROOT")
                        directoryRoot = value;
                    if(key=="DIRECTORY")
                        directory = value;
                    if(key=="FILENAMEVERTEX")
                        fileNameVertex = value;
                    if(key=="FILENAMEFRAGMENT")
                        fileNameFragment = value;
                }
            }

            // 3. Create Shaders
            // a> testing this first, should create models with no errors
            // b> but will need to add ID as parameter as well as create a variable inside the class to store it.
            // -_-
            // Shaders are not being passed down
            // Basically I migrating the old system to the new 
            // system strarting with models, which is working
            // geometry and colliders are fucked, I sort have a idea buts its a shit show
            // the geometry file
            loaded_shaders.push_back( new Shader((directoryRoot + directory + fileNameVertex).c_str(), (directoryRoot + directory + fileNameFragment).c_str(), std::stoi(id)) );
        }

        // 4. Return Models
        return loaded_shaders;
    };


};

#endif