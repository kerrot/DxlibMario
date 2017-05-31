#pragma once
#include "smart_ptr.h"
#include <map>

PTR( Input );

//for keyboard input
class Input {
public:
	virtual ~Input() = 0;
	
	//use state to judge input event
	bool GetKey(const char* key);
	bool GetKeyDown(const char* key);
	bool GetKeyUp(const char* key);

	//update all input. record in _state
	virtual void UpdateKey() = 0;

	static InputPtr GetInstance();

protected:
	Input();
	struct KEYS {
		char now[ 256 ];
		char before[ 256 ];
		std::map< std::string, int > convert; //key string to value mapping
	};
	
	KEYS _state; // input key state record
};

#define sInput Input::GetInstance()