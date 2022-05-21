#include "Components.h"

void CircleMove::Begin()
{
	offset = sf::Vector2f(0, 0);
	shape = ((sf::CircleShape*)((ShapeNode*)m_node)->m_shape);
}

void CircleMove::Update()
{
	sf::Vector2i mousePos = EventTracker::get_mousePos();
	
	if(EventTracker::get_mouseLeftHeld())
		offset = sf::Vector2f(mousePos.x - 100, mousePos.y - 100);

	//add way to check if mouse is released in EventTracker
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		shape->setFillColor(sf::Color::Cyan);
		pressed = true;
	}
	else if (pressed)
	{
		shape->setFillColor(sf::Color::Red);
		pressed = false;
	}
		
	float sineVal = std::sinf(Time::getTimeInSeconds() * 2);

	float radius = 75 - 25 * sineVal;

	float center = 100 - radius;

	shape->setRadius(radius);
	shape->setPosition(sf::Vector2f(center + offset.x, center + offset.y));

	sf::Color col = shape->getFillColor();

	col.r = radius;

	shape->setFillColor(col);
}
