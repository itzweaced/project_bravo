#include "game.h"


Game::Game(): graphics(WINDOW_WIDTH, WINDOW_HEIGHT, map_dimmensions), camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(0.0f))
{
    if(graphics.initiate())
    {
        glfwSetWindowUserPointer(graphics.window, this);
        glfwSetCursorPosCallback(graphics.window, mouse_callback);
        glfwSetScrollCallback(graphics.window, scroll_callback);

        initiate();
    }
};

void Game::initiate()
{
    ConfigLoad configLoad;
    loaded_models = configLoad.loadModels();
    loaded_shaders = configLoad.loadShaders();
    loaded_geometry.push_back(new Geometry(0));


    SceneLoad sceneLoad;
    std::vector<std::vector<std::string>> files = sceneLoad.loadGamobjects();
    loaded_gameobjects = sceneLoad.generateGameobjects(files, loaded_shaders, loaded_models, loaded_geometry, &camera);

    SceneSave sceneSave;
    sceneSave.save(loaded_gameobjects);
};

Game::~Game()
{
    for(int i=0; i<loaded_gameobjects.size(); i++)
        delete loaded_gameobjects[i];
    glfwTerminate();
};

void Game::play()
{
    mainloop();
};

void Game::mainloop()
{
    while (!glfwWindowShouldClose(graphics.window))
    {
        ///////////////////////////////////////
        // Frame Speed
        ///////////////////////////////////////
        
        float currentFrameTime = glfwGetTime();
        graphics.deltaTime = currentFrameTime - graphics.lastFrameTime;
        graphics.lastFrameTime = currentFrameTime;


        ///////////////////////////////////////
        // Input
        ///////////////////////////////////////
        processInput(graphics.window, loaded_gameobjects[0]);

        ///////////////////////////////////////
        // Camera
        ///////////////////////////////////////

        camera.setCameraPosition(loaded_gameobjects[0]->returnPosition() / map_dimmensions);
        glm::mat4 projection = glm::perspective(glm::radians(camera.camera_fov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 150.0f);
        glm::mat4 view = camera.getViewMatrix();

        ///////////////////////////////////////
        // Logic
        ///////////////////////////////////////



        ///////////////////////////////////////
        // Render
        ///////////////////////////////////////
        graphics.render(loaded_gameobjects, projection, view);

    }
};

void Game::processInput(GLFWwindow *window, GameObject *gameobject)
{
    const float speed = 2.0f;
    const float climbSpeed = 3.0f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        gameobject->setPosition( glm::vec3( gameobject->returnPosition().x + (speed * camera.camera_front.x), gameobject->returnPosition().y + (speed * camera.camera_front.y), gameobject->returnPosition().z + (speed * camera.camera_front.z) ) );
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x - (speed * camera.camera_front.x), gameobject->returnPosition().y - (speed * camera.camera_front.y), gameobject->returnPosition().z - (speed * camera.camera_front.z) ) );
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        gameobject->setPosition(gameobject->returnPosition() - (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        gameobject->setPosition(gameobject->returnPosition() + (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x, gameobject->returnPosition().y + climbSpeed , gameobject->returnPosition().z));
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x, gameobject->returnPosition().y - climbSpeed , gameobject->returnPosition().z));

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
};


void Game::mouse_callback(GLFWwindow *window, double xPos, double yPos)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    
    if(game->mouseLeftClick)
    {
        game->lastX = xPos;
        game->lastY = yPos;
        game->mouseLeftClick = false;
    }

    float xoffset = xPos - game->lastX;
    float yoffset = game->lastY - yPos;

    game->lastX = xPos;
    game->lastY = yPos;
    game->camera.processMouseInput(xoffset, yoffset);
};

void Game::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    Game* game = static_cast<Game*>(glfwGetWindowUserPointer(window));
    game->camera.processMouseScroll(float(yoffset));
};