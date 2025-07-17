#include "vertex.h"

typedef struct p_triangle {
    p_vec2 p1, p2, p3;
} p_triangle;

void p_createTriangle(p_triangle*, p_vec2, p_vec2, p_vec2);
void p_createTriangleNoVec(p_triangle*, float, float, float, float, float, float);
