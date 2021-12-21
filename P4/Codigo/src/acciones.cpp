/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Acciones.cpp
 * Author: pablo
 * 
 * Created on 25 de diciembre de 2019, 12:36
 */

#include "acciones.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;


void acciones::clear(){
    
    datos.clear();
}

void acciones::insertar(string acc, unsigned char ariedad){
    
    
    pair<string,unsigned char> p(acc, ariedad);
    
    datos.insert(p);
    
}

char acciones::getAriedad(const string &accion)const{
	char ariedad='.';
        
	
	if(datos.at(accion)=='1' || datos.at(accion)=='2' ){
		ariedad = datos.at(accion);
	}

	return ariedad;
}


istream & operator >>(istream & is, acciones & acc){

    acc.clear();
    
    string clave;
    unsigned char ariedad;
    string aux;

        
    string linea;
    int pos;
   //  cout<<"a"<<endl;
     while (getline(is,linea)){          
    
            
            if(linea.c_str()==0) 
                return is;
            
   
        //Captar clave
    
            pos=linea.find(" ");
    
            clave=linea.substr(0,pos);
    
            linea=linea.substr(pos+1);
            
         //Captar ariedad
            
           pos=linea.find("\n"); 
             if(pos==string::npos)
                pos=linea.find("\r");
            
           aux=linea.substr(0,pos);
           
           if(aux.length()>0){
                
               ariedad = aux[0];
                
                acc.insertar(clave,ariedad);
           }
	}
    
    return is;
}


 ostream & operator<<(ostream &os,const acciones &acc){
    
    map<string,unsigned char>::const_iterator it=acc.datos.begin();

	for(;it!=acc.datos.end();it++){
		os<<"Accion: "<<(*it).first<<" "<<"Ariedad: "<<(*it).second<<endl;
	}

	return os;
    
    
}


