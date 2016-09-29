#include "Process.h"
#include "GameEngine.h"

Process::~Process() {

}

Process::Process() {
}

ProcessPtr Process::GetInstance() {
	return sGameEngine->GetProcess();
}