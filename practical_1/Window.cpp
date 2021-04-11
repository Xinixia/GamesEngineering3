#include "Window.h"

float windowWidth = 1280.0f;
float windowHeight = 720.0f;

Window::Window(const std::string& windowName)
	: window(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Default) {

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

void Window::Draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type) {
	window.draw(vertices, vertexCount, type);
}

const sf::View& Window::GetView() const {
	return window.getView();
}

void Window::SetView(const sf::View& view) {
	window.setView(view);
}

sf::FloatRect Window::GetViewSpace() const {
	const sf::View& view = GetView();
	const sf::Vector2f& viewCenter = view.getCenter();
	const sf::Vector2f& viewSize = view.getSize();
	sf::Vector2f viewSizeHalf(viewSize.x * 0.5f, viewSize.y * 0.5f);
	sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);
	return viewSpace;
}