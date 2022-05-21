#include "Scenes.h"

DrawTest::DrawTest()
{
	SceneSettings::window_clearing = false;

	sf::CircleShape* pencil = new sf::CircleShape(0);
	pencil->setFillColor(sf::Color::White);

	ShapeNode* shapeNode = new ShapeNode(pencil);
	shapeNode->addComponent<SimplePencil>();

	nodes.push_back(shapeNode);

	sf::Vector2i windowSize = EventTracker::get_windowSize();
	views.emplace_back(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
}