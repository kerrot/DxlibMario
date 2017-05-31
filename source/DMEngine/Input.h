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

//"A"
//"B"
//"C"
//"D"
//"E"
//"F"
//"G"
//"H"
//"I"
//"J"
//"K"
//"L"
//"N"
//"M"
//"O"
//"P"
//"Q"
//"R"
//"S"
//"T"
//"U"
//"V"
//"W"
//"X"
//"Y"
//"Z"
//"1"
//"2"
//"3"
//"4"
//"5"
//"6"
//"7"
//"8"
//"9"
//"0"
//"NUM1"
//"NUM2"
//"NUM3"
//"NUM4"
//"NUM5"
//"NUM6"
//"NUM7"
//"NUM8"
//"NUM9"
//"NUM0"
//"ARROW_LEFT"
//"ARROW_RIGHT"
//"ARROW_UP"
//"ARROW_DOWN"
//"F1"
//"F2"
//"F3"
//"F4"
//"F5"
//"F6"
//"F7"
//"F8"
//"F9"
//"F10"
//"F11"
//"F12"
//"+"
//"-"
//"ENTER"
//"ESC"
//"BACK_SPACE"