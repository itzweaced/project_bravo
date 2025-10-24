Model(std::string const &path, int setId)
- Description: 

void loadModel(std::string const &path)
- Description: 

void draw(Shader &shader)
- Description: 

void create_boundingBox()
- Description: 

void drawBoundingBox()
- Description: 

void processNode(aiNode *node, const aiScene *scene)
- Description: 

Mesh processMesh(aiMesh *mesh, const aiScene *scene)
- Description: 

std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
- Description: 

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma)
- Description: 

std::string returnModelPath()
- Description: 

std::vector<Vertex> returnBoundingBox()
- Description: 