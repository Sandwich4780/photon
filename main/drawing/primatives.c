#include "primatives.h"

// Color values should be from 0 to 255
// TODO: Figure out why alpha isn't changing opacity at all
void p_colorPixel(Uint32* pixels, int windowWidth, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    pixels[y * windowWidth + x] = (Uint32)((a << 24) | (b << 16) | (g << 8) | r); // RGBA32 type used here
}

// Bresenham's line algorithm implementation
void p_drawLine(Uint32* pixels, int windowWidth, int windowHeight, p_vec2 start, p_vec2 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
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
            p_colorPixel(pixels, windowWidth, x, y, r, g, b, a);

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
void p_drawTriangle(Uint32* pixels, int windowWidth, int windowHeight, p_triangle* theTriangle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    p_drawLine(pixels, windowWidth, windowHeight, theTriangle->p1, theTriangle->p2, r, g, b, a);
    p_drawLine(pixels, windowWidth, windowHeight, theTriangle->p2, theTriangle->p3, r, g, b, a);
    p_drawLine(pixels, windowWidth, windowHeight, theTriangle->p3, theTriangle->p1, r, g, b, a);
}
