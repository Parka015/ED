#ifndef RECETA_H
#define RECETA_H
#include <string>
#include <list>
#include <iostream>
#include <instrucciones.h>
#include <ctype.h>

using namespace std;

class receta{
	private:
  
	string code;  
	unsigned int plato;
	string nombre;
	list<pair<string,unsigned int> > ings;
	float calorias = 0,hc = 0,grasas = 0,proteinas = 0,fibra = 0;
        instrucciones inst;
           
	public:

	receta();
        receta fusionarReceta(/*const*/ receta /*&*/ rec);
        void mostrarDatosReceta();
	string getNombre()const;
	string getCode()const;
	unsigned int getPlato()const;
	list<pair<string,unsigned int> > getIngs()const;

	float getCalorias()const;
	float getHc()const;
	float getGrasas()const;
	float getProteinas()const;
	float getFibra()const;

	void setNombre(string nombre);
	void setCode(string code);
	void setPlato(unsigned int plato);

	void setCalorias(float cal);
	void setHc(float h);
	void setGrasas(float gr);
	void setProteinas(float prot);
	void setFibra(float fib);

	void insertar(pair<string,unsigned int> ing);
	int ningredientes();
	void clear();
        bool CargarReceta( const string &path_ins,const instrucciones &instr);

	

	class iterator{ 
		private: 
                    list<pair<string,unsigned int> >::iterator it;   
       
                public:

        iterator(){}

        bool operator == (const iterator &i)const {

            return  i.it==it;

        }

        bool operator != (const iterator &i)const {

            return  i.it!=it;

        }

        const pair<string,unsigned int> & operator *()const {

            return *it;

        }

        iterator &operator ++(){

            ++it;
            return *this;

        }

        iterator &operator --(){

            --it;
            return *this;

        }

        friend  class receta;
        friend  class const_iterator;

    }; //fin iterator
         
	class const_iterator{       
	private:           
		list<pair<string,unsigned int>> ::const_iterator it;   
	public:

        const_iterator(){}

        const_iterator(const iterator &i):it(i.it){}

        bool operator == (const const_iterator & i)const {

            return i.it==it;

        }

        bool operator != (const const_iterator & i)const {

            return i.it!=it;

        }
        
        const pair<string,unsigned int> & operator *()const {

            return *it;

        }

        const_iterator &operator ++(){

            ++it;
            return *this;

        }

        const_iterator &operator --(){

            --it;
            return *this;

        }

        friend  class  receta;

    }; //fin const_iterator

	iterator begin(){
            
            iterator i;
            i.it=ings.begin();
            return i;
            
        }

	iterator end(){
            
             iterator i;
            i.it=ings.end();
            return i;
            
        } 
   
	const_iterator begin()const{
            
            const_iterator i;
            i.it=ings.begin();           
            return i;
            
        }

	const_iterator end()const{
            
             
            const_iterator i;
            i.it=ings.end();
            return i;
            
        }



friend istream& operator>> (istream& flujo,receta &r);

friend ostream& operator<< (ostream &flujo,const receta &r);

};//end receta

#endif
