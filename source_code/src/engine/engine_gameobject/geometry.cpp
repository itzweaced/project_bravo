#include "geometry.h"


Geometry::Geometry(int setAssetShaderId)
{
    assetShaderId = setAssetShaderId;
    create_cube();
};

std::vector<Vertex> Geometry::returnBoundingBox()
{
    return this->boundingBox;
};


void Geometry::create_cube()
{
    std::vector<glm::vec3> positions = 
    {
        glm::vec3( -1.0f, -1.0f,  1.0f),
        glm::vec3(  1.0f, -1.0f,  1.0f),
        glm::vec3( -1.0f, -1.0f, -1.0f),
        glm::vec3(  1.0f, -1.0f, -1.0f),

        glm::vec3( -1.0f,  1.0f,  1.0f),
        glm::vec3(  1.0f,  1.0f,  1.0f),
        glm::vec3( -1.0f,  1.0f, -1.0f),
        glm::vec3(  1.0f,  1.0f, -1.0f),
    };

    this->indices = 
    {
        0, 1, 2,
        2, 3, 1,
        4, 5, 6,
        6, 7, 5,
        0, 1, 4,
        4, 5, 1,
        2, 3, 6,
        6, 7, 3,
        0, 2, 4,
        4, 6, 2,
        1, 3, 5,
        5, 7, 3
    };

    for(int i=0; i<positions.size(); i++)
    {
        glm::vec3 vector;
        vector.x = positions[i].x;
        vector.y = positions[i].y;
        vector.z = positions[i].z;

        Vertex vertex;
        vertex.Position = vector;

        this->vertices.push_back(vertex);
    }

    create_boundingBox();
};


void Geometry::create_boundingBox()
{
for(int i=0; i<vertices.size(); i++)
    {
        if(std::isnan(x_min)){
            x_min = vertices[i].Position.x;
        }else{
            if(x_min > vertices[i].Position.x)
                x_min = vertices[i].Position.x;
        }

        if(std::isnan(x_max)){
            x_max = vertices[i].Position.x;
        }else{
            if(x_max < vertices[i].Position.x)
                x_max = vertices[i].Position.x;
        }

        if(std::isnan(y_min)){
            y_min = vertices[i].Position.y;
        }else{
            if(y_min > vertices[i].Position.y)
                y_min = vertices[i].Position.y;
        }

        if(std::isnan(y_max)){
            y_max = vertices[i].Position.y;
        }else{
            if(y_max < vertices[i].Position.y)
                y_max = vertices[i].Position.y;
        }

        if(std::isnan(z_min)){
            z_min = vertices[i].Position.z;
        }else{
            if(z_min > vertices[i].Position.z)
                z_min = vertices[i].Position.z;
        }

        if(std::isnan(z_max)){
            z_max = vertices[i].Position.z;
        }else{
            if(z_max < vertices[i].Position.z)
                z_max = vertices[i].Position.z;
        }
    }

    boundingBoxIndices = {
        0, 2, 1,
        2, 3, 1,

        4, 5, 6,
        5, 7, 6,

        0, 1, 4,
        1, 5, 4,

        2, 6, 3,
        3, 6, 7,

        0, 4, 2,
        2, 4, 6,

        1, 3, 5,
        3, 7, 5
    };

    std::vector<glm::vec3> positions = {
        //Bottom
        glm::vec3(x_min, y_min, z_max),
        glm::vec3(x_max, y_min, z_max),
        glm::vec3(x_min, y_min, z_min),
        glm::vec3(x_max, y_min, z_min),
        
        // Top
        glm::vec3(x_min, y_max, z_max),
        glm::vec3(x_max, y_max, z_max),
        glm::vec3(x_min, y_max, z_min),
        glm::vec3(x_max, y_max, z_min)
    };

    for(int i=0; i<positions.size(); i++){
        glm::vec3 vector;
        vector.x = vertices[i].Position.x;
        vector.y = vertices[i].Position.y;
        vector.z = vertices[i].Position.z;

        Vertex vertex;
        vertex.Position = vector;

        boundingBox.push_back(vertex);
    }
};


void Geometry::draw(Shader &shader)
{
    GLuint VAO, EBO, VBO;

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(Vertex),&vertices[0],GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,this->indices.size() * sizeof(unsigned int),&this->indices[0],GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);

    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
 
    glBindVertexArray(0);
};

void Geometry::drawWireFrame(Shader &shader)
{
    GLuint VAO, EBO, VBO;

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(Vertex),&vertices[0],GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,this->indices.size() * sizeof(unsigned int),&this->indices[0],GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)0);

    glBindVertexArray(VAO);
    glLineWidth(5.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  
    glBindVertexArray(0);
};

std::string Geometry::returnGeometryType(){
    return geometryType;
};

std::vector<unsigned int> Geometry::returnIndices()
{
    return indices;
};