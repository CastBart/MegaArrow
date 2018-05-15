#pragma once
#include "SFML\Graphics.hpp"
#include <memory>


class Obstacle
{
public:
	Obstacle(sf::Vector2f position, int radius, int speed);
	~Obstacle();
	void update(double dt);
	void draw(sf::RenderWindow &window);
	sf::Vector2f Pos();
private:

	//circle shape representing the obatacle
	sf::CircleShape m_obstacle;

	// position of the obsatcle
	sf::Vector2f m_position;

	// velocity of the obstacle
	sf::Vector2f m_velocity;

	// speed of the obstacle
	int m_speed;

	// radius of the obstacle
	int m_radius;


};

