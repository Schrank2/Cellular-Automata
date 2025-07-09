#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;

int game() {
	SDL_Event event;
	int StartTime = SDL_GetTicks();
	int CurrentTime = SDL_GetTicks() - StartTime;
	while (1) {
		CurrentTime = SDL_GetTicks()-StartTime;
		render();
		if (SDL_PollEvent(&event) && event.type == SDL_EVENT_QUIT)
			break;
	}
	return 0;
}