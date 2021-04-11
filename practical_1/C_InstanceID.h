#pragma once

#include "Component.h"

class C_InstanceID : public Component {
public:
	C_InstanceID(Object* owner);
	~C_InstanceID();

	int Get() const;

private:
	static int count;
	int id;
};