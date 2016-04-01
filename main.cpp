#include <ncurses.h>
#include <cstring>
#include <string>
#include <vector>
#include "person.hpp"
#include "node.hpp"
#include "list.hpp"

using namespace std;


int main(int argc, char const *argv[]){
	List friendList;
	
	
	int width, height;
	initscr();
	start_color();
	scrollok(curscr,TRUE);

	init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(2, COLOR_GREEN,   COLOR_BLACK);
    init_pair(3, COLOR_CYAN,    COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_WHITE,   COLOR_BLACK);


	getmaxyx(curscr,height,width);
	int move_this_y_1 = (height/2)-1;
	int move_this_y_2 = (height/2)+1;
	mvprintw(move_this_y_1,(width-strlen("Bienvenido a tu agenda de amigos."))/2,"Bienvenido a tu agenda de amigos.");
	mvprintw(move_this_y_2,(width-strlen("Laboratorio 5 de programación 3."))/2,"Laboratorio 5 de programación 3.");
	getch();

	clear();
	refresh();

	attron(A_BOLD);

	attron(COLOR_PAIR(4));
	mvprintw(move_this_y_1-2,(width-strlen(".-*-.-*-.-*MENU.-*-.-*-.-*"))/2,".-*-.-*-.-*MENU.-*-.-*-.-*");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(3));
	mvprintw(move_this_y_1-1,(width-strlen("1.-) Agregar contacto."))/2,"1.-) Agregar contacto.");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(2));
	mvprintw(move_this_y_1,(width-strlen("2.-) Listar contactos."))/2,"2.-) Listar contactos.");	
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(3));
	mvprintw(height/2,(width-strlen("3.-) Eliminar contacto."))/2,"3.-) Eliminar contacto.");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(1));
	mvprintw(move_this_y_2,(width-strlen("4.-) Salir."))/2,"4.-) Salir.");
	attroff(COLOR_PAIR(1));

	attroff(A_BOLD);

	char ans = getch();

	while(ans == '1' || ans == '2' || ans == '3'){
		clear();
		refresh();

		if(ans == '1'){
			int nameCounter = 0;
			char nombre[26];
			bool nameEnd = false;
			attron(COLOR_PAIR(3));
			mvprintw(move_this_y_1,(width-strlen("Ingrese nombre: "))/2,"Ingrese nombre: ");
			attroff(COLOR_PAIR(3));

			while(nameCounter < 26 && !nameEnd){
				noecho();
				char temp;
				temp = getch();
				if((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)){
					echo();
					addch(temp);
					nombre[nameCounter] = temp;
					nameCounter++;
				}
				else if(temp == 10 && nameCounter != 0){
					nameEnd = true;
					nombre[nameCounter] = '\0';
				}
			}

			attron(COLOR_PAIR(2));
			mvprintw(move_this_y_1+1,(width-strlen("Ingrese numero: "))/2,"Ingrese numero: ");	
			attroff(COLOR_PAIR(2));
			int numberCounter = 0;
			char number[10];

			while(numberCounter < 9){
				noecho();
				char temp;
				temp = getch();
				if(temp >= '0' && temp <= '9' && numberCounter != 4){
					echo();
					addch(temp);
					number[numberCounter] = temp;
					numberCounter++;
				}
				if(numberCounter == 4  && temp == '-'){
					echo();
					addch(temp);
					number[numberCounter] = temp;
					numberCounter++;
				}
			}
			number[9] = '\0';

			friendList.push_back(Person(nombre,number));
			echo();
			clear();

		}
		else if(ans == '2'){
			clear();
			refresh();

			getmaxyx(curscr,height,width);
			attron(A_BOLD);
			attron(COLOR_PAIR(4));
			mvprintw(height/4,width/4,"Nombre");
			attroff(COLOR_PAIR(4));
			attron(COLOR_PAIR(5));
			mvprintw(height/4,width/2,"Celular");
			attroff(COLOR_PAIR(5));
			attroff(A_BOLD);
			for (int i = 0; i < friendList.size(); ++i){
				attron(COLOR_PAIR(2));
				mvprintw((height/4)+2+i,width/4,friendList.at(i).getName());
				attroff(COLOR_PAIR(2));
				attron(COLOR_PAIR(3));
				mvprintw((height/4)+2+i,width/2,friendList.at(i).getPhone());
				attroff(COLOR_PAIR(3));
			}

			getch();
		}

		else if(ans == '3'){
			clear();
			refresh();

			getmaxyx(curscr,height,width);
			attron(A_BOLD);
			attron(COLOR_PAIR(4));
			mvprintw(height/4,(width/6)+6,"Nombre");
			attroff(COLOR_PAIR(4));
			attron(COLOR_PAIR(5));
			mvprintw(height/4,(width/4)+12,"Celular");
			attroff(COLOR_PAIR(5));
			attroff(A_BOLD);
			for (int i = 0; i < friendList.size(); ++i){
				attron(COLOR_PAIR(2));
				mvprintw((height/4)+2+i,(width/6)+6,friendList.at(i).getName());
				attroff(COLOR_PAIR(2));
				attron(COLOR_PAIR(3));
				mvprintw((height/4)+2+i,(width/4)+12,friendList.at(i).getPhone());
				attroff(COLOR_PAIR(3));
			}

			int nameCounter = 0;
			char nombre[26];
			bool nameEnd = false;
			attron(A_BOLD);
			attron(COLOR_PAIR(2));
			mvprintw(height/4,(width/2)+8,"Nombre: ");
			attroff(COLOR_PAIR(2));
			attroff(A_BOLD);

			while(nameCounter < 26 && !nameEnd){
				noecho();
				char temp;
				temp = getch();
				if((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)){
					echo();
					addch(temp);
					nombre[nameCounter] = temp;
					nameCounter++;
				}
				else if(temp == 10 && nameCounter != 0){
					nameEnd = true;
					nombre[nameCounter] = '\0';
				}
			}

			Person persona;
			persona.setName(nombre);

			int position = friendList.find(persona
				);
			if(position != -1){
				friendList.erase(position);
			}

		}
		clear();
		refresh();
		attron(A_BOLD);

		attron(COLOR_PAIR(4));
		mvprintw(move_this_y_1-2,(width-strlen(".-*-.-*-.-*MENU.-*-.-*-.-*"))/2,".-*-.-*-.-*MENU.-*-.-*-.-*");
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(3));
		mvprintw(move_this_y_1-1,(width-strlen("1.-) Agregar contacto."))/2,"1.-) Agregar contacto.");
		attroff(COLOR_PAIR(3));
		attron(COLOR_PAIR(2));
		mvprintw(move_this_y_1,(width-strlen("2.-) Listar contactos."))/2,"2.-) Listar contactos.");	
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(3));
		mvprintw(height/2,(width-strlen("3.-) Eliminar contacto."))/2,"3.-) Eliminar contacto.");
		attroff(COLOR_PAIR(3));
		attron(COLOR_PAIR(1));
		mvprintw(move_this_y_2,(width-strlen("4.-) Salir."))/2,"4.-) Salir.");
		attroff(COLOR_PAIR(1));

		attroff(A_BOLD);

		ans = getch();
	}	

	endwin();

	return 0;
}