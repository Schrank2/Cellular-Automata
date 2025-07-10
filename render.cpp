#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;
int Toggle=0;

void render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // Clear the screen with white color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	if (LastTime = CurrentTime+100) {
		LastTime = CurrentTime;
		if (Toggle==0) {
			Toggle = 1;
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		} else {
			Toggle = 0;
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		}
		
	}
	triangle_fill(0, 0, 1280, 0, 1280, 720);
	triangle_fill(0, 720, 640, 720, 0, 360);
	SDL_RenderPoint(renderer, 33, 140);
	SDL_RenderPresent(renderer);
}
