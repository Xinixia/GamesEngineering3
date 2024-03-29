#pragma once

#include "Component.h"
#include "C_Collider.h"

class C_BoxCollider : public C_Collider {
public:
	C_BoxCollider(Object* owner);

	Manifold Intersects(std::shared_ptr<C_Collider> other) override;
	void ResolveOverlap(const Manifold& m) override;

	void SetCollidable(const sf::FloatRect& rect);
	const sf::FloatRect& GetCollidable();

	void SetOffset(const sf::Vector2f& offset);
	void SetOffset(float x, float y);

	void SetSize(const sf::Vector2f& size);
	void SetSize(float width, float height);

private:
	void SetPosition();

	sf::FloatRect AABB;
	sf::Vector2f offset;
};