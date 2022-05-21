#pragma once
#include "EngineDeclaration.h"
#include "EventTracker.h"
#include "Globle.h"

class CircleMove : public Component
{
	sf::Vector2f offset;

	sf::CircleShape* shape;

	//add way to check if mouse is released in EventTracker
	bool pressed = false;

	virtual void Begin();

	virtual void Update();
};

class SimplePencil : public Component
{

	sf::CircleShape* circle;

	virtual void Begin();

	virtual void Update();
};

class Spinner : public Component
{
public:

	sf::CircleShape* shape;
	
	//set speed on initialization
	float m_speed;

	virtual void Begin();

	virtual void Update();
};

class Rainbowify : public Component
{
public:

	sf::CircleShape* shape;

	float hueVal = 0;
	float speed = 0.1f;

	virtual void Begin();

	virtual void Update();
};

class SetFramerate : public Component
{
public:
	sf::Text* text;

	virtual void Begin();

	virtual void Update();
};