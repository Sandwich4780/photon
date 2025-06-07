#include <SDL2/SDL.h>
#include "../types/triangle.h"
#include "../types/matrix.h"
#include "../math/photon_math.h"

void colorPixel(Uint32*, int, int, int, Uint8, Uint8, Uint8, Uint8);
void draw2dLine(Uint32*, const int, const int, const vertex2, const vertex2, Uint8, Uint8, Uint8, Uint8);
void draw2dTriangle(Uint32*, const int, const int, const triangle*, Uint8, Uint8, Uint8, Uint8);
void perspectiveTransform(const vertex3, vertex3*, const p_matrix4x4*, const int, const int);
