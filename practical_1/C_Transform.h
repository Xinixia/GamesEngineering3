#ifndef C_Transform_h
#define C_Transform_h

#include "Component.h"

class C_Transform : public Component {
public:
	C_Transform(Object* owner);

	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f pos);

	void AddPosition(float x, float y);
	void AddPosition(sf::Vector2f pos);

	//Allows us to set x/y values separately
	void SetX(float x);
	void SetY(float y);

	void AddX(float x);
	void AddY(float y);

	void rotate(float rot);
	const float& GetRotation() const;

	const sf::Vector2f& GetPosition() const;

	void SetStatic(bool isStatic);
	bool isStatic() const;

private:
	sf::Vector2f position;
	float rotation = 0.f;
	bool isStaticTransform;
};

#endif /* C_Transform_h */