#include "Components.h"
#include <sstream>
#include <iostream>
void SetFramerate::Begin()
{
	text = (((TextNode*)m_node)->m_text);
	std::cout.precision(0);
	std::cout << std::fixed;
}

void SetFramerate::Update()
{
	float fps = 1.0 / Time::getDeltaTime();
	
	std::stringstream ss;
	ss.precision(0);
	ss << std::fixed << "FPS: " << fps;
	std::cout.precision(0);
	std::cout << "FPS: " << fps << std::endl;
	//text->setString("yes");
}