#include "ObjectCollection.h"

void ObjectCollection::Update(float deltaTime) {
	for (auto& o : objects) {
		o->Update(deltaTime);
	}
	collidables.Update();
}

void ObjectCollection::lateUpdate(float deltaTime) {
	for (auto& o : objects) {
		o->LateUpdate(deltaTime);
	}
}

void ObjectCollection::Draw(Window& window) {
	
	drawables.Draw(window);
}

void ObjectCollection::Add(std::shared_ptr<Object> object) {
	newObjects.push_back(object);
}

void ObjectCollection::Add(std::vector<std::shared_ptr<Object>> objects) {
	for(auto& o : objects)
		newObjects.push_back(o);
}

void ObjectCollection::ProcessNewObjects() {
	if (newObjects.size() > 0) {
		for (const auto& o : newObjects) {
			o->Awake();
		}

		for (const auto& o : newObjects) {
			o->Start();
		}

		objects.insert(objects.end(), newObjects.begin(), newObjects.end());

		drawables.Add(newObjects);

		collidables.Add(newObjects);

		newObjects.clear();
	}
}

void ObjectCollection::ProcessRemovals() {

	bool removed = false;
	auto objIterator = objects.begin();
	while (objIterator != objects.end()) {
		auto obj = **objIterator;

		if (obj.isQueuedForRemoval()) {
			objIterator = objects.erase(objIterator);
			removed = true;
		}
		else {
			++objIterator;
		}
	}
	if (removed) {
		drawables.ProcessRemovals();
		collidables.ProcessRemovals();
	}
}