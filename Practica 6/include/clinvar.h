#ifndef __CLINVAR_H
#define __CLINVAR_H
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iostream> 
#include <mutacion.h>
#include <enfermedad.h>
#include <assert.h>
using namespace std;


typedef string IDgen;
typedef string IDmut;
typedef string IDenf;
class clinvar{
public:

	void load (const string &nombreDB);
	void insert (const mutacion & x);
	bool erase (IDmut ID);


	class iterator;
	class enfermedad_iterator;
	class gen_iterator;
	class ProbMutaciones;
	class ProbMutaciones{
		public:
			bool operator()(const mutacion &x, const mutacion &z);
	};


	iterator find_Mut (IDmut ID);
	enfermedad_iterator find_Enf(IDenf ID);
	vector<enfermedad> getEnfermedades(mutacion & mut);
	list<IDenf> getEnfermedades(string keyword);
	set<IDmut> getMutacionesEnf (IDenf ID);
	set<IDmut> getMutacionesGen (IDgen ID);
	set<mutacion,clinvar::ProbMutaciones> topKMutaciones (int k, string keyword);
/* Métodos relacionados con los iteradores */
	iterator begin();
	iterator end();
	iterator lower_bound(string cromosoma, unsigned int posicion);
	iterator upper_bound(string cromosoma, unsigned int posicion);
	enfermedad_iterator ebegin();
	enfermedad_iterator eend();
	gen_iterator gbegin();
	gen_iterator gend();

	class iterator{
		public:
			iterator();
			iterator(const iterator &  x);
			
			const mutacion & operator*();
			iterator & operator++();
			iterator operator++(int i);
			iterator & operator--();
			iterator operator--(int i);
			bool operator==(const iterator & x) const ;		  
			bool operator!=(const iterator & x) const ;
			iterator & operator=(const iterator & x);
		public:
			friend class clinvar;
			set<mutacion>::iterator it;
	};

	class enfermedad_iterator{
		public:
			enfermedad_iterator();
			enfermedad_iterator(const enfermedad_iterator &  x);
			
			const enfermedad & operator*();
			enfermedad_iterator & operator++();
			enfermedad_iterator operator++(int i);
			enfermedad_iterator & operator--();
			enfermedad_iterator operator--(int i);
			bool operator==(const enfermedad_iterator & x) const ;		  
			bool operator!=(const enfermedad_iterator & x) const ;
			enfermedad_iterator & operator=(const enfermedad_iterator & x);
		public:
			friend class clinvar;
			map<IDenf, enfermedad>::iterator enfermedad_it;
	};	

	class gen_iterator{
		public:
			gen_iterator();
			gen_iterator(const gen_iterator &  x);
			
			const mutacion & operator*();
			gen_iterator & operator++();
			gen_iterator operator++(int i);
			bool operator==(const gen_iterator & x) const ;		  
			bool operator!=(const gen_iterator & x) const ;
			gen_iterator & operator=(const gen_iterator & x);
		public:
			friend class clinvar;
			map<IDgen, list< set<mutacion>::iterator>>::iterator itmap;
			list<set<mutacion>::iterator>::iterator itlist;
			clinvar *ptrclinvar;
	};

private:
	friend class iterator; 
	friend class enfermedad_iterator; 
	friend class gen_iterator; 
	set<mutacion> mutDB; //base de datos que contiene toda la información asociada a una mutacion
	unordered_map<IDmut,set<mutacion>::iterator> IDm_map; // Asocia IDmutacion con mutación
	map<IDgen, list< set<mutacion>::iterator> > gen_map; // Asocia genes con mutaciones
	map<IDenf,enfermedad> EnfDB; // Base de datos de enfermedades
	multimap<IDenf,set<mutacion>::iterator> IDenf_map; // Asocia enfermedad con mutaciones
};

#endif