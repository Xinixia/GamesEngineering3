#pragma once

#include "Component.h"

class C_Camera : public Component {
public:
	C_Camera(Object* owner);

	void LateUpdate(float deltaTime) override;

	void SetWindow(Window* gameWindow);

private:
	Window* window;
};