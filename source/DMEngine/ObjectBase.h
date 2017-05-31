#pragma once
#include "smart_ptr.h"

PTR(ObjectBase)

class ObjectBase : public std::enable_shared_from_this < ObjectBase > {
public:
	virtual ~ObjectBase();

	bool IsEnabled() const;
	void SetEnable(bool v);

protected:
	ObjectBase();

	bool _enable;	//visible in game
};

