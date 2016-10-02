#include "CameraControl.h"
#include "Input.h"
#include "GameObject.h"

CameraControl::CameraControl(GameObjectPtr obj) 
: Behavior(obj){
}

CameraControl::~CameraControl() {
}

void CameraControl::Update() {
	//if (sInput->GetKey("ARROW_RIGHT")) {
	//	_gameobject->SetGlobalPosition(_gameobject->GetGlobalPosition() + Vector(1, 0));
	//}
}
