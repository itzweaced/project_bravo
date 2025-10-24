# What is a Asset Config file?
A config file is used associate a loaded asset with an ID that can be used. To be associated with an entity



# Description: Shader Asset Config File
- A config file is used to assign Shader to an ID
- The ID will be used to associate a entity like a model or geometry with specified Shader
- File Name can be named anything
- File Type or Suffix is .config

# Example: Shader Asset Config File
- SHADERID=0
- DIRECTORYROOT=./scene/assets/shaders
- DIRECTORY=/boundingBoxShader
- FILENAMEVERTEX=/boundingBoxShader.vert
- FILENAMEFRAGMENT=/boundingBoxShader.frag



# Description: Model Asset Config File 
- A config file is used to assign Model to an ID
- The ID will be used to associate a entity with a Model
- File Name can be named anything
- File Type or Suffix is .config

# Example: Model Asset Config File
- MODELID=0
- DIRECTORYROOT=./scene/assets/models
- DIRECTORY=/project_bravo_map_hangar
- FILENAME=/project_bravo_map_hangar.obj
- FILETYPE=obj