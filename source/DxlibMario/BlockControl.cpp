#include "BlockControl.h"
#include "Input.h"
#include "GameEngine.h"
#include "GameObject.h"
#include "GameObjectHelper.h"

#include "Animation.h"
#include "AnimationClip.h"
#include "AnimationProperty.h"
#include "AnimationDataPosition.h"

BlockControl::BlockControl() {

}


BlockControl::~BlockControl() {
	
}

void BlockControl::Start() {
	AnimationClipPtr clip = sGameEngine->CreateAnimationClip("test");
	AnimationPropertyPtr pro = clip->CreateProperty(ANIMATION_PROPERTY_POSITION);
	AnimationDataPositionPtr begin = std::dynamic_pointer_cast<AnimationDataPosition>(pro->AddKey(0));
	AnimationDataPositionPtr end = std::dynamic_pointer_cast<AnimationDataPosition>(pro->AddKey(10000));
	begin->SetPosition(_gameobject->GetLocalPosition());
	end->SetPosition(_gameobject->GetGlobalPosition() + Vector(100, 0));

	AnimationPtr animation = _gameobject->AddAnimation();
	animation->SetClip(clip);
}

void BlockControl::Update() {

	// moving block. for collision testing
	if (sInput->GetKey("A")) {
		AnimationPtr animation = GameObjectHelper::GetGameObjectComponent<Animation>(_gameobject);
		if (animation) {
			animation->Play();
		}
	}
}

void BlockControl::CollisionEnter(GameObjectPtr other) {
	DestroyObject(_gameobject);
}
