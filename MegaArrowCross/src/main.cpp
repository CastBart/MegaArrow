#pragma comment(lib,"opengl32.lib")

#include "Game.h"
#include<memory>

int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->init();
	game->run();
	return EXIT_SUCCESS;
}