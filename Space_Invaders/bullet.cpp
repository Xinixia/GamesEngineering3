//bullet.cpp
#include "bullet.h"
#include "game.h"
using namespace sf;
using namespace std;

//Create definition for the constructor
//...

unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];

Bullet::Bullet() {
	setTexture(spritesheet);
}

Bullet::Bullet(IntRect ir) : Sprite() {
	
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
}

void Bullet::Update(const float& dt)
{ 
	for (int s = 0; s < 256; s++) {
		bullets[s]._Update(dt);
	}
}

void Bullet::Render(sf::RenderWindow& window)
{
	for (const auto& s : bullets) {
		window.draw(s);
	}
}

void Bullet::Fire(const sf::Vector2f& pos, const bool mode)
{
	if (mode == true) 
		bullets[bulletPointer].setTextureRect(IntRect(32, 32, 32, 32));
	
	if (mode == false)
		bullets[bulletPointer].setTextureRect(IntRect(64, 32, 32, 32));

	bullets[bulletPointer].setPosition(pos);
	bullets[bulletPointer]._mode = mode;
	bulletPointer++;
}

Bullet::Bullet(const sf::Vector2f& vec, bool check) {

}

void Bullet::_Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		return;
	}
	else {
		move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
		const FloatRect boundingBox = getGlobalBounds();

		for (auto s : ships) {
			if (!_mode && s == player) {

				continue;
			}
			if (_mode && s != player) {

				continue;
			}
			if (!s->is_exploded() && s->getGlobalBounds().intersects(boundingBox)) {

				s->Explode();

				setPosition(-100, -100);
				return;
			}
		}
	}
}



