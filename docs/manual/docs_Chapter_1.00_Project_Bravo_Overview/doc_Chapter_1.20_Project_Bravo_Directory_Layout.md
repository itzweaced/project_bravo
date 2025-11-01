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
- `./bin` Directory contains `.exe` and `.dll` files
- `./docs` Directory contains Manual and File Templates for `.asset` and `.entity` files
- `./scene` Directory contains Game Asset Files, such as Models, Images, Audio, `.asset` file(s), `.entity` file(s)
- `./source_code` Directory contains the Game Engine's source code
- `./LICENSE.md` File containing Licensening Details
- `./Makefile` File is called a Makefile and used to compile Source Code
- `./README` File describing project

# BODY

- Root Directory Layout
    - This is Project Bravo's root Directory containing everything needed.
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory.png "Project Bravo Screenshot")

#

- Bin Directory Layout
    - This is where the `.exe` and `.dll` files are located, neccessary to run the game program.
    - `./bin/main.exe` Is the Main Program, and what the Makefile and Compiler outputs once compiled
    - The Main Program can be only called when you are located in the root directory via Command Prompt or Terminal
    - ASSIMP uses `./bin/libassimp-6.dll`
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_bin.png "Project Bravo Screenshot")

#

- Docs Directory Layout
    - Project Bravo's User Manual
    - File Templates for `.asset` file(s) and `.entity` file(s) 
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_docs.png "Project Bravo Screenshot")

#

- Scene Directory Layout
    - Directory contains Game Asset Files, such as Models, Images, Audio, `.asset` file(s), `.entity` file(s)
    - The Scene Directory and it's Sub Directory Structure is essential
    - The program looks for data in this folder during loading 
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_scene.png "Project Bravo Screenshot")

#

- Source Code Directory Layout
    - Directory contains the source code to build the engine and the game
    - Header files are located in `./source_code/include`
    - Source file are located in `./source_code/src`
    - External Libraries are located in `./source_code/libraries`
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_directory_source_code.png "Project Bravo Screenshot")

#

- Project Bravo Source Code Layout
    - Its made up of two parts 'Game' and 'Enginge'
    - Engine contains components that Game can use to build a Game
    - ![Project Bravo Screenshot](../../../docs/images/project_bravo_layout_source_code.png "Project Bravo Screeshot")
