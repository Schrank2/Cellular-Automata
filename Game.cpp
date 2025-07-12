#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <cstdlib>
#include "defs.h"
#include "functions.h"
#include <thread>
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
int GameScale = 2;
float mapDensity = 5.0f; // Percentage of cells that are alive at the start
int GameTemp = 0;
int TickTime = 0;
int Pause = 0;
float mouseX, mouseY;
int mouseXgame, mouseYgame;
int GameWidth = ScreenWidth / GameScale;
int GameHeight = ScreenHeight / GameScale;
const int neighborOffsets[8][2] = {
	{-1, -1}, {0, -1}, {1, -1},
	{-1,  0},         {1,  0},
	{-1,  1}, {0,  1}, {1,  1}
};
vector<vector<int>> GameMap(GameWidth, vector<int>(GameHeight));
vector<vector<int>> GameMapNext(GameWidth, vector<int>(GameHeight));
static void CellularAutomataRules(int txMin,int txMax,int tyMin, int tyMax) {
	// Cellular Automata do stuff now
	for (int i = txMin; i < txMax; i++) {
		for (int j = tyMin; j < tyMax; j++) {
			survive = 0; neighbors = 0;
			if (GameMap[i][j] == 1) { survive = 1; }
			// Determine Neighbors
			for (int k = 0; k < 8; k++) {
				int ni = i + neighborOffsets[k][0];
				int nj = j + neighborOffsets[k][1];
				if (ni >= 0 && ni < GameWidth && nj >= 0 && nj < GameHeight) {
					if (GameMap[ni][nj] == 1) {
						neighbors++;
					}
				}
			}
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
}



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
			// emptying GameMapNext
			for (auto& row : GameMapNext)
				fill(row.begin(), row.end(), 0);
			// Cellular Automata Logic
			thread thread1(CellularAutomataRules, 0, GameWidth * 0.5, 0, GameHeight * 0.5);
			thread thread2(CellularAutomataRules, GameWidth * 0.5, GameWidth, 0, GameHeight * 0.5);
			thread thread3(CellularAutomataRules, 0, GameWidth * 0.5, GameHeight * 0.5, GameHeight);
			thread thread4(CellularAutomataRules, GameWidth * 0.5, GameWidth, GameHeight * 0.5, GameHeight);
			thread1.join();
			thread2.join();
			thread3.join();
			thread4.join();
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
				GameTemp = !GameTemp;
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