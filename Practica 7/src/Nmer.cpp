#include "Nmer.h"

#include <fstream>



void Nmer::sube(ktree<pair<char,int>,4>::const_node n, string & aux) const{
  if (!n.parent().null()){
      aux.push_back((*n).first);
      sube(n.parent(),aux);
  }
  else{
    reverse(aux.begin(),aux.end());
  }
}



void Nmer::recorrido_preorden(ktree<pair<char,int>,4>::const_node n) const{
  if (!n.null()){

      string cadena="";
      sube(n,cadena);
      cout << "( " << cadena<<"); "<<(*n).second <<endl; 

    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrido_preorden(*ini);
      ++ini;
    }
 }
}


Nmer Nmer::recorrido_preorden_para_union(ktree<pair<char,int>,4>::node n, ktree<pair<char,int>,4>::node n2, Nmer & original) {
for(int i=0; i<4; i++){
  if(!n.k_child(i).null() && !n2.k_child(i).null()){
    (*n.k_child(i)).second+=(*n2.k_child(i)).second;
    recorrido_preorden_para_union(n.k_child(i),n2.k_child(i), original);
  }
  if(!n2.k_child(i).null() && n.k_child(i).null()){
    Nmer aux;
    aux.el_Nmer.assing(original.el_Nmer, n2.k_child(i));
    el_Nmer.insert_k_child(n,i,aux.el_Nmer);
  }
 }
return (*this);
}

bool Nmer::recorrido_preorden_para_included(ktree<pair<char,int>,4>::const_node n, const Nmer &reference, bool & anterior_contenido) const {
  if (!n.null()){

    if(n.k_child(0).null() && n.k_child(1).null() && n.k_child(2).null() && n.k_child(3).null()){
        string cadena="";
        sube(n,cadena);
        anterior_contenido=reference.containsString(cadena);
    }
    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin && anterior_contenido){
      recorrido_preorden_para_included((*ini), reference, anterior_contenido);
      ++ini;
    }
 }
 return anterior_contenido;
}

void Nmer::recorrido_preorden_para_rareNmer(ktree<pair<char,int>,4>::const_node n, int frecuencia, set<pair<string,int>,OrdenCre> & salida) {
  if (!n.null()){

    if(n.k_child(0).null() && n.k_child(1).null() && n.k_child(2).null() && n.k_child(3).null()){
      if((*n).second>=frecuencia){
        string cadena="";
        sube(n,cadena);
        pair<string,int> aux;
        aux.first=cadena;
        aux.second=(*n).second;
        salida.insert(aux);
      }

    }
    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrido_preorden_para_rareNmer((*ini),frecuencia,salida);
      ++ini;
    }
 }
}

void Nmer::recorrido_preorden_para_commonNmer(ktree<pair<char,int>,4>::const_node n,
         int frecuencia, set<pair<string,int>,OrdenDecre> & salida) {
  if ((!n.null() && (*n).second>frecuencia  ) || n==el_Nmer.root() ){

      if(
        (!(n.k_child(0)).null() && (*n.k_child(0)).second>frecuencia) ||
        (!(n.k_child(1)).null() && (*n.k_child(1)).second>frecuencia) ||
        (!(n.k_child(2)).null() && (*n.k_child(2)).second>frecuencia) ||
        (!(n.k_child(3)).null() && (*n.k_child(3)).second>frecuencia)){


      }
    else{;
      string cadena="";
      sube(n,cadena);
      pair<string,int> aux;
      aux.first=cadena;
      aux.second=(*n).second;
      salida.insert(aux);
    }

    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrido_preorden_para_commonNmer((*ini),frecuencia,salida);
      ++ini;
    }
    
 }
}

int Nmer::numero_hijos(ktree<pair<char,int>,4>::const_node n){
  int salida=0;
  if(!n.k_child(0).null()){
    salida++;
  }
  if(!n.k_child(1).null()){
    salida++;
  }
  if(!n.k_child(2).null()){
    salida++;
  }
  if(!n.k_child(3).null()){
    salida++;
  }
  return salida;
}

void Nmer::recorrido_preorden_para_level(ktree<pair<char,int>,4>::const_node n, int & nivel, set<pair<string,int>,OrdenCre> & salida) {
  if (!n.null() && nivel>=0){
    int aux2=nivel;
    if(aux2==0){
      string cadena="";
      sube(n,cadena);
      pair<string,int> aux;
      aux.first=cadena;
      aux.second=(*n).second;
      salida.insert(aux);
    }
    aux2--;
    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrido_preorden_para_level((*ini),aux2,salida);
      ++ini;
    }
 }
}

