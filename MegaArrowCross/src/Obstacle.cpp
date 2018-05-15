#include "..\include\Obstacle.h"



Obstacle::Obstacle(sf::Vector2f position, int radius, int speed)
	: m_position(position)
	, m_radius(radius)
	, m_speed(speed)
{
	m_obstacle.setFillColor(sf::Color::Blue);
	m_obstacle.setRadius(m_radius);
	m_obstacle.setPosition(m_position);
	m_velocity = sf::Vector2f(m_speed, 0);
}

Obstacle::~Obstacle()
{
}

void Obstacle::update(double dt)
{
	m_position += m_velocity;
	m_obstacle.setPosition(m_position);
	m_obstacle.setOrigin(sf::Vector2f(m_obstacle.getLocalBounds().width / 2, m_obstacle.getLocalBounds().height / 2));
}

void Obstacle::draw(sf::RenderWindow &window)
{
	window.draw(m_obstacle);
}

sf::Vector2f Obstacle::Pos()
{
	return m_position;
}
