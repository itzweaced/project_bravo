# NAVIGATION
- 🏠 [Home](../../../README.md)
- 📖 [Table of Contents](../docs_Chapter_0.00_Welcome/doc_Chapter_0.10_Table_of_Contents.md)


# CHAPTER
1.40


# TITTLE
Project Bravo's Source Code


# DESCRIPTION
 The Source Code is broken into 2x parts "Header File(s) .h" and "Src File(s) .cpp" and are seperated into src and include directories. Its compiled with a makefile and shipped with the neccessary libraries.

# HIGHLIGHTS
- Header Files `.h` can be found in `./source_code/include/...`
- Source Files `.cpp` can be found in `./source_code/src/...`
- 3rd Party External Libraries can be found in `./source_code/libraries/...`
- Game is where game logic is hard coded to make a game
- Engine is made up of Components that Game can use to make a game
- Source Code is compiled with a Makefile

# BODY

- Source Code Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_source_code.png "Project Bravo Screenshot")
    - Directory contains the source code to build the engine and the game
        - `./source_code/include` Contains Header files 
        - `./source_code/src` Contains Source files
        - `./source_code/libraries` Contains External Libraries

#

- Project Bravo Source Code Flow Chart
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_source_code.png "Project Bravo Screeshot")
    - Its made up of two parts 'Game' and 'Enginge'
        - Audio: Not Operational
        - Entitiy: All spawnable objects in 2D and 3D world are referred to as a Entity
            - `Entity` Defines what a Entity is and contains
            - `Camera` Spawns Camera(s)
            - `Geometry` Spawns Geometery(s) Cubes
            - `Model` Spawns Models
        - Graphics: Handles Opengl Pipeline and Data flows from Game
            - `Graphics` Main Handle for the Graphics Pipeline
            - `Mesh` Is used to draw meshes from loaded models
            - `Shader` Is used to handle Opengl Shaders
        - Network: Handles Networking for Server and Client
            - `Network Server` Handles Game Server, Work In Progress
        - Physics: Handles anything Physics Related
            - `Collider` Handles Axis Alligned Bouding Box
            - `Collision` Check for Axis Alligned Bounding Box Collsions between to two AABB colliders
            - `Raycast` 3D Raycast Collision check for shooting
            - `Rigid Body` Used to create simple Motion
        - Scene: Handles the loading of Models and Entity Scene Game Data
            - `Scene Load` Loads Entity Files
            - `Scene Save` Saves Entities to Files
            - `Config Load` Load Asset File Data
        - User: Handles user input interface for periphials
            - `Keyboard` Handles User Keyboard input
            - `Mouse` Handles User Mouse Input