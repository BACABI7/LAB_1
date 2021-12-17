#pragma once

class LinkedList
{
private:

	void add_first(int newElem);
	void reset_list();

	class Node
	{
	public:
		Node(int data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
		~Node() {}

		int data;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	LinkedList();
	~LinkedList();

	void push_back(int newElem); //add in the end
	void push_front(int newElem); //add in the origin
	void pop_back(); //delete last
	void pop_front(); //delete first
	void insert(int newElem, size_t index); // insert at the index
	int at(size_t index); //returns data of the index element
	void remove(size_t index); //delete index element
	size_t get_size(); //returns size of the list
	void print_to_console();
	void clear(); //clear list
	void set(size_t, int);
	bool isEmpty(); // if empty - true, else false
	void reverse(); //reverse list
};


