#ifndef PROJECT_LOAD_H
#define PROJECT_LOAD_H

#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

#include "gameobject.h"
#include "shader.h"
#include "model.h"
#include "camera.h"

class ProjectLoad
{
private:
    std::string loadModelDir(std::string path_root_directory, std::string modelDir);

public:
    std::vector<Model*> loadModels();
    std::vector<std::vector<std::string>> loadGamobjects();
    std::vector<GameObject*> generateGameobjects(std::vector<std::vector<std::string>> files, std::vector<Shader*> loaded_shaders, std::vector<Model*> loaded_models, std::vector<Geometry*> loaded_geometry, Camera* camera);
};

#endif