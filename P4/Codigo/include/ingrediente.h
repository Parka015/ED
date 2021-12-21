/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA ingrediente
  *
  */

/* 
 * File:   Ingrediente.h
 * Author: pablo
 *
 * Created on 12 de octubre de 2019, 13:42
 */

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "string"
#include "iostream"
#include <fstream>
using namespace std;




/**
  *  @brief T.D.A. ingrediente
  *
  * Una instancia del tipo de datos abstracto ingrediente es un objeto
  * compuesto de las caracteristicas principales de un ingrediente alimenticio
  * (calorias,proteinas, hidratos de carbono,grasas, fibra y el tipo de alimento)
  */

class ingrediente {

private:


/**
  * @page repConjunto Rep del TDA ingrediente
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es cal, hdc,proteinas,grasas,fibra >=0
  *
  * @section faConjunto Función de abstracción
  *
  *
  */
    
    string nombre;
    float calorias; //por cada 100g
    float hdc; //hidratos de carbono
    float proteinas;
    float grasas;
    float fibra;
    string tipo;

  

public:
    
    
    /**
    * @brief Constructor por defecto de la clase. Crea el ingrediente inicializado
    * a 0 (sus atributos float) y el nombre y tipo inicializados a "Undefined"
    */
    ingrediente();
    
 /**
  * @brief Constructor de la clase
  * @param nom nombre del ingrediente (en 100 gramos)
  * @param cal numero de calorias del ingrediente (en 100 gramos)
  * @param hdc numero de hidratos de carbono del ingrediente (en 100 gramos)
  * @param protein numero de proteinas del ingrediente (en 100 gramos)
  * @param grasa numero de grasas del ingrediente  (en 100 gramos)
  * @param fib numero de fibras del ingrediente (en 100 gramos)
  * @param tip nombre del tipo al que pertenece el ingrediente 
  * @return Crea el ingrediente inicializado con los parametros de entrada
  * @pre cal, hdc, protein, grasa, fib deben ser mayores que cero
  */
    ingrediente(string nom,float cal,float hdc,float protein,float grasa,float fib,string  tip);
    
    
    //Modificadores
    
    /**
  * @brief Modificador completo de la clase
  * @param nom nombre del ingrediente (en 100 gramos)
  * @param cal numero de calorias del ingrediente (en 100 gramos)
  * @param hdc numero de hidratos de carbono del ingrediente (en 100 gramos)
  * @param protein numero de proteinas del ingrediente (en 100 gramos)
  * @param grasa numero de grasas del ingrediente  (en 100 gramos)
  * @param fib numero de fibras del ingrediente (en 100 gramos)
  * @param tip nombre del tipo al que pertenece el ingrediente 
  * @return Modifica el ingrediente con los parametros de entrada
  * @pre cal, hdc, protein, grasa, fib deben ser mayor o igual que cero
  */
    void setIngrediente(string nom,float cal,float hdc,float protein,float grasa,float fib,string  tip);
    
    
    /**
  * @brief Modificador del atributo nombre de la clase
  * @param nom nombre del ingrediente (en 100 gramos)
   */
    void setNombre(string nom);
    
    
    /**
  * @brief Modificador del atributo calorias de la clase
  * @param cal numero de calorias del ingrediente (en 100 gramos)
   * @pre debe ser mayor o igual a cero
   */
    void setCalorias(float cal);
    
    
   /**
  * @brief Modificador del atributo hidratos de carbono de la clase
  * @param hdc numero de hidratos de carbono del ingrediente (en 100 gramos)
   * @pre debe ser mayor o igual a cero
   */
    void setHDC(float hdc);
    
    
    /**
  * @brief Modificador del atributo proteinas de la clase
  * @param protein numero de proteinas del ingrediente (en 100 gramos)
   * @pre debe ser mayor o igual a cero
   */
    void setProteinas(float protein);
    
    
   /**
  * @brief Modificador del atributo grasas de la clase
  * @param grasa numero de grasas del ingrediente  (en 100 gramos)
   * @pre debe ser mayor o igual a cero
   */
    void setGrasas(float grasa);
    
    
    
   /**
  * @brief Modificador del atributo fibra de la clase
  * @param fib numero de fibras del ingrediente (en 100 gramos)
  * @pre debe ser mayor o igual a cero
   */
    void setFibra(float fib);
    
    
   /**
  * @brief Modificador del atributo tipo de la clase
  * @param tip nombre del tipo al que pertenece el ingrediente 
   */
    void setTipo(string  tip);
    
    //Consultores
    /**
  * @brief get de nombre
  * @return Devuelve el nombre del ingrediente
  */   
    string getNombre()const;
    
    
  /**
  * @brief get de calorias
  * @return Devuelve el numero de calorias del ingrediente
  */   
    float getCalorias()const;
    
    
  /**
  * @brief get de hidratos de carbono
  * @return Devuelve el numero de hdc del ingrediente
  */  
    float getHc()const;
    
  /**
  * @brief get de proteinas
  * @return Devuelve el numero de proteinas del ingrediente
  */  
    float getProteinas()const;
    
    
  /**
  * @brief get de grasas
  * @return Devuelve el numero de grasas del ingrediente
  */  
    float getGrasas()const;
    
  /**
  * @brief get de fibras
  * @return Devuelve el numero de fibras del ingrediente
  */  
    float getFibra()const;
    
    
  /**
  * @brief get de tioo
  * @return Devuelve el tipo del ingrediente
  */  
    string getTipo()const;
    
    //Metodos
   
    
    
    /**
  * @brief Sobrecarga del operador >>
  * @param flujo stream de entrada
  * @param ing ingrediente a escribir
  * @pre La entrada tiene el formato:
     * nombre
     * calorias
     * hidratos sde carbono
     * proteinas
     * grasas
     * fibras
     * tipo
     * 
   * @pre cal, hdc, protein, grasa, fib deben ser mayor o igual que cero
  */  
   friend istream& operator>> (istream& flujo,ingrediente &ing);
   
   
   /**
  * @brief Sobrecarga del operador <<
  * @param flujo stream de salida
  * @param ing ingrediente a mostrar
  * @post Se obtiene en una la cadena con la info del ingreediente
  */  
   friend ostream& operator<< (ostream &flujo,const ingrediente &ing);


};




#endif /* INGREDIENTE_H */

