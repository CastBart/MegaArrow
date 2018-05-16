#pragma once
//libs
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <iostream>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>  

//classes
#include "Obstacle.h"
#include "Platform.h"
    


class Game
{

public:
	Game();
	~Game();
	void init();
	void run();
	static const int WINDOW_WIDTH;
	static const int WINDOW_HEIGHT;

private:
	void processEvents();
	void update(const double &dt);
	void render(const double &ms);
	void spawnObstacles();

	bool collisions();
	bool spawnNextObstacle();

	int radius;
	static const sf::Int32 s_MS_PER_UPDATE;
	sf::RenderWindow m_window;

	std::vector<Obstacle> m_obstacles;
	std::vector<Platform> m_platforms;
	
	
};

