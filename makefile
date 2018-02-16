main: main.o carro.o parqueo.o
	g++ main.o carro.o parqueo.o -o main
	rm *.o
main.o : main.cpp carro.h parqueo.h
	g++ -c main.cpp
carro.o : carro.cpp carro.h
	g++ -c carro.cpp
parqueo.o: parqueo.cpp parqueo.h carro.h
	g++ -c parqueo.cpp

