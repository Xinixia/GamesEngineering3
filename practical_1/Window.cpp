#include "Window.h"

float windowWidth = 800.0f;
float windowHeight = 800.0f;

Window::Window(const std::string& windowName)
	: window(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Titlebar) {

	window.setVerticalSyncEnabled(true);
}

void Window::Update() {
	sf::Event event;
	if (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Window::beginDraw() {
	window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable) {
	window.draw(drawable);
}

void Window::endDraw() {
	window.display();
}

bool Window::isOpen() const {
	return window.isOpen();
}

sf::Vector2u Window::getCentre() {
	sf::Vector2u centre = sf::Vector2u(windowWidth / 2, windowHeight / 2);
	return centre;
}