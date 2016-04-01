#include "person.hpp"
#include <cstring>
#include <iostream>

using namespace std;

Person::Person(){
	name = new char[26];
	phone = new char[10];
}
Person::Person(char* name, char* phone){
	setName(name);
	setPhone(phone);
}
/*Person::~Person(){
	delete[] name;
	delete[] phone;
	cout << "Persona destruida";
}*/
char* Person::getName(){
	return name;
}
char* Person::getPhone(){
	return phone;
}
void Person::setName(char* name){
	this->name = new char[26];
	strcpy(this->name,name);
}
void Person::setPhone(char* phone){
	this->phone = new char[10];
	strcpy(this->phone,phone);
}