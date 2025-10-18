#include "shader.h"

Shader::Shader( const char* vertexPath, const char* fragmentPath, int setAssetShaderId)
{
    vertex_path = vertexPath;
    fragment_path = fragmentPath;
    assetShaderId = setAssetShaderId;

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch(const std::exception& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_OPEN_SUCCESSFULLY_READ" << std::endl;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    int success;
    char infoLog[512];

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }

    shaderID = glCreateProgram();

    glAttachShader( shaderID, vertexShader);
    glAttachShader( shaderID, fragmentShader);
    glLinkProgram( shaderID );

    glGetProgramiv( shaderID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog( shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
};

void Shader::activate()
{
    glUseProgram( shaderID );
};

void Shader::setBool( const std::string &name, bool value) const
{
    glUniform1i( glGetUniformLocation( shaderID, name.c_str()), (int)value);
};

void Shader::setInt( const std::string &name, int value) const
{
    glUniform1i( glGetUniformLocation( shaderID, name.c_str()), value);
};

void Shader::setFloat( const std::string &name, float value) const
{
    glUniform1f( glGetUniformLocation( shaderID, name.c_str()), value);
};

void Shader::setMat4( const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv( glGetUniformLocation( shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
};

void Shader::setVec3( const std::string &name, const glm::vec3 &vec) const
{
    glUniform3fv( glGetUniformLocation( shaderID, name.c_str()), 1, &vec[0]);
};