void Nmer::recorrido_preorden_para_distancia(ktree<pair<char,int>,4>::const_node n, set<pair<string,int>,OrdenDecre> & salida ) {
  if (!n.null()){

    
      string cadena="";
      sube(n,cadena);
      pair<string,int> aux;
      aux.first=cadena;
      aux.second=(*n).second;
      salida.insert(aux);

    ktree<pair<char,int>,4>::const_node::child_iterator ini = n.begin();
    ktree<pair<char,int>,4>::const_node::child_iterator fin = n.end();
    while (ini!=fin){
      recorrido_preorden_para_distancia((*ini), salida);
      ++ini;
    }
 }
}

Nmer::Nmer() {
  max_long = 0;
  el_Nmer = ktree<pair<char,int>,4>(pair<char,int>('-',0));
  
}

Nmer::Nmer(const Nmer &a){
  max_long=a.max_long;
  el_Nmer=a.el_Nmer;
}

bool Nmer::loadSerialized(const string & fichero) {
 string cadena;
 ifstream fe;
 pair<char,int> nulo('x',-1);
 Nmer::String2Base stb;
 
 fe.open(fichero.c_str(), ifstream::in);
 if (fe.fail()){
    cerr << "Error al abrir el fichero " << fichero << endl;
 } 
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{ 
      getline(fe,cadena,'\n'); 
    } while (cadena.find("#")==0 && !fe.eof());
    // leemos Nmer_length
     max_long = std::stoi(cadena);
     // leemos cadena serializada
    getline(fe,cadena,'\n');
    el_Nmer.deserialize(cadena,nulo,';',stb); 
    fe.close();
    return true;
 } // else
 fe.close();
 return false;
}

bool Nmer::loadFicheroTxt(const string & nombre_fichero){
 string cadena;
 ifstream fe; 
 fe.open(nombre_fichero.c_str(), ifstream::in);
 if (fe.fail()){
    cerr << "Error al abrir el fichero " << nombre_fichero << endl;
 } 
 else {
     // leemos cadena serializada
    getline(fe,cadena,'\n');
    for(unsigned int i=0; i<cadena.size(); i++){
      cadena[i]=toupper(cadena[i]);
    }
    sequenceADN(10,cadena);
    fe.close();
    return true;
 } // else
 fe.close();
 return false;
}
 
void Nmer::list_Nmer() const {
    // implmenentar el recorrido en preorden para el ktree de forma que nos devuelva los Nmers completos y no sólo el nodo.
     recorrido_preorden(el_Nmer.root());
}
 
unsigned int Nmer::length() const {
   return max_long;
}
 
Nmer::size_type Nmer::size() const{
  return el_Nmer.size()-1;
}

Nmer & Nmer::operator=(const Nmer &a){
  this->max_long=a.max_long;
  this->el_Nmer=a.el_Nmer;
  return (*this);
}


Nmer Nmer::Prefix(string adn){
  ktree<pair<char,int>,4>::node n(el_Nmer.root());
  for(unsigned int i=0; i<adn.size(); i++){
    if(adn[i]=='A'){
      n=n.k_child(0);
    }
    if(adn[i]=='G'){
      n=n.k_child(1);
    }                           
    if(adn[i]=='C'){
      n=n.k_child(2);
    }
    if(adn[i]=='T'){
      n=n.k_child(3);
    }
    if(n.null()){
      i=adn.size();
    }
  }

  Nmer salida;
  if(!n.null()){
    salida.el_Nmer.assing(el_Nmer, n);
  }
  (*salida.el_Nmer.root()).first='-';
  (*salida.el_Nmer.root()).second=0;
  return (salida);
}


Nmer Nmer::Union(const Nmer referencia){
  Nmer aux(referencia);
  Nmer salida(*this);
  salida.recorrido_preorden_para_union(salida.el_Nmer.root(), aux.el_Nmer.root(),aux);
  return salida;
}

