#include "Node.h"
Node::Node(int** board, const int dimension, const int r, const int c, const int num) : dimension(dimension), row(r), column(c), number_to_insert(num)
{
	this->board_of_node = new int*[this->dimension];
	for (int i = 0; i < this->dimension; i++)
		this->board_of_node[i] = new int[this->dimension];
	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			this->board_of_node[i][j] = board[i][j];
		}
	}
	this->used_node = false;
		
}
Node::~Node()
{
	for (int i = 0; i < this->dimension; i++)
	{
		delete[] this->board_of_node[i];
	}
	delete[] board_of_node;
}
int Node::get_column()
{
	return this->column;
}
int Node::get_row()
{
	return this->row;
}
int Node::get_num()
{
	return this->number_to_insert;
}
void Node::set_num(int num)
{
	this->number_to_insert = num;
}
bool Node::get_used_node()
{
	return this->used_node;
}
void Node::set_used_node(bool used)
{
	this->used_node = used;
}
void Node::set_number_at_board(int x, int y,int num)
{
	this->board_of_node[x][y] = num;
}
int Node::insert()
{
	if (this->board_of_node[this->row][this->column] == 0)
	{
		for (int i = 0; i < this->dimension; i++)
		{
			if (this->board_of_node[this->row][i] == this->number_to_insert)
				return 1;
		}
		for (int i = 0; i < this->dimension; i++)
		{
			if (this->board_of_node[i][this->column] == this->number_to_insert)
				return 1;
		}
		//std::cout << "Changing num at (" << this->row << "," << this->column << ") to number " << this->number_to_insert << std::endl;
		this->board_of_node[this->row][this->column] = this->number_to_insert;
		return 2;
	}
	return 0;
}
bool Node::valid_solution()
{
	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			//check if the number allowed to be there
			for (int k = 0; k < this->dimension; k++)
			{
				if(k!=j)
					if (this->board_of_node[i][j] == this->board_of_node[i][k])
						return false;
			}
			for (int k = 0; k < this->dimension; k++)
			{
				if(k!=i)
					if (this->board_of_node[i][j] == this->board_of_node[k][j])
						return false;
			}
		}
	}
	return true;
}
int** Node::getBoard()
{
	return this->board_of_node;
}

void Node::print_board()
{
	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			std::cout << this->board_of_node[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}