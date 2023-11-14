#include "RunAlgorithm.h"
RunAlgorithm::RunAlgorithm(const int n)
{
	this->dimension = n;
	this->board = new int* [n];
	for (int i = 0; i < n; i++)
	{
		this->board[i] = new int[this->dimension];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->board[i][j] = 0;
		}
	}
	//---input procedure of the board ---//
	std::cout << "Enter how many numbers would you like to insert to the board " << std::endl;
	int temp1, temp2, number_to_insert, amount_nums_to_insert;
	std::cin >> amount_nums_to_insert;
	for (int i = 0; i < amount_nums_to_insert; i++)
	{
		std::cout << "Enter where you want to insert a number i.e 1 and then 4 means insert at row 1 and column 4" << std::endl;
		std::cin >> temp1 >> temp2;
		if (temp1<1 || temp1>n || temp2<1 || temp2>n)
		{
			std::cout << "please insert a proper values" << std::endl;
			i--;
			continue;
		}
		std::cout << "Enter the number to insert " << std::endl;
		std::cin >> number_to_insert;
		if (number_to_insert < 1 || number_to_insert>9)
		{
			std::cout << "please insert a proper value" << std::endl;
			i--;
			continue;
		}
		this->board[temp1 - 1][temp2 - 1] = number_to_insert;
	}
	this->solving_algorithm();

}
RunAlgorithm::~RunAlgorithm()
{
	for (int i = 0; i < this->dimension; i++)
	{
		delete[] this->board[i];
	}
	delete[] this->board;
}
void RunAlgorithm::solving_algorithm()
{
	int i = 0, j = 0, num = 1;
	std::stack<Node*>* s = new std::stack<Node*>;
	Node* root = new Node(this->board, this->dimension, i, j, num);
	Node* temp;
	bool flag = true;
	int insert_status;
	s->push(root);
	while (!s->empty())
	{
		temp = s->top();
		insert_status = temp->insert();
		if (!temp->get_used_node())
		{
			if (insert_status == 0 || insert_status == 2)
			{

				if (j < (this->dimension - 1))
					j++;
				else
				{
					j = 0;
					if (i < (this->dimension - 1))
						i++;
					else
					{
						if (temp->valid_solution())
						{
							std::cout << "found a solution " << std::endl << std::endl;
							temp->print_board();
							break;
						}
						else
						{
							s->pop();
							delete temp;
						}
					}
				}
				Node* n = new Node(temp->getBoard(), this->dimension, i, j, 1);
				temp->set_used_node(true);
				if (insert_status == 0)
				{
					s->pop();
					delete temp;
				}
				s->push(n);
				continue;
			}
		}
		if (temp->get_used_node() || insert_status == 1)
		{
			if (temp->get_used_node())
				temp->set_used_node(false);
			if (temp->get_num() < this->dimension)
			{
				temp->set_num(temp->get_num() + 1);
				temp->set_number_at_board(i, j, 0);
			}
			else
			{
				s->pop();
				delete temp;
				temp = s->top();
				j = temp->get_column();
				i = temp->get_row();
			}
		}
	}
	while (!s->empty())
	{
		temp = s->top();
		s->pop();
		delete temp;
	}
	delete s;

}
void RunAlgorithm::print_Board()
{
	for (int i = 0; i < this->dimension; i++)
	{
		for (int j = 0; j < this->dimension; j++)
		{
			std::cout << this->board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
