#pragma once
#include "SFML\Graphics.hpp"
class Platform
{
public:
	Platform(sf::Vector2f position);
	~Platform();

	void update(double dt);
	void draw(sf::RenderWindow &window);
	sf::FloatRect boundingBox();

private:
	sf::RectangleShape m_platform;
	sf::Vector2f m_position;

	float m_HEIGHT;
	float m_WIDTH;
	
};

