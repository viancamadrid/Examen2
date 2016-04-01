#pragma once

#include <cstring>

class Person{
  public:
  	Person();
  	Person(char* name, char* phone);
	//~Person();
  	char* getName();
  	char* getPhone();
  	void setName(char*);
  	void setPhone(char*);
  private:
  	char* name;
  	char* phone;
};