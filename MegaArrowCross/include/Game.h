#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <iostream>
#include "Obstacle.h"


class Game
{

public:
	Game();
	~Game();
	void init();
	void run();

private:
	void processEvents();
	void update(const double &dt);
	void render(const double &ms);

	static const sf::Int32 s_MS_PER_UPDATE;
	sf::RenderWindow m_window;

	Obstacle test;
};

