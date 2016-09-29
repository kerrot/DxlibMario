#pragma once
#include "Input.h"
#include "smart_ptr.h"

PTR( DxlibInput );

class DxlibInput : public Input {
friend class GameEngine;
public:
	virtual ~DxlibInput();
	virtual void UpdateKey();
private:
	DxlibInput();
};
