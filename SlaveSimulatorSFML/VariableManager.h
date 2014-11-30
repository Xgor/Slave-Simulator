#pragma once


#include <vector>

#include "Slave.h"
class VariableManager
{
public:
	VariableManager();
	~VariableManager();

	float Health;
	int LavaTime;
	float Hunger;
	int Water;
	int Alcohol;
	std::vector<Slave> slaves;

	
};

