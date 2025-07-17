typedef struct p_vec2 {
    float x, y;
} p_vec2;

void p_createVec2(p_vec2*, float, float);

typedef struct p_vec3 {
    float x, y, z; // The y component is the vertical one, not z
} p_vec3;

void p_createVec3(p_vec3*, float, float, float);
