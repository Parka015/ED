#include "instrucciones.h"
#include "recetas.h"
#include "acciones.h"
#include "ingredientes.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc,char *argv[]){
    
    //Fase de carga de datos
    
  if (argc!=5){
    cout<<"Introduce 1º el fichero con las acciones 2º el fichero con las recetas, 3º los ingredientes, 4º el directotio de las instrucciones,"<<endl;
    return 0;
  
  }
  ifstream fAcc(argv[1]);
  if (!fAcc){
	  cout<<"No existe el fichero de las acciones "<<argv[1]<<endl;
  }
  
  ifstream fIng(argv[3]);
  if (!fIng){
	  cout<<"No existe el fichero "<<argv[3]<<endl;
  }
  
  ingredientes ingrs;
  acciones acc;
  string dir_recs=argv[2];
  string dir_instr=argv[4];
  recetas rec;
  
  fIng>>ingrs;
  fAcc>>acc;
  
  instrucciones instr(acc);
  
  if(!rec.CargarRecetas(dir_recs,dir_instr,instr)){
      
      cout<<"Ha ocurrido un error con la carga de las recetas"<<endl;
      exit(-1);
  }
      
  rec.setNutricion(ingrs);
  
  //Comienza el programa 
  
  rec.mostrarRecetas();
  
  cout<<endl;
  
  string codigo;
  string fusion1;
  string fusion2;
  
  cout<<"Introduzca el codigo de una receta: "<<endl;
  cin>>codigo;
  
  if(rec[codigo].getNombre()=="Undefined"){
      
      cout<<"Fue introducido un codigo erroneo, por defecto se usara R1"<<endl;
      codigo="R1";      
  }
  
  rec[codigo].mostrarDatosReceta();
  
  cin.get();
  cin.get();
  
  /****************************************************************/
  //Fusion de recetas
  
  
  cout<<endl<<"Fase de fusion de Recetas"<<endl;
  
  cout<<"Introduzca el codigo la 1º receta: "<<endl;
  cin>>fusion1;
  
  if(rec[fusion1].getNombre()=="Undefined"){
      
      cout<<"Fue introducido un codigo erroneo, por defecto se usara R1"<<endl;
      fusion1="R1";      
  }
  
  cout<<"Introduzca el codigo la 2º receta: "<<endl;
  cin>>fusion2;
  
  if(rec[fusion2].getNombre()=="Undefined"){
      
      cout<<"Fue introducido un codigo erroneo, por defecto se usara R9"<<endl;
      fusion2="R9";      
  }
  
  receta aux=rec[fusion2];
  
  receta recetafusion;
  
  recetafusion=rec[fusion1].fusionarReceta(aux);
  cout<<endl;
  
  
  recetafusion.mostrarDatosReceta();
  

  
  cout<<endl<<endl<<"FIN"<<endl;
  
  cin.get();

  
}

