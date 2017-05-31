#pragma once
#include "Component.h"

PTR (Animation)
PTR (AnimationClip)

class Animation : public Component {
friend class GameObject;	// can only created by gameobject
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

private:
	bool _pause;
	bool _unscaledTime;		//play even when game pause

	AnimationClipWPtr _clip;

	__int64 _current;
	double _animationSpeed;
};