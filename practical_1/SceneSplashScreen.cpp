#include "SceneSplashScreen.h"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window)
	: sceneStateMachine(sceneStateMachine), workingDir(workingDir), window(window), switchToScene(0), currentSeconds(0.f), showForSeconds(3.f) {}

void SceneSplashScreen::OnCreate() {

	//We'll initialise our splash screen image here

	splashTexture.loadFromFile(workingDir.Get() + "RedSquirrelGamesSplash.jpg");
	splashSprite.setTexture(splashTexture);

	sf::FloatRect spriteSize = splashSprite.getLocalBounds();

	//Set the origin of the sprite to the centre of the image
	splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
	splashSprite.setScale(0.5f, 0.5f);

	sf::Vector2u windowCentre = window.getCentre();

	//Positions sprite in centre of screen
	splashSprite.setPosition(windowCentre.x, windowCentre.y);
}

void SceneSplashScreen::OnActivate() {
	//Resets the currentSeconds count whenever the scene is active
	currentSeconds = 0.f;
}

void SceneSplashScreen::OnDestroy(){}

void SceneSplashScreen::SetSwitchToScene(unsigned int id) {
	//Stores the id of the scene that we will transition to
	switchToScene = id;
}

void SceneSplashScreen::Update(float deltaTime) {
	currentSeconds += deltaTime;

	if (currentSeconds >= showForSeconds) {
		//Switches states
		sceneStateMachine.SwitchTo(switchToScene);
	}
}

void SceneSplashScreen::Draw(Window& window) {
	window.Draw(splashSprite);
}