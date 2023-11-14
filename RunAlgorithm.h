#pragma once
#include <iostream>
#include <stack>
#include "Node.h"
class RunAlgorithm
{
private:
	int dimension;
	int** board;
	bool** can_be_changed;
public:
	RunAlgorithm(const int n);
	~RunAlgorithm();
	void print_Board();
	void solving_algorithm();
};


