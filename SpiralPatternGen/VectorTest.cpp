#include "Scenes.h"
#include <iostream>
#include <chrono>

VectorTest::VectorTest()
{
	std::vector<char> myvector;
	myvector.emplace_back('a');
	myvector.emplace_back('c');
	myvector.emplace_back('x');
	myvector.emplace_back('y');
	myvector.emplace_back('z');
	// vector becomes a, c, x, y, z

	// printing the vector
	for (auto it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;

	int size = 512;
	
	std::vector<int> v;
	std::vector<int> v1;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	


	v.reserve(size);
	for (int i = 0; i < size; i++)
	{
		v.push_back(i);
		//v.emplace_back(i);
		//std::cout << "PB Size: " << v.size() << " |Capacity: " << v.capacity() << " ||EB Size: " << v.size() << " |Capacity: " << v.capacity() << std::endl;
	}
	

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();




	std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();

	//std::vector<int> v2;
	//std::vector<int> v3;
	//v2.reserve(size);
	//v3.reserve(size);
	v1.resize(size);
	for (int i = 0; i < size; i++)
	{
		//v1.push_back(i);
		v1.assign(i,i);
		//std::cout << "PB Size: " << v.size() << " |Capacity: " << v.capacity() << " ||EB Size: " << v.size() << " |Capacity: " << v.capacity() << std::endl;
	}


	std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

	std::cout << "Time difference0 = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference0 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

	std::cout << "Time difference1 = " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count() << "[µs]" << std::endl;
	std::cout << "Time difference1 = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - begin1).count() << "[ns]" << std::endl;
}