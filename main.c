#include <SDL2/SDL.h>
#include <emscripten.h>


void mainloop()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_FINGERDOWN:
                printf("DOWN Id: %d\n", event.tfinger.fingerId);
                break;

            case SDL_FINGERUP:
                printf("UP   Id: %d\n", event.tfinger.fingerId);
                break;

            case SDL_FINGERMOTION:
          		printf("MOVE Id: %d\n", event.tfinger.fingerId);
                break;
        }
    }
}

int main(int a, char* g[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindow( "Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 360, 0);

    emscripten_set_main_loop(mainloop, 0, 1);

    return 0;
}
