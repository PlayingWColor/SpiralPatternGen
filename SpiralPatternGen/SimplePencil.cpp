#include "Components.h"

void SimplePencil::Begin()
{
	circle = ((sf::CircleShape*)((ShapeNode*)m_node)->m_shape);
}

void SimplePencil::Update()
{
	sf::Vector2f mousePos = (sf::Vector2f)EventTracker::get_mousePos();
	circle->setPosition(mousePos);

	if (EventTracker::get_mouseLeftPressed())
		circle->setRadius(5);
	
	if(EventTracker::get_mouseLeftReleased())
		circle->setRadius(0);
}