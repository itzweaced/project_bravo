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
    std::vector<Model*> loadModels();
    std::vector<Shader*> loadShaders();
};

#endif