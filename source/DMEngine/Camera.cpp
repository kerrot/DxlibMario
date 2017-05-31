#include "Camera.h"
#include "GameEngine.h"

Camera::Camera() {
}


Camera::~Camera() {
}

CameraPtr Camera::GetMainCamera() {
	return sGameEngine->GetMainCamera();
}
