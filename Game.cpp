#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;

int game() {
	render();
	SDL_Event event;
	while (1) {
		if (SDL_PollEvent(&event) && event.type == SDL_EVENT_QUIT)
			break;
	}
	return 0;
}