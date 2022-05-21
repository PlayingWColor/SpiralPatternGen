#include "Scenes.h"
#include <chrono>
#include <array>

const sf::CircleShape empty = sf::CircleShape(0);

std::array<std::array<int, 3>, 5> patternStyles{ { {{7000,7000,7000}}, {{700,7000,70}}, {{7000,700,70}}, {{70,700,7000}}, {{7000,700,70}} }};

PatternGenerator::PatternGenerator()
{
	SceneSettings::window_clearing = false;
	SceneSettings::window_background = sf::Color(32, 32, 32, 255);

	ShapeNode* node1 = new ShapeNode(new sf::CircleShape(empty));
	ShapeNode* node2 = new ShapeNode(new sf::CircleShape(empty));
	ShapeNode* node3 = new ShapeNode(new sf::CircleShape(empty));
	ShapeNode* node4 = new ShapeNode(new sf::CircleShape(1));
	node4->m_shape->setFillColor(sf::Color(0,0,0,1));
	node1->m_shape->setPosition(800, 450);
	node2->m_shape->setPosition(sf::Vector2f(130, 50));
	node3->m_shape->setPosition(sf::Vector2f(-70, 0));
	node4->m_shape->setPosition(sf::Vector2f(90, 0));
	//node4->m_shape->setOrigin(sf::Vector2f(90, 0));
	node3->addChild(node4);
	node2->addChild(node3);
	node1->addChild(node2);

	node4->addComponent<Rainbowify>();


	auto now = std::chrono::system_clock::now();
	srand(std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count());

	int chosenStyle = (rand() % 5);

	Spinner* spinner1 = node1->addComponent<Spinner>();
	spinner1->m_speed = (rand() % patternStyles[chosenStyle][0]) + 1;
	Spinner* spinner2 = node2->addComponent<Spinner>();
	spinner2->m_speed = (rand() % patternStyles[chosenStyle][1]) + 1;
	Spinner* spinner3 = node3->addComponent<Spinner>();
	spinner3->m_speed = (rand() % patternStyles[chosenStyle][2]) + 1;


	nodes.push_back(node1);

	sf::Vector2i windowSize = EventTracker::get_windowSize();
	views.emplace_back(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
	//views[0].zoom(0.5);
	//views.emplace_back(sf::FloatRect(0.75f, 0, 0.25f*windowSize.x, 0.25f*windowSize.y));


	//ShapeNode* origin = new ShapeNode(new sf::CircleShape(6));

	//nodes.push_back(origin);

	endNode = node4;
}

void PatternGenerator::Update()
{
	//views[0].setCenter(((ShapeNode*)endNode)->get_LocalTransform().getPosition());
	//std::cout << "yes" << std::endl;
	
	Scene::Update();


}