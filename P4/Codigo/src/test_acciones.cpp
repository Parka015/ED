#include "acciones.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
  if (argc!=2){
    cout<<"Dime el fichero con las acciones"<<endl;
    return 0;
  
  }
  ifstream f(argv[1]);
  if (!f){
	  cout<<"No existe el fichero "<<argv[1]<<endl;
  }
  /***********************************************************************/
  
  //SECTION 1: Test sobre TDA receta. Operadores de entrada y salida
  acciones r;
  f>>r;
  cout<<"Las Acciones leidas son "<<endl<<r<<endl;
  cout<<"Pulse una tecla para continuar"<<endl;
  cin.get();
  /***********************************************************************/

}
