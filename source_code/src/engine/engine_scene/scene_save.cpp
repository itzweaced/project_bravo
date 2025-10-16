#include "scene_save.h"


// Thinking on how to setup a area here to modify gameobject files

// I have to make sure everything is the way I want it, once I push play it will overwrite the old files.
// Better to take your time, think problems through. At least for idiots like myself XD
// Now Overlay, This basically rendering the fps camera gun and UI that you would find in games HUD
// This part I need to think though because its 2D system part of things 
// I want to apply the same principals like having a gameobject being either a 3D object or 2D object in the overlay
// Again not rushing , real time sitting on me ass and thinking XD
// Worst case scenario I just resave the file as is, but I want a system to reflect that game object can play in the overlay world and 3D world
// But I want to differiant from a image or model, currently using the 3D model
// And a janky texture overlay
// RAMBLES XD....
// Should I make a ID system for Assets
// Each Model and Shader has/will have there own directory
// So if you look at file path for shaders and models 
// I am not specifying the last part
// I am thinking it should not be unique
// Then again models doesnt use it and it works normally
// More thinking....
// XD

void SceneSave::save(std::vector<GameObject*> gameobjects)
{
    for(int i=0; i<gameobjects.size(); i++)
    {
        std::string path = "./project/temp_gameobjects/";
        std::string filename = "object_" + std::to_string(i) + ".gameobject";
        std::ofstream file_write(path + filename);

        if(file_write.is_open())
        {
            if(gameobjects[i]->returnType() == "camera")
            {
                file_write << "TYPE=" << gameobjects[i]->returnType() << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;
            }

            if(gameobjects[i]->returnType() == "model")
            {
                file_write << "TYPE=" << gameobjects[i]->returnType() << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "VERTEXPATH=./project/assets/shaders/" << std::endl;
                file_write << "VERTEXFILENAME=" << gameobjects[i]->returnShader()->vertex_path << std::endl;
                file_write << "FRAGMENTPATH=./project/assets/shaders/" << std::endl;
                file_write << "FRAGMENTFILENAME=" << gameobjects[i]->returnShader()->fragment_path << std::endl;

                file_write << "MODELPATH=./project/assets/models/" << std::endl;
                file_write << "MODELFILENAME=" << gameobjects[i]->returnModel()->returnModelPath() << std::endl;

                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "SCALEX=" << gameobjects[i]->returnScale().x << std::endl;
                file_write << "SCALEY=" << gameobjects[i]->returnScale().y << std::endl;
                file_write << "SCALEZ=" << gameobjects[i]->returnScale().z << std::endl;
                
                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;

                file_write << "ENABLERENDER=" << gameobjects[i]->returnEnableRender() << std::endl;
                file_write << "ENABLEBOUNDINGBOX=" << gameobjects[i]->returnEnableBoundingBox() << std::endl;
            }

            if(gameobjects[i]->returnType() == "geometry")
            {
                file_write << "TYPE=" << gameobjects[i]->returnType() << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "VERTEXPATH=./project/assets/shaders/" << std::endl;
                file_write << "VERTEXFILENAME=" << gameobjects[i]->returnShader()->vertex_path << std::endl;
                file_write << "FRAGMENTPATH=./project/assets/shaders/" << std::endl;
                file_write << "FRAGMENTFILENAME=" << gameobjects[i]->returnShader()->fragment_path << std::endl;

                file_write << "GEOMETRYTYPE=" << gameobjects[i]->returnGeometry()->returnGeometryType() << std::endl;
                file_write << "GEOMETRYCOLORRED=" << gameobjects[i]->returnColor().x << std::endl;
                file_write << "GEOMETRYCOLORGREEN=" << gameobjects[i]->returnColor().y << std::endl;
                file_write << "GEOMETRYCOLORBLUE=" << gameobjects[i]->returnColor().z << std::endl;
                
                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "SCALEX=" << gameobjects[i]->returnScale().x << std::endl;
                file_write << "SCALEY=" << gameobjects[i]->returnScale().y << std::endl;
                file_write << "SCALEZ=" << gameobjects[i]->returnScale().z << std::endl;

                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;

                file_write << "ENABLERENDER=" << gameobjects[i]->returnEnableRender() << std::endl;
                file_write << "ENABLEBOUNDINGBOX=" << gameobjects[i]->returnEnableBoundingBox() << std::endl;
                file_write << "ENABLECOLLIDER=0" << std::endl;
            }
            // How can I efficently break path into components easily
            // Again for if directory path is ever changed
            // Thinking about implementing a numeric id system instead using paths
            // Also lazy to really tear this apart. I need coffee XD
            // Its looking like ima have to do this manual, 
            // Lesson here start small ass shit, I mean small as shit
            // I would say No Pain No Gain , but it didnt work out well for Mark XD forgot who was the other mofo
            if(gameobjects[i]->returnType() == "collider")
            {
                file_write << "TYPE=geometry" << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "VERTEXPATH=./project/assets/shaders/" << std::endl;
                file_write << "VERTEXFILENAME=" << gameobjects[i]->returnShader()->vertex_path << std::endl;
                file_write << "FRAGMENTPATH=./project/assets/shaders/" << std::endl;
                file_write << "FRAGMENTFILENAME=" << gameobjects[i]->returnShader()->fragment_path << std::endl;

                file_write << "GEOMETRYTYPE=" << gameobjects[i]->returnGeometry()->returnGeometryType() << std::endl;
                file_write << "GEOMETRYCOLORRED=" << gameobjects[i]->returnColor().x << std::endl;
                file_write << "GEOMETRYCOLORGREEN=" << gameobjects[i]->returnColor().y << std::endl;
                file_write << "GEOMETRYCOLORBLUE=" << gameobjects[i]->returnColor().z << std::endl;
                
                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "SCALEX=" << gameobjects[i]->returnScale().x << std::endl;
                file_write << "SCALEY=" << gameobjects[i]->returnScale().y << std::endl;
                file_write << "SCALEZ=" << gameobjects[i]->returnScale().z << std::endl;
                
                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;

                file_write << "ENABLERENDER=" << gameobjects[i]->returnEnableRender() << std::endl;
                file_write << "ENABLEBOUNDINGBOX=" << gameobjects[i]->returnEnableBoundingBox() << std::endl;
                file_write << "ENABLECOLLIDER=1" << std::endl;
            }

            if(gameobjects[i]->returnType() == "overlay")
            {
                file_write << "TYPE=" << gameobjects[i]->returnType() << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "OVERLAYTYPE=model" << std::endl;

                file_write << "VERTEXPATH=./project/assets/shaders/"  << std::endl;
                file_write << "VERTEXFILENAME=" << gameobjects[i]->returnShader()->vertex_path << std::endl;
                file_write << "FRAGMENTPATH=./project/assets/shaders/" << std::endl;
                file_write << "FRAGMENTFILENAME=" << gameobjects[i]->returnShader()->fragment_path << std::endl;

                file_write << "MODELPATH=./project/assets/models/" << std::endl;
                file_write << "MODELFILENAME=" << gameobjects[i]->returnModel()->returnModelPath() << std::endl;

                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "SCALEX=" << gameobjects[i]->returnScale().x << std::endl;
                file_write << "SCALEY=" << gameobjects[i]->returnScale().y << std::endl;
                file_write << "SCALEZ=" << gameobjects[i]->returnScale().z << std::endl;
                
                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;

                file_write << "ENABLERENDER=" << gameobjects[i]->returnEnableRender() << std::endl;
                file_write << "ENABLEBOUNDINGBOX=" << gameobjects[i]->returnEnableBoundingBox() << std::endl;
            }

            if(gameobjects[i]->returnType() == "ui")
            {
                file_write << "TYPE=overlay" << std::endl;
                file_write << "TAG=" << gameobjects[i]->returnName() << std::endl;

                file_write << "OVERLAYTYPE=image" << std::endl;

                file_write << "VERTEXPATH=./project/assets/shaders/"  << std::endl;
                file_write << "VERTEXFILENAME=" << gameobjects[i]->returnShader()->vertex_path << std::endl;
                file_write << "FRAGMENTPATH=./project/assets/shaders/" << std::endl;
                file_write << "FRAGMENTFILENAME=" << gameobjects[i]->returnShader()->fragment_path << std::endl;

                file_write << "MODELPATH=./project/assets/models/" << std::endl;
                file_write << "MODELFILENAME=" << gameobjects[i]->returnModel()->returnModelPath() << std::endl;

                file_write << "POSITIONX=" << gameobjects[i]->returnPosition().x << std::endl;
                file_write << "POSITIONY=" << gameobjects[i]->returnPosition().y << std::endl;
                file_write << "POSITIONZ=" << gameobjects[i]->returnPosition().z << std::endl;

                file_write << "SCALEX=" << gameobjects[i]->returnScale().x << std::endl;
                file_write << "SCALEY=" << gameobjects[i]->returnScale().y << std::endl;
                file_write << "SCALEZ=" << gameobjects[i]->returnScale().z << std::endl;
                
                file_write << "ROTATIONX=" << gameobjects[i]->returnRotation().x << std::endl;
                file_write << "ROTATIONY=" << gameobjects[i]->returnRotation().y << std::endl;
                file_write << "ROTATIONZ=" << gameobjects[i]->returnRotation().z << std::endl;

                file_write << "ENABLERENDER=" << gameobjects[i]->returnEnableRender() << std::endl;
                file_write << "ENABLEBOUNDINGBOX=" << gameobjects[i]->returnEnableBoundingBox() << std::endl;
            }

            file_write.close();
        }
        else
        {
            std::cerr << "ERROR::SAVING_GAMEOBJECTS" << std::endl;
        }
    }
};
