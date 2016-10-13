#include "MarioControl.h"
#include "Input.h"
#include "GameObject.h"
#include "GameEngine.h"
#include "GameObjectHelper.h"
#include "RigidBody2D.h"

#include "Animator.h"
#include "AnimationState.h"
#include "AnimationClip.h"
#include "AnimationProperty.h"
#include "AnimationDataSprite.h"

#include "Sprite.h"

MarioControl::MarioControl() {
}

MarioControl::~MarioControl() {
}

void MarioControl::Start() {
	AnimationClipPtr clip = sGameEngine->CreateAnimationClip("marioMove");
	AnimationPropertyPtr pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);

	SpritePtr sprite = sGameEngine->LoadSprite("Resources/player0.png");

	AnimationDataSpritePtr p1 = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(0));
	p1->SetSprite(sprite);
	p1->SetDrawRect(Rect(16, 32, 0, 16));
	p1->SetPivot(8, 16);
	AnimationDataSpritePtr p2 = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(500));
	p2->SetSprite(sprite);
	p2->SetDrawRect(Rect(32, 48, 0, 16));
	p2->SetPivot(8, 16);
	AnimationDataSpritePtr p3 = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(1000));
	p3->SetSprite(sprite);
	p3->SetDrawRect(Rect(48, 64, 0, 16));
	p3->SetPivot(8, 16);
	AnimationDataSpritePtr p4 = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(1500));
	p4->SetSprite(sprite);
	p4->SetDrawRect(Rect(48, 64, 0, 16));
	p4->SetPivot(8, 16);

	AnimatorPtr animator = _gameobject->AddAnimator();
	AnimationStatePtr moveState = animator->AddState("Move");
	moveState->SetClip(clip);

	clip = sGameEngine->CreateAnimationClip("marioJump");
	pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);

	p1 = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(0));
	p1->SetSprite(sprite);
	p1->SetDrawRect(Rect(80, 96, 0, 16));
	p1->SetPivot(8, 16);

	AnimationStatePtr jumpState = animator->AddState("Jump");
	jumpState->SetClip(clip);
}

void MarioControl::Update() {
	if (sInput->GetKey("X")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(0, -3));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Jump");
		}
	}

	if (sInput->GetKey("ARROW_LEFT")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(-1, 0));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Move");
		}
	}

	if (sInput->GetKey("ARROW_RIGHT")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector(1, 0));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Move");
		}
	}
}
