#include "component_opengl_canvas.h"

ComponentOpenglCanvas::ComponentOpenglCanvas(wxWindow* parent ,  ModuleGameobjects* moduleGameobjects, ModuleProperties* moduleProperties): wxGLCanvas(parent, wxID_ANY, nullptr), context(nullptr), camera(OPENGL_WINDOW_WIDTH, OPENGL_WINDOW_HEIGHT, glm::vec3(0.0f))
{
    handleModuleGameobjects = moduleGameobjects;
    handleModuleProperties = moduleProperties;

    wxGLContextAttrs ctxAttrs;
    ctxAttrs.PlatformDefaults().CoreProfile().OGLVersion(3, 3).EndList();

    context = new wxGLContext(this);

    SetCurrent(*context);

    if (!gladLoadGL())
    {
        wxMessageBox("Failed to initialize GLAD", "Error", wxOK | wxICON_ERROR);
        delete context;
        context = nullptr;
    }

    glViewport(0, 0, OPENGL_WINDOW_WIDTH, OPENGL_WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);

    Bind( wxEVT_PAINT, &ComponentOpenglCanvas::OnPaint, this);

    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        wxLogError(wxString::Format("OpenGL error: %d", err));
    }
};


ComponentOpenglCanvas::~ComponentOpenglCanvas()
{
    for(size_t i=0; i<gameobjects.size(); i++){
        delete gameobjects[i];
    }
    for(size_t i=0; i<loaded_shaders.size(); i++){
        delete loaded_shaders[i];
    }
    for(size_t i=0; i<loaded_models.size(); i++){
        delete loaded_models[i];
    }
    delete context;
};

