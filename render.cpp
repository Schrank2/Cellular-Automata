#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "defs.h"
#include "functions.h"
using namespace std;
int Toggle=0;
int temp = 0;

void render(const std::vector<std::vector<int>>& GameMap) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // Clear the screen with white color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i=0; i < GameMap.size(); i++) {
		for (int j = 0; j < GameMap[0].size(); j++) {
			if (GameMap[i][j] == 1) {
				for (int l=0;l<=GameScale;l++){ 
					for (int m = 0; m <= GameScale; m++) {
						temp = 100+(40*m/GameScale)+ (40 * l / GameScale);
						SDL_SetRenderDrawColor(renderer, 0, temp, 0, 255);
						SDL_RenderPoint(renderer, i * GameScale + l, j * GameScale + m);
					}
				}
			}
		}
	}
	SDL_RenderPresent(renderer);
}
