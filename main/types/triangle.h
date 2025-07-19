#include "vertex.h"

typedef struct p_triangle {
    p_vec2 p1, p2, p3;
} p_triangle;

void p_createTriangle(p_triangle*, p_vec2, p_vec2, p_vec2);
void p_createTriangleNoVec(p_triangle*, float, float, float, float, float, float);

typedef struct p_triangle3d {
    p_vec3 p1, p2, p3, normal;
} p_triangle3d;

void p_createTriangle3d(p_triangle3d*, p_vec3, p_vec3, p_vec3);
void p_findNormal3d(p_triangle3d*);
