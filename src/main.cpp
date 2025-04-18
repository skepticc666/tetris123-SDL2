#define SDL_MAIN_HANDLED

#include <iostream>


#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    int width = 680;
    int height = 480;
    SDL_Window *window = SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
    
    SDL_Renderer *render = SDL_CreateRenderer(window,-1,0);
    
    SDL_Event event;
    bool isrunning = true;


    while(isrunning)
    {
        while(SDL_PollEvent(&event))
        { 

            if(event.type == SDL_QUIT)
            {
                isrunning = false;
            }
        
        }
        

        SDL_SetRenderDrawColor(render , 0 , 0, 0, 255);
        SDL_RenderClear(render);

        SDL_RenderPresent(render);

        
    }
    return 0;
}