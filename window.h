#include <SDL2/SDL.h>

typedef struct
{
	SDL_Window *window_handle;
} Window;

Window *window_create();
void window_close(Window *window);
void window_update(Window *window);
