#pragma once
#include "Process.h"
#include "smart_ptr.h"

PTR( DxlibProcess );

class DxlibProcess : public Process {
friend class GameEngine;
public:
	virtual ~DxlibProcess();

	virtual int WindowMessage();

private:
	DxlibProcess();
};