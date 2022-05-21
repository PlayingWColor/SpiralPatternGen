#include "Scenes.h"

CircleTest::CircleTest()
{
	SceneSettings::window_background = sf::Color(120, 120, 140, 255);
	SceneSettings::window_clearing = false;

	sf::CircleShape* shape = new sf::CircleShape(100.f);
	shape->setFillColor(sf::Color::Red);

	ShapeNode* shapeNode = new ShapeNode(shape);
	shapeNode->addComponent<CircleMove>();

	nodes.push_back(shapeNode);

	sf::Vector2i windowSize = EventTracker::get_windowSize();
	views.emplace_back(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
}