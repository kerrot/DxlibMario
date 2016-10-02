#include "Behavior.h"
#include "GameEngine.h"

Behavior::Behavior() {

}

Behavior::~Behavior() {

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
