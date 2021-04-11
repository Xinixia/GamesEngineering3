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
	void Draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type);
	void endDraw();

	bool isOpen() const;

	sf::Vector2u getCentre();

	const sf::View& GetView() const;
	void SetView(const sf::View& view);
	sf::FloatRect Window::GetViewSpace() const;

private:
	sf::RenderWindow window;

};

#endif /*Window_h*/