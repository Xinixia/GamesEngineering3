#pragma once

#include <memory>
#include <vector>

#include "C_BoxCollider.h"
#include "Object.h"
#include "Debug.h"

class Quadtree {
public:
	Quadtree();
	Quadtree(int maxObjects, int maxLevels, int level, sf::FloatRect bounds, Quadtree* parent);

	//Inserts object into quadtree
	void Insert(std::shared_ptr<C_BoxCollider> object);

	//Removes object from quadtree
	void Remove(std::shared_ptr<C_BoxCollider> object);

	//Removes all objects from tree
	void Clear();

	//Returns vector of colliders that intersect with the search area
	std::vector<std::shared_ptr<C_BoxCollider>> Search(const sf::FloatRect& area);

	//Returns the bounds of this node
	const sf::FloatRect& GetBounds() const;

	void DrawDebug();

private:
	void Search(const sf::FloatRect& area, std::vector<std::shared_ptr<C_BoxCollider>>& overlappingObjects);

	//Returns the index for the node that will contain
	//the object. -1 is returned if it is this node.
	int GetChildIndexForObject(const sf::FloatRect& objectBounds);

	//Creates the child nodes
	void Split();

	//Indices for array of children
	static const int thisTree = -1;
	static const int childNE = 0;
	static const int childNW = 1;
	static const int childSW = 2;
	static const int childSE = 3;

	int maxObjects;
	int maxLevels;

	//Nullptr is this is the base node
	Quadtree* parent;
	std::shared_ptr<Quadtree> children[4];

	//Stores objects in this nodee
	std::vector<std::shared_ptr<C_BoxCollider>> objects;

	//How deep the current node is from the base node
	//The first node starts at 0 & then its child node
	//is at level 1 & so on.
	int level;

	//The bounds of this node
	sf::FloatRect bounds;
};