# NAVIGATION
- 🏠 [Home](../../../README.md)
- 📖 [Table of Contents](../docs_Chapter_0.00_Welcome/doc_Chapter_0.10_Table_of_Contents.md)


# CHAPTER
1.20


# TITTLE
Project Bravo Directory Layout


# DESCRIPTION
When you clone the repo, the repo should contain everything you need and thought as the root Project directory. Inside the `./scene` is used by the engine to build a scene. The Engine's source code is inside...........`./source_code` Documents can be found ing `./doc`. And the actual program under `./bin/main.exe`

# HIGHLIGHTS
- `./bin` Directory contains Main Program
- `./docs` Directory contains Manual and File Templates
- `./scene` Directory contains Game Asset Files
- `./source_code` Directory contains the Game Engine's source code

# BODY

- Root Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory.png "Project Bravo Screenshot")
    - This is Project Bravo's root Directory and contains everything needed
        - `./bin` Directory contains Main Program`.exe` and `.dll` files
        - `./docs` Directory contains Manual and File Templates for `.asset` and `.entity` files
        - `./scene` Directory contains Game Asset Files, such as Models, Images, Audio, `.asset` file(s), `.entity` file(s)
        - `./source_code` Directory contains the Game Engine's source code
        - `./LICENSE.md` File containing Licensening Details
        - `./Makefile` File is called a Makefile and used to compile Source Code
        - `./README` File describing project
#

- Bin Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_bin.png "Project Bravo Screenshot")
    - This is where the Main Program `.exe` and `.dll` files are located, neccessary to run the game program.
        -  `./bin/main.exe` Main Program
        - `./bin/libassimp-6.dll` ASSIMP Dynamic Linked Library

#

- Docs Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_docs.png "Project Bravo Screenshot")
    - Project Bravo's User Manual, Images, and File Templates
        - `./docs/development` Project Bravo Development Tasks
        - `./docs/images` Project Bravo Images for Manual
        - `./docs/manual` Project Bravo User Manual
        - `./docs/templates` File Templates for `.asset` file(s) and `.entity` file(s) 

#

- Scene Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_scene.png "Project Bravo Screenshot")
    - Directory contains Game Asset Files. The Scene Directory and it's Sub Directory Structure is essential and which the program looks for data in during loading. 
        - `./scene/assets` Contains Model, Audio, Image file(s)
        - `./scene/config` Contains `.assets` file(s) which is used to load Models or Shaders
        - `./scene/entities` Contains `.entity` file(s) which is used to build a scene.

#

- Source Code Directory Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_source_code.png "Project Bravo Screenshot")
    - Directory contains the source code to build the engine and the game
        - `./source_code/include` Contains Header files 
        - `./source_code/src` Contains Source files
        - `./source_code/libraries` Contains External Libraries

#

- Project Bravo Source Code Layout
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_source_code.png "Project Bravo Screeshot")
    - Its made up of two parts 'Game' and 'Enginge'
        - Engine contains components that Game can use to build a Game