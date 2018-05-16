#pragma once
#include"SFML\Graphics.hpp"
class Math
{
public:
	Math();
	~Math();
	static sf::Vector2f clampX(sf::Vector2f &value, sf::Vector2f &min, sf::Vector2f &max);
};

