#pragma once
#include "SFML\Graphics.hpp"
#include "utils\Math.h"

class Player
{
public:
	Player(sf::Vector2f position);
	~Player();
	void update(double dt);
	void draw(sf::RenderWindow& window);
private:

	void movement();

	sf::RectangleShape m_player;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_minVel;
	sf::Vector2f m_maxVel;
};

