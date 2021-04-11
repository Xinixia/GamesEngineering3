#define _USE_MATH_DEFINES

#include "C_KeyboardMovement.h"
#include "Object.h"
#include "Window.h"
#include "math.h"

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner), moveSpeed(200) {}

void C_KeyboardMovement::SetInput(Input* input, Window* window) {
	this->input = input;
	this->window = window;
}

void C_KeyboardMovement::SetMovementSpeed(int moveSpeed) {
	this->moveSpeed = moveSpeed;
}



void C_KeyboardMovement::Update(float deltaTime) {

	sf::Vector2f movement = { 0.f, 0.f };

	if (input == nullptr) {
		return;
	}

	if (input->IsKeyPressed(Input::Key::Left)) {
		movement.x = -moveSpeed;
		animation->SetAnimationDirection(FacingDirection::Left);
	}
	else if (input->IsKeyPressed(Input::Key::Right)) {
		movement.x = moveSpeed;
		animation->SetAnimationDirection(FacingDirection::Right);
	}

	if (input->IsKeyPressed(Input::Key::Up)) {
		movement.y = -moveSpeed;
	}
	else if (input->IsKeyPressed(Input::Key::Down)) {
		movement.y = moveSpeed;
	}

	if (movement.x == 0 && movement.y == 0) {
		animation->SetAnimationState(AnimationState::Idle);
	}
	else {
		animation->SetAnimationState(AnimationState::Walk);
	}

	float s = 1.f;
	float c = 1.f;

	if (input->IsKeyUp(Input::Key::Q)) {
		sf::View view = window->GetView();
		//view.zoom(1.1f);
		owner->transform->rotate(90.f);
		view.rotate(90.f);
		window->SetView(view);

	}
	else if (input->IsKeyUp(Input::Key::E)) {
		sf::View view = window->GetView();
		//view.zoom(0.9f);
		owner->transform->rotate(-90.f);
		view.rotate(-90.f);
		window->SetView(view);
	}

	auto rad = owner->transform->GetRotation() * (M_PI / 180);
	s = sinf(rad);
	c = cosf(rad);
	movement = { movement.x * c - movement.y * s, movement.y * c + movement.x * s };

	float xFrameMove = movement.x * deltaTime;
	float yFrameMove = movement.y * deltaTime;

	owner->transform->AddPosition(xFrameMove, yFrameMove);

}

void C_KeyboardMovement::Awake() {
	animation = owner->GetComponent<C_Animation>();
}