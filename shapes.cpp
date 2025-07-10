#include <iostream>
#include <SDL3/SDL.h>
#include "defs.h"
#include "functions.h"
using namespace std;


int ScreenCoordinateX(int x, int z) {
	return ScreenWidth * x / z + ScreenWidth / 2;
}
int ScreenCoordinateY(int y, int z) {
	return -ScreenHeight * y / z + ScreenHeight / 2;
}

float VectorLength(float x, float y) {
	return sqrt(x * x + y * y);
}
float VectorLength(float x, float y, float z) {
	return sqrt(x * x + y * y + z * z);
}

void vector_draw(float x1, float y1, float x2, float y2) {
	float vector[2] = { (x2 - x1), (y2 - y1) };
	float vector_length = VectorLength(vector[0], vector[1]);
	int steps = (int)(vector_length);
	for (int i = 0; i <= vector_length; i++) {
		float r = 0;
		if (vector_length != 0) {
			r = (float)i / vector_length;
		}
		int x = (int)(x1 + vector[0] * r + 0.5f);
		int y = (int)(y1 + vector[1] * r + 0.5f); // adds 0.5 for proper rounding to avoid gaps
		SDL_RenderPoint(renderer, x, y);
	}
}
void vector_draw3D(float x1, float y1, float z1, float x2, float y2, float z2) {
	float vector[3] = { (x2 - x1), (y2 - y1), (z2 - z1) };
	float vector_length = VectorLength(vector[0], vector[1], vector[2]);
	for (int i = 0; i <= vector_length; i++) {
		float r = i / vector_length;
		float x = x1 + vector[0] * r;
		float y = y1 + vector[1] * r;
		float z = z1 + vector[2] * r;
		SDL_RenderPoint(renderer, ScreenCoordinateX(x, z), ScreenCoordinateY(y, z));
	}
}
void triangle_fill(float x1, float y1, float x2, float y2, float x3, float y3) {
	int VectorAB[2] = { (x2 - x1), (y2 - y1) };
	int VectorAC[2] = { (x3 - x1), (y3 - y1) };
	int VectorBC[2] = { (x3 - x2), (y3 - y2) };
	float maxEdge = max({ VectorLength(VectorAB[0], VectorAB[1]), VectorLength(VectorAC[0], VectorAC[1]), VectorLength(VectorBC[0], VectorBC[1]) });
	int length = max({ (int)(maxEdge), 2 });
	for (int i = 0; i <= length; i++) {
		float r = 0;
		if (length != 0) {
			r = (float)i / length;
		}
		float VX1 = x1 + VectorAB[0] * r;
		float VY1 = y1 + VectorAB[1] * r;
		float VX2 = x1 + VectorAC[0] * r;
		float VY2 = y1 + VectorAC[1] * r;
		vector_draw(VX1, VY1, VX2, VY2);
	}
}