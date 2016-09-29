#include "DxlibProcess.h"
#include "DxLib.h"

DxlibProcess::DxlibProcess() {
}


DxlibProcess::~DxlibProcess() {
}

bool DxlibProcess::WindowMessage() {
	return ProcessMessage();
}
