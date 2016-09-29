#pragma once
#include "smart_ptr.h"
#include <map>

PTR( Input );

class Input {
public:
	virtual ~Input() = 0;
	
	bool GetKey(const char* key);
	bool GetKeyDown(const char* key);
	bool GetKeyUp(const char* key);

	virtual void UpdateKey() = 0;


protected:
	Input();
	struct KEYS {
		char now[ 256 ];
		char before[ 256 ];
		std::map< std::string, int > convert;
	};
	
	KEYS _state;
};