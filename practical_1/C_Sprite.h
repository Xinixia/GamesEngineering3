#ifndef C_Sprite_h
#define C_Sprite_h

#include "Component.h"

class C_Sprite : public Component {
public:
	C_Sprite(Object* owner);

	//Loads a sprite from a file.
	void Load(const std::string& filePath);
	void Load(const std::string& filePath, sf::IntRect intRect);

	//Override the draw method so we can draw our sprite
	void Draw(Window& window) override;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif // !C_Sprite_h