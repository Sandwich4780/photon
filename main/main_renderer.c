#include "main_renderer.h"
#include <stdio.h>

void p_updateScreen(SDL_Renderer* renderer, SDL_Texture* texture, int windowWidth, int windowHeight) {
    if (!renderer || !texture)
        return;

    void* buffer;
    int pitch; // Not needed anymore

    SDL_LockTexture(texture, NULL, &buffer, &pitch);

    Uint32* pixels = (Uint32*)buffer;

    if (!pixels)
        return;

    // DRAW PIXELS HERE

    float fFar = 1000.f;
    float fNear = 0.1f;
    float fov = 90.f;
    float aspectRatio = (float)windowHeight / (float)windowWidth;
    float fovFactor = 1.f / tanf((fov * P_PI) / 360.f);
    float scaleFactor = fFar / (fFar - fNear);

    p_matrix4x4 matr;
    matr.mat[0] = aspectRatio * fovFactor;
    matr.mat[5] = fovFactor;
    matr.mat[10] = scaleFactor;
    matr.mat[11] = -fNear * scaleFactor;
    matr.mat[14] = 1.f;

    // TODO: Redo how points are converted to screen space. I wanna have all the calcs done with 3d triangles and then convert them to 2d and just draw them

    p_vec3 lookVec;
    p_createVec3(&lookVec, cosf(P_PI / 2.f), 0.f, sinf(P_PI / 2.f)); // TODO: add a few more trig funcs to this to allow for future camera rotation from the user

    p_vec3 lower;
    p_createVec3(&lower, -1.f, -1.f, 2.f);
    p_vec3 upper;
    p_createVec3(&upper, -0.5f, -0.5f, 2.5f);

    p_vec3 vertexList[8];
    p_createCubeVerticies(vertexList, lower, upper);

    p_triangle3d triangles[12];
    p_generateTrianglesFromCube(vertexList, triangles);

    for (int i = 0; i < 12; i++) {
        p_triangle3d tri;
        p_findNormal3d(&(triangles[i]));// Normals should be pre-computed in the model

        // This code sucks but it's just for testing so it should be ok
        if (p_backfaceTest(lookVec, triangles[i].normal)) {
            p_vec3 a;
            p_vec3 b;
            p_vec3 c;

            p_pointPerspectiveTransform(triangles[i].p1, &a, &matr, windowWidth, windowHeight);
            p_pointPerspectiveTransform(triangles[i].p2, &b, &matr, windowWidth, windowHeight);
            p_pointPerspectiveTransform(triangles[i].p3, &c, &matr, windowWidth, windowHeight);

            p_triangle tri2d;
            p_createTriangleNoVec(&tri2d, a.x, a.y, b.x, b.y, c.x, c.y);

            p_rasterizeTriangle(pixels, windowWidth, windowHeight, &tri2d, 255, 255, 255, 255);
            p_drawTriangle(pixels, windowWidth, windowHeight, &tri2d, 255, 100, 255, 255);
        }
    }

    SDL_UnlockTexture(texture);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
