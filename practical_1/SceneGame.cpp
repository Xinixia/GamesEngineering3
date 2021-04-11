#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator, Window& window) : workingDir(workingDir), textureAllocator(textureAllocator), mapParser(textureAllocator), window(window) {}

void SceneGame::OnCreate() {


	std::shared_ptr<Object> player = std::make_shared<Object>();

	//Adds a component by calling our previously written template
	auto sprite = player->AddComponent<C_Sprite>();
	sprite->SetTextureAllocator(&textureAllocator);
	sprite->SetDrawLayer(DrawLayer::Entities);

	auto movement = player->AddComponent<C_KeyboardMovement>();

	movement->SetInput(&input, &window);

	auto animation = player->AddComponent<C_Animation>();

	int vikingTextureID = textureAllocator.Add(workingDir.Get() + "valkyrie.png");

	const int frameWidth = 199;
	const int frameHeight = 144;

	//Create Idle Animation
	std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);

	const float idleAnimFrameSeconds = 0.2f;

	idleAnimation->AddFrame(vikingTextureID, 6, 6, frameWidth, frameHeight, idleAnimFrameSeconds);

	idleAnimation->AddFrame(vikingTextureID, 6, 156, frameWidth, frameHeight, idleAnimFrameSeconds);

	idleAnimation->AddFrame(vikingTextureID, 6, 306, frameWidth, frameHeight, idleAnimFrameSeconds);

	idleAnimation->AddFrame(vikingTextureID, 6, 456, frameWidth, frameHeight, idleAnimFrameSeconds);

	animation->AddAnimation(AnimationState::Idle, idleAnimation);

	//Create Walking Animation
	std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);

	const float walkAnimFrameSeconds = 0.15f;

	walkAnimation->AddFrame(vikingTextureID, 211, 6, frameWidth, frameHeight, idleAnimFrameSeconds);

	walkAnimation->AddFrame(vikingTextureID, 211, 156, frameWidth, frameHeight, idleAnimFrameSeconds);

	walkAnimation->AddFrame(vikingTextureID, 211, 306, frameWidth, frameHeight, idleAnimFrameSeconds);

	walkAnimation->AddFrame(vikingTextureID, 211, 456, frameWidth, frameHeight, idleAnimFrameSeconds);

	walkAnimation->AddFrame(vikingTextureID, 211, 606, frameWidth, frameHeight, idleAnimFrameSeconds);

	walkAnimation->AddFrame(vikingTextureID, 211, 756, frameWidth, frameHeight, idleAnimFrameSeconds);

	animation->AddAnimation(AnimationState::Walk, walkAnimation);

	sf::Vector2i mapOffset(-100, 128);
	std::vector<std::shared_ptr<Object>> levelTiles = mapParser.Parse(workingDir.Get() + "TestMap1.tmx", mapOffset);

	player->transform->SetPosition(100, 700);

	auto collider = player->AddComponent<C_BoxCollider>();
	collider->SetSize(frameWidth * 0.4f, frameHeight * 0.5f);
	collider->SetOffset(0.f, 14.f);
	collider->SetLayer(CollisionLayer::Player);

	auto camera = player->AddComponent<C_Camera>();
	camera->SetWindow(&window);

	objects.Add(levelTiles);
	objects.Add(player);
}

void SceneGame::OnDestroy() {

}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltaTime) {

	objects.ProcessRemovals();
	objects.ProcessNewObjects();
	objects.Update(deltaTime);

	Debug::HandleCameraZoom(window, input);
}

void SceneGame::Draw(Window& window) {
	objects.Draw(window);
	Debug::Draw(window);
}

void SceneGame::LateUpdate(float deltaTime) {
	objects.lateUpdate(deltaTime);
}