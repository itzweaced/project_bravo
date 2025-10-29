# CLASS
Model

# DESCRIPTION

# FUNCTIONS
`Model(std::string const &path, int setId)`
- Parameters:
- Description: 

`void loadModel(std::string const &path)`
- Parameters:
- Description: 

`void draw(Shader &shader)`
- Parameters:
- Description: 

`void create_boundingBox()`
- Parameters:
- Description: 

`void drawBoundingBox()`
- Parameters:
- Description: 

`void processNode(aiNode *node, const aiScene *scene)`
- Parameters:
- Description: 

`Mesh processMesh(aiMesh *mesh, const aiScene *scene)`
- Parameters:
- Description: 

`std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)`
- Parameters:
- Description: 

`unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma)`
- Parameters:
- Description: 

`std::string returnModelPath()`
- Parameters:
- Description: 

`std::vector<Vertex> returnBoundingBox()`
- Parameters:
- Description: 