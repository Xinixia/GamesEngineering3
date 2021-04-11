#pragma once

#include <array>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Input.h"
#include "Object.h"

class Debug {
public:
	static void Draw(Window& window);

	static void DrawRect(const sf::FloatRect& rect, sf::Color colour = sf::Color::White);

	static void DrawLine(const sf::Vector2f& from, const sf::Vector2f& to, sf::Color colour = sf::Color::White);

	static void Log(const std::string& msg);
	static void LogWarning(const std::string& msg);
	static void LogError(const std::string& msg);

	static void HandleCameraZoom(Window& window, Input& input);

private:
	static std::vector<std::array<sf::Vertex, 2>> lines;
	static std::vector<sf::RectangleShape> rects;
};