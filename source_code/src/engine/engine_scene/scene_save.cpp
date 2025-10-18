#include "scene_save.h"

void SceneSave::save(std::vector<GameObject*> gameobjects)
{
    for(int i=0; i<gameobjects.size(); i++)
    {
        std::string path = "./scene/temp_gameobjects/";
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
                
                file_write << "SHADERID=3" << std::endl;
                file_write << "MODELID=" << gameobjects[i]->returnModel()->id << std::endl;

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

                file_write << "SHADERID=2" << std::endl;

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

            file_write.close();
        }
        else
        {
            std::cerr << "ERROR::SAVING_GAMEOBJECTS" << std::endl;
        }
    }
};
