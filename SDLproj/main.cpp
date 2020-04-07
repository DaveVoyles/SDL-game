#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#define IMG_PATH "sonic.bmp"

int main(int argc, char* argv[]) 
{
	SDL_Init    (SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL error: " << SDL_GetError();
		return 1;
	}

	const int WIDTH = 640, HEIGHT = 480;
	
	SDL_Surface* imageSurface  = NULL;
	SDL_Surface* windowSurface = NULL;
	SDL_Texture* img           = NULL;

	SDL_Window*   window   = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear	      (renderer                );
	SDL_RenderPresent     (renderer                );
	SDL_Delay             (3000                    );

	// Close WINDOW
	SDL_Event windowEvent;
	while (true)
	{
		// If window event type is 'quit', break
		if (SDL_PollEvent (&windowEvent))
			if (SDL_QUIT == windowEvent.type) {break;}

		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}

	// Get reference to window
	windowSurface = SDL_GetWindowSurface(window);
	imageSurface  = SDL_LoadBMP("sonic.bmp");
	img = IMG_LoadTexture(renderer, IMG_PATH);




	if (NULL == imageSurface) 
	{
		std::cout << "SDL count not load image! SDL Error: " << SDL_GetError() << std::endl;
	}

	// Clean up resources
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);
	imageSurface  = NULL;
	windowSurface = NULL;

	SDL_DestroyTexture(img);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}