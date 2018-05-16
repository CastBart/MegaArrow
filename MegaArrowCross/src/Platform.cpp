#include "..\include\Platform.h"



Platform::Platform(sf::Vector2f position)
	: m_HEIGHT(50)
	, m_WIDTH(20)
	, m_position(position)

{
	m_platform.setSize(sf::Vector2f(m_WIDTH, m_HEIGHT));

	m_platform.setPosition(m_position);
	m_platform.setOrigin(m_WIDTH / 2, m_HEIGHT / 2);
	m_platform.setFillColor(sf::Color::Green);
}


Platform::~Platform()
{
}

void Platform::update(double dt)
{
	m_platform.setPosition(m_position);
}

void Platform::draw(sf::RenderWindow & window)
{
	window.draw(m_platform);
}

sf::FloatRect Platform::boundingBox()
{
	return m_platform.getGlobalBounds();
}
