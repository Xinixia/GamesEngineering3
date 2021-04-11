#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
	: window("Density Experiment")
{
	std::shared_ptr<SceneSplashScreen> splashScreen =
		std::make_shared<SceneSplashScreen>(workingDir, sceneStateMachine, window, textureAllocator);

	std::shared_ptr<SceneGame> gameScene =
		std::make_shared<SceneGame>(workingDir, textureAllocator, window);

	unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	splashScreen->SetSwitchToScene(gameSceneID);

	sceneStateMachine.SwitchTo(splashScreenID);

	deltaTime = clock.restart().asSeconds();
}

void Game::Update() {
	window.Update();

	sceneStateMachine.Update(deltaTime);
}

void Game::lateUpdate() {
	sceneStateMachine.LateUpdate(deltaTime);
}

void Game::processInput() {
	sceneStateMachine.ProcessInput();
}

void Game::Draw() {
	window.beginDraw();

	sceneStateMachine.Draw(window);

	window.endDraw();
}

void Game::calculateDeltaTime() {
	deltaTime = clock.restart().asSeconds();
}

bool Game::isRunning() const {

	return window.isOpen();;
}