#include "Input.h"

Input::Input() {
}

Input::~Input() {
}

bool Input::GetKey(const char* key) {
	std::map< std::string, int >::iterator iter = _state.convert.find(key);
	if (iter != _state.convert.end()) {
		return _state.now[iter->second] == 1;
	}

	return false;
}

bool Input::GetKeyDown(const char* key) {
	std::map< std::string, int >::iterator iter = _state.convert.find(key);
	if (iter != _state.convert.end()) {
		return _state.now[iter->second] == 1 && _state.before[iter->second] == 0;
	}

	return false;
}

bool Input::GetKeyUp(const char* key) {
	std::map< std::string, int >::iterator iter = _state.convert.find(key);
	if (iter != _state.convert.end()) {
		return _state.now[iter->second] == 0 && _state.before[iter->second] == 1;
	}

	return false;
}