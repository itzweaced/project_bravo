#include "game.h"


Game::Game(): graphics(WINDOW_WIDTH, WINDOW_HEIGHT, map_dimmensions), camera(WINDOW_WIDTH, WINDOW_HEIGHT, glm::vec3(0.0f)), keyboard(&graphics), mouse(&graphics, WINDOW_WIDTH, WINDOW_HEIGHT)
{
    if(graphics.initiate())
    {
        glfwSetWindowUserPointer(graphics.window, this);
        glfwSetCursorPosCallback(graphics.window, mouse.mouse_callback);
        glfwSetScrollCallback(graphics.window, mouse.scroll_callback);

        initiate();
    }
    
};

void Game::initiate()
{

    // Loading Assets
    ConfigLoad configLoad;
    loaded_models = configLoad.loadModels();
    loaded_shaders = configLoad.loadShaders();
    loaded_geometry.push_back(new Geometry(0));

    // Building Scene
    SceneLoad sceneLoad;
    std::vector<std::vector<std::string>> files = sceneLoad.loadEntities();
    loaded_entities = sceneLoad.generateEntities(files, loaded_shaders, loaded_models, loaded_geometry, &camera);
};

Game::~Game()
{
    for(int i=0; i<loaded_entities.size(); i++)
        delete loaded_entities[i];
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

        processInputKeyboard(graphics.window, loaded_entities[0]);
        processInputMouse();
        
        ///////////////////////////////////////
        // Camera
        ///////////////////////////////////////

        camera.setCameraPosition(loaded_entities[0]->returnPosition() / map_dimmensions);
        glm::mat4 projection = glm::perspective(glm::radians(camera.camera_fov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 150.0f);
        glm::mat4 view = camera.getViewMatrix();

        ///////////////////////////////////////
        // Logic
        ///////////////////////////////////////
        

        ///////////////////////////////////////
        // Render
        ///////////////////////////////////////
        graphics.render(loaded_entities, projection, view);


    }
};


void Game::processInputKeyboard(GLFWwindow *window, Entity *entity)
{
    const float speed = 2.0f;
    const float climbSpeed = 3.0f;

    if (keyboard.inputKeyboard() == 130)
        entity->setPosition( glm::vec3( entity->returnPosition().x + (speed * camera.camera_front.x), entity->returnPosition().y + (speed * camera.camera_front.y), entity->returnPosition().z + (speed * camera.camera_front.z) ) );
    if (keyboard.inputKeyboard() == 144)
        entity->setPosition(glm::vec3( entity->returnPosition().x - (speed * camera.camera_front.x), entity->returnPosition().y - (speed * camera.camera_front.y), entity->returnPosition().z - (speed * camera.camera_front.z) ) );
    if (keyboard.inputKeyboard() == 143)
        entity->setPosition(entity->returnPosition() - (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );
    if (keyboard.inputKeyboard() == 145)
        entity->setPosition(entity->returnPosition() + (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );
    if (keyboard.inputKeyboard() == 169)
        entity->setPosition(glm::vec3( entity->returnPosition().x, entity->returnPosition().y + climbSpeed , entity->returnPosition().z));
    if (keyboard.inputKeyboard() == 167)
        entity->setPosition(glm::vec3( entity->returnPosition().x, entity->returnPosition().y - climbSpeed , entity->returnPosition().z));
    if (keyboard.inputKeyboard() == 101)
        glfwSetWindowShouldClose(window, true);

};

void Game::processInputMouse()
{
    if(Mouse::cursor_active)
    {
        camera.processMouseInput(Mouse::cursor_xPos, Mouse::cursor_yPos);
        Mouse::cursor_active = false;
    }
    if(Mouse::scroll_active)
    {
        camera.processMouseScroll(float(Mouse::scroll_yPos));
        Mouse::scroll_active = false;
    }
}