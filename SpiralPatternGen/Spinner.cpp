#include "Components.h"

void Spinner::Begin()
{
	shape = (sf::CircleShape*)((ShapeNode*)m_node)->m_shape;
	m_speed = 0;
}

void Spinner::Update()
{
	shape->rotate(Time::getDeltaTime()*m_speed);
	((ShapeNode*)m_node)->updateTransform();
}