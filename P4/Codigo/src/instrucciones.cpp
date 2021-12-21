
#include "instrucciones.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

instrucciones::instrucciones(const acciones &acc1){
	acc = acc1;
}

instrucciones::instrucciones(){
    
}


ArbolBinario<string>  instrucciones::getArbol(){

    return datos;
    
}


void instrucciones::clear(){
    
    datos.clear();
}

//Para que funcione correctamente los archivos de texto no puede tener lineas vacias, es decir una vez escrito el archivo de txt, añadirle un salto de linea
/**
    @brief. Inserta un subarbol como hijo a la izquierda de uno dado que consta de un solo nodo
    @param dir_ins: Direccion del archivo con la instruccion
    @param ings: La lista de ingredientes de la receta
    @note Para que funcione correctamente los archivos de texto no puede tener lineas vacias, es decir una vez escrito el archivo de txt, añadirle un salto de linea
    */
bool instrucciones::crearArbol(const string &dir_ins,const list<pair<string,unsigned int> > &ings){
    int cont=0;
    ifstream dirIns1;
    
        dirIns1.open(dir_ins);
        

        
        if(dirIns1.fail()){
            cout<<"Error al leer direccion (instrucciones)"<<endl;
            return false;
        }
        
        
        stack <ArbolBinario <string>> pila;
	
	datos.clear();
        
        istream &dirIns=dirIns1;
        
        stack <string> elementos;
    	string accion;
    	string ing="";

    	string aux;
        
    	string linea;
    	int pos;
        char ariedad;

     	while (getline(dirIns,linea)){          
           
            linea=linea+"\n";
            
          	if(linea.c_str()==0) 
                	return false;
            
   
        	//Captar accion

                if(linea.find(" ")==string::npos){ //En la linea hay solo una instruccion
                   
                   
                    pos=linea.find("\n");

                    if(pos==string::npos)
			pos=linea.find("\r");
                    
                    accion=linea.substr(0,pos);
                    
                                    
                    ariedad = (*this).acc.getAriedad(accion);
                    
                
			if(ariedad == '2'){
                            
                        
				ArbolBinario<string> i1 = pila.top();                                        
                                pila.pop();
                                
				ArbolBinario<string> i2 = pila.top();                                        
                                pila.pop();
				
				ArbolBinario<string>arbol(accion);
				arbol.Insertar_Hd(arbol.getRaiz(),i1);
				arbol.Insertar_Hi(arbol.getRaiz(),i2);
				
				pila.push(arbol);
                                
                    
                                
			}else if(ariedad == '1'){
                            
                    
                            
				ArbolBinario<string> i1 = pila.top();                                        
                                pila.pop();

				ArbolBinario<string>arbol(accion);
				arbol.Insertar_Hi(arbol.getRaiz(),i1);
                                
                                pila.push(arbol);
                                
                    
			}
                    
                }else{  //En la linea hay una instruccion y un ingrediente
                 
                  
		pos=linea.find(" ");               
                 
		accion=linea.substr(0,pos);

		linea=linea.substr(pos+1);
                
                                         

		//Captar ingrediente
                
                list<pair<string,unsigned int>>::const_iterator it=ings.cbegin();
                bool encontrado=false;
                
                while(!linea.empty()){
                    
                    encontrado=false;
                     
                    it=ings.cbegin();
                    
                    
                   
                    
                    if(pos=linea.find(" ")==string::npos){                        
                        
                         pos=linea.find("\n");
                        

                    if(pos==string::npos)
			pos=linea.find("\r"); 
                                                 
                    }else
                        
                        pos=linea.find(" ");
                    
                                         
		
                    aux=linea.substr(0,pos);
                    
                    if(ing!="")
                        aux=" "+aux;
                    
                    ing=ing+aux;
                
               
                while(it != ings.cend()  && !encontrado){
                   
                if (ing== it->first ){
                    
                    encontrado=true;
                    
                    elementos.push(ing);
                    
                    ing="";
                    
                }
                
                it++;
         
                }
          
                   
                linea=linea.substr(pos+1);            
              
                }
                
                if(!encontrado)
                    elementos.push(ing);
                    
                
            
                                              
            ariedad=(*this).acc.getAriedad(accion);
            
            ArbolBinario<string>arbol2(accion);
            
            if(ariedad == '2'){
                
                if(elementos.size()==2){
                    
                    arbol2.Insertar_Hi(arbol2.getRaiz(), elementos.top());
                    elementos.pop();
                    arbol2.Insertar_Hd(arbol2.getRaiz(),elementos.top());
                    elementos.pop();
                                        
                   
                }else{
                            ArbolBinario<string> i3 = pila.top();                                        
                                pila.pop();
                            arbol2.Insertar_Hi(arbol2.getRaiz(),i3);
                            arbol2.Insertar_Hd(arbol2.getRaiz(),elementos.top());
                            elementos.pop();
                                                 
                }
                
             }else{
                
                        
			
			arbol2.Insertar_Hi(arbol2.getRaiz(),elementos.top());
                        elementos.pop();
                     
                     }   
                                            

			pila.push(arbol2);
                        
                     
		}
//cont++;
        //cout<<cont<<endl;		
	//cout<<pila.size()<<endl;       
      // cin.get();	
	}
        //cout<<pila.size()<<endl;       
       // cin.get();
	(*this).datos = pila.top();                                        
        pila.pop();       
       
        dirIns1.close();
        
    return true;
    
}

ArbolBinario<string> & instrucciones::operator=(const ArbolBinario<string> & ab){
	  if (&(this->datos)!=&ab){
              datos=ab;
	  }
}


ostream & operator<<(ostream &os,const instrucciones &ins){
    	ArbolBinario<string>::postorden_iterador it = ins.datos.beginpostorden();
        stack<string> ing;
        //vector<string>::iterator iter;
        string aux;
        int cont=0;

	
	for(; it != ins.datos.endpostorden(); ++it){
            
            cont++;
            
            

            if(it.hd().nulo() && it.hi().nulo()){
               
                ing.push(*it);
                
            }else{
            
                if(!ing.empty()){
                
                os << *it;
                
                  while(!ing.empty()){
                        os<<" "<<ing.top();
                       
                        ing.pop();
                    }
                
                cout<<endl;
                
                }else
                    
                     os << *it << endl;  
                
                
             
            }
            
            
	}

	return os;   
}


