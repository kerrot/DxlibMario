#include "BlockControl.h"

BlockControl::BlockControl() {
}


BlockControl::~BlockControl() {
}

void BlockControl::CollisionEnter(GameObjectPtr other) {
	DestroyObject(_gameobject);
}
