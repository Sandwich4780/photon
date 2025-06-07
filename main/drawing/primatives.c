#include "primatives.h"

// Color values should be from 0 to 255
void colorPixel(Uint32* pixels, int windowWidth, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    pixels[y * windowWidth + x] = (Uint32)((r << 24) | (g << 16) | (b << 8) | a); // RGBA32 type used here
}

// Bresenham's line algorithm implementation
// TODO: Add a check to stop drawing the line when out of screen bounds
void draw2dLine(Uint32* pixels, const int windowWidth, const int windowHeight, const vertex2 start, const vertex2 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    int x = (int)start.x;
    int y = (int)start.y;
    int ex = (int)end.x;
    int ey = (int)end.y;

    int deltaX = abs(ex - x);
    int deltaY = -abs(ey - y);

    int sx = x < ex ? 1 : -1;
    int sy = y < ey ? 1 : -1;
    int error = deltaX + deltaY;

    while (true) {
        if (x > 0 && x < windowWidth && y > 0 && y < windowHeight) // Make sure the pixel is in bounds
            colorPixel(pixels, windowWidth, x, y, r, g, b, a);

        int error2 = 2 * error;

        if (error2 >= deltaY) {
            if (x == ex)
                break;

            error += deltaY;
            x += sx;
        }

        if (error2 < deltaX) {
            if (y == ey)
                break;

            error += deltaX;
            y += sy;
        }
    }
}

// Passing the exact same params this many times is prob not very optimized...
void draw2dTriangle(Uint32* pixels, const int windowWidth, const int windowHeight, const triangle* theTriangle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    draw2dLine(pixels, windowWidth, windowHeight, theTriangle->p1, theTriangle->p2, r, g, b, a);
    draw2dLine(pixels, windowWidth, windowHeight, theTriangle->p2, theTriangle->p3, r, g, b, a);
    draw2dLine(pixels, windowWidth, windowHeight, theTriangle->p3, theTriangle->p1, r, g, b, a);
}

// Essentially converts 3d verticies into 2d points; this could prob be far more optimized but I'm just implementing it so it exists
// Ignore the z component (it's there cuz I'm still learning stuff yk)
void perspectiveTransform(const vertex3 in, vertex3* out, const p_matrix4x4* matrix, const int windowWidth, const int windowHeight) {
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
