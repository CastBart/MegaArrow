#include "Game.h"

const sf::Int32 Game::s_MS_PER_UPDATE = 10;
const int Game::WINDOW_WIDTH = 800;
const int Game::WINDOW_HEIGHT = 600;

Game::Game()
	: m_window()
	, m_player(sf::Vector2f(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT - 50))
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
	m_player.update(dt);
	if (!m_obstacles.empty())
	{
		if (spawnNextObstacle())
		{
			spawnObstacles();
		}
		for (auto &obstacle : m_obstacles)
		{
			obstacle.update(dt);
		}
	}
	if (!m_platforms.empty())
	{
		if (spawnNextObstacle())
		{
			spawnObstacles();
		}
		for (auto &platform : m_platforms)
		{
			platform.update(dt);
		}
	}
}

void Game::render(const double &ms)
{
	m_window.clear();
	m_player.draw(m_window);
	if (!m_obstacles.empty())
	{
		for (auto &obstacle : m_obstacles)
		{
			obstacle.draw(m_window);
			
		}
	}
	if (!m_platforms.empty())
	{
		for (auto &platform : m_platforms)
		{
			platform.draw(m_window);

		}
	}
	m_window.display();
}


void Game::spawnObstacles()
{
	sf::Vector2f tempObstaclePos = sf::Vector2f(0, 0);
	sf::Vector2f tempPlatfoormPos = sf::Vector2f();

	radius = 20;
	int randNum = rand() % (2-1+1)+1;
	int randY = rand() % ((Game::WINDOW_HEIGHT - 300)- radius) + (radius);
	int speed = 0;
	if (randNum == 1)
	{
		tempObstaclePos = sf::Vector2f(static_cast<float>(-radius), static_cast<float>(randY));
		tempPlatfoormPos = sf::Vector2f(static_cast<float>(Game::WINDOW_WIDTH - (radius*2)), static_cast<float>(randY));
		speed = 2;
	}
	else
	{
		tempObstaclePos = sf::Vector2f(static_cast<float>(Game::WINDOW_WIDTH + radius), static_cast<float>(randY));
		tempPlatfoormPos = sf::Vector2f(static_cast<float>(radius*2), static_cast<float>(randY));
		speed = -2;
	}
	//puhs back to obstacle vector
	m_obstacles.push_back(Obstacle(tempObstaclePos, radius, speed));
	//push back to platform vector
	m_platforms.push_back(Platform(tempPlatfoormPos));

	if (m_obstacles.size() >= 2)
	{
		m_obstacles.erase(m_obstacles.begin());
	}

	if ( m_platforms.size() >= 2)
	{
		m_platforms.erase(m_platforms.begin());
	}
}

bool Game::collisions()
{
	if (m_platforms.back().boundingBox().intersects(m_obstacles.back().boudingBox()))
	{
		return true;
	}
	return false;
	
}

bool Game::spawnNextObstacle()
{
	int radiusTwice = radius * 2;
	if (collisions())
	{
		
		return true;
	}

	return false;
}

