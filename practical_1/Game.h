#ifndef Game_h
#define Game_h
#include "Window.h"
#include "WorkingDirectory.h"
#include <SFML/Graphics.hpp>
#include "Input.h"

#include "SceneStateMachine.h"
#include "SceneSplashScreen.h"
#include "SceneGame.h"

class Game
{
public:
	Game();

	void processInput();
	void Update();
	void lateUpdate();
	void Draw();
	void calculateDeltaTime();
	bool isRunning() const;

private:
	Window window;
	WorkingDirectory workingDir;

	sf::Clock clock;
	float deltaTime;

	SceneStateMachine sceneStateMachine;
};

#endif /* Game_h */