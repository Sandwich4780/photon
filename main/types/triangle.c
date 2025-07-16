#include "triangle.h"

void createTriangle(triangle* out, const vertex2 p1In, const vertex2 p2In, const vertex2 p3In) {
    out->p1 = p1In;
    out->p2 = p2In;
    out->p3 = p3In;
}

// Triangle without neededing vertex2 inputs
void createTriangleNoVertex(triangle* out, const float p1X, const float p1Y, const float p2X, const float p2Y, const float p3X, const float p3Y) {
    createVertex2(&(out->p1), p1X, p1Y);
    createVertex2(&(out->p2), p2X, p2Y);
    createVertex2(&(out->p3), p3X, p3Y);
}

// ALL OF THESE FOLLOWING FUNCS ARE TEMPORARY!!!!!

// List (array) should have 8 members (list[8])
void createCubeVerticies(vertex3* list, const vertex3 lower, const vertex3 upper) {
    vertex3 diff;
    createVertex3(&diff, upper.x - lower.x, upper.y - lower.y, upper.z - lower.z);

    createVertex3(&(list[0]), lower.x, lower.y, lower.z);
    createVertex3(&(list[1]), lower.x, lower.y, lower.z + diff.z);
    createVertex3(&(list[2]), lower.x + diff.x, lower.y, lower.z + diff.z);
    createVertex3(&(list[3]), lower.x + diff.x, lower.y, lower.z);
    createVertex3(&(list[4]), lower.x, upper.y, lower.z);
    createVertex3(&(list[5]), lower.x, upper.y, lower.z + diff.z);
    createVertex3(&(list[6]), upper.x, upper.y, upper.z);
    createVertex3(&(list[7]), lower.x + diff.x, upper.y, lower.z);
}

// Assumes all the verticies have been transformed into 2d space
// OutList should have 12 members (outList[12])
void generateTrianglesFromCube(vertex3* cubeList, triangle* outList) {
    // Might be the most unreadable code of all time... (dw this is only for testing and is temporary)
    createTriangleNoVertex(&(outList[0]), cubeList[0].x, cubeList[0].y, cubeList[1].x, cubeList[1].y, cubeList[2].x, cubeList[2].y);
    createTriangleNoVertex(&(outList[1]), cubeList[2].x, cubeList[2].y, cubeList[3].x, cubeList[3].y, cubeList[0].x, cubeList[0].y);
    createTriangleNoVertex(&(outList[2]), cubeList[4].x, cubeList[4].y, cubeList[5].x, cubeList[5].y, cubeList[6].x, cubeList[6].y);
    createTriangleNoVertex(&(outList[3]), cubeList[6].x, cubeList[6].y, cubeList[7].x, cubeList[7].y, cubeList[4].x, cubeList[4].y);
    createTriangleNoVertex(&(outList[4]), cubeList[0].x, cubeList[0].y, cubeList[1].x, cubeList[1].y, cubeList[5].x, cubeList[5].y);
    createTriangleNoVertex(&(outList[5]), cubeList[5].x, cubeList[5].y, cubeList[4].x, cubeList[4].y, cubeList[0].x, cubeList[0].y);
    createTriangleNoVertex(&(outList[6]), cubeList[1].x, cubeList[1].y, cubeList[2].x, cubeList[2].y, cubeList[6].x, cubeList[6].y);
    createTriangleNoVertex(&(outList[7]), cubeList[6].x, cubeList[6].y, cubeList[5].x, cubeList[5].y, cubeList[1].x, cubeList[1].y);
    createTriangleNoVertex(&(outList[8]), cubeList[2].x, cubeList[2].y, cubeList[3].x, cubeList[3].y, cubeList[7].x, cubeList[7].y);
    createTriangleNoVertex(&(outList[9]), cubeList[7].x, cubeList[7].y, cubeList[6].x, cubeList[6].y, cubeList[2].x, cubeList[2].y);
    createTriangleNoVertex(&(outList[10]), cubeList[3].x, cubeList[3].y, cubeList[0].x, cubeList[0].y, cubeList[4].x, cubeList[4].y);
    createTriangleNoVertex(&(outList[11]), cubeList[4].x, cubeList[4].y, cubeList[7].x, cubeList[7].y, cubeList[3].x, cubeList[3].y);
}
