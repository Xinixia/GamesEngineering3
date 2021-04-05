#include <SFML/Graphics.hpp>
#include "player.h"
#include "Entity.h"

using namespace sf;
using namespace std;


unique_ptr<Player> player;

void Load() {
	player = make_unique<Player>();
}


void Update(RenderWindow& window) {
    // Reset clock, recalculate deltatime
    static Clock clock;
    float dt = clock.restart().asSeconds();
    float direction = 0.0f;
    // check and consume events
    Event event;

	player->Update(dt);
}


void Render(RenderWindow& window) {
	player->Render(window);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Tile Engine");
	Load();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		Render(window);
		Update(window);
		window.display();
	}
	return 0;
}