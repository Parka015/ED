/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA ingrediente
  *
  */

/* 
 * File:   Ingredientes.h
 * Author: pablo
 *
 * Created on 19 de octubre de 2019, 21:22
 */

#ifndef INGREDIENTES_H
#define INGREDIENTES_H
#include <vector>
#include <iostream>
#include <utility>
#include <ingrediente.h>


using namespace std;


/**
  *  @brief T.D.A. ingredientes
  *
  * Una instancia del tipo de datos abstracto ingredientes es un objeto
  * compuesto de un vector de ingrediente ordenado por nombre y un vector de indices 
  * a este siguiendo una ordenacion alfabetica del tipo y a igualdad de tipo, por nombre
  */
class ingredientes {

private:
    
    vector<ingrediente> datos;
    vector<int> indice;
    
    pair <bool,int> BuscarEnDatos(const ingrediente & ing);
    pair <bool,int> BuscarEnIndice(const ingrediente & ing);
    int BusquedaBinariaNombre(const ingrediente & ing);
    int BusquedaBinariaNombre(string nom);
    int BusquedaBinariaIndice(const ingrediente & ing);
    void Clear();
    
    
    
public:
    
    /**
     * @brief Constructor por defecto de la clase
     * @note Los vectores reservan 10 posiciones de memoria
     **/
    ingredientes();
    
    //METODOS 
    
    /**
     * @brief Borra un ingrediente de ingredientes
     * @param nom Se pasa el nombre del ingrediente a eliminar
     * @note en caso de no encontrar el elemento a borrar, lo notifica
     **/
    void borrar( string  nom);
    
    
    /**
     * @brief Borra un ingrediente de ingredientes
     * @param ing Se pasa el ingrediente a eliminar
     * @note en caso de no encontrar el elemento a borrar, lo notifica
     **/
    void borrar(const ingrediente & ing);
    
    
    /**
     * @brief Inserta un ingrediente a ingredientes
     * @param ing Se pasa el ingrediente a insertar
     **/
    void Insertar(const ingrediente & ing);
    
    
    /**
     * @brief Borra un ingrediente de ingredientes
     * @return Devuelve el valor del vector    
     **/
    int size()const;
    
    
    /**
     * @brief Muestra por pantalla a los ingredientes que haya en el vector ordenados por tipo y a igualdad de tipo por nombre
     * @return Devuelve los ingredientes por pantalla
     **/
    void ImprimirPorTipo(ostream & os);
    
    /**
     * @brief Muestra por pantalla la info de un ingrediente de ingredientes por medio de un nombre
     * @param nom Nombre del ingrediente
     * @return Devuelve la informacion del ingrediente
     **/
    void Info(string nom);
    
    
    /**
     * @brief Devuelve un ingrediente de ingredientes a partir del nombre
     * @param nom Nombre del ingrediente
     * @return Devuelve un dato tipo ingrediente
     * @note En caso de no encontrarlo devuelve un ingrediente inicializado
     * a 0 (sus atributos float) y el nombre y tipo inicializados a "Undefined"
     **/
    ingrediente get(string nom);
    
    
    /**
     * @brief Devuelve un tipo de datos ingredientes con los "ingredientes" del tipo especificado
     * @param tipo Tipo de ingrediente a buscar
     * @return Devuelve un dato tipo ingredientes
     * @note En caso de no encontrarlo lo notifica y se produce un exit
     * @note Los devuelve manteniendo la ordenacion
     **/
    ingredientes  getIngredienteTipo(string tipo);
    
    
    /**
     * @brief Devuelve un todos los tipos de ingrediente que hay en ingredientes sin repetir y ordenados
     * @return Devuelve un vector
     **/
    vector <string> getTipos();
    
    /**
     * @brief Modifica un ingrediente pasandole otro en su lugar
     * @param ing Es el ingrediente a modificar
     * @param nuevo Es el nuevo ingrediente a introducir
     * @note Sigue manteniendo la ordenacion por lo que no se garantiza que se guarde en la misma posicion
     **/
    void ModificarIngrediente(const ingrediente & ing,const ingrediente & nuevo);
   
    //OPERADORES
        
    /**
     * @brief Operador corchete de lectura
     **/
    const ingrediente &operator[] (int i) const {return datos[i];}
    
    /**
     * @brief Operador de asignacion
     **/
    ingredientes &  operator =(const ingredientes & ing1);


    //ITERATORS

    class iterator{

    private:

        vector<ingrediente>::iterator it;

    public:

        iterator(){}

        bool operator == (const iterator &i)const {

            return  i.it==it;

        }

        bool operator != (const iterator &i)const {

            return  i.it!=it;

        }

        const ingrediente & operator *()const {

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

        friend  class ingredientes;
        friend  class const_iterator;

    }; //fin iterator

    class const_iterator{

    private:

        vector<ingrediente>::const_iterator it;

    public:

        const_iterator(){}

        const_iterator(const iterator &i):it(i.it){}

        bool operator == (const const_iterator & i)const {

            return i.it==it;

        }

        bool operator != (const const_iterator & i)const {

            return i.it!=it;

        }
        
        const ingrediente & operator *()const {

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

        friend  class  ingredientes;

    }; //fin const_iterator




    iterator begin(){

        iterator i;
        i.it=datos.begin();
        return i;
    }

    iterator end(){

        iterator i;
        i.it=datos.end();
        return i;
    }


    const_iterator begin()const{

        const_iterator i;
        i.it=datos.begin();
        return i;
    }

    const_iterator end()const{

        const_iterator i;
        i.it=datos.end();
        return i;
    }

    /*
  * @brief Sobrecarga del operador >>
  * @param is stream de entrada
  * @param I ingredientes a escribir
  */  
    friend istream & operator >>(istream & is, ingredientes & I);
    
    
   /**
  * @brief Sobrecarga del operador <<
  * @param os stream de salida
  * @param I ingredientes a mostrar
  */  
    friend ostream & operator <<(ostream & os,const ingredientes & I);
    
    


};

bool operator ==(const ingrediente & ing1,const ingrediente & ing2);

#endif /* INGREDIENTES_H */

