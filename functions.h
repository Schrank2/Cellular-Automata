#include <vector>
int main(int argc, char* argv[]);
int game();
void render(const std::vector<std::vector<int>>& GameMap);
int ScreenCoordinateX(int x, int z);
int ScreenCoordinateY(int y, int z);
float VectorLength(float x, float y);
float VectorLength(float x, float y, float z);
void vector_draw(float x1, float y1, float x2, float y2);
void vector_draw3D(float x1, float y1, float z1, float x2, float y2, float z2);
void triangle_fill(float x1, float y1, float x2, float y2, float x3, float y3);

