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
        - Graphics: Handles Opengl Pipeline, Entity list is sent down and draws based on the Entit's properties
        - Network: Handles Networking for Server and Client
        - Physics: Handle anything physics related like Axis Aligned Bounding Box Collider, 3D Shooter Raycast, Rigid Body Motion, and Collisions.
        - Scene: Handles the loading of Models and Entity Scene Game Data
        - User: Handles user input interface for periphials