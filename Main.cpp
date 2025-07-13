#include <iostream>
#include <SDL3/SDL.h>
#include "functions.h"
#include "defs.h"
#include <thread>
using namespace std;
int ThreadCount = thread::hardware_concurrency();
int ThreadCountUsed; // Number of threads used
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[])
{
	readSettings();
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

