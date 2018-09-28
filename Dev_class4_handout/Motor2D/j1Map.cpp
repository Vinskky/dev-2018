#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)
	p2List_item<Tileset*>* item = map.tileset_list.start;

	while (item != NULL)
	{
		App->render->Blit(item->data->texture, 0, 0);
		item = item->next;
	}
}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");
	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map
	p2List_item<Tileset*>* item;
	item = map.tileset_list.start;
	
	if (item != NULL)
	{
		RELEASE(item);
		item = item->next;
	}

	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data
		ret = LoadMap();
	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	pugi::xml_node tileset;

	for (tileset = map_file.child("map").child("tileset"); tileset && ret; tileset = tileset.next_sibling("tileset"))
	{
		Tileset* set = new Tileset();
		if (ret == true)
		{
			ret = LoadSpecificTileset(tileset, set);
		}
		map.tileset_list.add(set);
	}


	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything

		LOG("Successfully parsed map XML file: %s", file_name);
		LOG("width: %d height: %d", map.width, map.height);
		LOG("tile_width: %s tile_height: %d", map.tilewidth, map.tileheight);
		p2List_item<Tileset*>* item = map.tileset_list.start;
		while (item != NULL)
		{
			LOG("Tileset ----");
			LOG("name: %s firstgid:%d", item->data->name.GetString(), item->data->firstgid);
			LOG("tile_width: %d tile_height %d", item->data->tilewidth, item->data->tileheight);
			LOG("spacing: %d margin: %d", item->data->spacing, item->data->margin);
			item = item->next;
		}
	}

	map_loaded = ret;

	return ret;
}

bool j1Map::LoadMap()
{
	bool ret = true;

	pugi::xml_node map_node = map_file.child("map");

	if (map_node == NULL)
	{
		LOG("node map not found");
		ret = false;
	}
	else
	{
		map.height = map_node.attribute("height").as_int();
		map.width = map_node.attribute("width").as_int();
		map.tileheight = map_node.attribute("tileheight").as_int();
		map.tilewidth = map_node.attribute("tilewidht").as_int();
		map.nextobjectid = map_node.attribute("nextobjectid").as_int();

		p2SString map_type(map_node.attribute("orientation").as_string());
		
		if (map_type == "orthogonal")
		{
			map.renderorder = ORTHOGONAL;
		}
		else if (map_type == "isometric")
		{
			map.renderorder = ISOMETRIC;
		}

		p2SString orientation(map_node.attribute("renderorder").as_string());

		if (orientation == "left_up")
		{
			map.map_orientation = LEFT_UP;
		}
		else if (orientation == "left_down")
		{
			map.map_orientation = LEFT_DOWN;
		}
		else if (orientation == "right_up")
		{
			map.map_orientation = RIGHT_UP;
		}
		else if (orientation == "right_down")
		{
			map.map_orientation = RIGHT_DOWN;
		}
	}

	return ret;
}

bool j1Map::LoadSpecificTileset(pugi::xml_node & node_tileset, Tileset * set)
{
	bool ret = true;
	
	set->name.create(node_tileset.attribute("name").as_string());
	set->firstgid = node_tileset.attribute("firstgid").as_int();
	set->margin = node_tileset.attribute("margin").as_int();
	set->spacing = node_tileset.attribute("spacing").as_int();
	set->tileheight = node_tileset.attribute("tileheight").as_int();
	set->tilewidth = node_tileset.attribute("tilewidth").as_int();

	p2SString image = "maps/";
	image += node_tileset.child("image").attribute("source").as_string();
	set->texture = App->tex->Load(image.GetString());
	LOG("image loaded from XML: %s", image.GetString());
	return ret;
}
