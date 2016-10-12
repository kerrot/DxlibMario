#pragma once
#include "Component.h"

PTR (Animation)
PTR (AnimationClip)

class Animation : public Component {
friend class GameObject;
public:
	virtual ~Animation();

	void SetClip(AnimationClipWPtr ptr);

	void Start();
	void Stop();
	void Pause();

	void Update();

private:
	Animation();

	AnimationClipWPtr _clip;
	
	bool _pause;

	__int64 _current;
	__int64 _clipTime;
};