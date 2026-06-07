#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "../include/png.h"


int main(){
    printf("Hello world!\n");
    int status = test();
    /*
    SDL_Window *pwindow =  SDL_CreateWindow("spx",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    //SDL_FillRect(psurface, NULL, 0xFF00FF);
    int x = 50,y = 50;
    SDL_Rect pixel = {x,y,1,1};
    int r,g,b;
    r = 0xFF;
    g = 0x00;
    b = 0x00;
    int color = SDL_MapRGB(psurface->format,r, g, b);

    for(int h=0;h<600;h++){
        pixel.y = h;
        for(int w=0;w<600;w++){
            pixel.x = w;
            SDL_FillRect(psurface, &pixel, color);
        }
        if (h == 300){
            r = 0x00;
            g = 0xFF;
            color = SDL_MapRGB(psurface->format,r, g, b);
        }
    }
    SDL_FillRect(psurface, &pixel, color);
    SDL_UpdateWindowSurface(pwindow);

    SDL_Delay(2000);
    */
    return 0;
}
