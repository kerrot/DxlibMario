#include "DxlibInput.h"
#include "DxLib.h"

DxlibInput::DxlibInput() {
	_state.convert[ "A" ] = KEY_INPUT_A;
	_state.convert[ "B" ] = KEY_INPUT_B;
	_state.convert[ "C" ] = KEY_INPUT_C;
	_state.convert[ "D" ] = KEY_INPUT_D;
	_state.convert[ "E" ] = KEY_INPUT_E;
	_state.convert[ "F" ] = KEY_INPUT_F;
	_state.convert[ "G" ] = KEY_INPUT_G;
	_state.convert[ "H" ] = KEY_INPUT_H;
	_state.convert[ "I" ] = KEY_INPUT_I;
	_state.convert[ "J" ] = KEY_INPUT_J;
	_state.convert[ "K" ] = KEY_INPUT_K;
	_state.convert[ "L" ] = KEY_INPUT_L;
	_state.convert[ "N" ] = KEY_INPUT_N;
	_state.convert[ "M" ] = KEY_INPUT_M;
	_state.convert[ "O" ] = KEY_INPUT_O;
	_state.convert[ "P" ] = KEY_INPUT_P;
	_state.convert[ "Q" ] = KEY_INPUT_Q;
	_state.convert[ "R" ] = KEY_INPUT_R;
	_state.convert[ "S" ] = KEY_INPUT_S;
	_state.convert[ "T" ] = KEY_INPUT_T;
	_state.convert[ "U" ] = KEY_INPUT_U;
	_state.convert[ "V" ] = KEY_INPUT_V;
	_state.convert[ "W" ] = KEY_INPUT_W;
	_state.convert[ "X" ] = KEY_INPUT_X;
	_state.convert[ "Y" ] = KEY_INPUT_Y;
	_state.convert[ "Z" ] = KEY_INPUT_Z;
	_state.convert[ "1" ] = KEY_INPUT_1;
	_state.convert[ "2" ] = KEY_INPUT_2;
	_state.convert[ "3" ] = KEY_INPUT_3;
	_state.convert[ "4" ] = KEY_INPUT_4;
	_state.convert[ "5" ] = KEY_INPUT_5;
	_state.convert[ "6" ] = KEY_INPUT_6;
	_state.convert[ "7" ] = KEY_INPUT_7;
	_state.convert[ "8" ] = KEY_INPUT_8;
	_state.convert[ "9" ] = KEY_INPUT_9;
	_state.convert[ "0" ] = KEY_INPUT_0;
	_state.convert[ "NUM1" ] = KEY_INPUT_NUMPAD1;
	_state.convert[ "NUM2" ] = KEY_INPUT_NUMPAD2;
	_state.convert[ "NUM3" ] = KEY_INPUT_NUMPAD3;
	_state.convert[ "NUM4" ] = KEY_INPUT_NUMPAD4;
	_state.convert[ "NUM5" ] = KEY_INPUT_NUMPAD5;
	_state.convert[ "NUM6" ] = KEY_INPUT_NUMPAD6;
	_state.convert[ "NUM7" ] = KEY_INPUT_NUMPAD7;
	_state.convert[ "NUM8" ] = KEY_INPUT_NUMPAD8;
	_state.convert[ "NUM9" ] = KEY_INPUT_NUMPAD9;
	_state.convert[ "NUM0" ] = KEY_INPUT_NUMPAD0;
	_state.convert[ "ARROW_LEFT"  ] = KEY_INPUT_LEFT;
	_state.convert[ "ARROW_RIGHT" ] = KEY_INPUT_RIGHT;
	_state.convert[ "ARROW_UP"    ] = KEY_INPUT_UP;
	_state.convert[ "ARROW_DOWN"  ] = KEY_INPUT_DOWN;
	_state.convert[ "F1" ]  = KEY_INPUT_F1;
	_state.convert[ "F2" ]  = KEY_INPUT_F2;
	_state.convert[ "F3" ]  = KEY_INPUT_F3;
	_state.convert[ "F4" ]  = KEY_INPUT_F4;
	_state.convert[ "F5" ]  = KEY_INPUT_F5;
	_state.convert[ "F6" ]  = KEY_INPUT_F6;
	_state.convert[ "F7" ]  = KEY_INPUT_F7;
	_state.convert[ "F8" ]  = KEY_INPUT_F8;
	_state.convert[ "F9" ]  = KEY_INPUT_F9;
	_state.convert[ "F10" ] = KEY_INPUT_F10;
	_state.convert[ "F11" ] = KEY_INPUT_F11;
	_state.convert[ "F12" ] = KEY_INPUT_F12;
	_state.convert[ "+" ] = KEY_INPUT_ADD;
	_state.convert[ "-" ] = KEY_INPUT_SUBTRACT;
	_state.convert[ "ENTER" ] = KEY_INPUT_RETURN;
	_state.convert[ "ESC" ] = KEY_INPUT_ESCAPE;
	_state.convert[ "BACK_SPACE" ] = KEY_INPUT_BACK;
}


DxlibInput::~DxlibInput() {
}

void DxlibInput::UpdateKey() {
	memcpy(_state.before, _state.now, 256);

	GetHitKeyStateAll( _state.now );
}


