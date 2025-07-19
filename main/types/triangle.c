#include "triangle.h"

void p_createTriangle(p_triangle* out, p_vec2 p1In, p_vec2 p2In, p_vec2 p3In) {
    out->p1.x = p1In.x;
    out->p1.y = p1In.y;

    out->p2.x = p2In.x;
    out->p2.y = p2In.y;

    out->p3.x = p3In.x;
    out->p3.y = p3In.y;
}

// Triangle without neededing p_vec2 inputs. It makes testing easier
void p_createTriangleNoVec(p_triangle* out, float p1X, float p1Y, float p2X, float p2Y, float p3X, float p3Y) {
    p_createVec2(&(out->p1), p1X, p1Y);
    p_createVec2(&(out->p2), p2X, p2Y);
    p_createVec2(&(out->p3), p3X, p3Y);
}

void p_createTriangle3d(p_triangle3d* out, p_vec3 p1In, p_vec3 p2In, p_vec3 p3In) {
    out->p1.x = p1In.x;
    out->p1.y = p1In.y;
    out->p1.z = p1In.z;

    out->p2.x = p2In.x;
    out->p2.y = p2In.y;
    out->p2.z = p2In.z;

    out->p3.x = p3In.x;
    out->p3.y = p3In.y;
    out->p3.z = p3In.z;
}

// When your triangle's points are in clockwise order (p1->p2->p3), the normal will be facing away
void p_findNormal3d(p_triangle3d* out) {
    // Doing each subtraction twice, maybe change that for better performance later on
    out->normal.x = (out->p2.y - out->p1.y) * (out->p3.z - out->p1.z) - (out->p2.z - out->p1.z) * (out->p3.y - out->p1.y);
    out->normal.y = (out->p2.z - out->p1.z) * (out->p3.x - out->p1.x) - (out->p2.x - out->p1.x) * (out->p3.z - out->p1.z);
    out->normal.z = (out->p2.x - out->p1.x) * (out->p3.y - out->p1.y) - (out->p2.y - out->p1.y) * (out->p3.x - out->p1.x);
}
