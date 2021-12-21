/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ingredientes.cpp
 * Author: pablo
 * 
 * Created on 19 de octubre de 2019, 21:22
 */

#include <vector>
#include <string.h>

#include <iostream>
#include <utility>
#include <ingrediente.h>

#include "ingredientes.h"

using namespace std;

ingredientes::ingredientes(){
    
}


void ingredientes::borrar( string  nom){

int a=BusquedaBinariaNombre(nom);
int aux;

vector <ingrediente>::iterator i;
vector <int>::iterator j;

i=datos.begin();


 
if(a>=0){
	datos.erase(i+a);
	for(int i=0;i<indice.size();i++)
		if(indice[i]==a)
		aux=i;
        
        for(int i=0;i<indice.size();i++)
		if(indice[i]>a)
                    indice[i]=indice[i]-1;
        j=indice.begin();
	indice.erase(j+aux);

}else 
	cout<<"No existe el elemento";
}

void ingredientes::borrar(const ingrediente & ing){

pair <bool,int> pos=BuscarEnDatos(ing);
int aux;
    
    if(pos.first){
        vector <ingrediente>::iterator i;
        vector <int>::iterator j;
        i=datos.begin();
	datos.erase(i+pos.second);
	for(int i=0;i<indice.size();i++)
		if(indice[i]==pos.second)
		aux=i;
        
        for(int i=0;i<indice.size();i++)
		if(indice[i]>pos.second)
                    indice[i]=indice[i]-1;
        j=indice.begin();
	indice.erase(j+aux);
}

else 
	cout<<"No existe el elemento";
}



int ingredientes::BusquedaBinariaNombre(const ingrediente & ing){ 
    
    int izda, dcha, centro; 
    bool encontrado = false;
    
    izda = 0;
    //indice del  elemento valido mas a la derecha
    dcha = datos.size() - 1;
    //indice del elemento en la mitad del vector
    centro = (izda + dcha) / 2;
    
    while (izda <= dcha && !encontrado){
        
    if (datos[centro] == ing)//lo hemos encontrado?
        encontrado = true;
    
    else
        //esta a la izquierda
        if (ing.getNombre()<datos[centro].getNombre())
            dcha = centro - 1;
        
        else//debe estar a la derecha
            
            
            izda = centro + 1;
    centro = (izda + dcha) / 2;
    }
    
    if (encontrado)
        return centro;
    
    else
        return (-1)*izda;//No esta en el vector
    
}

int ingredientes::BusquedaBinariaNombre(string nom){ 
    
    int izda, dcha, centro;
    bool encontrado = false;
        
    
    izda = 0;
    //indice del  elemento valido mas a la derecha
    dcha = datos.size() -1;
    //indice del elemento en la mitad del vector
    centro = (izda + dcha) / 2;
    
    while (izda <= dcha && !encontrado){
        
    if (datos[centro].getNombre() == nom)//lo hemos encontrado
        encontrado = true;
    
    else{
        //esta a la izquierda
        if (nom<datos[centro].getNombre())
            dcha = centro - 1;
        
        else  //debe estar a la derecha
            izda = centro + 1;
          
    }
        
    centro = (izda + dcha) / 2;
    }
    
    if (encontrado)
        return centro;
    
    else{
        
        cout<<"el elemento no existe";//revisar
        return -1;
    }  
    
}


int ingredientes::BusquedaBinariaIndice(const ingrediente & ing){ 
    
    
    int izda, dcha, centro;
    bool encontrado = false;
    
    izda = 0;
    //indice del  elemento valido mas a la derecha
    dcha = indice.size() -1;
    //indice del elemento en la mitad del vector
    centro = (izda + dcha) / 2;
    
    while (izda <= dcha && !encontrado){
        
    if (datos[indice[centro]] == ing)//lo hemos encontrado
        encontrado = true;
    
    else{
        //esta a la izquierda
        if (ing.getTipo()<datos[indice[centro]].getTipo())
            dcha = centro - 1;
        
        else if (ing.getTipo()>datos[indice[centro]].getTipo())//debe estar a la derecha
            izda = centro + 1;
        
        else if ((ing.getTipo()==datos[indice[centro]].getTipo()) && (ing.getNombre() < datos[indice[centro]].getNombre()))
             dcha = centro - 1;
        
        else //if ((datos[pos].getTipo()==datos[indice[centro]].getTipo()) && (datos[pos].getNombre() >  datos[indice[centro]].getNombre()))
             izda = centro + 1;
       
    
    }
        
    centro = (izda + dcha) / 2;
    }
    
    if (encontrado)
        return centro;
    
    else
        return (-1)*izda;
    
}

pair <bool,int> ingredientes::BuscarEnDatos(const ingrediente & ing){
    
    int aux=BusquedaBinariaNombre(ing);
        if(aux>0)
            
            return make_pair (true,aux);
            
        else if(aux<0)
            
            return make_pair (false,aux*(-1));
         
        else{
                 
            if(datos,size()>0 && datos[0]==ing)//datos[0]
                return make_pair (true,0);
         
            else
                return make_pair (false,0); 
            cout<<"BuscarEnDatos"<<endl;
    cin.get(); 
        }
      cout<<"BuscarEnDatos";
    cin.get(); 
            
    }

