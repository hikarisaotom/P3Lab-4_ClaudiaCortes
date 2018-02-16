using namespace std;
#include "parqueo.h"
#include <string>
#include <iostream>
#include "carro.h"
parqueo::parqueo(){
	pisos=5;
	capacidad=5;
}

parqueo::parqueo(int x, int y, int z){
	/*pisos=Ppisos;
	capacidad=Pcapacidad;*/
	personas=x;
	pisos=z;
	altura=y;
	z=z;//pisos
	setcapacidad(x,y);
	carros=new carro***[x];
	for (int i=0;i<x;i++){
		carros[i]=new carro**[y];	
		for (int j=0;j<capacidad;j++){
			carros[i][j]=new carro*[y];
			for (int k=0;k<y;k++){
				carros[i][j][k]=NULL;;
			}//fin del tercero.
		}//fin del segundo.
	}//fin del primero
}

parqueo::~parqueo(){
	cout <<"Destruyendo el parqueo";
	for (int i=0;i!=n;i++){
		for(int j=0;j!=m;j++){
			for (int k=0;k!=z;k++){
				carros[i][j][k]=NULL;
				delete carros[i][j][k];
			}
			delete[] carros[i][j];
		}
		delete [] carros[i];/*pisos personas y altura, y calcular capacidad en contructor*/
	}	
	delete[] carros;
}


void parqueo::setcapacidad(int N_Personas, int M){
	 n=N_Personas/10;
	 m=0;
	if (N_Personas<12){
		m=N_Personas*0.7;	
	}else{
		m=N_Personas*0.4;
	}

}

void parqueo::setpisos(int Pisos){
	pisos=Pisos;

}

int parqueo::getpisos(){
	return pisos;
}

int  parqueo::getcapacidad(){
	return capacidad;
}


carro**** parqueo::getmatriz(){
	return carros; 
}
int parqueo:: getn(){
	return n;
}

int parqueo:: getm(){
	return n;
}

int parqueo::getaltura(){
	return altura;
}
