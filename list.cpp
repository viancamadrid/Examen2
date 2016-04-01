#include "list.hpp"
#include "person.hpp"
#include "node.hpp"
#include <iostream>

List::List(){
	head=NULL;
}
List::List(Person persona){
	head= new Node(persona);
}
List::~List(){

}
void List::setHead(Person persona){
	this->head=head;
}
Person List::getHead(){
	Person x=head->getValue();
	return x;
}
void List::insert(int posicion, Person persona){
	Node* temp= head;
	if(posicion==0){
		if(head!=NULL){
			head->setValue(persona);
			head->setNext(temp);
		}else{
			setHead(persona);
		}
	}else{
		int i=0;
		while(temp->hasNext()){
			i++;
			Node* actual= temp->getNext();
			if(i==posicion-1){
				Node* insertar= new Node(persona);
				insertar->setNext(actual->getNext());
				actual->setNext(insertar);
				break;
			}
		}
	}
}

Person List::at(int posicion){
	Node* temp=head;
	Person actual;
	int i=0;
	while(temp->hasNext()){
		if(i==posicion){
			actual=temp->getValue();
			break;
		}
		i++;
		temp=temp->getNext();
	}
	return actual;
}
void List::erase(int posicion){
	Node* temp=head;
	Node* otro;
	int i=0;
	while(temp->hasNext()){
		if(i==posicion){
			Person eliminar=temp->getValue();
		}
		i++;
		otro=temp;
		temp=temp->getNext();
	}

}
void List::concat(List* lista){

}
int List::find(Person persona){
	Node* temp=head;
	int i=0;
	while (temp->hasNext()){
		if(persona.getName()==temp->getValue().getName()){
			break;
		}
		temp=temp->getNext();
		i++;
	}
	return i;
}
int List::size(){
	int i=0;
	Node* temp=head;
	if(head!=NULL){
		while(temp->hasNext()){
			i++;
			temp=temp->getNext();
		}
	}
	return i;
}
void List::push_back(Person persona){
	if(!head){
		this->setHead(persona);
	}
	Node* temp  = head ;
	temp -> setNext(NULL);
	if(!temp -> hasNext()){
		temp->setNext(new Node(persona));
	}else{
		while(temp->hasNext()){
			temp = temp->getNext();
		}
		temp -> setNext(new Node(persona));
	}
}
Node* List::first(){
	return head;
}