#include "..\include\Player.h"


Player::Player(sf::Vector2f position)
	: m_position(position)
	, m_minVel(-2,0)
	, m_maxVel(2,0)
{
	m_player.setSize(sf::Vector2f(40, 100));
	m_player.setFillColor(sf::Color::White);
	m_player.setOrigin(m_player.getLocalBounds().width / 2, m_player.getLocalBounds().height / 2);

}


Player::~Player()
{
}

void Player::update(double dt)
{
	movement();
	m_velocity += m_acceleration;
	Math::clampX(m_velocity, m_minVel, m_maxVel);
	m_position += m_velocity;
	m_player.setPosition(m_position);
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(m_player);
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_acceleration = sf::Vector2f(-0.01, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_acceleration = sf::Vector2f(0.01, 0);
	}
}
