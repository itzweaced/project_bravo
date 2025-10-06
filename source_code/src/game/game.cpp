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
    ProjectLoad projectLoad;

    // !!! THIS SHIT NEEDS TO BE MADE TO BE DYNAMIC !!!
    loaded_shaders.push_back(new Shader("./project/assets/shaders/modelShader.vert", "./project/assets/shaders/modelShader.frag"));
    loaded_shaders.push_back(new Shader("./project/assets/shaders/modelColliderShader.vert", "./project/assets/shaders/modelColliderShader.frag"));

    // !!! THIS SHIT NEEDS TO BE MADE TO BE DYNAMIC !!!
    loaded_geometry.push_back(new Geometry());
    

    // Need load any overlay textures images
    // ->

    std::vector<std::vector<std::string>> files = projectLoad.loadGamobjects();

    loaded_models = projectLoad.loadModels();
    loaded_gameobjects = projectLoad.generateGameobjects(files, loaded_shaders, loaded_models, loaded_geometry, &camera);

    // Categorizing Objects
    for(int i=0; i<loaded_gameobjects.size(); i++)
    {
        if(loaded_gameobjects[i]->returnName() == "player")
            loaded_players.push_back(loaded_gameobjects[i]);

        if(loaded_gameobjects[i]->returnType() == "camera")
            loaded_cameras.push_back(loaded_gameobjects[i]);

        if(loaded_gameobjects[i]->returnType() == "collider")
        {
            if(loaded_gameobjects[i]->returnName() == "floor")
                loaded_colliders_floors.push_back(loaded_gameobjects[i]);
            if(loaded_gameobjects[i]->returnName() == "wall")
                loaded_colliders_walls.push_back(loaded_gameobjects[i]);
            if(loaded_gameobjects[i]->returnName() == "portal")
                loaded_colliders_portals.push_back(loaded_gameobjects[i]);
            if(loaded_gameobjects[i]->returnName() == "target")
                loaded_colliders_targets.push_back(loaded_gameobjects[i]);
        }
    }

    // Colliders
    for( int i=0; i<loaded_colliders_floors.size(); i++)
        colliders_floors.push_back(new Collider(loaded_colliders_floors[i], NULL, loaded_colliders_floors[i]->returnGeometry()));
    
    for( int i=0; i<loaded_colliders_walls.size(); i++)
        colliders_walls.push_back(new Collider(loaded_colliders_walls[i], NULL, loaded_colliders_walls[i]->returnGeometry()));

    for( int i=0; i<loaded_colliders_portals.size(); i++)
        colliders_portals.push_back(new Collider(loaded_colliders_portals[i], NULL, loaded_colliders_portals[i]->returnGeometry()));

    for( int i=0; i<loaded_colliders_targets.size(); i++)
        colliders_targets.push_back(new Collider(loaded_colliders_targets[i], NULL, loaded_colliders_targets[i]->returnGeometry()));
    
    // Resetting Scene
    if(sceneReset == true)
    {
        loaded_cameras[0]->setPosition(resetCameraPosition);
        sceneReset = false;
    }
};

Game::~Game()
{
    for(int i=0; i<loaded_gameobjects.size(); i++)
        delete loaded_gameobjects[i];

    for(int i=0; i<loaded_shaders.size(); i++)
        delete loaded_shaders[i];

    for(int i=0; i<loaded_models.size(); i++)
        delete loaded_models[i];

    for(int i=0; i<colliders_floors.size(); i++)
        delete colliders_floors[i];

    for(int i=0; i<colliders_walls.size(); i++)
        delete colliders_walls[i];

    glfwTerminate();
};

void Game::play()
{
    mainloop();
};

