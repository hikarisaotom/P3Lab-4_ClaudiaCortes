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
carro crearcarro(carro****,int,int,int);
int main()
{	bool Continuar=1;
	parqueo* Global_parqueo;
	vector<string> Array;
	carro**** carros;
	while (Continuar){
		//Llamado del menu del programa.
		switch(menu()){
			case 1:{//
				cout<<"Usted selecciono: crear parqueo"<<endl;
				Global_parqueo=crearparqueo();
				carros=Global_parqueo->getmatriz();
				break;
				}//Fin del case 1.
			case 2:{//
				cout<<"Usted selecciono: crear carro"<<endl;
				crearcarro(Global_parqueo->getmatriz(), Global_parqueo->getn(),Global_parqueo->getm(),Global_parqueo->getaltura());
				break;
				}//Fin del case 2

			case 3:{//
				cout<<"Usted selecciono: "<<endl;

				break;
				}//Fin del case 3

			case 4:{//
				cout<<"Usted selecciono: "<<endl;

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
carro  crearcarro(carro**** parqueo,int  x,int y, int altura){
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
	for (int i=0;i<x;i++){
		for (int j=0;j<y;j++){
			if (parqueo[piso][i][j]==NULL){
			//temporal = new carro();
				parqueo[i][j][piso] = new carro(matricula,color,alturacarro);
			}
		}
	}


}
parqueo* crearparqueo(){
	int personas=-5;
	int pisos=0;
	int altura=0;
//	parqueo Temporal;
	while (personas<=50||personas>=100){
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


