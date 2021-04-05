#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"
#include "bullet.h"

using namespace sf;
using namespace std;

const Keyboard::Key controls[2] = {
	Keyboard::A, //Player1 Left
	Keyboard::D, //Player1 Righ
};

sf::Texture spritesheet;
sf::Sprite invader;
sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Space Invaders");

std::vector < Ship* > ships;
Player* player;

float x = 0;
float y = 32;
int invaderColumns = 25;
int invaderRows = 7;
int spaceBetweenSprites = 30;
int invaderCount = invaderColumns * invaderRows;
const float playerSpeed = 400.f;

void Load() {
	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(0, 0, 32, 32));

	player = new Player;
	ships.push_back(player);

	for (int r = 0; r < invaderRows; r++) {
		x = spaceBetweenSprites;

		auto rect = IntRect(64, 0, 32, 32);

		for (int c = 0; c < invaderColumns; c++) {

			if (r % 2 == 0) {
				rect = IntRect(0, 0, 32, 32);
			}

			Vector2f position = { x, y };
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
			x += spaceBetweenSprites;
		}
		y += spaceBetweenSprites;
	}
}


void Render() {

	Bullet::Render(window);

	for (const auto s : ships) {
		window.draw(*s);
	}

}



void Update(RenderWindow& window) {
	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	float direction = 0.0f;
	// check and consume events
	Event event;

	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit via ESC key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}

	if (ships[0]->getPosition().x + 64 > gameWidth) {
		ships[0]->setPosition(gameWidth - 64, ships[0]->getPosition().y);
	}

	if (ships[0]->getPosition().x - 32 < 0) {
		ships[0]->setPosition(32, ships[0]->getPosition().y);
	}

	ships[0]->move(direction * playerSpeed * dt, 0);

	for (auto& s : ships) {
		s->Update(dt);
	}

	Bullet::Update(dt);
}

int main() {

	Load();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		Render();
		Update(window);
		window.display();
	}
	return 0;
}