void Game::mainloop()
{

    Collider collider_player(loaded_players[0], loaded_players[0]->returnModel(), NULL);

    RigidBody rigidBody_player(loaded_cameras[0]);

    Collision collision;
    Raycast raycast;

    bool floorCollision = false;

    PlaySound(TEXT("./project/assets/audio/stonemans_rave.wav"), NULL, SND_FILENAME | SND_ASYNC);

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

        camera.setCameraPosition(loaded_cameras[0]->returnPosition() / map_dimmensions);
        
        glm::mat4 projection = glm::perspective(glm::radians(camera.camera_fov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 150.0f);
        glm::mat4 view = camera.getViewMatrix();

        ///////////////////////////////////////
        // Logic
        ///////////////////////////////////////

        loaded_players[0]->setPosition(loaded_cameras[0]->returnPosition() + glm::vec3(0.0f, -12.5f, 0.0f));

        for(int i=0;i<colliders_floors.size(); i++)
        {
            if( collision.checkCollisionAABB( &collider_player, colliders_floors[i]) == true )
                floorCollision = true;
        }

        for(int i=0;i<colliders_portals.size(); i++)
        {
            if( collision.checkCollisionAABB( &collider_player, colliders_portals[i]) == true )
                floorCollision = false;
        }

        if(floorCollision == false)
        {
            rigidBody_player.applySimpleForce(glm::vec3(0.0f, -1.0f, 0.0f));   
        }else
        {
            floorCollision = false;
        }


        // Raycast

        for(int i=0;i<colliders_targets.size(); i++)
        {
            if(raycast.raycast_collsion(loaded_cameras[0]->returnPosition(), loaded_cameras[0]->returnCamera()->camera_front, colliders_targets[i]) == true)
            {
                loaded_colliders_targets[0]->setColor(glm::vec3(1.0f, 0.0f, 0.0f));
            }else{
                loaded_colliders_targets[0]->setColor(glm::vec3(0.0f, 1.0f, 1.0f));
            }
        }

        ///////////////////////////////////////
        // Render
        ///////////////////////////////////////
        graphics.render(loaded_gameobjects, projection, view);

    }
};


void Game::reset()
{
    resetCameraPosition = loaded_cameras[0]->returnPosition();

    for(int i=0; i<loaded_gameobjects.size(); i++)
        delete loaded_gameobjects[i];
    
    for(int i=0; i<loaded_shaders.size(); i++)
        delete loaded_shaders[i];
    
    for(int i=0; i<loaded_models.size(); i++)
        delete loaded_models[i];

    for(int i=0; i<colliders_floors.size(); i++)
        delete colliders_floors[i];
    
    for(int i=0; i<colliders_walls.size(); i++)
        delete colliders_walls[i];

    for(int i=0; i<colliders_portals.size(); i++)
        delete colliders_portals[i];
    
    loaded_gameobjects.clear();
    loaded_shaders.clear();
    loaded_models.clear();
    loaded_players.clear();
    loaded_cameras.clear();

    loaded_colliders_floors.clear();
    loaded_colliders_walls.clear();
    loaded_colliders_portals.clear();

    colliders_floors.clear();
    colliders_walls.clear();
    colliders_portals.clear();
    
    sceneReset = true;
    
    initiate();
};


void Game::processInput(GLFWwindow *window, GameObject *gameobject)
{
    const float speed = 2.0f;
    const float climbSpeed = 3.0f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        gameobject->setPosition( glm::vec3( gameobject->returnPosition().x + (speed * camera.camera_front.x), gameobject->returnPosition().y, gameobject->returnPosition().z + (speed * camera.camera_front.z) ) );
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x - (speed * camera.camera_front.x), gameobject->returnPosition().y, gameobject->returnPosition().z - (speed * camera.camera_front.z) ) );
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        gameobject->setPosition(gameobject->returnPosition() - (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        gameobject->setPosition(gameobject->returnPosition() + (speed * glm::normalize(glm::cross(camera.camera_front, camera.camera_up))) );

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x, gameobject->returnPosition().y + climbSpeed , gameobject->returnPosition().z));
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
        gameobject->setPosition(glm::vec3( gameobject->returnPosition().x, gameobject->returnPosition().y - climbSpeed , gameobject->returnPosition().z));

    if(glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS)
        reset();

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