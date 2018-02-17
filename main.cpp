#include <iostream>
#include <string>
#include <vector> 
#include "carro.h"
//#include "edificio.cpp"
#include "parqueo.h"
using namespace std;

//Prototipos de los metodos.

//Menu principal del programa.
int menu();
//Liberar memoria de la matriz
void liberarMatriz(int**&, int);
//Liberar memoria de la matriz.
void liberarTablero(string**&,int);
parqueo* crearparqueo();
	carro crearcarro(int,int,int, parqueo*);
void eliminarcarro(parqueo*);

int main()
{	bool Continuar=1;
	parqueo* Global_Parqueo;
	vector<string> Array;
	carro**** carros;
	while (Continuar){
		//Llamado del menu del programa.
		switch(menu()){
			case 1:{//
				cout<<"Usted selecciono: crear parqueo"<<endl;
				Global_Parqueo=crearparqueo();
				carros=Global_Parqueo->getmatriz();
				break;
				}//Fin del case 1.
			case 2:{//
				cout<<"Usted selecciono: crear carro"<<endl;
				crearcarro(Global_Parqueo->getn(),Global_Parqueo->getm(),Global_Parqueo->getaltura(),Global_Parqueo);
				break;
				}//Fin del case 2

			case 3:{//
				cout<<"Usted selecciono:Eliminar el parqueo "<<endl;

				eliminarcarro(Global_Parqueo);	
				break;
				}//Fin del case 3

			case 4:{//
				cout<<"Usted selecciono: contabilizar"<<endl;
				Global_Parqueo->contabilizar();
				break;
				}//Fin del case 4.
			default:{//		
				cout<<"OPCION NO VALIDA"<<endl;

				break;
				}//FIn del default

		}//Fin del switch.	
	cout<<"Desea Continuar en el sistema?[0/1]"<<endl;
	cin>>Continuar;
	}//FIn del while.
return 0;
}

void eliminarcarro(parqueo* lugar){
	int piso;
	int posx;
	int posy;
	cout<<"ingrese la primera posicion del carro";
	cin>>posx;
	cout<<"ingrese la posicion  del y dle carro";
	cin>>posy;
	cout<<"Ingrese el piso del carro";
	cin>>piso;
	lugar->eliminarcarro(posx,posy,piso);
}

carro  crearcarro(int  x,int y, int altura, parqueo* lugar){
	int piso=0;
	int alturacarro;
	string matricula;
	string color;
	cout<<"Ingrese el piso en el que desea parquearse";
	cin>>piso;
	carro temporal;
	cout<<"Ingrese la matricula del carro";
	cin>>matricula;
	cout<<"ingrese el color";
	cin >>color;
	cout<<"ingrese la altura";
	cin>>alturacarro;
	/*
	for (int i=0;i<x;i++){
		for (int j=0;j<y;j++){
			if (parqueo[piso][i][j]==NULL){
			//temporal = new carro();
				parqueo[i][j][piso] = new carro(matricula,color,alturacarro);
				cout<<"Se Parqueo exitosamente el carro en la posicion" <<endl;
				cout<<i<<j<<piso<<endl;
				break;
			}
		}
	}*/
	lugar->agregarcarro(new carro(matricula,color,alturacarro),piso);
	return temporal;
}
parqueo* crearparqueo(){
	int personas=-5;
	int pisos=0;
	int altura=0;
//	parqueo Temporal;
	while (personas<=50||personas>=200){
		cout<<"Ingrese la cantidad de personas"<<endl;
		cin>>personas;
	}
	cout<<"Ingrese la altura del parqueo"<<endl;
	cin>>altura;
	cout<<"ingrese la cantidad de pisos de la matriz"<<endl;
	cin>>pisos;
	//parqueo Temporal=new parqueo();
	parqueo* Temporal=new parqueo(personas,altura,pisos);
	return Temporal;
}

//Menu principal del programa
int menu(){
	int Respuesta=-100;
	while(Respuesta<=0||Respuesta>4){
		cout<<"Bienvenido al laboratorio #"<<endl<<"Seleccione la opcion que desea: "<<endl;
		cout <<"1-Crear parqueo."<<endl<<"2-Crear Carros y Agregar a parqueo"<<endl<<"3- Eliminar Carro del parqueo"<<endl<<"4-Listar Parqueo."<<endl;
		cin>>Respuesta;
	}
	return Respuesta;
}//Fin del metodo del Menu.



//liberar memoria
void liberarMatriz(int**& matriz, int size){
        for(int i= 0; i<size; i++){
                delete[] matriz[i];
                matriz[i] = NULL;
        }

        delete[] matriz;
        matriz = NULL;

        cout<< "Espacio liberado"<< endl;
}
//Liberar memoria de la matriz.
void liberarTablero(string**& tablero, int size){
        for(int i = 0; i< size; i++){
                delete[] tablero[i];
                tablero[i] = NULL;
        }

        delete[] tablero;
        tablero = NULL;

        cout<< "liberado memoria tablero "<< endl;
}


