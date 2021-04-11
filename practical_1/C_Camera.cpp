#include "C_Camera.h"
#include "Object.h"

C_Camera::C_Camera(Object* owner) : Component(owner){}

void C_Camera::LateUpdate(float deltaTime) {
	if (window) {
		sf::View view = window->GetView();

		const sf::Vector2f& targetPos = owner->transform->GetPosition();

		view.setCenter(targetPos.x, 500);

		window->SetView(view);
	}
}

void C_Camera::SetWindow(Window* gameWindow) {
	window = gameWindow;
}