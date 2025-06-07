#include <stdio.h>
#include "main/drawing/main_renderer.h"

#define DEFAULT_WINDOW_WIDTH 500
#define DEFAULT_WINDOW_HEIGHT 500

#define MAX_FPS 50
#define MS_PER_FRAME (1000 / MAX_FPS) // This loses some precision so the fps won't be exactly what MAX_FPS is, unless 1000 / MAX_FPS is a whole number

void shutdownPhoton(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    // Initialize
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Photon", SDL_WINDOWPOS_UNDEFINED_MASK, SDL_WINDOWPOS_UNDEFINED_MASK, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN); // Vulkan my beloved <3
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    if (!window || !renderer) {
        printf("Failed\n");
        return 1;
    }

    SDL_SetWindowMinimumSize(window, 200, 200);
    Uint64 timeLog = 0;
    int windowWidth = DEFAULT_WINDOW_WIDTH;
    int windowHeight = DEFAULT_WINDOW_HEIGHT;

    while (1) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                shutdownPhoton(texture, renderer, window);
                return 0;
            case SDL_WINDOWEVENT: // Whenever the window is resized, we gotta create a new texture w the new size
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    windowWidth = event.window.data1;
                    windowHeight = event.window.data2;

                    SDL_DestroyTexture(texture);
                    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, event.window.data1, event.window.data2);
                    break;
                }
            default:
                break;
            }
        }

        updateScreen(renderer, texture, windowWidth, windowHeight); // Main drawing func!!!!!

        // Clunky fps limiter
        if (SDL_GetTicks64() - timeLog < MS_PER_FRAME)
            SDL_Delay(MS_PER_FRAME - (SDL_GetTicks64() - timeLog));

        // Print fps into the console
        //if (SDL_GetTicks64() - timeLog > 0)
            //printf("FPS: %d\n", (1000.f / (SDL_GetTicks64() - timeLog)));

        timeLog = SDL_GetTicks64();
    }

    shutdownPhoton(texture, renderer, window);
    return 0;
}
