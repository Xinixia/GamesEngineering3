#include "Debug.h"
#include "SceneGame.h"

std::vector<sf::RectangleShape> Debug::rects = {};
std::vector<std::array<sf::Vertex, 2>> Debug::lines = {};

void Debug::HandleCameraZoom(Window& window, Input& input) {
	//std::shared_ptr<Object> player = std::make_shared<Object>();
	
	/*if (input.IsKeyUp(Input::Key::Q)) {
		sf::View view = window.GetView();
		//view.zoom(1.1f);
		player->transform->rotate(-90.f);
		view.setRotation(view.getRotation() + 90.f);
		window.SetView(view);
	}
	else if (input.IsKeyUp(Input::Key::E)) {
		sf::View view = window.GetView();
		//view.zoom(0.9f);
		player->transform->rotate(90.f);
		view.setRotation(view.getRotation() - 90.f);
		window.SetView(view);
	}*/
}

void Debug::Draw(Window& window) {
	for (auto& r : rects) {
		window.Draw(r);
	}
	rects.clear();

	for (auto& l : lines) {
		sf::Vertex line[2] = { l.at(0), l.at(1) };
		window.Draw(line, 2, sf::Lines);
	}
	lines.clear();
}

void Debug::DrawRect(const sf::FloatRect& rect, sf::Color colour) {
	sf::Vector2f size(rect.width, rect.height);
	sf::Vector2f pos(rect.left, rect.top);
	sf::RectangleShape shape(size);
	shape.setPosition(pos);
	shape.setOutlineColor(colour);
	shape.setOutlineThickness(3.f);
	shape.setFillColor(sf::Color::Transparent);
	rects.push_back(shape);
}

void Debug::DrawLine(const sf::Vector2f& from, const sf::Vector2f& to, sf::Color colour) {
	lines.push_back({ sf::Vertex(from, colour), sf::Vertex(to, colour) });
}

void Debug::Log(const std::string& msg) {
	std::cout << msg << std::endl;
}

void Debug::LogWarning(const std::string& msg) {
	std::cout << "WARNING: " << msg << std::endl;
}

void Debug::LogError(const std::string& msg) {
	std::cout << "ERROR: " << msg << std::endl;
}

