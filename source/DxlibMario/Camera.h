#pragma once
#include "GameObject.h"

PTR( Camera )

class Camera : public GameObject {
friend class GameEngine; // only gameengine can create camera
public:
	virtual ~Camera();

	static CameraPtr GetMainCamera(); // main camera is unique

private:
	Camera();
};

#define sCamera Camera::GetMainCamera()