pair <bool,int> ingredientes::BuscarEnIndice(const ingrediente & ing){
    
    int aux=BusquedaBinariaIndice(ing);
        
        if(aux>0)
            
            return make_pair (true,aux);
            
        else if(aux<0)
            
            return make_pair (false,aux*(-1));
         
        else
            
            if( datos,size()>0 && datos[indice[0]]==ing)//datos[0]
                return make_pair (true,0);
        
            else
                return make_pair (false,0);
            
            
    }

void ingredientes::Clear(){ 
    
    datos.clear();
    indice.clear();
}


ingrediente ingredientes::get(string nom){
    
    
    int izda, dcha, centro;
    bool encontrado = false;
    

    izda = 0;
    //indice del  elemento valido mas a la derecha
    dcha = datos.size() -1;
    //indice del elemento en la mitad del vector
    centro = (izda + dcha) / 2;
    
    while (izda <= dcha && !encontrado){
        
    if (datos[centro].getNombre() == nom)//lo hemos encontrado
        encontrado = true;
    
    else{
        //esta a la izquierda
        if (nom<datos[centro].getNombre())
            dcha = centro - 1;
        
        else  //debe estar a la derecha
            izda = centro + 1;
          
    }
        
    centro = (izda + dcha) / 2;
    }
    
    if (encontrado)
        return datos[centro];
    
    else{
        ingrediente a;
        return a;
    }
        
     
}

ingredientes ingredientes::getIngredienteTipo(string tipo){   
    
    int izda, dcha, centro;
    bool encontrado = false;
    
    izda = 0;
    //indice del  elemento valido mas a la derecha
    dcha = indice.size() -1;
    //indice del elemento en la mitad del vector
    centro = (izda + dcha) / 2;
    
    while (izda <= dcha && !encontrado){
        
    
        //esta a la izquierda
        if (tipo<datos[indice[centro]].getTipo())
            dcha = centro - 1;
        
        else if (tipo>datos[indice[centro]].getTipo())//debe estar a la derecha
            izda = centro + 1;
        
        else{
             
           
            if ((centro-1)>=0 && datos[indice[centro-1]].getTipo() == tipo)
             dcha = centro - 1;
            
            else
                 encontrado=true;          
   
        }
        
     
    centro = (izda + dcha) / 2;
    }
     
 
    int comienzo=0;
    
    if (encontrado)
        comienzo=centro;
    
    else{
        cout<<"No hay ingedientes del tipo especificado"<<endl;//No esta en el vector
        exit(-1);
    }
    
    ingredientes salida;
    ingrediente aux;
    
    while ((datos[indice[comienzo]].getTipo()==tipo) && (comienzo<indice.size())){
        
        aux=datos[indice[comienzo]];
        
        salida.Insertar(aux);
        comienzo++;
   
        
     }
    
    return salida;
    
}

vector <string> ingredientes::getTipos(){
    
    vector <string> tipos;
    
    string aux=datos[indice[0]].getTipo();
    
     vector <string>::const_iterator j=tipos.begin();
    tipos.insert(j,aux);
    
    
    //int cont=1;
    
    for(int i=1;i<indice.size();i++){
        
        if(aux!=datos[indice[i]].getTipo()){
            
           // it=indice.begin();
            aux=datos[indice[i]].getTipo();
            tipos.insert(tipos.end(),aux);
         }
        
    }
    
    return tipos;
    
}


void ingredientes::Insertar(const ingrediente & ing){ 
     
    pair <bool,int> posdatos=BuscarEnDatos(ing);
    pair <bool,int> posindice=BuscarEnIndice(ing);
     
    for(int i=0;i<indice.size();i++)
        if(indice[i]>=posdatos.second)
            indice[i]=indice[i]+1;
    
    vector <ingrediente>::const_iterator i=datos.begin();
    vector <int>::const_iterator j=indice.begin();
    
  
    
    if(!posdatos.first)        
        datos.insert(posdatos.second + i,ing);
    
    j=indice.begin();
    if(!posindice.first)        
        indice.insert(posindice.second+j,posdatos.second);
    
       
        
    
    
}

void ingredientes::ImprimirPorTipo(ostream & os){
    
    cout<<"Ingredientes por tipo: "<<"\n"; //Hacer esto con el metodo imprimir indice
    
     for(int i=0;i<indice.size();i++)
        
        os<<datos[indice[i]];
      
}


void ingredientes::Info(string nom){
    
    
    ingrediente ing;
    
    ing=get(nom);
    
    cout<<"Informacion del ingrediente: "<<ing;
    
  
}

void ingredientes::ModificarIngrediente(const ingrediente & ing,const ingrediente & nuevo){
    
    borrar(ing);
    Insertar(nuevo);
    
    
}

int ingredientes::size()const{
    
    return datos.size();
     
}



bool operator ==(const ingrediente & ing1,const ingrediente & ing2){
    
    return (ing1.getNombre()==ing2.getNombre()) && (ing1.getTipo()==ing2.getTipo());
}


ingredientes &  ingredientes::operator=(const ingredientes & ing1){
    
	if(this != &ing1){
    datos=ing1.datos;
    indice=ing1.indice;
    }
	return *this;
    
}

istream & operator >>(istream & is, ingredientes & I){
    
    I.Clear();
    
    string linea;
    getline(is,linea);
    
    
    ingrediente ing;
    
    while (is>>ing){  
    I.Insertar(ing);
    
    }
    
    return is;
    
}


ostream & operator <<(ostream & os,const ingredientes & I){
    
    cout<<"Ingredientes en datos: "<<"\n";
    
    for(int i=0;i<I.size();i++)
        os<<I.datos[i];
    
    cout<<"\n";
    
    return os;
    
}



























































