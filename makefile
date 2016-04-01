FriendList.exe:	main.o person.o node.o list.o
	g++ main.o person.o node.o list.o -lncurses -o FriendList

main.o:	main.cpp person.hpp
	g++ -c main.cpp -lncurses

person.o:	person.hpp person.cpp
	g++ -c person.cpp

node.o:	person.hpp node.hpp node.cpp
	g++ -c node.cpp

list.o:	person.hpp node.hpp list.hpp list.cpp
	g++ -c list.cpp

clean:
	rm *.o FriendList