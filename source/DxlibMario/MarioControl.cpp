#include "MarioControl.h"
#include "Input.h"
#include "GameObject.h"
#include "GameObjectHelper.h"
#include "RigidBody2D.h"

MarioControl::MarioControl() {
}

MarioControl::~MarioControl() {
}

void MarioControl::Update() {
	if (sInput->GetKey("X")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(0, -3));
		}
	}

	if (sInput->GetKey("ARROW_LEFT")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(-1, 0));
		}
	}

	if (sInput->GetKey("ARROW_RIGHT")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(1, 0));
		}
	}
}
