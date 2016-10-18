#pragma once
#include "Component.h"

PTR (Animation)
PTR (AnimationClip)

class Animation : public Component {
friend class GameObject;
public:
	virtual ~Animation();

	void SetClip(AnimationClipWPtr ptr);

	void Play();
	void Stop();
	void Pause();

	void Update();

	void SetSpeed(double speed);
	void SetUnscaled(bool v);

private:
	Animation();

	AnimationClipWPtr _clip;
	
	bool _pause;
	bool _unscaledTime;


	__int64 _current;
	double _animationSpeed;
};