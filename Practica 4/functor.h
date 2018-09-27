/* 
 * conjunto.h
 * 
 * Copyright  (C) Marcos Avilés Luque
*/

#ifndef __FUNCTOR_H
#define __FUNCTOR_H
#include <string>
#include <vector>
#include <iostream> 


using namespace std;

template <typename T>
class ComparacionPorID_creciente {
	public:
		bool operator()(const T &a, const T &b);
		
}; 

template <typename T>
class ComparacionPorID_decreciente {
	public:
		bool operator()(const T &a, const T &b);
		
};
	
#include "functor.hxx" // Incluimos la implementacion.
#endif