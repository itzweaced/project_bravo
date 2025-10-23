# Description: Camera Entity File
- The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale. This can be used for inital start.

# Example: Camera Entity File
- TYPE=camera
- NAME=camera
- TAG=camera
- POSITIONX=0
- POSITIONY=-145
- POSITIONZ=200
- ROTATIONX=0
- ROTATIONY=0
- ROTATIONZ=0

# Description: Model Entity File
- A Entity that uses a Model, is associated with the Shader Asset with an ID.
- A Entity that uses a Model, is associated with the Model Asset with an ID.
- The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale

# Example: Model Entity File
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

# Description: Geometry Entity File
- A Entity that uses a Model, is associated with the Shader Asset with an ID.
- The Entity file stores information on the objects X,Y,Z Position Coordinates, Rotation, and Scale
- The Entity file stores R,G,B color for the Geometry.

# Example: Geometry Entity File
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