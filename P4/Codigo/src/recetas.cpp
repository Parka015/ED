#include "recetas.h"
#include <fstream>
#include <string>
#include <map>
using namespace std;


void recetas::insertar(const receta &r){
    
    pair<string,receta> p(r.getCode(), r);
    
    datos.insert(p);
    
}



void recetas::setNutricion(ingredientes &ings){

    recetas::iterator it_recetas;

	for(it_recetas = begin(); it_recetas != end(); ++it_recetas){
		
		receta::iterator it_r;
		
		for (it_r = (*it_recetas).begin(); it_r != (*it_recetas).end(); ++it_r){
			
			float cantidad = ((float)((*it_r).second))/(float)100;

			ingrediente ing = ings.get((*it_r).first);

			(*it_recetas).setCalorias((*it_recetas).getCalorias() + ing.getCalorias() * cantidad);
			(*it_recetas).setHc((*it_recetas).getHc() + ing.getHc() * cantidad);
			(*it_recetas).setProteinas((*it_recetas).getProteinas() + ing.getProteinas() * cantidad);
			(*it_recetas).setGrasas((*it_recetas).getGrasas() + ing.getGrasas() * cantidad);
			(*it_recetas).setFibra((*it_recetas).getFibra() + ing.getFibra() * cantidad);
		}
        }
}

void recetas::borrar(const string &c){
    
    datos.erase(c);
    
}

void recetas::mostrarRecetas(){
    
    map<string,receta>::const_iterator it=datos.begin();

	for(;it!=datos.end();it++){
		cout<<"CODE: "<<(*it).first<<" "<<"NOMBRE: "<<(*it).second.getNombre()<<" "<<"Plato: "<<(*it).second.getPlato()<<endl;
	}

    
}


bool recetas::CargarRecetas(const string& dir_recetas, const string& path_ins, instrucciones &instr){
	datos.clear();
//hacer las direcciones fstream
	receta r;
        
        
        
        ifstream dirRec;
        dirRec.open(/*"datos/recetas.txt"*/dir_recetas);
        
        if(!dirRec){
          
            cout<<"Error al leer direccion (cargar recetas)"<<endl;
            return false;
        }
        
	while (dirRec>>r){
            
           if(!r.CargarReceta(path_ins,instr))
               return false;
            
            (*this).insertar(r);
	}
       
        dirRec.close();
    
    return true;
    
}

istream & operator>>(istream &is,recetas &rs){
	rs.clear();

	receta r;

	while (is>>r){
    		rs.insertar(r);
	}
    
    return is;
    
}


ostream & operator<<(ostream &os,const recetas &rs){
    
	map<string,receta>::const_iterator it=rs.datos.begin();

	for(;it!=rs.datos.end();it++){
		os<<"Codigo: "<<(*it).first<<" "<<"Receta: "<<(*it).second<<endl;
	}

	return os;
}


