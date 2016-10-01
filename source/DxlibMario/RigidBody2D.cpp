#include "RigidBody2D.h"
#include "GameObject.h"
#include "GameObjectHelper.h"
#include "SpriteCollider.h"
#include "GameEngine.h"

RigidBody2D::RigidBody2D(GameObjectPtr obj)
: Component(obj)
, _drag(0) {

}


RigidBody2D::~RigidBody2D() {
}

void RigidBody2D::Update() {
	_velocity += _acceleration + _gravity;

	_velocity = _velocity.normalize() * (_velocity.getLength() - _drag);

	SpriteColliderPtr collider = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(_gameobject);
	if (collider) {
		Vector pos = _gameobject->GetGlobalPosition() + _velocity;

		const std::map<int, GameObjectPtr>& objs = sGameEngine->GetGameObjects();
		for (std::map<int, GameObjectPtr>::const_iterator iter = objs.begin();
			iter != objs.end(); ++iter) {

			SpriteColliderPtr tmp = GameObjectHelper::GetGameObjectComponent<SpriteCollider>(iter->second);
			if (_gameobject == iter->second || !tmp) {
				continue;
			}

			Rect rect1, rect2;
			rect1._left = (int)_gameobject->GetGlobalPosition().x + collider->GetRect()._left;
			rect1._up = (int)_gameobject->GetGlobalPosition().y + collider->GetRect()._up;
			rect1._right = rect1._left + collider->GetRect()._right - collider->GetRect()._left;
			rect1._down = rect1._up + collider->GetRect()._down - collider->GetRect()._up;

			rect2._left = (int)iter->second->GetGlobalPosition().x + tmp->GetRect()._left;
			rect2._up = (int)iter->second->GetGlobalPosition().y + tmp->GetRect()._up;
			rect2._right = rect2._left + tmp->GetRect()._right - tmp->GetRect()._left;
			rect2._down = rect2._up + tmp->GetRect()._down - tmp->GetRect()._up;

			if (Rect::IsCollision(rect1, rect2)) {
				return;
			}
		}
	}
	
	_gameobject->SetGlobalPosition(_gameobject->GetGlobalPosition() + _velocity);
	
}

void RigidBody2D::SetGravity(const Vector & g) {
	_gravity = g;
}
