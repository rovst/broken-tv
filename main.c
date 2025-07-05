//
// Created by admin on 5/07/25.
//

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

//USE I3
void print_random_data(SDL_Surface *surface) {
/*
    int bytesPerPixel = surface->format->BytesPerPixel;
    printf(("bytes per pixel: %d\n"), bytesPerPixel);
*/


    int num_pixel= surface -> w*surface->h;
    Uint32 *pixels = (Uint32 *) surface-> pixels;

    for (int i =0; i<num_pixel; i++) {
        pixels[i]=(Uint32) rand();
    }
}
int main(){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window =SDL_CreateWindow("My broken tv", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700,0);

    SDL_Surface *surface=SDL_GetWindowSurface(window);

    SDL_Event event;
    bool running =true;

    while (running==1) {

        while (SDL_PollEvent(&event)) {
            if (event.type==SDL_QUIT) {
                running=false;
            }
        }

        print_random_data(surface);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(1);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;

}