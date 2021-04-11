#ifndef C_Sprite_h
#define C_Sprite_h

#include "Component.h"
#include "C_Transform.h"
#include "ResourceAllocator.h"
#include "C_Drawable.h"

class C_Sprite : public Component, public C_Drawable {
public:
	C_Sprite(Object* owner);

	//Loads a sprite from a file.
	void Load(const std::string& filePath);
	//void Load(const std::string& filePath, sf::IntRect intRect);
	void Load(int id);

	//Override the draw method so we can draw our sprite
	void Draw(Window& window) override;

	//This is used to update the sprite based on position
	void LateUpdate(float deltaTime) override;

	void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

	void SetScale(float s1, float s2);

	void SetTextureRect(int x, int y, int width, int height);
	void SetTextureRect(const sf::IntRect& rect);

	bool ContinueToDraw() const override;

private:
	ResourceAllocator<sf::Texture>* allocator;
	sf::Sprite sprite;
	int currentTextureID;
};

#endif // !C_Sprite_h