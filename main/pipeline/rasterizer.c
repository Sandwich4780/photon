#include "rasterizer.h"

// This returns the doubled area of three triangles. DO NOT USE FOR ACTUAL AREA OF POLYGONS!!!
void getTestPolygonArea(int testX, int testY, triangle* tri, int* output) {
    // Shoelace formula :)
    // TODO: Make this do everything with ints later on to speed things up
    *output = abs((testX - tri->p3.x) * (tri->p2.y - testY) - (testX - tri->p2.x) * (tri->p3.y - testY));
    *output += abs((testX - tri->p3.x) * (tri->p1.y - testY) - (testX - tri->p1.x) * (tri->p3.y - testY));
    *output += abs((testX - tri->p1.x) * (tri->p2.y - testY) - (testX - tri->p2.x) * (tri->p1.y - testY));
}

// TODO: Make a version of this to use given textures (not needed for a LONG time tho)
void rasterizeTriangle(Uint32* pixels, const int windowWidth, const int windowHeight, triangle* tri, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    int boundingXMin = windowWidth;
    int boundingYMin = windowHeight;
    int boundingXMax = 0;
    int boundingYMax = 0;

    if (tri->p1.x < boundingXMin) boundingXMin = tri->p1.x;
    if (tri->p1.x > boundingXMax) boundingXMax = tri->p1.x;
    if (tri->p1.y < boundingYMin) boundingYMin = tri->p1.y;
    if (tri->p1.y > boundingYMax) boundingYMax = tri->p1.y;

    if (tri->p2.x < boundingXMin) boundingXMin = tri->p2.x;
    if (tri->p2.x > boundingXMax) boundingXMax = tri->p2.x;
    if (tri->p2.y < boundingYMin) boundingYMin = tri->p2.y;
    if (tri->p2.y > boundingYMax) boundingYMax = tri->p2.y;

    if (tri->p3.x < boundingXMin) boundingXMin = tri->p3.x;
    if (tri->p3.x > boundingXMax) boundingXMax = tri->p3.x;
    if (tri->p3.y < boundingYMin) boundingYMin = tri->p3.y;
    if (tri->p3.y > boundingYMax) boundingYMax = tri->p3.y;

    // TODO: Make this do everything with ints later on to speed things up
    int triangleArea = abs((tri->p1.x - tri->p3.x) * (tri->p2.y - tri->p1.y) - (tri->p1.x - tri->p2.x) * (tri->p3.y - tri->p1.y));
    int testArea;

    for (int x = boundingXMin; x < boundingXMax; x++) {
        if (x < 0 || x > windowWidth)
            continue;

        for (int y = boundingYMin; y < boundingYMax; y++) {
            if (y < 0 || y > windowHeight)
                continue;

            getTestPolygonArea(x, y, tri, &testArea);

            if (testArea <= triangleArea) // Pixel is inside the triangle
                colorPixel(pixels, windowWidth, x, y, r, g, b, a);
        }
    }
}
