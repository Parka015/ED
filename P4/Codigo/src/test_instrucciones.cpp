#include "instrucciones.h"
#include "recetas.h"
#include "acciones.h"
#include "ingredientes.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc,char *argv[]){
  if (argc!=5){
    cout<<"Dime el fichero con las acciones y el fichero con las instrucciones, recetas y luego ingredientes"<<endl;
    return 0;
  
  }
  ifstream f(argv[1]);
  if (!f){
	  cout<<"No existe el fichero "<<argv[1]<<endl;
  }
  
  ifstream fIng(argv[4]);
  if (!fIng){
	  cout<<"No existe el fichero "<<argv[2]<<endl;
  }

  /***********************************************************************/
  
  //SECTION 1: Test sobre TDA Acciones. Operadores de entrada y salida
  acciones acc;
  f>>acc;
  cout<<"Las Acciones leidas son "<<endl<<acc<<endl;
  cout<<"Pulse una tecla para continuar"<<endl<<endl;
  cin.get();
  /***********************************************************************/

  //SECTION 2: Test sobre TDA Instrucciones. Operadores de entrada y salida
  instrucciones ins(acc);
  ingredientes ings;
  fIng>>ings;
  string srecs,sins;
  recetas recs;
  
  
  
  recs.CargarRecetas(argv[3],argv[2],ins);
  
  
  
  //ins.setAcciones(acc);
  //fIns>>ins;
  cout<<"Las instrucciones son: "<<endl<<recs<<endl;
  cout<<"Pulse una tecla para continuar"<<endl;
  cin.get();
  /***********************************************************************/

}
