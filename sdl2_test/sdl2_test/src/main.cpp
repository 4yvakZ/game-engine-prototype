#include <iostream>
#include <SDL.h>
#include <glad/glad.h>

int main(int argc, char* argv[]) {

	SDL_Window* window = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	}
	else {
		std::cout << "SDL video system is ready to go\n";
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow("SDL2 Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext context;
	context = SDL_GL_CreateContext(window);

	gladLoadGLLoader(SDL_GL_GetProcAddress);


	bool gameIsRunning = true;
	while (gameIsRunning) {
		glViewport(0, 0, 640, 480);
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

			glClearColor(1, 0, 0, 1);
			glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

			SDL_GL_SwapWindow(window);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}