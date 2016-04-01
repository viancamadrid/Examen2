#pragma once

#include <string>
#include "person.hpp"

using namespace std;

class Node{
private:
	Person persona;
	Node* next;
public:
	Node();
	Node(Person persona);
	~Node();
	Person getValue();
	Node* getNext();
	void setValue(Person persona);
	void setNext(Node* next);
	bool hasNext();
};