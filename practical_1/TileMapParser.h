#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

#include "rapidxml.h"
#include "rapidxml_utils.h"
#include "rapidxml_iterators.h"
#include "Tile.h"
#include "Utilities.h"
#include "Object.h"
#include "C_Sprite.h"
#include "C_BoxCollider.h"

using namespace rapidxml;

struct TileSheetData {

	int textureId; //The id of the tile sets texture
	sf::Vector2u imageSize; //The size of the texture
	int columns; //How many columns in the tile sheet
	int rows; //How many rows in the tile sheet
	sf::Vector2u tileSize; //The size of a tile
};

struct Layer {
	std::vector<std::shared_ptr<Tile>> tiles;
	bool isVisible;
};

//stores layer names with layer
using MapTiles = std::map<std::string, std::shared_ptr<Layer>>;

//stores the different tile types that can be used
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;

using TileSheets = std::map<int, std::shared_ptr<TileSheetData>>;

class TileMapParser {
public:
	TileMapParser(ResourceAllocator<sf::Texture>& textureAllocator);

	std::vector<std::shared_ptr<Object>> Parse(const std::string& file, sf::Vector2i offset);

private:
	std::shared_ptr<TileSheets> BuildTileSheetData(xml_node<>* rootNode);
	std::shared_ptr<MapTiles> BuildMapTiles(xml_node<>* rootNode);
	std::pair<std::string, std::shared_ptr<Layer>>
		BuildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheets> tileSheets);
	ResourceAllocator<sf::Texture>& textureAllocator;
};