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
    float fovFactor = 1.f / tanf((fov * 3.1415927f) / 360.f);
    float scaleFactor = fFar / (fFar - fNear);

    p_matrix4x4 matr;
    matr.mat[0] = aspectRatio * fovFactor;
    matr.mat[5] = fovFactor;
    matr.mat[10] = scaleFactor;
    matr.mat[11] = -fNear * scaleFactor;
    matr.mat[14] = 1.f;

    p_vec3 a;
    p_createVec3(&a, -1.f, -0.5f, 2.f);
    p_vec3 b;
    p_createVec3(&b, 0.f, 0.5f, 3.f);

    p_vec3 vertexList[8];
    p_createCubeVerticies(vertexList, a, b);

    for (int i = 0; i < 8; i++)
        p_perspectiveTransform(vertexList[i], &(vertexList[i]), &matr, windowWidth, windowHeight);

    p_triangle triangleList[12];
    p_generateTrianglesFromCube(vertexList, triangleList);

    for (int i = 0; i < 12; i++) {
        p_drawTriangle(pixels, windowWidth, windowHeight, &(triangleList[i]), 255, 255, 255, 255);
        //p_rasterizeTriangle(pixels, windowWidth, windowHeight, &(triangleList[i]), 255, 255, 255, 255);
    }



    //p_triangle tri;
    //p_createTriangleNoVertex(&tri, 100, 350, 250, 50, 350, 300);

    SDL_UnlockTexture(texture);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}
