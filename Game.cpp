#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <cstdlib>
#include "defs.h"
#include "functions.h"
using namespace std;
int StartTime;
int CurrentTime;
int LastTime;
int CameraX = 0;
int CameraY = 0;
int CameraZ = 0;
int neighbors = 0;
int survive = 0;
vector<vector<int>> GameMap(ScreenWidth, vector<int>(ScreenHeight));
vector<vector<int>> GameMapNext(ScreenWidth, vector<int>(ScreenHeight));

int game() {
	SDL_Event event;
	// Setting up the Timer
	int StartTime = SDL_GetTicks();
	int CurrentTime = SDL_GetTicks() - StartTime;
	int LastTime = CurrentTime;
	// Filling the Game Map with random values
	for (int i = 0; i < ScreenWidth; i++) {
		for (int j = 0; j < ScreenHeight; j++) {
			if (rand() % 2 == 0) {
				GameMap[i][j] = 1;
			}
			else {
				GameMap[i][j] = 0;
			}
		}
	}
	// The Game Loop
	while (1) {
		CurrentTime = SDL_GetTicks()-StartTime;
		if (LastTime = CurrentTime + 100) {
			LastTime = CurrentTime;

			// Cellular Automata do stuff now
			for (int i = 0; i < ScreenWidth; i++) {
				for (int j = 0; j < ScreenHeight; j++) {
					survive = 0; neighbors = 0;
					if (GameMap[i][j] == 1) { survive = 1; }
					// Determine Neighbors
					if (i + 1 < ScreenWidth && GameMap[i + 1][j] == 1) { neighbors++; }
					if (i - 1 >= 0 && GameMap[i - 1][j] == 1) { neighbors++; }
					if (j + 1 < ScreenHeight && GameMap[i][j + 1] == 1) { neighbors++; }
					if (j - 1 >= 0 && GameMap[i][j - 1] == 1) { neighbors++; }
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
			GameMap = GameMapNext;
		}
		render(GameMap);
		if (SDL_PollEvent(&event) && event.type == SDL_EVENT_QUIT)
			break;
	}
	// Cleanup
	return 0;
}