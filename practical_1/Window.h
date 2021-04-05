#ifndef Window_h
#define Window_h

#include <SFML/Graphics.hpp>

class Window
{
public:
	Window(const std::string& windowName);

	void Update();

	void beginDraw();
	void Draw(const sf::Drawable& drawable);
	void endDraw();

	bool isOpen() const;

	sf::Vector2u getCentre();

private:
	sf::RenderWindow window;

};

#endif /*Window_h*/