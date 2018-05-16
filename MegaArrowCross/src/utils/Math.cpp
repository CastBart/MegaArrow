#include "..\..\include\utils\Math.h"



Math::Math()
{
}


Math::~Math()
{
}

sf::Vector2f Math::clampX(sf::Vector2f & value, sf::Vector2f & min, sf::Vector2f & max)
{
	if (value.x < min.x)
	{
		value.x = min.x;
	}
	else if(value.x > max.x)
	{
		value.x = max.x;
	}
	return sf::Vector2f();
}
