#include "geometry.h"

// ALL OF THESE FOLLOWING FUNCS ARE TEMPORARY!!!!!

// List (array) should have 8 members (list[8])
void p_createCubeVerticies(p_vec3* list, p_vec3 lower, p_vec3 upper) {
    p_vec3 diff;
    p_createVec3(&diff, upper.x - lower.x, upper.y - lower.y, upper.z - lower.z);

    p_createVec3(&(list[0]), lower.x, lower.y, lower.z);
    p_createVec3(&(list[1]), lower.x, lower.y, lower.z + diff.z);
    p_createVec3(&(list[2]), lower.x + diff.x, lower.y, lower.z + diff.z);
    p_createVec3(&(list[3]), lower.x + diff.x, lower.y, lower.z);
    p_createVec3(&(list[4]), lower.x, upper.y, lower.z);
    p_createVec3(&(list[5]), lower.x, upper.y, lower.z + diff.z);
    p_createVec3(&(list[6]), upper.x, upper.y, upper.z);
    p_createVec3(&(list[7]), lower.x + diff.x, upper.y, lower.z);
}

// Assumes all the verticies have been transformed into 2d space
// OutList should have 12 members (outList[12])
void p_generateTrianglesFromCube(p_vec3* cubeList, p_triangle* outList) {
    // Might be the most unreadable code of all time... (dw this is only for testing and is temporary)
    p_createTriangleNoVec(&(outList[0]), cubeList[0].x, cubeList[0].y, cubeList[1].x, cubeList[1].y, cubeList[2].x, cubeList[2].y);
    p_createTriangleNoVec(&(outList[1]), cubeList[2].x, cubeList[2].y, cubeList[3].x, cubeList[3].y, cubeList[0].x, cubeList[0].y);
    p_createTriangleNoVec(&(outList[2]), cubeList[4].x, cubeList[4].y, cubeList[5].x, cubeList[5].y, cubeList[6].x, cubeList[6].y);
    p_createTriangleNoVec(&(outList[3]), cubeList[6].x, cubeList[6].y, cubeList[7].x, cubeList[7].y, cubeList[4].x, cubeList[4].y);
    p_createTriangleNoVec(&(outList[4]), cubeList[0].x, cubeList[0].y, cubeList[1].x, cubeList[1].y, cubeList[5].x, cubeList[5].y);
    p_createTriangleNoVec(&(outList[5]), cubeList[5].x, cubeList[5].y, cubeList[4].x, cubeList[4].y, cubeList[0].x, cubeList[0].y);
    p_createTriangleNoVec(&(outList[6]), cubeList[1].x, cubeList[1].y, cubeList[2].x, cubeList[2].y, cubeList[6].x, cubeList[6].y);
    p_createTriangleNoVec(&(outList[7]), cubeList[6].x, cubeList[6].y, cubeList[5].x, cubeList[5].y, cubeList[1].x, cubeList[1].y);
    p_createTriangleNoVec(&(outList[8]), cubeList[2].x, cubeList[2].y, cubeList[3].x, cubeList[3].y, cubeList[7].x, cubeList[7].y);
    p_createTriangleNoVec(&(outList[9]), cubeList[7].x, cubeList[7].y, cubeList[6].x, cubeList[6].y, cubeList[2].x, cubeList[2].y);
    p_createTriangleNoVec(&(outList[10]), cubeList[3].x, cubeList[3].y, cubeList[0].x, cubeList[0].y, cubeList[4].x, cubeList[4].y);
    p_createTriangleNoVec(&(outList[11]), cubeList[4].x, cubeList[4].y, cubeList[7].x, cubeList[7].y, cubeList[3].x, cubeList[3].y);
}
