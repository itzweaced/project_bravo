#ifndef PROJECT_SAVE_H
#define PROJECT_SAVE_H

#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

#include "gameobject.h"
#include "shader.h"
#include "model.h"

class ProjectSave
{
public:
    void save(std::vector<GameObject*> gameobjects);
};


#endif