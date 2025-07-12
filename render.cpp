#include <iostream>
#include <SDL3/SDL.h>
#include <vector>
#include "defs.h"
#include "functions.h"
using namespace std;
int Toggle=0;
int temp = 0;
SDL_FRect rect;

SDL_Texture* genCellTexture() { // Lots of Help from Copilot
	// Setup the Texture
	SDL_Texture* Texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_TARGET,
		GameScale + 1,
		GameScale + 1
	);
	// Check if successful
	if (!cellTexture) {
		std::cerr << "Failed to create cell texture: " << SDL_GetError() << std::endl;
		return nullptr;
	}
	// Save current render target
	SDL_Texture* prevTarget = SDL_GetRenderTarget(renderer);
	// Clear the texture
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	for (int l = 0; l <= GameScale; l++) {
		for (int m = 0; m <= GameScale; m++) {
			temp = 100 + (40 * m / GameScale) + (40 * l / GameScale);
			SDL_SetRenderDrawColor(renderer, 0, temp, 0, 255);
			SDL_RenderPoint(renderer, l, m);
		}
	}
	// Reset render target
	SDL_SetRenderTarget(renderer, prevTarget);
	return Texture;
}

void render(const std::vector<std::vector<int>>& GameMap) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // Clear the screen with white color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i=0; i < GameWidth; i++) {
		for (int j = 0; j < GameHeight; j++) {
			if (GameMap[i][j] == 1) { 
				rect = { static_cast<float>(i), static_cast<float>(j), static_cast<float>(GameWidth), static_cast<float>(GameHeight)};
				SDL_RenderTexture(renderer, cellTexture, nullptr, &rect);
			}
		}
	}
	SDL_RenderPresent(renderer);
}
