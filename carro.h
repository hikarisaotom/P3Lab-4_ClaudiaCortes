using namespace std;
#ifndef CARRO_H
#define CARRO_H
//#pragma once
#include <string>
class carro{
	private:
		string color;
		string marca;
		int altura;
	public :
		carro();
		carro(string,string,int);
		~carro();
		void setcolor(string);
		void setmarca(string);
		void setaltura(int);
		string getcolor();
		string getmarca();
		int getaltura();

};
#endif
