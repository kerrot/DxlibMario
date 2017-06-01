# DxlibMario
DMEngine is a 2d game engine emulated unity.  
Its data structure and main loop are all based on unity design.  
You can create custom script like what you do in unity.  
It supports functions like Start, Update, CollisionEnter...etc.

This game engine supports several functions below: <br />
1. Object Hierarchy.(set object relations: parent and child)
2. Physics. (RigidBody, Collider)
3. Animation (state machine, key frame...etc.)
* It's better to understand this systum by class diagram in the DMEngine project.

# How to use:
DMEngine is built as static library.  
You can find the lib file in the Lib folder inside DMEngine folder. Both Release version and Debug version(end with _d).  
To setup, you need to set the additional include and library directories in the project setting.  
There is a example project(DxlibMario). It shows the way to setting and sample of custom script. 
