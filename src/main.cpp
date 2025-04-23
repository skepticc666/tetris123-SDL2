#define SDL_MAIN_HANDLED

#include <iostream>


#include <SDL2/SDL.h>

int shapes[5][4][4][4] = {
    { // T- shape
        {
            { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 }
        },
        {
            { 0, 0, 0, 0 },
            { 0, 1, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 0, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 1, 0, 0, 0 }
        }
    },
    { // I- shape
        {
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 }
        },
        {
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 }
        }
    },
    { // O- shape
        {
            { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }        },
        {
            { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        }
    },
    { // L- shape
        {
            { 1, 1, 1, 0 },
            { 1, 0, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 0, 0, 1, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 0, 0, 0 },
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 }
        }
    },
    { // S- shape
        {
            { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 }
        },
        {
            { 1, 0, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 }
        }
    }
};

void shapeColor(SDL_Rect box , SDL_Renderer* render) {

    int m = rand() % 6;
   
       switch(m){
           case 1:
               SDL_SetRenderDrawColor(render, 50 , 40 , 60 , 255);
               SDL_RenderFillRect(render , &box);
               break;
           case 2:
               SDL_SetRenderDrawColor(render, 10 , 70 , 60 , 255);
               SDL_RenderFillRect(render , &box);         
               break;
           case 3:
               SDL_SetRenderDrawColor(render, 50 , 90 , 0 , 255);
               SDL_RenderFillRect(render , &box);
               break;
           case 4:
               SDL_SetRenderDrawColor(render, 70 , 20 , 50 , 255);
               SDL_RenderFillRect(render , &box);
               break;
           case 5:
               SDL_SetRenderDrawColor(render, 30 , 30 , 30 , 255);
               SDL_RenderFillRect(render , &box);
               break;
       }
            
    }


     



int gridarray[10][20] = { 0 };

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    int width = 480;
    int height = 700;
    SDL_Window *window = SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
    
    SDL_Renderer *render = SDL_CreateRenderer(window,-1,0);
    const int rows = 20;
    const int cols = 10;
    

    


 
    SDL_Event event;
    bool isrunning = true;
    

    SDL_Point currentpos;
    currentpos.x = 0;
    currentpos.y = 5;

    int currentrot = 0;
    int currentshape = 0; 

    while(isrunning)
    {
        while(SDL_PollEvent(&event))
        { 

            if(event.type == SDL_QUIT)
            {
                isrunning = false;
            }
            if(event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_DOWN){
                    currentpos.y += 1;
                }
                else if (event.key.keysym.sym == SDLK_RIGHT){
                    currentpos.x += 1;
                }
                else if (event.key.keysym.sym == SDLK_LEFT){
                    currentpos.x -= 1;
                }
                else if(event.key.keysym.sym == SDLK_a){
                    currentrot -= 1;
                }
                else if(event.key.keysym.sym == SDLK_s){
                    currentrot += 1;
                }

                if(currentrot< 0){
                    currentrot = 3;
                }
                if(currentrot > 3){
                    currentrot = 0;
                }
            }
        
        }
        
        SDL_SetRenderDrawColor(render , 0 , 0, 0, 255);
        SDL_RenderClear(render);

    


        static SDL_Rect box;

        box.w = width/cols;
        box.h = height/rows;

        // gridarray[0][9] = 1;
        // gridarray[2][9] = 1;
        // gridarray[3][9] = 1;


        //for drawing the grids
        for(int x = 0; x <10 ; x ++){
            for( int y = 0 ; y < 20 ; y++) {
                box.x = x * box.w;
                box.y = y * box.h;
                SDL_SetRenderDrawColor(render , 255 , 255 , 255, 255);
                SDL_RenderDrawRect(render , &box); 

                
                //for transfereing shape to the grid permenantly
                if (gridarray[x][y] != 0) {

                    SDL_SetRenderDrawColor(render , 2 , 25 ,255 ,255);
                    SDL_RenderFillRect(render , &box);
                }



            }
        }

        bool copyEnabled = false;

        //

        for(int x =0 ; x< 4 ; x++){
            for(int y = 0 ; y < 4  ; y++){
                box.x = (currentpos.x + x) * box.w;
                box.y = (currentpos.y + y) * box.h;

                if (shapes[currentrot][x][y] != 0) {
                    if(currentpos.y + y == 19 || gridarray[currentpos.x + x][currentpos.y + y + 1] != 0){
                        
                        copyEnabled = true;

                    }
                    
                    shapeColor(box , render);
                    
                }
            }
        }
        if(copyEnabled){
            for(int i =0 ; i< 4; i++){
                for(int j = 0 ; j<4; j++){
                    if(shapes[currentrot][i][j] != 0){
                        gridarray[currentpos.x + i][currentpos.y + j] = shapes[currentshape][currentrot][i][j];
                    }
                }
            }
            currentpos.y = 5;
        }
        


        SDL_Delay(100);

        


        SDL_RenderPresent(render);

        
    }
    return 0;
}