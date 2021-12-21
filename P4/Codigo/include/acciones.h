/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   acciones.h
 * Author: pablo
 *
 * Created on 25 de diciembre de 2019, 12:36
 */

#ifndef ACCIONES_H
#define ACCIONES_H

#include <string>
#include <map>

using namespace std;

class acciones {

private:
    
    map <string,unsigned char > datos;
    

    void insertar(string acc, unsigned char ariedad);

public:
    
    void clear();
	
    char getAriedad(const string &accion)const;
    
    class iterator{
		  private:
		    map<string,unsigned char>::iterator it;
		   public:
		      iterator(){}
		      bool operator==(const iterator &i)const{
				   return i.it==it;
			  }
			  bool operator!=(const iterator &i)const{
				  return i.it!=it;
			  }
			  unsigned char & operator*(){
				  return it->second;
			  }
			  iterator & operator++(){
				  ++it;
				  return *this;
			  }
			  iterator & operator--(){
				  --it;
				  return *this;
			  }
			  friend class acciones;
		  };
      class const_iterator{
		  private:
		    map<string,unsigned char>::const_iterator it;
		   public:
		      const_iterator(){}
		      bool operator==(const const_iterator &i)const{
				   return i.it==it;
			  }
			  bool operator!=(const const_iterator &i)const{
				  return i.it!=it;
			  }
			  const unsigned char& operator*(){
				  return it->second;
			  }
			  const_iterator & operator++(){
				  ++it;
				  return *this;
			  }
			  const_iterator & operator--(){
				  --it;
				  return *this;
			  }
			  friend class acciones;
		  };
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
			  i.it=datos.cbegin();
			  return i;
		  }
		  const_iterator end()const{
			  const_iterator i;
			  i.it=datos.cend();
			  return i;
		  }		  
    
   friend ostream & operator<<(ostream &os,const acciones &acc);
   friend istream & operator>>(istream &is,acciones &acc);
   
};

#endif /* ACCIONES_H */

