#ifndef ResourceAllocator_h
#define ResourceAllocator_h

#include <map>
#include <memory>
#include <string>
#include <iostream>

template<typename T>
class ResourceAllocator {
public:

	int Add(const std::string& filePath) {
		auto it = resources.find(filePath);
		if (it != resources.end()) {
			std::cout << "Shit's broke here too (line 15)" << std::endl;
			return it->second.first;
		}

		std::shared_ptr<T> resource = std::make_shared<T>();
		if (!resource->loadFromFile(filePath)) {
			std::cout << "Shit's broke (line 21)" << std::endl;
			return -1;
		}

		resources.insert(std::make_pair(filePath, std::make_pair(currentId, resource)));
		std::cout << "Oh fuck oh no (line 26)" << std::endl;
		return currentId++;
	}

	void Remove(int id) {
		for (auto it = resources.begin(); it != resources.end(); ++it)
			if (it->second.first == id)
				resources.erase(it->first);
	}

	std::shared_ptr<T> Get(int id) {
		for (auto it = resources.begin(); it != resources.end(); ++it)
			if (it->second.first == id)
				return it->second.second;

		return nullptr;
	}

	bool Has(int id) {
		return (Get(id) != nullptr);
	}

private:
	int currentId;
	std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};



#endif // !ResourceAllocator_h
