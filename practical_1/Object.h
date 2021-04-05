#ifndef Object_h
#define Object_h

#include <vector>

#include "Component.h"
#include "Window.h"

class Object {
public:
	//Awake is called when object created. Use to ensure
	//required components are present
	void Awake();

	//Start is called after Awake method. Use to initialise variables
	void Start();

	void Update(float deltaTime);
	void LateUpdate(float deltaTime);
	void Draw(Window& window);

	template <typename T> std::shared_ptr<T> AddComponent() {
		//This ensures that we only try to add a class that derives from Component.
		//This is tested at compile time.
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

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

		return newComponent;
	};

	template <typename T> std::shared_ptr<T> GetComponent() {
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		//Check that we don't already have a component of this type
		for (auto& existingComponent : components) {
			if (std::dynamic_pointer_cast<T>(existingComponent)) {
				return std::dynamic_pointer_cast<T>(existingComponent);
			}
		}

		return nullptr;
	};

private:
	std::vector<std::shared_ptr<Component>> components;
};

#endif // !Object_h
