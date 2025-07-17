#include "triangle.h"

void p_createTriangle(p_triangle* out, p_vec2 p1In, p_vec2 p2In, p_vec2 p3In) {
    out->p1 = p1In;
    out->p2 = p2In;
    out->p3 = p3In;
}

// Triangle without neededing p_vec2 inputs. It makes testing easier
void p_createTriangleNoVec(p_triangle* out, float p1X, float p1Y, float p2X, float p2Y, float p3X, float p3Y) {
    p_createVec2(&(out->p1), p1X, p1Y);
    p_createVec2(&(out->p2), p2X, p2Y);
    p_createVec2(&(out->p3), p3X, p3Y);
}
