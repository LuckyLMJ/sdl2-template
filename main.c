#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define WINDOW_TITLE "SDL Game"

SDL_Window* screen = NULL;
SDL_Renderer* renderer;

int screenWidth = 1600;
int screenHeight = 900;

int TARGET_FPS = 60;

int random(int max) {
	return (rand() % max);
}

void init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(screenWidth, screenHeight, SDL_WINDOW_SHOWN, &screen, &renderer);
    SDL_SetWindowTitle(screen, WINDOW_TITLE);
}

void quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
}

void gameLoop() {
    //we can do whatever here.
    int running = TRUE;
    int t = SDL_GetTicks();
    int fps = 0;
    int numFrames = 0;

    int lastFrameStartTime;
    while (running) {
        while (SDL_GetTicks() - lastFrameStartTime < (float)1000/(float)TARGET_FPS) {
            continue;
        }
        lastFrameStartTime = SDL_GetTicks();
        if (lastFrameStartTime - t > 1000) {
            t = lastFrameStartTime;
            fps = numFrames;
            numFrames = 0;
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < 1; i++) {
            //Place a random rectangle somewhere.
            SDL_Rect rect;
            SDL_SetRenderDrawColor(renderer, random(255), random(255), random(255), 255);
            rect.w = random(screenWidth/2) + 20;
            rect.h = random(screenHeight/2) + 20;
            rect.x = random(screenWidth - rect.w);
            rect.y = random(screenHeight - rect.h);
            SDL_RenderFillRect(renderer, &rect);
        }
        //Render the rectangles
        SDL_RenderPresent(renderer);

        char s[50];
        sprintf(s, "%s FPS: %d", WINDOW_TITLE, fps);
        SDL_SetWindowTitle(screen, s);

        int key;

        SDL_Event event;
        SDL_PollEvent(&event);
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
                case SDL_QUIT:
                {
                    running = FALSE;
                    break;
                }
			}
		}
        numFrames++;
    }
}

int main(int argc, char* args[]) {
    init();
    gameLoop();
    quit();

    return 0;
}

