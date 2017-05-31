#pragma once
#include "smart_ptr.h"

PTR( Process );

//for windows message
class Process {
public:
	virtual ~Process() = 0;

	//Get window message
	virtual int WindowMessage() = 0;

	static ProcessPtr GetInstance();
protected:
	Process();
};

#define sProcess Process::GetInstance()

