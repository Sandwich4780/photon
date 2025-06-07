#include "vertex.h"

void createVertex2(vertex2* out, const float xIn, const float yIn) {
    out->x = xIn;
    out->y = yIn;
}

void createVertex3(vertex3* out, const float xIn, const float yIn, const float zIn) {
    out->x = xIn;
    out->y = yIn;
    out->z = zIn;
}
