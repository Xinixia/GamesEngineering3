#include "C_Sprite.h"
#include "Object.h"
#include "ResourceAllocator.h"

C_Sprite::C_Sprite(Object* owner) : Component(owner), currentTextureID(-1) {}

void C_Sprite::SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator) {
	this->allocator = allocator;
}

void C_Sprite::Load(int id) {
	if (id >= 0 && id != currentTextureID) {

		currentTextureID = id;
		std::shared_ptr<sf::Texture> texture = allocator->Get(id);
		sprite.setTexture(*texture);
	}
}

void C_Sprite::Load(const std::string& filePath) {
	if (allocator) {
		int textureID = allocator->Add(filePath);

		if (textureID >= 0 && textureID != currentTextureID) {

			currentTextureID = textureID;
			std::shared_ptr<sf::Texture> texture = allocator->Get(textureID);
			sprite.setTexture(*texture);
		}
	}
}

void C_Sprite::Draw(Window& window) {
	window.Draw(sprite);
}

void C_Sprite::LateUpdate(float deltaTime) {

	sf::Vector2f pos = owner->transform->GetPosition();
	const sf::Vector2f& spriteScale = sprite.getScale();
	float rot = owner->transform->GetRotation();
	sprite.setRotation(rot);
	const sf::IntRect& spriteBounds = sprite.getTextureRect();


	sprite.setPosition(
		pos.x - ((abs(spriteBounds.width) * 0.5f) * spriteScale.x),
		pos.y - ((abs(spriteBounds.height) * 0.5f) * spriteScale.y)
	);


}

void C_Sprite::SetScale(float s1, float s2){
	sprite.setScale(s1, s2);
}

void C_Sprite::SetTextureRect(int x, int y, int width, int height) {
	sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void C_Sprite::SetTextureRect(const sf::IntRect& rect) {
	sprite.setTextureRect(rect);
}

bool C_Sprite::ContinueToDraw() const {
	return !owner->isQueuedForRemoval();
}

