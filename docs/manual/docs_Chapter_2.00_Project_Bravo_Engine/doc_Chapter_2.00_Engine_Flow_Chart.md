# NAVIGATION
- 🏠 [Home](../../../readme.md)
- 📖 [Table of Contents](../docs_Chapter_0.00_Welcome/doc_Chapter_0.10_Table_of_Contents.md)


# Note
- Best to open in a Text Editor or on Github's Code tab

# Engine Layout
  
Engine
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