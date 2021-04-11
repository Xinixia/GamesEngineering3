#ifndef Object_h
#define Object_h

#include <vector>

#include "Component.h"
#include "Window.h"
#include "C_Transform.h"
#include "C_Drawable.h"
#include "C_InstanceID.h"

class Object {
public:

	Object();

	//Awake is called when object created. Use to ensure
	//required components are present
	void Awake();

	//Start is called after Awake method. Use to initialise variables
	void Start();

	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);

	bool isQueuedForRemoval();
	void queueForRemoval();

	std::shared_ptr<C_Transform> transform;
	std::shared_ptr<C_InstanceID> instanceID;

	template <typename T> std::shared_ptr<T> AddComponent() {

		//Check that we don't already have a component of this type
		for (auto& existingComponent : components) {
			//Currently we prevent adding the same component twice
			//This may be something we will change in future.
			if (std::dynamic_pointer_cast<T>(existingComponent)) {
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}

		//The object does not have this component so we create it & add it to our list
		std::shared_ptr<T> newComponent = std::make_shared<T>(this);
		components.push_back(newComponent);

		if (std::dynamic_pointer_cast<C_Drawable>(newComponent)) {
			drawable = std::dynamic_pointer_cast<C_Drawable>(newComponent);
		}

		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent() {

		//Check that we don't already have a component of this type
		for (auto& existingComponent : components) {
			if (std::dynamic_pointer_cast<T>(existingComponent)) {
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}

		return nullptr;
	};

	std::shared_ptr<C_Drawable> GetDrawable();

private:
	std::vector<std::shared_ptr<Component>> components;
	std::shared_ptr<C_Drawable> drawable;
	bool queuedForRemoval;
};

#endif // !Object_h
