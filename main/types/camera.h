#include "vertex.h"
//#include "matrix.h"

typedef struct camera {
    vertex3 position;
    float pitch, yaw; // All angles will be measured in radians btw
    float fov;
    float zNearPlane;
    float zFarPlane;
} camera;
