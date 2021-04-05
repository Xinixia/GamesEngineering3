//bullet.h
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	explicit Bullet(sf::IntRect ir);
	static void Update(const float& dt);
	static void Render(sf::RenderWindow& window);
	static void Fire(const sf::Vector2f& pos, const bool mode);
	Bullet(const sf::Vector2f& vec, bool check);

	~Bullet() = default;
protected:
	static unsigned char bulletPointer;
	Bullet();
	sf::IntRect _sprite;
	void _Update(const float& dt);
	static Bullet bullets[256];
	//false=player bullet, true=Enemy bullet
	bool _mode = true;
};