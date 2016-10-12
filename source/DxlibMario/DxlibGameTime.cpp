#include "DxlibGameTime.h"
#include "DxLib.h"

long DxlibGameTime::UpdateCurrent() {
	return GetNowHiPerformanceCount();
}

DxlibGameTime::DxlibGameTime() {
}


DxlibGameTime::~DxlibGameTime() {
}
