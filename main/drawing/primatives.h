#include <SDL2/SDL.h>
#include "../types/triangle.h"
#include "../types/matrix.h"
#include "../math/photon_math.h"

void p_colorPixel(Uint32*, int, int, int, Uint8, Uint8, Uint8, Uint8);
void p_drawLine(Uint32*, int, int, p_vec2, p_vec2, Uint8, Uint8, Uint8, Uint8);
void p_drawTriangle(Uint32*, int, int, p_triangle*, Uint8, Uint8, Uint8, Uint8);