bool Nmer::containsString(const string adn) const{
  bool salida=false;
  ktree<pair<char,int>,4>::const_node n(el_Nmer.root());
  for(unsigned int i=0; i<adn.size(); i++){
    if(adn[i]=='A'){
      n=n.k_child(0);
    }
    if(adn[i]=='G'){
      n=n.k_child(1);
    }                           
    if(adn[i]=='C'){
      n=n.k_child(2);
    }
    if(adn[i]=='T'){
      n=n.k_child(3);
    }
    if(n.null()){
      salida=false;
      i=adn.size();
    }
    else{
      salida=true;
    }
  }
  return salida;
}
 
bool Nmer::included(const Nmer reference) const{
  bool aux=true;
  return recorrido_preorden_para_included(el_Nmer.root(),reference,aux);
}

void Nmer::insertar_cadena(const string & cadena){
  ktree<pair<char,int>,4>::node n=el_Nmer.root();
  int hijo;
  for(unsigned int i=0; i<cadena.size(); i++){
    if(cadena[i]=='A'){
      hijo=0;
    }
    if(cadena[i]=='G'){
      hijo=1;
    }
    if(cadena[i]=='C'){
      hijo=2;
    }
    if(cadena[i]=='T'){
      hijo=3;
    }
    if(!n.k_child(hijo).null()){
      (*n.k_child(hijo)).second+=1;
    }
    else{
      pair<char,int> etiqueta;
      etiqueta.first=cadena[i];
      etiqueta.second=1;
      el_Nmer.insert_k_child(n, hijo, etiqueta);
    }
    n=n.k_child(hijo);
  }
}

void Nmer::sequenceADN(unsigned int l, const string & adn){
  el_Nmer = ktree<pair<char,int>,4>(pair<char,int>('-',0));
  max_long=l;
  string aux;
  unsigned int longitud=adn.size()-l;
  int contador=0;
  for(unsigned int i=0; i<=longitud; i++){
    for(unsigned int j=contador; j<l+contador; j++){
      aux+=adn[j];
    }
    insertar_cadena(aux);
    aux="";
    contador++;
  }

}

set<pair<string,int>,OrdenCre> Nmer::rareNmer(int threshold){
  set<pair<string,int>,OrdenCre> salida;
  recorrido_preorden_para_rareNmer(el_Nmer.root(),threshold,salida);
  return salida;
}

set<pair<string,int>,OrdenDecre> Nmer::commonNmer(int threshold){
  set<pair<string,int>,OrdenDecre> salida;
  recorrido_preorden_para_commonNmer(el_Nmer.root(),threshold,salida);
  return salida;
}

set<pair<string,int>,OrdenCre> Nmer::level(int l){
  set<pair<string,int>,OrdenCre> salida;
  recorrido_preorden_para_level(el_Nmer.root(),l,salida);
  return salida;
}

set<pair<string,int>,OrdenCre>::iterator Nmer::pertenece(set<pair<string,int>,OrdenCre> & rankingY, const string & cadena){
  set<pair<string,int>,OrdenCre>::iterator salida=rankingY.begin();
  while(salida!=rankingY.end()){
    if((*salida).first==cadena){
      return salida;
    }
    else{
      salida++;
    }
  }
  return salida;
}

float Nmer::Distance(const Nmer &x){
  set<pair<string,int>,OrdenDecre> nmX, nmY;
  map<string,int> rankingX, rankingY;
  recorrido_preorden_para_distancia(el_Nmer.root(),nmX);
  recorrido_preorden_para_distancia(x.el_Nmer.root(),nmY);
  set<pair<string,int>,OrdenDecre>::iterator it=nmX.begin();
  set<pair<string,int>,OrdenDecre>::iterator it2=nmY.begin();
  int contador=1;
  while(it!=nmX.end()){
    rankingX[(*it).first]=contador;
    contador++;
    it++;
  }
  contador=1;
  while(it2!=nmY.end()){
    rankingY[(*it2).first]=contador;
    contador++;
    it2++;
  }
  float max, dist, posX, posY, valor;
  if(rankingX.size()>=rankingY.size()){
    max=rankingX.size();
  }
  else{
    max=rankingY.size();
  }
  dist=0;
  map<string,int>::iterator it3=rankingX.begin();
  map<string,int>::iterator aux2;
  while(it3!=rankingX.end()){
    if(x.containsString((*it3).first)){
      aux2=rankingY.find((*it3).first);
      posX=(*it3).second;
      posY=(*aux2).second;
      valor=abs(posX-posY)/max;
    }
    else{
      valor=1;
    }
    dist+=valor;
    it3++;
  }
  return dist/rankingX.size();
}