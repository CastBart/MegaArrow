#include "Game.h"

const sf::Int32 Game::s_MS_PER_UPDATE = 10;
const int Game::WINDOW_WIDTH = 800;
const int Game::WINDOW_HEIGHT = 600;

Game::Game()
	: m_window()
	
{
	srand(time(NULL));
	spawnObstacles();
}


Game::~Game()
{
}

void Game::init()
{
	
	sf::ContextSettings windowSettings = sf::ContextSettings();
	windowSettings.antialiasingLevel = 4u;
	m_window.create(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "MegaArrowCross", sf::Style::Default, windowSettings);
	m_window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;
	sf::Time dt = sf::Time::Zero;
	while (m_window.isOpen())
	{
		dt = clock.restart();
		lag += dt.asMilliseconds();
		processEvents();
		while (lag > s_MS_PER_UPDATE)
		{
			update(static_cast<double>(dt.asMilliseconds()));
			lag -= s_MS_PER_UPDATE;
		}
		update(static_cast<double>(dt.asMilliseconds()));
		render(static_cast<double>(dt.asMilliseconds()));
	}
}

void Game::processEvents()
{
	sf::Event event;
	int hi = 0;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			break;
		case sf::Event::KeyReleased:
			break;
		case sf::Event::MouseButtonPressed:

			break;
		default:
			break;
		}
	}
}

void Game::update(const double &dt)
{
	if (!m_obstacles.empty())
	{
		for (auto &obstacle : m_obstacles)
		{
			obstacle.update(dt);
		}
	}
}

void Game::render(const double &ms)
{
	m_window.clear();
	if (!m_obstacles.empty())
	{
		for (auto &obstacle : m_obstacles)
		{
			obstacle.draw(m_window);
		}
	}
	m_window.display();
}

void Game::spawnObstacles()
{
	sf::Vector2f tempPos = sf::Vector2f(0, 0);
	int radius = 20;
	int randNum = rand() % (2-1+1)+1;
	int randY = rand() % ((Game::WINDOW_HEIGHT - 150)- radius) + (radius);
	int speed = 0;
	if (randNum == 1)
	{
		tempPos = sf::Vector2f(-radius, randY);
		speed = 2;
	}
	else
	{
		tempPos = sf::Vector2f(Game::WINDOW_WIDTH + radius, randY);
		speed = -2;
	}
	Obstacle tempObstacle = Obstacle(tempPos, radius, speed);

	m_obstacles.push_back(tempObstacle);
}

