#include <SDL3/SDL.h>
#ifndef COMMON_H
#define COMMON_H
extern int ScreenHeight;
extern int ScreenWidth;
extern int CurrentTime;
extern int StartTime;
extern int LastTime;
extern int Toggle;
extern int CameraX;
extern int CameraY;
extern int CameraZ;
extern int GameScale;
extern int GameWidth;
extern int GameHeight;
extern float ThreadUsage;
extern int ThreadCount;
extern int ThreadCountUsed;
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Event event;
extern SDL_Texture* cellTexture;
#endif