#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	}
	else {
		std::cout << "SDL video system is ready to go\n";
	}

	window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	bool gameIsRunning = true;

	while (gameIsRunning) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				gameIsRunning = false;
				break;
			case SDL_MOUSEMOTION:
				std::cout << "Mouse moved\n";
				break;
			case SDL_KEYDOWN:
				std::cout << (char)event.key.keysym.sym << " was pressed\n";
			default:
				break;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}