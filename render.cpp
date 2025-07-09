#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;
float VectorLength(float x, float y) {
	return sqrt(x*x+y*y);
}

void vector_draw(float x1, float y1, float x2, float y2) {
	float vector[2] = { (x2 - x1), (y2 - y1) };
	float vector_length = VectorLength(vector[0], vector[1]);
	for (int i=0;i<= vector_length; i++) {
		float r = i/vector_length;
		int x = x1 + vector[0] * r;
		int y = y1 + vector[1] * r;
		SDL_RenderPoint(renderer,x,y);
	}
}
void triangle_fill(float x1,float y1, float x2, float y2, float x3, float y3) {
	int VectorAB[2] = {(x2 - x1), (y2 - y1)};
	int VectorAC[2] = {(x3 - x1), (y3 - y1)};
	float VectorAB_length = VectorLength(VectorAB[0], VectorAB[1]);
	float VectorAC_length = VectorLength(VectorAC[0], VectorAC[1]);
	float length = VectorAB_length;
	if (length < VectorAC_length) {
		length = VectorAC_length;
	}
	for (int i=0; i<=length*10;i++) {
		float r = (i/10) / length;
		float VX1 = x1 + VectorAB[0] * r;
		float VY1 = y1 + VectorAB[1] * r;
		float VX2 = x1 + VectorAC[0] * r;
		float VY2 = y1 + VectorAC[1] * r;
		vector_draw(VX1, VY1, VX2, VY2);
	}
}
void render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer); // Clear the screen with white color
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	vector_draw(0, 0, 500, 700); // Draws a line from (i, j) to (150, 150)
	SDL_RenderPoint(renderer, 33, 140);
	triangle_fill(150, 150, 600, 600, 1000, 500); // Draws a triangle
	SDL_RenderPresent(renderer);
}
