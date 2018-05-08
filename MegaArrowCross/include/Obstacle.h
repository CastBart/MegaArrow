#pragma once
#include "SFML\Graphics.hpp"
#include <memory>


class Obstacle
{
public:
	Obstacle(sf::Vector2f position);
	~Obstacle();
	void update(double dt);
	void draw(sf::RenderWindow &window);

private:

	sf::CircleShape m_obstacle;

	// position of the obsatcle
	sf::Vector2f m_position;

	// velocity of the obstacle
	sf::Vector2f m_velocity;

	// speed of the obstacle
	float m_speed;


};

