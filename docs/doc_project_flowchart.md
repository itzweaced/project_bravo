# Note
- Best to open in a Text Editor or on Github's Code tab

# Project Layout

source_code
|
|
|
|
|------> include --- Note: Contains Header Files
|         |
|         |
|         |
|        App
|        |
|        |
|        |
|        |------> Game
|                    |
|                    |
|                    |       
|                    |------> Engine
|                                |
|                                |
|                                |------> Audio --- Note: Audio Pipeline
|                                |------> Entity --- Note: Everything in the engine is consider a entity
|                                |          |
|                                |          |
|                                |          |------> Entity
|                                |          |------> Camera
|                                |          |------> Geometry
|                                |          |------> Model
|                                |          
|                                |------> Graphics --- Note: Handle rendering pipeline for OpenGL
|                                |          |
|                                |          |
|                                |          |------> Opengl
|                                |                      |
|                                |                      |
|                                |                      |------> Graphics
|                                |                      |------> Mesh
|                                |                      |------> Shader
|                                |
|                                |------> Network --- Note: Network Handeling for Server and Client Status
|                                |          |
|                                |          |
|                                |          |------> Netowrk Server
|                                |
|                                |------> Physics --- Note: Controls anythings related to Physics and Collisions
|                                |          |
|                                |          |
|                                |          |------> Collider
|                                |          |------> Collision
|                                |          |------> Raycast
|                                |          |------> Rigid Body
|                                |
|                                |------> Scene --- Note: Asset Loading and Scene Entity Loading
|                                |          |
|                                |          |
|                                |          |------> Scene Load
|                                |          |------> Scene Save
|                                |          |------> Config Load
|                                |
|                                |------> User --- Note: User Device Interfaces
|                                           |
|                                           |
|                                           |------> Keyboard
|                                           |------> Mouse
|
|
|
|------> src --- Note: Contains cpp files
          |
          |
          |
         App
         |
         |
         |
         |------> Game
                     |
                     |
                     |       
                     |------> Engine
                                 |
                                 |
                                 |------> Audio --- Note: Audio Pipeline
                                 |------> Entity --- Note: Everything in the engine is consider a entity
                                 |          |
                                 |          |
                                 |          |------> Entity
                                 |          |------> Camera
                                 |          |------> Geometry
                                 |          |------> Model
                                 |          
                                 |------> Graphics --- Note: Handle rendering pipeline for OpenGL
                                 |          |
                                 |          |
                                 |          |------> Opengl
                                 |                      |
                                 |                      |
                                 |                      |------> Graphics
                                 |                      |------> Mesh
                                 |                      |------> Shader
                                 |
                                 |------> Network --- Note: Network Handeling for Server and Client Status
                                 |          |
                                 |          |
                                 |          |------> Netowrk Server
                                 |
                                 |------> Physics --- Note: Controls anythings related to Physics and Collisions
                                 |          |
                                 |          |
                                 |          |------> Collider
                                 |          |------> Collision
                                 |          |------> Raycast
                                 |          |------> Rigid Body
                                 |
                                 |------> Scene --- Note: Asset Loading and Scene Entity Loading
                                 |          |
                                 |          |
                                 |          |------> Scene Load
                                 |          |------> Scene Save
                                 |          |------> Config Load
                                 |
                                 |------> User --- Note: User Device Interfaces
                                            |
                                            |
                                            |------> Keyboard
                                            |------> Mouse