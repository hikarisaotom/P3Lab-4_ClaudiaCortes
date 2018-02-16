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
	pisos=y;
	altura=z;
	setcapacidad(x,y);
	carros=new carro***[x];
	for (int i=0;i<x;i++){
		carros[i]=new carro**[y];	
		for (int j=0;j<y;j++){
			carros[i][j]=new carro*[y];
			for (int k=0;k<y;k++){
				carros[i][j][k]=NULL;;
			}//fin del tercero.
		}//fin del segundo.
	}//fin del primero
}

parqueo::~parqueo(){
	cout <<"Destruyendo el parqueo";
	int x=personas;
	int y=pisos;
	int z=pisos;
	for (int i=0;i!=x;i++){
		for(int j=0;j!=y;j++){
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
	int n_personas=N_Personas/10;
	int m=0;
	if (N_Personas<12){
		m=n_personas*0.7;	
	}else{
		m=n_personas*0.4;
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

