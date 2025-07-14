#include <iostream>
#include <SDL3/SDL.h>
#include "functions.h"
#include "defs.h"
#include <thread>
using namespace std;
string settings = readSettings();
int GameScale; // The Dimensions of each tile in pixels
float mapDensity; // The density of Cells in the beginning in 0.0 -> 1.0
int ScreenWidth; // The width of the game window in pixels
int ScreenHeight; // The height of the game window in pixels
float ThreadCountUsage; // The percentage of CPU threads to use for the game
int TickTime; // Time between game ticks in milliseconds
int ThreadCount = thread::hardware_concurrency();
int ThreadCountUsed; // Number of threads used
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[])
{
	ThreadCountUsed = ThreadCount * ThreadCountUsage;
	if (SDL_Init( SDL_INIT_VIDEO or SDL_INIT_AUDIO) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded! \n";
	}
	window = SDL_CreateWindow("CELLULAR AUTOMATA", ScreenWidth, ScreenHeight, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, nullptr);;
	cout << "Available Threads: " << ThreadCount << "   Using " << ThreadCountUsed << " Threads" << endl;
	game();
	cin.get();
	return 0;
}

