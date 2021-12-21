#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include "acciones.h"
#include "arbolbinario.h"
#include <string>
#include <list>
#include <fstream>
#include <stack>

class instrucciones{

	private:

	ArbolBinario<string> datos;
	/*static*/ acciones /*&*/acc;

	public:
            //hara falta iterador
	void clear();
        ArbolBinario<string> getArbol();
        instrucciones();
	instrucciones(const acciones &acc1);
        bool crearArbol(const string &dir_ins,const list<pair<string,unsigned int> > &ings);

	
	ArbolBinario<string> & operator=(const ArbolBinario<string> & ab);

	friend ostream & operator<<(ostream &os,const instrucciones &ins);
	
};

#endif /* INSTRUCCIONES_H */
