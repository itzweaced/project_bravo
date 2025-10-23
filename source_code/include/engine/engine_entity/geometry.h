#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glad/glad.h> 
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>

#include "shader.h"
#include "mesh.h"

class Geometry
{
private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    std::string geometryType = "cube";

private:
    std::vector<Vertex> boundingBox;
    std::vector<unsigned int> boundingBoxIndices;

    float x_min;
    float x_max;
    float y_min;
    float y_max;
    float z_min;
    float z_max;

private:
    void create_boundingBox();
    void create_cube();

public:
    int assetShaderId;

    Geometry(int setAssetShaderId);
    std::vector<Vertex> returnBoundingBox();
    void draw(Shader &shader);
    void drawWireFrame(Shader &shader);
    
    std::string returnGeometryType();
    std::vector<unsigned int> returnIndices();

    
};

#endif