# DxlibMario
DxlibMario is a test project to verify the function of DMEngine.   
DMEngine is a 2d game engine emulated unity.   
The graphic SDK used in this engine is DXLib (https://ja.wikipedia.org/wiki/DX%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA).  
Its data structure and main loop are all based on unity design.    
You can create custom script like what you do in unity.    
It supports functions like Start, Update, CollisionEnter...etc.

This game engine supports several functions below: <br />
1. Object Hierarchy.(parent and child)
2. Physics. (RigidBody, Collider)
3. Animation (state machine, key frame...etc.)
* It's better to understand this systum by class diagram in the DMEngine project.

# Files
-bin............................the exe of DxlibMario   
-source.....................source directory   
---DMEngine..........source of DMEngine   
------Lib....................static library of DMEngine  
---DxlibMario.........source of DxlibMario  
---ThirdParty...........Dxlib include  

# How to use:
DMEngine is built as static library.  
You can find the lib file in the Lib folder inside DMEngine folder. Both Release version and Debug version(end with _d).  
To setup, you need to set the additional include and library directories in the project setting.  
There is a example project(DxlibMario). It shows the way to setting and also samples of custom script. 
