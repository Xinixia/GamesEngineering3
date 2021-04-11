#pragma once

#include <vector>

struct FrameData {
	int id;
	int x;
	int y;
	int width;
	int height;
	float displayTimeSeconds;
};

enum class FacingDirection {
	None,
	Left,
	Right
};

class Animation {
public:
	Animation();

	Animation(FacingDirection direction);

	void AddFrame(int textureID, int x, int y, int width, int height, float frameTime);

	const FrameData* GetCurrentFrame() const;

	bool UpdateFrame(float deltaTime);

	void Reset();

	void SetDirection(FacingDirection dir);
	FacingDirection GetDirection() const;

private:
	void IncrementFrame();

	std::vector<FrameData> frames;

	int currentFrameIndex;

	float currentFrameTime;

	FacingDirection direction;
};