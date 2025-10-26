# Project Code Name
Project Bravo

# Description
Project Bravo is a liight weight 2D and 3D Game Engine based on the Entity Component System. The Game Engine is broken into two parts, the "Game" and the "Engine". "Engine" is made up of modules and "Game" uses those modules to build a game.

# Source Code
The Source Code is broken into 2x parts "Header File(s) .h" and "Src File(s) .cpp" and are seperated into src and include directories. Its compiled with a makefile ans shipped with the neccessary libraries. To be a self containted project including everything.

# Loading Game Assets
- A Asset Config File contains a Asset's file paths and ID integer. The ID will be used so a Entity can be associated with it.
- A Entity File is used for Cameras, Models, and Geometry. It contains information such as Asset ID and a object Position, Rotation, and Scale.

# Layout
I like visualizing this project like a pyramid
    - Where App is at the Top, it the actual application for system, the actual EXE
    - Then there is Game the Middle, it the actual game area that uses engine to create to hearts content. You can afford to be a little sloppy.
    - Then there is Engine the Bottom, it's the foundation. Its made of components that can be used to build a game. This is where features are added. I see this as the level that talks to the machine/hardware.