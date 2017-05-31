#include "Behavior.h"
#include "GameEngine.h"

void Behavior::InitBehavior() {
	if (!_init) {
		_init = true;
		Start();
	}
}

Behavior::Behavior()
: _init(false) {

}

Behavior::~Behavior() {

}	

void Behavior::Start() {
}

void Behavior::Update(){

}

void Behavior::LastUpdate() {

}

void Behavior::DestroyObject(GameObjectPtr obj) {
	sGameEngine->DestroyObject(obj);
}

void Behavior::CollisionEnter(GameObjectPtr other) {
}

void Behavior::CollisionStay(GameObjectPtr other) {
}

void Behavior::CollisionExit(GameObjectPtr other) {
}
