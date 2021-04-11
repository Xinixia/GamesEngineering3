#ifndef Input_h
#define Input_h

#include <SFML/Graphics.hpp>
#include "Bitmask.h"

class Input
{
public:
	enum class Key {
		None = 0,
		Left = 1,
		Right = 2,
		Up = 3,
		Down = 4,
		Esc = 5,
		Q = 6,
		E = 7
	};

	void Update();

	bool IsKeyPressed(Key keycode);
	bool IsKeyDown(Key keycode);
	bool IsKeyUp(Key keycode);

private:
	Bitmask thisFrameKeys;
	Bitmask lastFrameKeys;
};

#endif // !Input_h
