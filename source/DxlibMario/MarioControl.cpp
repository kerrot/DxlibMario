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
#include "AnimationDataEnable.h"

#include "Sprite.h"
#include "SpriteCollider.h"
#include "SpriteRenderer.h"
#include "GoombaControl.h"

#include "GameTime.h"

MarioControl::MarioControl() 
: _dead(false) {
}

MarioControl::~MarioControl() {
}

void MarioControl::Start() {
	AnimationClipPtr clip = sGameEngine->CreateAnimationClip("marioMove");
	AnimationPropertyPtr pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);

	SpritePtr sprite = sGameEngine->LoadSprite("Resources/player0.png");

	AnimationDataSprite::SetSpriteAnimation(pro->AddPeroidKeys(500, 4), sprite, 16, 16, 16, 0, 8, 16);

	AnimatorPtr animator = _gameobject->AddAnimator();
	AnimationStatePtr moveState = animator->AddState("Move");
	moveState->SetClip(clip);

	clip = sGameEngine->CreateAnimationClip("marioJump");
	pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);
	AnimationDataSpritePtr p = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(0));
	p->SetSprite(sprite);
	p->SetDrawRect(Rect(80, 96, 0, 16));
	p->SetPivot(8, 16);
	AnimationStatePtr jumpState = animator->AddState("Jump");
	jumpState->SetClip(clip);


	clip = sGameEngine->CreateAnimationClip("marioDead");
	pro = clip->CreateProperty(ANIMATION_PROPERTY_ENABLE);
	AnimationDataEnablePtr e = std::dynamic_pointer_cast<AnimationDataEnable>(pro->AddKey(0));
	e->SetEnable(GameObjectHelper::GetGameObjectComponent<SpriteCollider>(_gameobject), false);
	pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);
	p = std::dynamic_pointer_cast<AnimationDataSprite>(pro->AddKey(0));
	p->SetSprite(sprite);
	p->SetDrawRect(Rect(96, 112, 0, 16));
	p->SetPivot(8, 16);
	AnimationStatePtr deadState = animator->AddState("Dead");
	deadState->SetClip(clip);

	animator->SetSpeed(2);
	animator->SetUnscaled(true);
}

void MarioControl::Update() {
	if (_dead) {
		return;
	}

	if (sInput->GetKey("X")) {
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->AddAcceleration(Vector(0, -3));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Jump");
		}
	}

	if (sInput->GetKey("ARROW_LEFT")) {
		SpriteRendererPtr renderer = GameObjectHelper::GetGameObjectComponent<SpriteRenderer>(_gameobject);
		if (renderer) {
			renderer->SetReverse(true);
		}

		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->AddAcceleration(Vector(-1, 0));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Move");
		}
	}

	if (sInput->GetKey("ARROW_RIGHT")) {
		SpriteRendererPtr renderer = GameObjectHelper::GetGameObjectComponent<SpriteRenderer>(_gameobject);
		if (renderer) {
			renderer->SetReverse(false);
		}
		
		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->AddAcceleration(Vector(1, 0));
		}

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Move");
		}
	}
}

void MarioControl::CollisionEnter(GameObjectPtr other) {
	GoombaControlPtr enemy = GameObjectHelper::GetGameObjectComponent<GoombaControl>(other);
	if (enemy) {
		_dead = true;
		//sGameTime->Pause();

		AnimatorPtr animator = GameObjectHelper::GetGameObjectComponent<Animator>(_gameobject);
		if (animator) {
			animator->ChangeState("Dead");
		}

		RigidBody2DPtr rigid = GameObjectHelper::GetGameObjectComponent<RigidBody2D>(_gameobject);
		if (rigid) {
			rigid->SetAcceleration(Vector());
			rigid->SetVelocity(Vector(0, -25, 0));
		}
	}
}