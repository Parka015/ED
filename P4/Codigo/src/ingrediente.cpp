/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ingrediente.cpp
 * Author: pablo
 * 
 * Created on 12 de octubre de 2019, 13:42
 */

#include "ingrediente.h"
#include <cstdlib>
#include "string"
#include "iostream"
#include <fstream>

ingrediente::ingrediente() {
    
    nombre="Undefined";
    calorias=0;
    hdc=0;
    proteinas=0;
    grasas=0;
    fibra=0;
    tipo="Undefined";
   
}

ingrediente::ingrediente(string nom,float cal,float hdc,float protein,float grasa,float fib,string  tip){
    
    nombre=nom;
    calorias=cal;
    this->hdc=hdc;
    proteinas=protein;
    grasas=grasa;
    fibra=fib;
    tipo=tip;
    
}



    
    //MODIFICADORES


void ingrediente::setIngrediente(string nom,float cal,float hdc,float protein,float grasa,float fib,string  tip){
    
    nombre=nom;
    calorias=cal;
    this->hdc=hdc;
    proteinas=protein;
    grasas=grasa;
    fibra=fib;
    tipo=tip;
    
}
    
void ingrediente::setNombre(string nom){
    
    nombre=nom;
    
}

void ingrediente::setCalorias(float cal){
    
    if(cal>=0)
    
        calorias=cal;
    
    else
        
        calorias=0;
    
}

void ingrediente::setHDC(float hdc){
    
    if(hdc>=0)
    
        this->hdc=hdc;
        
    else
        
        this->hdc=0;
    
}

void ingrediente::setProteinas(float protein){
    
    if(protein>=0)
    
        proteinas=protein;
        
    else
        
        proteinas=0;
    
}

void ingrediente::setGrasas(float grasa){
    
    if(grasa>=0)
    
        grasas=grasa;
        
    else
        
        grasas=0;
    
}

void ingrediente::setFibra(float fib){
    
    if(fib>=0)
    
        fibra=fib;
        
    else
        
        fibra=0;
    
}

void ingrediente::setTipo(string  tip){
            
        tipo=tip;    
}
    
   
//CONSULTORES
    
string ingrediente::getNombre()const{
    
    return nombre;
    
}

float ingrediente::getCalorias()const{
    
    return calorias;
    
}


float ingrediente::getHc()const{
    
    return hdc;
    
}


float ingrediente::getProteinas()const{
    
    return proteinas;
    
}


float ingrediente::getGrasas()const{
    
    return grasas;
    
}


float ingrediente::getFibra()const{
    
    return fibra;
    
}


string ingrediente::getTipo()const{
    
    return tipo;
    
}

//METODOS

istream& operator>> (istream& flujo,ingrediente &ing){
    
    
    string linea;
    
    getline(flujo,linea);
    
    if(linea.c_str()==0) 
        return flujo;
    
    //Captar nombre
    
    int pos=linea.find(";");
    
    ing.setNombre(linea.substr(0,pos));
    
    linea=linea.substr(pos+1);
    
    //Captar calorias
    
    string aux;
  
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    ing.setCalorias(atof(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar hdc
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    ing.setHDC(atof(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar proteinas
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    ing.setProteinas(atof(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar grasas
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    ing.setGrasas(atof(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar fibra
    
    pos=linea.find(";");
    
    aux=linea.substr(0,pos);
    
    ing.setFibra(atof(aux.c_str()));
        
    linea=linea.substr(pos+1);
    
    //Captar tipo
    
    pos=linea.find("\n"); 
    if(pos==string::npos)
        pos=linea.find("\r");
    
    ing.setTipo(linea.substr(0,pos));
    
    return flujo;
    
}


ostream& operator<< (ostream &flujo,const ingrediente &ing){
    
    
    flujo<<ing.getNombre()<<";"<<ing.getCalorias()<<";"<<ing.getHc()<<";"<<
           ing.getProteinas()<<";"<<ing.getGrasas()<<";"<<ing.getFibra()<<";"<<
           ing.getTipo()<<"\n"; 
    
    return flujo;
    
    
}
    
