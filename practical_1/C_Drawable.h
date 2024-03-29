#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"

enum class DrawLayer {
	Default,
	Background,
	Foreground,
	Entities
};

class C_Drawable {
public:
	C_Drawable();
	virtual ~C_Drawable();

	virtual void Draw(Window& window) = 0;

	void SetSortOrder(int order);
	int GetSortOrder() const;

	void SetDrawLayer(DrawLayer drawLayer);
	DrawLayer GetDrawLayer() const;

	virtual bool ContinueToDraw() const = 0;

private:
	int sortOrder;
	DrawLayer layer;
};