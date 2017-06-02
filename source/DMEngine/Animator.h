#pragma once
#include "Component.h"
#include <map>
#include <string>

PTR( Animator )
PTR( AnimationState )


// animation state (translate to different animation clip)
class Animator: public Component {
friend class GameObject;
public:
	virtual ~Animator();

	AnimationStatePtr AddState(const char* name);
	void ChangeState(const char* name);

	void Update();

	void SetSpeed(double speed);
	void SetUnscaled(bool v);
private:
	Animator();

	std::map<std::string, AnimationStatePtr> _states;

	AnimationStatePtr _currentState;

	bool _unscaledTime;			//play even when game pause
	__int64 _currentTime;
	double _animationSpeed;
};

