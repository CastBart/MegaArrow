#include "..\include\Obstacle.h"



Obstacle::Obstacle(sf::Vector2f position)
	: m_position(position)
{
	m_obstacle.setFillColor(sf::Color::Blue);
	m_obstacle.setRadius(20);
	m_obstacle.setPosition(m_position);
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(double dt)
{
}

void Obstacle::draw(sf::RenderWindow &window)
{
	window.draw(m_obstacle);
}
