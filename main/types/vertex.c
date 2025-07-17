#include "vertex.h"

void p_createVec2(p_vec2* out, float xIn, float yIn) {
    out->x = xIn;
    out->y = yIn;
}

void p_createVec3(p_vec3* out, float xIn, float yIn, float zIn) {
    out->x = xIn;
    out->y = yIn;
    out->z = zIn;
}
