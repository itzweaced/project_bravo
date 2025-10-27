# NAVIGATION
- [Table of Contents](..\Table_of_Contents.md)

# CHAPTER
1.40


# TITLE
Project Bravo, How it Works?


# DESCRIPTION



# HIGHLIGHTS
- A Asset Config File contains a Asset's file paths and ID integer. The ID will be used so a Entity can be associated with it.
- A Entity File is used for Cameras, Models, and Geometry. It contains information such as Asset ID and a object Position, Rotation, and Scale.


# BODY
- I like visualizing this project like a pyramid
    - Where App is at the Top, it the actual application for system
    - Then there is Game the Middle, it the actual game area that uses engine to create to hearts content. You can afford to be a little sloppy.
    - Then there is Engine the Bottom, it's the foundation. Its made of components that can be used to build a game. This is where features are added. I see this as the level that talks to the machine/hardware.