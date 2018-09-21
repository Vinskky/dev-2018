#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Window.h"

#include "SDL/include/SDL.h"


j1Window::j1Window() : j1Module()
{
	window = NULL;
	screen_surface = NULL;
	name.create("window");
}

// Destructor
j1Window::~j1Window()
{
}

// Called before render is available
bool j1Window::Awake(pugi::xml_node& config)
{
	LOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		Uint32 flags = SDL_WINDOW_SHOWN;
		bool fullscreen = config.child("fullscreen").attribute("value").as_bool();
		bool borderless = config.child("borderless").attribute("value").as_bool();
		bool resizable = config.child("resizable").attribute("value").as_bool();
		bool fullscreen_window = config.child("fullscreen_window").attribute("value").as_bool();

		width = config.child("width").attribute("value").as_uint();
		height = config.child("height").attribute("value").as_uint();
		scale = config.child("scale").attribute("value").as_uint();
		title = config.child("Title").attribute("win_title").value();

		if(fullscreen)
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}

		if(borderless)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		if(resizable)
		{
			flags |= SDL_WINDOW_RESIZABLE;
		}

		if(fullscreen_window)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		window = SDL_CreateWindow(title.GetString(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);

			// TODO 4: Read the title of the app from the XML
			// and set directly the window title using SetTitle()
			App->win->SetTitle(App->config_node.child("window").child("Title").attribute("win_title").as_string());
		}
	}

	return ret;
}

// Called before quitting
bool j1Window::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems");

	//Destroy window
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

// Set new window title
void j1Window::SetTitle(const char* new_title)
{
	//title.create(new_title);
	SDL_SetWindowTitle(window, new_title);
}

void j1Window::GetWindowSize(uint& width, uint& height) const
{
	width = this->width;
	height = this->height;
}

uint j1Window::GetScale() const
{
	return scale;
}