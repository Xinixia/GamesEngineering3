#ifndef SceneGame_h
#define SceneGame_h

#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"
#include "Object.h"
#include "C_Sprite.h"
#include "C_KeyboardMovement.h"
#include "ResourceAllocator.h"
#include "ObjectCollection.h"
#include "C_Animation.h"
#include "TileMapParser.h"
#include "C_BoxCollider.h"
#include "Debug.h"
#include "C_Camera.h"

class SceneGame : public Scene {
public:
	SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator);

	void OnCreate() override;
	void OnDestroy() override;

	void ProcessInput() override;
	void Update(float deltaTime) override;
	void Draw(Window& window) override;

	void LateUpdate(float deltaTime) override;

	SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator, Window& window);

private:
	std::shared_ptr<Object> player;

	WorkingDirectory& workingDir;
	Input input;

	ResourceAllocator<sf::Texture>& textureAllocator;

	ObjectCollection objects;

	TileMapParser mapParser;

	Window& window;
};

#endif // !SceneGame_h