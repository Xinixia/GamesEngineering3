#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir) {}

void SceneGame::OnCreate() {

	player = std::make_shared<Object>();

	//Adds a component by calling our previously written template
	auto sprite = player->AddComponent<C_Sprite>();
	sprite->Load(workingDir.Get() + "valkyrie.png", sf::IntRect(1, 1, 40, 29));
}

void SceneGame::OnDestroy() {

}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltaTime) {

}

void SceneGame::Draw(Window& window) {
	player->Draw(window);
}
