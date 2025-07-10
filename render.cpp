#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "defs.h"
#include "functions.h"
using namespace std;
int Toggle=0;

void render(const std::vector<std::vector<int>>& GameMap) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // Clear the screen with white color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i=0; i < ScreenWidth; i++) {
		for (int j = 0; j < ScreenHeight; j++) {
			if (GameMap[i][j] == 1) {
				SDL_RenderPoint(renderer, i, j);
			}
		}
	}
	SDL_RenderPresent(renderer);
}
