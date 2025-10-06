#include "graphics.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
};


Graphics::Graphics(const int windowWidth,const int windowHeight, glm::vec3 mapDimmensions)
{
    window_width = windowWidth;
    window_height = windowHeight;
    map_dimmensions = mapDimmensions;
    deltaTime = 0.0f;
    lastFrameTime = 0.0f;

};


int Graphics::initiate()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(window_width, window_height, "BRAVO", NULL, NULL);
    glfwSetWindowPos(window, 100, 50); 
    
    if (window == NULL){
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, window_width, window_height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);
    
    glClear(GL_DEPTH_BUFFER_BIT);

   
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);
    //glFrontFace(GL_CCW);

    return 1;
};

void Graphics::test()
{
    if(initiate()){
        Camera camera(window_width, window_height, glm::vec3(0.0f, 1.0f, -1.0f));
        Shader ourShader("./project/assets/shaders/modelShader.vert", "./project/assets/shaders/modelShader.frag");
        Model modelHangar("./project/assets/models/project_bravo_map_hangar/project_bravo_map_hangar.obj");
        
        float degrees = 180.0f;
        float pi = 3.14159265358979323846;

        while (!glfwWindowShouldClose(window))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glm::mat4 projection = glm::perspective(glm::radians(75.0f), (float)window_width / (float)window_height, 0.01f, 200.0f);
            glm::mat4 view = camera.getViewMatrix();
            glm::mat4 model = glm::mat4(1.0f);
            
            model = glm::translate(model, glm::vec3(0.0f));
            model = glm::scale(model, glm::vec3(1.5f));
            model = glm::rotate(model, degrees * ( pi/180) , glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));

            ourShader.activate();
            ourShader.setMat4("projection", projection);
            ourShader.setMat4("view", view);
            ourShader.setMat4("model", model);
            
            modelHangar.draw(ourShader);
        
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwTerminate();
    }
};

void Graphics::render(std::vector<GameObject*> gameobjects, glm::mat4 projection, glm::mat4 view)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //////////////////////
    // Scene
    //////////////////////

    for(int i=0; i<gameobjects.size(); i++)
    {
        if(gameobjects[i]->returnEnableRender() == true)
        {
            Shader& gameobjectShader = *gameobjects[i]->returnShader();

            glm::vec3 converted_position = gameobjects[i]->returnPosition() / map_dimmensions;
            glm::vec3 converted_scale = gameobjects[i]->returnScale() / map_dimmensions;

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, converted_position);
            model = glm::rotate(model, gameobjects[i]->returnRotation().x * ( PI/180) , glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, gameobjects[i]->returnRotation().y * ( PI/180) , glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, gameobjects[i]->returnRotation().z * ( PI/180) , glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, converted_scale);
            
            gameobjects[i]->returnShader()->activate();
            gameobjects[i]->returnShader()->setMat4("projection", projection);
            gameobjects[i]->returnShader()->setMat4("view", view);
            gameobjects[i]->returnShader()->setMat4("model", model);

            if(gameobjects[i]->returnType() == "model")
            {
                gameobjects[i]->returnModel()->draw(gameobjectShader);
            }

            if(gameobjects[i]->returnType() == "geometry")
            {
                    gameobjects[i]->returnShader()->setVec3("color", gameobjects[i]->returnColor() );
                    gameobjects[i]->returnGeometry()->draw(gameobjectShader);
            }

            if(gameobjects[i]->returnType() == "collider")
            {
                    gameobjects[i]->returnShader()->setVec3("color", gameobjects[i]->returnColor() );
                    gameobjects[i]->returnGeometry()->draw(gameobjectShader);
            }

            if(gameobjects[i]->returnEnableBoundingBox() == true)
            {
                Shader boundingBoxShader("./project/assets/shaders/boundingBoxShader.vert", "./project/assets/shaders/boundingBoxShader.frag");
                boundingBoxShader.activate();
                boundingBoxShader.setMat4("projection", projection);
                boundingBoxShader.setMat4("view", view);
                boundingBoxShader.setMat4("model", model);
                gameobjects[i]->returnModel()->drawBoundingBox();
            }

        }
    }

    //////////////////////
    // Overlay
    //////////////////////

    // Models
    for(int i=0; i<gameobjects.size(); i++)
    {
        if(gameobjects[i]->returnType() == "overlay")
        {
            if(gameobjects[i]->returnEnableRender() == true)
            {
                glClear(GL_DEPTH_BUFFER_BIT);
                Shader& fpsShader = *gameobjects[i]->returnShader();
                glm::mat4 fpsModel = glm::mat4(1.0f);
                fpsModel = glm::translate(fpsModel, gameobjects[0]->returnPosition() / map_dimmensions);
                fpsModel = glm::rotate(fpsModel, glm::radians( gameobjects[i]->returnRotation().x ) , glm::vec3(1.0f, 0.0f, 0.0f));
                fpsModel = glm::rotate(fpsModel, glm::radians( gameobjects[i]->returnRotation().y ) , glm::vec3(0.0f, 1.0f, 0.0f));
                fpsModel = glm::rotate(fpsModel, glm::radians( gameobjects[i]->returnRotation().z ) , glm::vec3(0.0f, 0.0f, 1.0f));
                fpsModel = glm::rotate(fpsModel, glm::radians( gameobjects[i]->returnRotation().y - gameobjects[0]->returnCamera()->camera_yaw ) , glm::vec3(0.0f, 1.0f, 0.0f));
                fpsModel = glm::rotate(fpsModel, glm::radians( gameobjects[i]->returnRotation().x - gameobjects[0]->returnCamera()->camera_pitch ) , glm::vec3(1.0f, 0.0f, 0.0f));
                fpsModel = glm::translate(fpsModel, glm::vec3(-7.0f, -5.0f, 20.0f) / map_dimmensions);
                fpsModel = glm::scale(fpsModel, gameobjects[i]->returnScale() / map_dimmensions);

                fpsShader.activate();
                fpsShader.setMat4("projection", projection);
                fpsShader.setMat4("view", view );
                fpsShader.setMat4("model", fpsModel);

                gameobjects[i]->returnModel()->draw(fpsShader);
            }
        }
    }

    // Textures
    if(!overlay_inititated)
    {
        
        float vertices[] = {
            // Positions                                           // Texture Coordinates
            0.0f                , float(window_height) , 0.0f,           0.0f, 1.0f,
            float(window_width) , float(window_height) , 0.0f,           1.0f, 1.0f,
            float(window_width) , 0.0f                 , 0.0f,           1.0f, 0.0f,
            0.0f                , 0.0f                 , 0.0f,           0.0f, 0.0f

        };

        unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        glGenTextures( 1, &texture);
        glBindTexture( GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_set_flip_vertically_on_load(true);

        int width, height, nrChannels;
        unsigned char* data;
        data = stbi_load("./project/assets/textures/overlay_crosshair.png", &width, &height, &nrChannels, 0);

        if(data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "ERROR::TEXTURE::Failed_TO_LOAD\n" << std::endl;
        }

        stbi_image_free(data);

        overlay_inititated = true;
    }
    else
    {
        glm::mat4 proj = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, -1.0f, 1.0f);

        Shader overlayShader("./project/assets/shaders/overlayShader.vert", "./project/assets/shaders/overlayShader.frag");
        overlayShader.activate();
        overlayShader.setMat4("projection", proj );
        overlayShader.setMat4("view",  glm::mat4(1.0f));
        overlayShader.setMat4("model", glm::mat4(1.0f));
        
        glDisable(GL_DEPTH_TEST);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glEnable(GL_DEPTH_TEST);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
    
};