#pragma once
#include "GameTime.h"

PTR(DxlibGameTime)

class DxlibGameTime : public GameTime {
	friend class  GameEngine;
public:
	virtual ~DxlibGameTime();
private:

	virtual __int64 UpdateCurrent();

	DxlibGameTime();
};

