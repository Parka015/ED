#include "receta.h"
#include "ingrediente.h"
#include "recetas.h"
#include "ingredientes.h"
#include "string"

#include <fstream>
using namespace std;

//Para copiar elementos de una fila a otra hasta cierto punto
void CopiaParcialFilaMatriz(vector <vector <int>> m,int fila, int columna, int inicio, int fin){
    
    for(columna=inicio;columna<=fin;columna++){
                    
        m[fila][columna]=m[fila-1][columna]; //copia los elementos de la fila anterior
    }
}

int main(int argc,char *argv[]){
	
	//Recibe y comprueba argumentos

	if (argc!=4){
		cout<<"Uso: nutricion_receta <fichero_recetas> <fichero_ingredientes> <(numero maximo de calorias)>"<<endl;
		return 0;
	}

	ifstream frecetas(argv[1]);

	if (!frecetas){
		cout<<"No existe el fichero de recetas"<<argv[1]<<endl;
		return 0;
	}

	ifstream fingredientes(argv[2]);

	if (!fingredientes){
		cout<<"No existe el fichero de ingredientes"<<argv[2]<<endl;
		return 0;
	}

	int maxCalorias = atoi(argv[3]);

	recetas rall;
	ingredientes iall;

	frecetas >> rall;
	fingredientes >> iall;

	/*Mostrar conjuntos de receta con sus valores nutricionales:

	Valores Nutricionales de la receta R1;1;Ensalada Mixta;Lechuga 200;Tomate 50;Pepino 50;Cebolla 50;Aceite Oliva 5;Vinagre De Vino 10;Sal 1 son :
	Calorias 92.85
	Hidratos de Carb.
	7.1
	Proteinas
	3.5
	Grasas 5
	Fibra
	5.5
	
	etc etc

	Para ello obtenemos cada ingrediente en la receta y lo buscamos en el fichero de ingredientes
	*/
	recetas::iterator it_recetas;

	for(it_recetas = rall.begin(); it_recetas != rall.end(); ++it_recetas){
		
		receta::iterator it_r;
		
		for (it_r = (*it_recetas).begin(); it_r != (*it_recetas).end(); ++it_r){
			
			float cantidad = ((float)((*it_r).second))/(float)100;

			ingrediente ing = iall.get((*it_r).first);

			(*it_recetas).setCalorias((*it_recetas).getCalorias() + ing.getCalorias() * cantidad);
			(*it_recetas).setHc((*it_recetas).getHc() + ing.getHc() * cantidad);
			(*it_recetas).setProteinas((*it_recetas).getProteinas() + ing.getProteinas() * cantidad);
			(*it_recetas).setGrasas((*it_recetas).getGrasas() + ing.getGrasas() * cantidad);
			(*it_recetas).setFibra((*it_recetas).getFibra() + ing.getFibra() * cantidad);
		}

		cout << endl << "Valores Nutricionales de la receta " << *(it_recetas) << " son: " << endl;

		cout << "Calorias " << (*it_recetas).getCalorias() 
			<< "\tHidratos de Carb. " << (*it_recetas).getHc()
			<< "\tProteinas " << (*it_recetas).getProteinas()
			<< "\tGrasas " << (*it_recetas).getGrasas()
			<< "\tFibra " << (*it_recetas).getFibra() << endl;
	}
        
         
        /*******************************************************************************************/
        //Segunda seccion
                                //filas                     //cols
        vector <vector <float>> m(rall.size()+1, vector <float> (maxCalorias+1, 0));
        int fila=1;
        int columna=1;
               
        
        vector <float> razones;
      
        it_recetas = rall.begin();
        
        
        
        for(;it_recetas!=rall.end();++it_recetas)
            razones.insert(razones.end(), ( (*it_recetas).getProteinas() / (*it_recetas).getHc()) );
        
        vector <string> rec_elegidas; //Para almacenar el codigo de las recetas que se escojan
              
        
        for(it_recetas = rall.begin();fila<m.size();fila++,++it_recetas){
            
            for(columna=1;columna<=maxCalorias;columna++){
            
                if( (int) (*it_recetas).getCalorias() <=maxCalorias && (int) ((*it_recetas).getCalorias()+1)<=columna){
                                    
                    
                    if( (razones[fila-1]+m[fila-1][columna-(int)((*it_recetas).getCalorias()+1)])>m[fila-1][columna]){
                        
                        m[fila][columna]=razones[fila-1]+m[fila-1][columna-(int)((*it_recetas).getCalorias()+1)];
                        
                        
                    }else
                       m[fila][columna]=m[fila-1][columna]; 
                    
                    
                }else{
                    
                    m[fila][columna]=m[fila-1][columna];
                    
                }
                    
             }
           
        }
    
        
        fila=rall.size();
        columna=maxCalorias;
        it_recetas=rall.end();
        --it_recetas;
               
        
        
        
        while ( fila>0 && columna>0){
            
            if(m[fila][columna] != m[fila-1][columna]){
                rec_elegidas.push_back((*it_recetas).getCode());
                fila=fila-1;
                columna=columna-(int)((*it_recetas).getCalorias()+1);
            }else
                fila=fila-1;
            
           --it_recetas;
        }
                
        
        if(rec_elegidas.empty()){
            cout<<endl<<"No hay recetas que cumplan el limite de calorias"<<endl;
        }else{
        cout<<endl<<"Las recetas elegidas para un maximo de "<<maxCalorias<<" calorias son: "<<endl;
        for(int i=0; i<rec_elegidas.size();i++)
            cout<<i<<"º"<<" Receta: "<<rall[rec_elegidas[i]]<<" || Total Calorias: "<<rall[rec_elegidas[i]].getCalorias()<<endl;//<<rall[rec_elegidas[i]].getProteinas() / rall[rec_elegidas[i]].getHc();
        }

	return 0;
}
