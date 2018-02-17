using namespace std;
#ifndef PARQUEO_H
#define PARQUEO_H
#include "carro.h"
class parqueo{
	private:
		int pisos;
		int personas;
		int altura;
		int capacidad;
		carro**** carros;
		int n;
		int m;
		int z;
	public:
	
		parqueo();
		parqueo(int,int,int);
		~parqueo();
		void setpisos(int);
		void setcapacidad(int,int);
		int getpisos();
		int getcapacidad();
		carro**** getmatriz();
		int getm();
		int getn();
		int getaltura();
		void eliminarcarro(int,int,int);
		void agregarcarro(carro*,int);
		void contabilizar();

		
};
#endif
