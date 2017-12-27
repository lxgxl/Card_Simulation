build : main.o
	g++ `pkg-config --cflags --libs opencv` main.o -o build
main.o : main.cpp
	g++ -c -g main.cpp
clean :
	rm *.o