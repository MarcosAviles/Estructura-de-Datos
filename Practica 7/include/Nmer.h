
/**
 * @file Nmer.h
 * @brief TDA Nmer
 *   Representa un conjunto de Nmer subsecuencias de tamaño 1 hasta N que se pueden obtener a partir de una cadena de ADN
 * @author alumno
 * @bug Por espeficicar
 */
#ifndef __NMER_H
#define __NMER_H

#include "ktree.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class OrdenCre {
   public:
     bool operator()( const pair<string,int> & a, const pair<string,int> & b) {
       if(a.second<b.second){
        return true;
       }
       else if(a.second>b.second){
        return false;
       }
       else{
        return a.first<b.first;
       }
       
     }
  };

class OrdenDecre {
   public:
     bool operator()( const pair<string,int> & a, const pair<string,int> & b) {
       if(a.second>b.second){
        return true;
       }
       else if(a.second<b.second){
        return false;
       }
       else{
        return a.first>b.first;
       }
       
     }
  };
class Nmer {
public:
  typedef unsigned int size_type;
  
  /** @brief Functor para ordenar en orden creciente un nodo definido por una pareja <string,int>
    
   */
  

  /** @brief Constructor primitivo .
      Crea un Nmer de longitud maxima 0, con el valor ('-',0) en la raíz
  */
  Nmer();

  /** @brief Constructor de copia .
      Genera un nuevo Nmer a partir de un Nmer recibido por parámetro.
  */
  Nmer(const Nmer &a);
  
  /** @brief lectura fichero serializado
   * @param nombre_fichero fichero serializado con extension .srl
   *
   * Genera a partir del fichero el ktree que contiene todos los kmers asociados a una cadena de ADN
   *
   * La cadena original viene descrita en el fichero serializado
   */ 
  bool loadSerialized(const string & nombre_fichero);

  /** @brief lectura fichero txt
   * @param nombre_fichero fichero serializado con extension .srl
   *
   * Genera a partir del fichero el ktree que contiene todos los kmers asociados a una cadena de ADN
   *
   */ 
  bool loadFicheroTxt(const string & nombre_fichero);

  /** @brief Imprime los Nmers
   * @todo Debemos de implementar este método de forma que nos garantizemos que se imprimen todos los Nmers.
   */ 
   void list_Nmer() const;
   
   
  /** @brief Máxima longitud de los Nmers almacenados
   */ 
   unsigned int length()const;
   
     
  /** @brief Número de Nmers almacenados
   */ 
   size_type size() const;

   /** @brief Operador de Asignación
   */ 
   Nmer & operator=(const Nmer &a);

   /** @brief Devuelve el Nmer asociado a un prefijo.
   */ 
   Nmer Prefix(string adn);

   /** @brief Devuelve un Nmer con la union del conjunto de Nmer(*this) y Nmer referencia
   */ 
   Nmer Union(const Nmer referencia);
  
  /** @brief Devuelve verdadero si la cadena se encuentra en el Nmer
   */ 
   bool containsString(const string adn) const;

   /** @brief Devuelve verdadero si todos los nodos de Emer(*this) están representados en el Nmer reference
   */ 
   bool included(const Nmer reference) const;

   void sequenceADN(unsigned int l, const string & adn);
   
   float Distance(const Nmer &x);

   /** @brief Este método devuelve la lista de todas las subcadenas (no prefijo) que aparecen un número menor o igual
         a threshold veces en el Nmer
      @param threshold frecuencia de aparición para las subcadenas
   */
   set<pair<string,int>,OrdenCre> rareNmer(int threshold);

   /** @brief Devuelve la lista de las cadenas de longitud mayor posible (sin ser prefijo) que aparecen un número de veces
mayor que de threshold veces en el Nmer, ordenadas en orden decreciente de frecuencia
      @param threshold frecuencia de aparición para las subcadenas
   */
   set<pair<string,int>,OrdenDecre> commonNmer(int threshold);

    /** @brief nos devuelve únicamente los Nmers de longitud l, ordenados en orden creciente de frecuencia.
      @param l longitud de las subcadenas 
   */
   set<pair<string,int>,OrdenCre> level(int l);

private:
  ktree<pair<char,int>,4> el_Nmer; // subsecuencias 
  unsigned int max_long; // Mayor longitud de la cadena representada, esto es, el nivel máximo del árbol
 
  /** @brief Functor para convertir un string en un pair<char,int>
   * se utiliza en loadSerialized
   */
  class String2Base {
   public:
    pair<char,int> operator()( const string & cad) {
	    pair<char,int> salida;
	    salida.first = cad[0];
	    salida.second = std::stoi(cad.substr(1)); 
	    return salida;
    }
  };

