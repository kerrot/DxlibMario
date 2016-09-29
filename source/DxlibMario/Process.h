#pragma once
#include "smart_ptr.h"

PTR( Process );

class Process {
public:
	virtual ~Process() = 0;

	virtual bool WindowMessage() = 0;

	static ProcessPtr GetInstance();
protected:
	Process();
};

#define sProcess Process::GetInstance()

