#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;
int StartTime;
int CurrentTime;
int LastTime;
int CameraX = 0;
int CameraY = 0;
int CameraZ = 0;

int game() {
	SDL_Event event;
	int StartTime = SDL_GetTicks();
	int CurrentTime = SDL_GetTicks() - StartTime;
	int LastTime = CurrentTime;
	while (1) {
		CurrentTime = SDL_GetTicks()-StartTime;
		render();
		if (SDL_PollEvent(&event) && event.type == SDL_EVENT_QUIT)
			break;
	}
	return 0;
}