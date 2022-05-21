#include "Scenes.h"
#include <iostream>
#include <chrono>
#include <deque>

ContainerTest::ContainerTest()
{
	std::vector<int> d = {1,2,3,4,5,6,7,8,9};

	d.resize(4);

	for (int i = 0; i < 9; i++)
	{
		std::cout << d[i] << " ";
	}
}