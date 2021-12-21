#include <string>

#include "receta.h"
using namespace std;

	receta::receta(){
		nombre = "Undefined";
		code = "Undefined";
		plato = 0;
                
	}

    string receta::getNombre()const{
    
        return nombre;
    
    }
    /**
     * @brief  Carga la receta con las instrucciones necesarias
     * @param path_ins: Direccion de el directorio con las instrucciones 
     * @param instr: Instrucciones con las acciones cargadas
     * @return Si ha tenido exito o no
     */
    bool receta::CargarReceta( const string &path_ins,const instrucciones &instr){
                
        
        string aux=path_ins + code +"m.txt"; 
        
        inst=instr;
        
        
       if(inst.crearArbol(aux,ings)){
          
           return true;
           
       }

        return false;
              
    }


    string receta::getCode()const{
        
        return code;
        
    }
    
    unsigned int receta::getPlato()const{
        
        return plato;
        
    }
    
    list<pair<string,unsigned int> > receta::getIngs()const{
        
        
        return ings;
        
    }

    void receta::setNombre(string nombre){
        
        this->nombre=nombre;
        
    }
            
    void receta::setCode(string code){
        
        this->code=code;
        
    }
            
    void receta::setPlato(unsigned int plato){
        
        this->plato=plato;
        
    }
            
    void receta::insertar(pair<string,unsigned int> ing){
         
       ings.push_back(ing);  
         
    }
    
    int receta::ningredientes(){
	 
	return ings.size();  
	 
    }
    
    void receta::clear(){
        
        ings.clear();
        
    }

	float receta::getCalorias()const{return calorias;}
	float receta::getHc()const{return hc;}
	float receta::getGrasas()const{return grasas;}
	float receta::getProteinas()const{return proteinas;}
	float receta::getFibra()const{return fibra;}

	void receta::setCalorias(float cal){calorias = cal;}
	void receta::setHc(float h){hc = h;}
	void receta::setGrasas(float gr){grasas = gr;}
	void receta::setProteinas(float prot){proteinas = prot;}
	void receta::setFibra(float fib){fibra = fib;}
        
        //Vendria a ser como el operador de salida pero el de salida muestra la receta
        //con el formato de receta.txt y este lo muestra tal y como se muestra en la guia
       /**
          @brief. Muestra toda la informacion necesaria de la receta
	    
        */
        void receta::mostrarDatosReceta(){
            
            cout<<"CODE: "<<code<<" "<<"RECETA: "<<nombre<<" "<<"PLATO: "<<plato<<endl<<endl;
            
            cout<<"Ingredientes: "<<endl<<endl;
            
            list<pair<string,unsigned int>>::iterator it;

            for(it = ings.begin();it != ings.end();++it){
		cout<<"   "<<(*it).first<<" "<<(*it).second<<endl;
            }
            
            cout<<"Informacion Nutricional: "<<endl<<endl;
            
            cout << "   Calorias: " << calorias<<endl
                 << "   Hidratos de Carbono: " << hc<<endl		 
		 << "   Grasas: " << grasas<<endl
                 << "   Proteina: " << proteinas<<endl
		 << "   Fibra: " << fibra << endl;
            
            cout<<"Pasos a seguir: "<<endl<<endl;
            
            cout<<inst;
            
        }
        //Al poner const ... & me daba problemas el getArbol y no he conseguido resolverlo por eso la cabecera es asi
        receta receta::fusionarReceta(/*const*/ receta /*&*/ rec){
            
            receta aux;
            
            list<pair<string,unsigned int>>::iterator it;
            list<pair<string,unsigned int>>::iterator it2;
            bool incluido=false;
            
            aux.ings=this->ings;
            
            for(it = rec.ings.begin();it != rec.ings.end();++it){
                
                incluido=false;
                
                for(it2 = aux.ings.begin();it2 != aux.ings.end() && !incluido;++it2){
                    
                    if(it->first==it2->first){
                        
                        incluido=true;
                        it2->second=it2->second+it->second;
                        
                    }
                    
                }    
                   
                if(!incluido)
                    aux.ings.push_back(*it);
                                  
            }
            
            //El criterio para el plato que uso es primero 2º plato, despues 1º plato y despues 3ª plato
            //Siguiendo este criterio el valor mas "alto" sera el que tenga la nueva receta
            
            if(plato==2 || rec.plato==2)
                aux.plato=2;
            
            else{
                
                if(plato>rec.plato)
                    aux.plato=rec.plato;
                else
                    aux.plato=plato;
                    
            }
            
            aux.nombre="Fusion "+nombre+" y "+rec.nombre;
            aux.code="F_"+code+"_"+rec.code;
            
            aux.calorias=calorias+rec.calorias;
            aux.grasas=grasas+rec.grasas;
            aux.proteinas=proteinas+rec.proteinas;
            aux.fibra=fibra+rec.fibra;
            aux.hc=hc+rec.hc;
            
            ArbolBinario<string> arb("Acompañar");
            
             ArbolBinario<string> i1=inst.getArbol();
             ArbolBinario<string> i2=rec.inst.getArbol();
            
            
            arb.Insertar_Hi(arb.getRaiz(), i1);
                 
            arb.Insertar_Hd(arb.getRaiz(),i2);
            
            aux.inst=arb;
            
            return aux;
            
        }
    
    ostream& operator<< (ostream &flujo,const receta &r){

	flujo<<r.getCode()<<";"<<r.getPlato()<<";"<<r.getNombre();
	

	list<pair<string,unsigned int>> ings = r.getIngs();
	list<pair<string,unsigned int>>::iterator it;

	for(it = ings.begin();it != ings.end();++it){
		flujo<<";"<<(*it).first<<" "<<(*it).second;
	}

	return flujo;
}
    
    istream& operator>> (istream& flujo,receta &r){
    
    string linea;
    
    getline(flujo,linea);
    
    r.clear();

    if(linea.c_str()==0 || linea.size()==0) 
        return flujo;
    
    //Captar codigo
    
    int pos=linea.find(";");
    
    r.setCode(linea.substr(0,pos));
    
    linea=linea.substr(pos+1);
    
    //Captar plato
    
    string aux;
  
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    r.setPlato(atoi(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar nombre
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    r.setNombre(aux);
        
    linea=linea.substr(pos+1);
    
    //Captar lista de ingredientes
    do{
		pos=linea.find(";");
	       
		aux=linea.substr(0,pos);
		string nombre;
		unsigned int cantidad = 0;
		int posCantidad = 0;

		for(int i = 0;i < aux.length() && !isdigit(aux.at(i));i++){
			posCantidad = i;
		}

		nombre = aux.substr(0,posCantidad);
		cantidad = atoi(aux.substr(posCantidad+1).c_str());
	
		pair <string,unsigned int> ing(nombre, cantidad);

		r.insertar(ing);
		linea=linea.substr(pos+1);
    }while(pos != string::npos);
    
    return flujo;
    
}





