#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <cstdlib>
#include "defs.h"
#include "functions.h"
using namespace std;
SDL_Texture* cellTexture;
int StartTime;
int CurrentTime;
int LastTime;
int CameraX = 0;
int CameraY = 0;
int CameraZ = 0;
int neighbors = 0;
int survive = 0;
int GameScale = 4;
float mapDensity = 5.0f; // Percentage of cells that are alive at the start
int GameTemp = 0;
int TickTime = 0;
int Pause = 0;
float mouseX, mouseY;
int mouseXgame, mouseYgame;
int GameWidth = ScreenWidth / GameScale;
int GameHeight = ScreenHeight / GameScale;
vector<vector<int>> GameMap(GameWidth, vector<int>(GameHeight));
vector<vector<int>> GameMapNext(GameWidth, vector<int>(GameHeight));


int game() {
	SDL_Event event;
	// Setting up the Timer
	int StartTime = SDL_GetTicks();
	int CurrentTime = SDL_GetTicks() - StartTime;
	int LastTime = CurrentTime;
	// Filling the Game Map with random values
	for (int i = 0; i < GameWidth; i++) {
		for (int j = 0; j < GameHeight; j++) {
			if (rand() % 10 > mapDensity) {
				GameMap[i][j] = 1;
			}
			else {
				GameMap[i][j] = 0;
			}
		}
	}
	// Generating the Textures
	cellTexture=genCellTexture();
	// The Game Loop
	while (1) {
		CurrentTime = SDL_GetTicks() - StartTime;
		if (CurrentTime - LastTime >= TickTime && Pause == 0) {
			LastTime = CurrentTime;
			// Cellular Automata do stuff now
			for (int i = 0; i < GameWidth; i++) {
				for (int j = 0; j < GameHeight; j++) {
					survive = 0; neighbors = 0;
					if (GameMap[i][j] == 1) { survive = 1; }
					// Determine Neighbors
					//i+1
					if (i + 1 < GameWidth && GameMap[i + 1][j] == 1) { neighbors++; } // ABOVE
					if (i + 1 < GameWidth && j + 1 < GameHeight && GameMap[i + 1][j + 1] == 1) { neighbors++; } // ABOVE, RIGHT
					if (i + 1 < GameWidth && j - 1 >= 0 && GameMap[i + 1][j - 1] == 1) { neighbors++; } // ABOVE, LEFT
					// i
					if (i - 1 >= 0 && GameMap[i - 1][j] == 1) { neighbors++; } // BELOW
					if (i - 1 >= 0 && j + 1 < GameHeight && GameMap[i - 1][j + 1] == 1) { neighbors++; } // BELOW,RIGHT
					if (i - 1 >= 0 && j - 1 >= 0 && GameMap[i - 1][j - 1] == 1) { neighbors++; } // BELOW,LEFT

					if (j + 1 < GameHeight && GameMap[i][j + 1] == 1) { neighbors++; } // RIGHT
					if (j - 1 >= 0 && GameMap[i][j - 1] == 1) { neighbors++; } // LEFT

					if (neighbors < 2) { survive = 0; }// Underpopulation
					if (neighbors > 3) { survive = 0; }// Overpopulation
					if (neighbors == 3) { survive = 1; } // Reproduction
					if (survive == 1) {
						GameMapNext[i][j] = 1; // Cell survives
					}
					else {
						GameMapNext[i][j] = 0; // Cell dies
					}
				}
			}
			// Apply Changes
			swap(GameMap, GameMapNext); // Basically GameMap = GameMapNext; but Copilot says it's faster lol
		}
		render(GameMap);
		SDL_GetMouseState(&mouseX, &mouseY); // Check mouse position
		if (SDL_PollEvent(&event) && event.type == SDL_EVENT_QUIT)
			break;
		if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				mouseXgame = mouseX / GameScale;
				mouseYgame = mouseY / GameScale;
				if (GameMap[mouseXgame][mouseYgame] == 1) { GameTemp = 0; }
				if (GameMap[mouseXgame][mouseYgame] == 0) { GameTemp = 1; }
				GameMap[mouseXgame][mouseYgame] = GameTemp;
			}
		}
		if (event.type == SDL_EVENT_KEY_DOWN) {
			if (event.key.key == SDLK_SPACE) {
				Pause = !Pause;
			}
		}
	}
	// Cleanup
	return 0;
}