# NAVIGATION
- 🏠 [Home](../../../readme.md)
- 📖 [Table of Contents](../docs_Chapter_0.00_Table_of_Contents/doc_Chapter_0.00_Table_of_Contents.md)

# CHAPTER
1.80


# TITTLE
What is a Entity File?


# DESCRIPTION


# HIGHLIGHTS
- Camera Entity File: The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale. This can be used for inital start.
- Model Entity File: A Entity that uses a Model, is associated with the Shader Asset using an ID, called `SHADERID`.
- Model Entity File: A Entity that uses a Model, is associated with the Model Asset using an ID, called `MODELID`.
- Model Entity File: The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale
- Geometry Entity File: A Entity that uses a Model, is associated with the Shader Asset with an ID.
- Geometry Entity File: The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale
- Geometry Entity File: The Entity file stores R,G,B color for the Geometry.


# BODY

- Example: Camera Entity File
    - TYPE=camera
    - NAME=camera
    - TAG=camera
    - POSITIONX=0
    - POSITIONY=-145
    - POSITIONZ=200
    - ROTATIONX=0
    - ROTATIONY=0
    - ROTATIONZ=0

- Example: Model Entity File
    - TYPE=model
    - NAME=N/A
    - TAG=hangar
    - SHADERID=3
    - MODELID=0
    - POSITIONX=0
    - POSITIONY=0
    - POSITIONZ=0
    - SCALEX=250
    - SCALEY=250
    - SCALEZ=250
    - ROTATIONX=0
    - ROTATIONY=0
    - ROTATIONZ=0
    - ENABLERENDER=1
    - ENABLEBOUNDINGBOX=0


- Example: Geometry Entity File
    - TYPE=geometry
    - NAME=N/A
    - TAG=hangar
    - SHADERID=2
    - GEOMETRYTYPE=cube
    - GEOMETRYCOLORRED=0
    - GEOMETRYCOLORGREEN=1
    - GEOMETRYCOLORBLUE=0
    - POSITIONX=0
    - POSITIONY=-163.5
    - POSITIONZ=0
    - SCALEX=740
    - SCALEY=2.5
    - SCALEZ=740
    - ROTATIONX=0
    - ROTATIONY=0
    - ROTATIONZ=0
    - ENABLERENDER=1
    - ENABLEBOUNDINGBOX=0
    - ENABLECOLLIDER=1