typedef struct vertex2 {
    float x, y;
} vertex2;

void createVertex2(vertex2*, const float, const float);

typedef struct vertex3 {
    float x, y, z; // The y component is the vertical one, not z
} vertex3;

void createVertex3(vertex3*, const float, const float, const float);
