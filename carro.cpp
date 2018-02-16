#include "carro.h"
#include <iostream>
#include <string>
using namespace std;

carro::carro(){
	color="Rojo";
	marca="Honda";
	altura=1;
		
}

carro::carro(string Ccolor, string Cmarca, int Caltura){
	color=Ccolor;
	marca=Cmarca;
	altura=Caltura;
}

void carro:: setcolor(string Ccolor){
	color=Ccolor;
}

void carro::setmarca(string Cmarca){
	marca=Cmarca;
}

void carro::setaltura(int Caltura){
	altura=Caltura;
}

string carro::getcolor(){
	return color;
}

string carro::getmarca(){

	return marca;
}

int carro::getaltura(){
	return altura;
}

carro::~carro(){
	cout<<"Destruyendo Carro";
}