   /** @brief Functor para convertir un pair<char,int> en un string 
    * Necesario para serializar un Nmer.
   */
  class Base2String {
   public:
     string operator()( const pair<char,int> & x) {
       string salida = string(1,x.first) + " " +std::to_string(x.second); 
       return salida;
     }
  };
  /** @brief Para un nodo sube hacia arriba en el árbol mediante su padre y recoge la secuencias de Etiquetas
      @param n un nodo constante del Nmer
      @param aux una cadena para almacenar el caracter de la etiqueta de cada nodo
   */
  void sube(ktree<pair<char,int>,4>::const_node n, string & aux) const;

  /** @brief Recorrido en preorden de un Nmer 
      @param n nodo que parte para el recorrido del Nmer
   */
  void recorrido_preorden(ktree<pair<char,int>,4>::const_node n) const;

  /** @brief Recorrido en preorden en pararelo para dos Nmers iguales
      @param n nodo que parte para el recorrido del Nmer 1
      @param n2 nodo que parte para el recorrido del Nmer 2
   */
  Nmer recorrido_preorden_para_union(ktree<pair<char,int>,4>::node n, ktree<pair<char,int>,4>::node n2, Nmer & original);

   /** @brief Recorrido en preorden del Nmer (*this) para cada secuencai obtendia se comprueba si es contenida en el Nmer
              reference
      @param n nodo que parte para el recorrido del Nmer (*this)
      @param n2 Nmer de referencia 
   */
  bool recorrido_preorden_para_included(ktree<pair<char,int>,4>::const_node n, const Nmer &referece, bool & aux) const;

  /** @brief avanzar por la cadena a la vez que descendemos por el árbol para actualizar los valores del Nmer que representa
       si no existe, se añade el nuevo nodo.
      @param cadena, subsecuencia de adn para insertar en el Nmer
   */
  void insertar_cadena(const string & cadena);

  /** @brief Recorrido en preorden para el metodo rareNmer, que recorre el arbol en preorden llegando hasta las hojas alcenando las subcadenas
      con mayor o igual frecuencia en el set pasado por referencia.
      @param n nodo que parte para el recorrido del Nmer 
      @param frencuencia, es equivalente al threshold
      @param salida, es un set pasado por referencia para el almacenamiento de las subsecuencias 
   */
  void recorrido_preorden_para_rareNmer(ktree<pair<char,int>,4>::const_node n, int frecuencia, set<pair<string,int>,OrdenCre> & salida);

 /** @brief Recorrido en preorden para el metodo commonNmer, que recorre el arbol en preorden llegando hasta los nodos
      con mayor frecuencia que threshold y almacenando las subcadenas correspondientes en el set salida
      @param n nodo que parte para el recorrido del Nmer 
      @param frencuencia, es equivalente al threshold
      @param salida, es un set pasado por referencia para el almacenamiento de las subsecuencias 
   */
  void recorrido_preorden_para_commonNmer(ktree<pair<char,int>,4>::const_node n, int frecuencia, set<pair<string,int>,OrdenDecre> & salida);

  /** @brief Recorrido en preorden para el metodo level, que recorre el arbol en preorden llegando hasta los nodos de nivel n
    almacenando las subcadenas correspondientes en el set salida.
      @param n nodo que parte para el recorrido del Nmer 
      @param nivel, nivel hasta que baja en el arbol
      @param salida, es un set pasado por referencia para el almacenamiento de las subsecuencias 
   */
  void recorrido_preorden_para_level(ktree<pair<char,int>,4>::const_node n, int & nivel, set<pair<string,int>,OrdenCre> & salida);

  /** @brief Para un nodo devuelve el numero de hijos que tiene ese nodo
      @param n un nodo constante del Nmer
   */
  int numero_hijos(ktree<pair<char,int>,4>::const_node n);

  /** @brief Recorrido en preorden para el metodo distacina, que recorre el arbol en preorden almacenando en orden Decreciente 
      las subcadenas correspondientes en el set salida.
      @param n nodo que parte para el recorrido del Nmer 
      @param salida, es un set pasado por referencia para el almacenamiento de las subsecuencias 
   */
  void recorrido_preorden_para_distancia(ktree<pair<char,int>,4>::const_node n, set<pair<string,int>,OrdenDecre> & salida );

  /** @brief Realiza uan búsqueda en el conjunto set si se encuentra una cadena y devuelve el iterador del elemento en el conjunto
      @param rankingY set sobre el que se itera
      @param cadena, valor de la cadena que buscamos
   */
  set<pair<string,int>,OrdenCre>::iterator pertenece(set<pair<string,int>,OrdenCre> & rankingY, const string & cadena);
};

#endif