void ComponentOpenglCanvas::generateGameobjects(std::vector<std::vector<std::string>> files)
{
    loaded_shaders.push_back(new Shader("./workshop/assets/shaders/modelShader.vert", "./workshop/assets/shaders/modelShader.frag"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelHangar/#model#11_01_2024#project_bravo_scene_hangar#version02.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelCharacterEyeLady/#model#11_01_2024#project_bravo_character_eyelady#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelCharacterToiletMan/#model#11_01_2024#project_bravo_character_toilet_man#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelGunRifleScarH/#model#11_01_2024#weapon_machine_gun_rifle_fn_herstal_scar_h#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelGunPistolBeretta/#model#11_01_2024#weapon_pistol_beretta_92fs#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelVehicleWW2LandingCraft/#model#11_01_2024#vehicle_vehicle_ww2_us_navy_landing_craft_mechanized_lcm3#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectLightSignal/#model#11_01_2024#object_street_stoplight#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectLightStreet/#model#11_01_2024#object_street_light#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectBarrel/#model#11_01_2024#object_barrel_drum#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectShippingContainer/#model#11_01_2024#object_shipping_container#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectShippingPallet/#model#11_01_2024#object_shipping_pallet#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectFenceMetalSegmented/#model#11_01_2024#object_fence_metal_segment#version01#cooked.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelBuildingNewYork/#model#11_01_2024#structure_building_style_new_york#version01.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelBuildingGunrangeRange/blender_project_bravo_gunrange_range.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelBuildingGunrangeTarget1/blender_project_bravo_gunrange_target1.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelBuildingGunrangeTarget2/blender_project_bravo_gunrange_target2.obj"));
    loaded_models.push_back(new Model( "./workshop/assets/models/modelObjectGunRack/#model#11_01_2024#project_bravo_object_gun_rack#version01.obj"));


    for(size_t index=0; index < files.size() ; index++)
    {
        //////////////////////////////////////////////////////////////////////////
        // Temp Gameobject Variables
        //////////////////////////////////////////////////////////////////////////

        std::string type = "";
        std::string name = "";

        std::string pathVertexShader = "";
        std::string pathFragmentShader = "";
        std::string pathModel = "";

        float xPos = 0.0f;
        float yPos = 0.0f;
        float zPos = 0.0f;

        float xScale = 0.0f;
        float yScale = 0.0f;
        float zScale = 0.0f;

        float xRotation = 0.0f;
        float yRotation = 0.0f;
        float zRotation = 0.0f;

        bool enableRender = false;
        bool enableBoundingBox = false;

        //////////////////////////////////////////////////////////////////////////
        // Read File Data
        //////////////////////////////////////////////////////////////////////////

        for(size_t subIndex=0; subIndex<files[index].size(); subIndex++)
        {
            size_t pos = files[index][subIndex].find('=');

            if(pos != std::string::npos){

                std::string key = files[index][subIndex].substr(0, pos);
                std::string value = files[index][subIndex].substr(pos + 1);

                if(key=="TYPE")
                    type = value;
                if(key=="NAME")
                    name = value;

                if(type=="model"){
                    if(key=="VERTEXPATH")
                        pathVertexShader = value;
                    if(key=="FRAGMENTPATH")
                        pathFragmentShader = value;
                    if(key=="MODELPATH")
                        pathModel = value;
                }

                if(type=="camera" || type=="model"){
                    if(key=="POSITIONX")
                        xPos = std::stof(value);
                    if(key=="POSITIONY")
                        yPos = std::stof(value);
                    if(key=="POSITIONZ")
                        zPos = std::stof(value);

                    if(key=="ROTATIONX")
                        xRotation = std::stof(value);
                    if(key=="ROTATIONY")
                        yRotation = std::stof(value);
                    if(key=="ROTATIONZ")
                        zRotation = std::stof(value);
                }

                if(type=="model"){
                    if(key=="SCALEX")
                        xScale = std::stof(value);
                    if(key=="SCALEY")
                        yScale = std::stof(value);
                    if(key=="SCALEZ")
                        zScale = std::stof(value);

                    if(key=="ROTATIONX")
                        xRotation = std::stof(value);
                    if(key=="ROTATIONY")
                        yRotation = std::stof(value);
                    if(key=="ROTATIONZ")
                        zRotation = std::stof(value);

                    if(key=="ENABLERENDER")
                        enableRender = std::stoi(value);
                    if(key=="ENABLEBOUNDINGBOX")
                        enableBoundingBox = std::stoi(value);
                }
            }
        }

        //////////////////////////////////////////////////////////////////////////
        // Generata Gameobject
        //////////////////////////////////////////////////////////////////////////

        GameObject* tempGameObj = new GameObject();

        if(type=="camera")
        {
            tempGameObj->setCamera(&camera);
            tempGameObj->setName("camera");
            tempGameObj->setType("camera");
            tempGameObj->setPosition(glm::vec3( xPos, yPos, zPos));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            gameobjects.push_back(tempGameObj);
        }

        if(type=="model")
        {
            for(int subIndex=0; subIndex<loaded_shaders.size(); subIndex++)
            {
                if(pathVertexShader == loaded_shaders[subIndex]->vertex_path && pathFragmentShader == loaded_shaders[subIndex]->fragment_path)
                    tempGameObj->setShader(loaded_shaders[subIndex]);
            }

            for(int subIndex=0; subIndex<loaded_models.size(); subIndex++)
            {
                if(pathModel == loaded_models[subIndex]->modelPath)
                    tempGameObj->setModel(loaded_models[subIndex]);
            }
  
            tempGameObj->setName(type);
            tempGameObj->setType(name);
            tempGameObj->setPosition(glm::vec3(xPos, yPos, zPos));
            tempGameObj->setScale(glm::vec3(xScale, yScale, zScale));
            tempGameObj->setRotation(glm::vec3( xRotation, yRotation, zRotation));
            tempGameObj->setEnableRender(enableRender);
            tempGameObj->setEnableBoundingBox(enableBoundingBox);
            gameobjects.push_back(tempGameObj);
        }
    }
};

void ComponentOpenglCanvas::initiateGameobjects()
{
    ProjectLoad projectLoad;
    std::vector<std::vector<std::string>> files = projectLoad.load();

    generateGameobjects(files);
};

void ComponentOpenglCanvas::createComponentsGameobjectsOptions()
{
    for(size_t i=0; i<gameobjects.size(); i++){
        ComponentGameobjectsOption* tempGameobject = new ComponentGameobjectsOption( handleModuleGameobjects, i , gameobjects[i]);
        handleModuleGameobjects->boxSizer->Add(tempGameobject, 0, wxALL, 5);
        handleModuleGameobjects->boxSizer->FitInside(handleModuleGameobjects);
        handleModuleGameobjects->Layout();
        handleModuleGameobjects->Refresh();
        handleModuleGameobjects->Update();
    }
};

// #####################################################################################################
// #####################################################################################################
// MAJOR BUG!!!!!!!!!!!!
// Nothing is showig up
// Test works though
// #####################################################################################################
// #####################################################################################################

void ComponentOpenglCanvas::OnPaint(wxPaintEvent& event)
{
    if(!initiated)
    {
        initiateGameobjects();
        createComponentsGameobjectsOptions();     
        initiated = true;
    }
    render();

    //test();
};

void ComponentOpenglCanvas::render()
{
    wxPaintDC dc(this);
    SetCurrent(*context);

    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection = glm::perspective(glm::radians(camera.camera_fov), (float)OPENGL_WINDOW_WIDTH / (float)OPENGL_WINDOW_HEIGHT, 0.01f, 150.0f);
    glm::mat4 view = camera.getViewMatrix();

    for(size_t i=0; i<gameobjects.size(); i++)
    {
        if(gameobjects[i]->returnType() == "camera")
        {
            camera.camera_position = gameobjects[i]->returnPosition() / MAP_DIMMENSIONS;
        }
        if(gameobjects[i]->returnType() == "model")
        {
            glm::vec3 converted_position = gameobjects[i]->returnPosition() / MAP_DIMMENSIONS;
            glm::vec3 converted_scale = gameobjects[i]->returnScale() / MAP_DIMMENSIONS;

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
            
            Shader& gameobjectShader = *gameobjects[i]->returnShader();
            gameobjects[i]->returnModel()->draw(gameobjectShader);
        }
    }

    SwapBuffers();

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl;
    }
};

void ComponentOpenglCanvas::test()
{
    Shader modelShader("./workshop/assets/shaders/modelShader.vert", "./workshop/assets/shaders/modelShader.frag");
    Model modelHangar( "./workshop/assets/models/modelHangar/#model#11_01_2024#project_bravo_scene_hangar#version02.obj");

    wxPaintDC dc(this);
    SetCurrent(*context);

    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection = glm::perspective(glm::radians(camera.camera_fov), (float)OPENGL_WINDOW_WIDTH / (float)OPENGL_WINDOW_HEIGHT, 0.01f, 150.0f);
    glm::mat4 view = camera.getViewMatrix();

    camera.camera_position = glm::vec3(0.0f) / MAP_DIMMENSIONS;

    glm::vec3 converted_position = glm::vec3(0.0f) / MAP_DIMMENSIONS;
    glm::vec3 converted_scale = glm::vec3(250.0f) / MAP_DIMMENSIONS;

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, converted_position);
    model = glm::rotate(model, 0.0f , glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, 0.0f , glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, 0.0f , glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, converted_scale);

    modelShader.activate();
    modelShader.setMat4("projection", projection);
    modelShader.setMat4("view", view);
    modelShader.setMat4("model", model);

    modelHangar.draw(modelShader);
    modelHangar.drawBoundingBox(modelShader);

    SwapBuffers();
};