#include "geometry.h"

// Essentially converts 3d verticies into 2d points; this could prob be far more optimized but I'm just implementing it so it exists
// Ignore the z component (it's there cuz I'm still learning stuff yk)
// TODO: Add a function which converts 3d triangles into 2d ones to make thing easier
void p_pointPerspectiveTransform(p_vec3 in, p_vec3* out, p_matrix4x4* matrix, int windowWidth, int windowHeight) {
    out->x = in.x * matrix->mat[0];
    out->y = in.y * matrix->mat[5];
    out->z = in.z * matrix->mat[10] + matrix->mat[11];
    float w = in.z * matrix->mat[14];

    // Divides by the depth (futher objects become smaller than closer ones)
    if (w != 0) {
        out->x /= w;
        out->y /= w;
        out->z /= w;
    }

    // Gives an output (per coordinate) between -1 and 1, so we change it to between 0 and 2
    out->x += 1;
    out->y += 1;

    // Now convert to actual screen coords
    out->x *= (float)windowWidth / 2.f;
    out->y *= (float)windowHeight / 2.f;
    out->y = (float)windowHeight - out->y; // Y is flipped for some reason
}

// Allows for backface culling and other optimizations
// False means the normal is facing away from us and true means the opposite
bool p_backfaceTest(p_vec3 cameraLookVec, p_vec3 normalVec) {
    float dotProduct = cameraLookVec.x * normalVec.x + cameraLookVec.y * normalVec.y + cameraLookVec.z * normalVec.z;
    if (dotProduct < 0) // A few polygons will slip past this check, but if we stop that then some visible polygons will be blocked as well so I'm just leaving it
        return false;

    return true;
}

// ALL OF THESE FOLLOWING FUNCS ARE TEMPORARY!!!!!

// List (array) should have 8 members (list[8])
void p_createCubeVerticies(p_vec3* list, p_vec3 lower, p_vec3 upper) {
    p_createVec3(&(list[0]), lower.x, lower.y, lower.z);
    p_createVec3(&(list[1]), upper.x, lower.y, lower.z);
    p_createVec3(&(list[2]), upper.x, lower.y, upper.z);
    p_createVec3(&(list[3]), lower.x, lower.y, upper.z);
    p_createVec3(&(list[4]), lower.x, upper.y, lower.z);
    p_createVec3(&(list[5]), upper.x, upper.y, lower.z);
    p_createVec3(&(list[6]), upper.x, upper.y, upper.z);
    p_createVec3(&(list[7]), lower.x, upper.y, upper.z);
}

// OutList should have 12 members (outList[12])
void p_generateTrianglesFromCube(p_vec3* cubeList, p_triangle3d* outList) {
    // Might be the most unreadable code of all time... (dw this is only for testing and is temporary)
    p_createTriangle3d(&(outList[0]), cubeList[0], cubeList[1], cubeList[5]);
    p_createTriangle3d(&(outList[1]), cubeList[0], cubeList[5], cubeList[4]);
    p_createTriangle3d(&(outList[2]), cubeList[1], cubeList[2], cubeList[6]);
    p_createTriangle3d(&(outList[3]), cubeList[1], cubeList[6], cubeList[5]);
    p_createTriangle3d(&(outList[4]), cubeList[2], cubeList[3], cubeList[7]);
    p_createTriangle3d(&(outList[5]), cubeList[2], cubeList[7], cubeList[6]);
    p_createTriangle3d(&(outList[6]), cubeList[3], cubeList[0], cubeList[4]);
    p_createTriangle3d(&(outList[7]), cubeList[3], cubeList[4], cubeList[7]);
    p_createTriangle3d(&(outList[8]), cubeList[1], cubeList[0], cubeList[3]);
    p_createTriangle3d(&(outList[9]), cubeList[1], cubeList[3], cubeList[2]);
    p_createTriangle3d(&(outList[10]), cubeList[6], cubeList[7], cubeList[4]);
    p_createTriangle3d(&(outList[11]), cubeList[6], cubeList[4], cubeList[5]);
}
