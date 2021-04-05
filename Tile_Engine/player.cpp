//player.cpp
#include "player.h"
using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
    Keyboard::W, //Player Up
    Keyboard::S, //Player Down
    Keyboard::A, //Player Left
    Keyboard::D //Player Right
};


void Player::Update(double dt) {
    //Move in four directions based on keys
	float directionX = 0;
	float directionY = 0;

	if (Keyboard::isKeyPressed(controls[0])) {
		directionY--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		directionY++;
	}

	if (Keyboard::isKeyPressed(controls[2])) {
		directionX--;
	}
	if (Keyboard::isKeyPressed(controls[3])) {
		directionX++;
	}

	move(Vector2f(directionX * _speed * dt, directionY * _speed * dt));

        Entity::Update(dt);
}

Player::Player()
    : _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}