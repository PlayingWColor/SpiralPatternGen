#include "Scenes.h"

Debug::Debug()
{
	sf::Text* text = new sf::Text();
	text->setString("Debug");
	text->setCharacterSize(12);

	sf::Color col = sf::Color(-(SceneSettings::window_background.r - 255), -(SceneSettings::window_background.g - 255), -(SceneSettings::window_background.b - 255), 255);

	text->setFillColor(sf::Color::Red);

	nodes.push_back(new TextNode(text));

	nodes[0]->addComponent<SetFramerate>();
}