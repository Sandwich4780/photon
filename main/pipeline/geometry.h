#include "../types/triangle.h"
#include "../types/matrix.h"

void p_pointPerspectiveTransform(p_vec3, p_vec3*, p_matrix4x4*, int, int);
bool p_backfaceTest(p_vec3, p_vec3);
void p_createCubeVerticies(p_vec3*, p_vec3, p_vec3);
void p_generateTrianglesFromCube(p_vec3*, p_triangle3d*);
