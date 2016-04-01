#pragma once
#include "node.hpp"

using namespace std;

class List{
private:
	Node* head;
public:
	List();
	List(Person persona);
	~List();
	void setHead(Person persona);
	Person getHead();
	void insert(int posicion, Person persona);
	Person at(int posicion);
	void erase(int posicion);
	void concat(List* lista);
	int find(Person persona);
	int size();
	void push_back(Person persona);
	Node* first();
};