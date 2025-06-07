#include "vertex.h"

typedef struct triangle {
    vertex2 p1, p2, p3;
} triangle;

void createTriangle(triangle*, const vertex2, const vertex2, const vertex2);
void createTriangleNoVertex(triangle*, const float, const float, const float, const float, const float, const float);
void createCubeVerticies(vertex3*, const vertex3, const vertex3);
void generateTrianglesFromCube(vertex3*, triangle*);
