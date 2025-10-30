# NAVIGATION
- 🏠 [Home](../../../readme.md)
- 📖 [Table of Contents](../docs_Chapter_0.00_Table_of_Contents/doc_Chapter_0.00_Table_of_Contents.md)

# CHAPTER
1.70

# TITTLE
What is a Asset File

# DESCRIPTION
A config file is used associate a loaded asset with an ID that can be used. To be associated with an entity

# HIGHLIGHTS
- Shader Asset File: A config file is used to assign Shader to an ID
- Shader Asset File: The ID will be used to associate a entity like a model or geometry with specified Shader
- Shader Asset File: File Name can be named anything
- Shader Asset File: File Type or Suffix is .config
- Model Asset File: A config file is used to assign Model to an ID
- Model Asset File: The ID will be used to associate a entity with a Model
- Model Asset File: File Name can be named anything
- Model Asset File: File Type or Suffix is .config

# BODY

- Example: Shader Asset Config File

    - SHADERID=0
    - DIRECTORYROOT=./scene/assets/shaders
    - DIRECTORY=/boundingBoxShader
    - FILENAMEVERTEX=/boundingBoxShader.vert
    - FILENAMEFRAGMENT=/boundingBoxShader.frag


- Example: Model Asset Config File
    - MODELID=0
    - DIRECTORYROOT=./scene/assets/models
    - DIRECTORY=/project_bravo_map_hangar
    - FILENAME=/project_bravo_map_hangar.obj
    - FILETYPE=obj