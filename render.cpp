#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
using namespace std;

void render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderPoint(renderer, 33, 140);
	for (float i = 0; i < 300; i++) {
		for (float j = 0; j < 300; j++) {
			SDL_RenderPoint(renderer, i, j);
		}
	}
	SDL_RenderPresent(renderer);
}