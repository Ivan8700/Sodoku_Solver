#pragma once
#include <iostream>
class Node
{
private:
	int** board_of_node;
	int dimension;
	int row;
	int column;
	int number_to_insert;
	bool used_node;
public:
	Node(int** board,int dimension,const int r, const int c, const int num);
	~Node();
	int get_num();
	int get_column();
	int get_row();
	void set_num(int num);
	bool get_used_node();
	void set_number_at_board(int x, int y,int num);
	void set_used_node(bool used);
	int insert();
	int** getBoard();
	bool valid_solution();
	void print_board();

};

