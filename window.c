#include <SDL2/SDL.h>
#include <stdlib.h>
#include "window.h"

Window *window_create()
{
	Window *window = malloc(sizeof(Window));
	window->window_handle = SDL_CreateWindow("Undead Awakening Launcher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 420, SDL_WINDOW_SHOWN);
	return window;
}

void window_close(Window *window)
{
	free(window);
}

void window_update(Window *window)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				extern volatile int is_running;
				is_running = 0;
				return;
			}
			case SDL_KEYDOWN:
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					extern volatile int is_running;
					is_running = 0;
					return;
				}
			}
			
		}
	}
}
