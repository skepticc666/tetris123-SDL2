#define SDL_MAIN_HANDLED

#include <iostream>


#include <SDL2/SDL.h>

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    int width = 480;
    int height = 700;
    SDL_Window *window = SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
    
    SDL_Renderer *render = SDL_CreateRenderer(window,-1,0);
    const int rows = 20;
    const int cols = 10;
    SDL_Rect grid[rows * cols];

    for( int i = 0 ; i < rows  ; i++)
    {
        for( int j = 0 ; j < cols ; j++ )
        {
            int index = i*cols + j;
            grid[index].x = j*(width/cols);
            grid[index].y = i*(height/rows);
            grid[index].w = width/cols;
            grid[index].h = height/rows;

        }
    }


            


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

        for(int i = 0 ; i < rows*cols ; i++)
        {
            SDL_SetRenderDrawColor(render , 255 , 255 ,255 ,255);
            SDL_RenderDrawRect(render , &grid[i]);
        }
        


        SDL_Delay(1000);

        


        SDL_RenderPresent(render);

        
    }
    return 0;
}