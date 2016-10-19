#include "GoombaControl.h"

#include "Animator.h"
#include "AnimationState.h"
#include "AnimationClip.h"
#include "AnimationProperty.h"
#include "AnimationDataSprite.h"

#include "GameEngine.h"
#include "GameObject.h"

GoombaControl::GoombaControl() {
}


GoombaControl::~GoombaControl() {
}

void GoombaControl::Start() {
	AnimationClipPtr clip = sGameEngine->CreateAnimationClip("enemyMove");
	AnimationPropertyPtr pro = clip->CreateProperty(ANIMATION_PROPERTY_SPRITE);

	SpritePtr sprite = sGameEngine->LoadSprite("Resources/enemy0.png");

	AnimationDataSprite::SetSpriteAnimation(pro->AddPeroidKeys(500, 3), sprite, 16, 16, 0, 0, 8, 16);

	AnimatorPtr animator = _gameobject->AddAnimator();
	AnimationStatePtr moveState = animator->AddState("Move");
	moveState->SetClip(clip);
}
