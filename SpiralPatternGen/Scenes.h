#pragma once
#include "EngineDeclaration.h"
#include "Components.h"

class CircleTest : public Scene
{
public:
	CircleTest();
};

class DrawTest : public Scene
{
public:
	DrawTest();
};

class PatternGenerator : public Scene
{
public:
	PatternGenerator();
	virtual void Update();
private:
	Node* endNode;

};

class Debug : public Scene
{
public:
	Debug();
};

class VectorTest : public Scene
{
public:
	VectorTest();
};

class ContainerTest : public Scene
{
public:
	ContainerTest();
};

class QuestTest : public Scene
{
public:
	QuestTest();
};