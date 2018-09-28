#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "p2SString.h"
// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------
struct Tileset
{
	int				firstgid = 0;
	p2SString		name = nullptr;
	int				tilewidth = 0;
	int				tileheight = 0;
	int				spacing = 0;
	int				margin = 0;
	SDL_Texture*	texture = nullptr;
};
enum Orientation
{
	LEFT_UP = 0,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN
};
struct Layer
{
	p2SString		name = nullptr;
	int				width = 0;
	int				height = 0;
};
enum MapType
{
	ISOMETRIC = 0,
	ORTHOGONAL
};
// TODO 1: Create a struct needed to hold the information to Map node
struct MapNode
{
	Orientation				map_orientation;
	MapType					renderorder;
	int						width = 0;
	int						height = 0;
	int						tilewidth = 0;
	int						tileheight = 0;
	int						nextobjectid= 0;
	p2List<Tileset*>		tileset_list;
	p2List<Layer*>			layer_list;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:
	bool LoadMap();
	bool LoadSpecificTileset(pugi::xml_node &node_tileset, Tileset* set);
	bool LoadLayer(pugi::xml_node &node_layer, Layer* set);
public:

	// TODO 1: Add your struct for map info as public for now
	MapNode map;
	
private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__