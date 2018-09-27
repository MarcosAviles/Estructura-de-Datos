#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "ktree.h"
#include "Nmer.h"

using namespace std;

int main(){
 
Nmer prueba, prueba2,prueba3, prueba4, prueba1;
prueba.loadSerialized("./datos/cadenaSimple.srl");
prueba2.sequenceADN(2,"AGCTA");

cout<<"---------------------------------------Metodo Listado de Nmer en preorden-----------"<<endl;
prueba.list_Nmer();
cout << prueba.size() << " " << prueba.length() << endl;

cout<<"---------------------------------------Metodo Prefix-----------"<<endl;

Nmer nuevo=prueba.Prefix("A");
nuevo.list_Nmer();

cout<<"---------------------------------------Metodo Union-----------"<<endl;
prueba3=prueba.Union(prueba2);
prueba3.list_Nmer();
cout<<"---------------------------------------Metodo contiene-----------"<<endl;
bool contiene=prueba.containsString("AC");
if(contiene){
	cout<<"El prueba contiene la cadena AC"<<endl;
}
else{
	cout<<"El prueba no contiene la cadena AC"<<endl;
}

cout<<"----------------Metodo crear un Nmer a partir de una secuencia-----------"<<endl;
prueba1.sequenceADN(6,"ATACATCATTGTGG");
prueba4.sequenceADN(6,"ATACATCATTGTGG");

prueba1.list_Nmer();

cout<<"----------------Metodo included para prueba1 y prueba4-----------"<<endl;

bool contiene2=prueba4.included(prueba1);
if(contiene2){
	cout<<"Prueba 4 esta incluido todas las secuencias en Prueba1"<<endl;
}
else{
	cout<<"Todas las secuencias de Prueba 4 no estan incluidas en prueba1"<<endl;
}

cout<<"----------------Metodo rareNmer-----------"<<endl;
set<pair<string,int>,OrdenCre> aux=prueba3.rareNmer(1);

set<pair<string,int>,OrdenCre>::iterator it=aux.begin();
while(it!=aux.end()){
	cout<<(*it).first<<" "<<(*it).second<<endl;
	it++;
}

cout<<"----------------Metodo commonNmer-----------"<<endl;
Nmer nuevo2;
nuevo2.loadSerialized("./datos/cadenaSimple.srl");
set<pair<string,int>,OrdenDecre> aux2=nuevo2.commonNmer(2);

set<pair<string,int>,OrdenDecre>::iterator it2=aux2.begin();
while(it2!=aux2.end()){
	cout<<(*it2).first<<" "<<(*it2).second<<endl;
	it2++;
}

cout<<"----------------Metodo level-----------"<<endl;
set<pair<string,int>,OrdenCre> aux3=prueba.level(2);

set<pair<string,int>,OrdenCre>::iterator it3=aux3.begin();
while(it3!=aux3.end()){
	cout<<(*it3).first<<" "<<(*it3).second<<endl;
	it3++;
}

cout<<"----------------Metodo distancia para todos los Genomas-----------"<<endl;
 Nmer prueba5, prueba6, prueba7, prueba8, prueba9, prueba10, prueba11, prueba12, prueba13, prueba14;
 prueba5.loadFicheroTxt("./datos/1.txt");
 prueba6.loadFicheroTxt("./datos/2.txt");
 prueba7.loadFicheroTxt("./datos/3.txt");
 prueba8.loadFicheroTxt("./datos/4.txt");
 prueba9.loadFicheroTxt("./datos/5.txt");
 prueba10.loadFicheroTxt("./datos/6.txt");
 prueba11.loadFicheroTxt("./datos/7.txt");
 prueba12.loadFicheroTxt("./datos/8.txt");
 prueba13.loadFicheroTxt("./datos/9.txt");
 prueba14.loadFicheroTxt("./datos/10.txt");
 cout<<"La distancia entre el Genoma Humano1 y el Humano2 es: "<<prueba5.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Humano1 y el Raton1 es: "<<prueba5.Distance(prueba7)<<endl;
 cout<<"La distancia entre el Genoma Humano1 y el Raton2 es: "<<prueba5.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Humano1 y el Gusano1 es: "<<prueba5.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Humano1 y el Gusano2 es: "<<prueba5.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Humano1 y la Mosca de Fruta1 es: "<<prueba5.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Humano1 y la Mosca de Fruta2 es: "<<prueba5.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Humano1 y el virus Ebola es: "<<prueba5.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Humano1 y el Pez Cebra es: "<<prueba5.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Humano2 y el Humano1 es: "<<prueba6.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Humano2 y el Raton1 es: "<<prueba6.Distance(prueba7)<<endl;
 cout<<"La distancia entre el Genoma Humano2 y el Raton2 es: "<<prueba6.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Humano2 y el Gusano1 es: "<<prueba6.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Humano2 y el Gusano2 es: "<<prueba6.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Humano2 y la Mosca de Fruta1 es: "<<prueba6.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Humano2 y la Mosca de Fruta2 es: "<<prueba6.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Humano2 y el virus Ebola es: "<<prueba6.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Humano2 y el Pez Cebra es: "<<prueba6.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Raton1 y el Humano1 es: "<<prueba7.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Raton1 y el Humano2 es: "<<prueba7.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Raton1 y el Raton2 es: "<<prueba7.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Raton1 y el Gusano1 es: "<<prueba7.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Raton1 y el Gusano2 es: "<<prueba7.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Raton1 y la Mosca de Fruta1 es: "<<prueba7.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Raton1 y la Mosca de Fruta2 es: "<<prueba7.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Raton1 y el virus Ebola es: "<<prueba7.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Raton1 y el Pez Cebra es: "<<prueba7.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Raton2 y el Humano1 es: "<<prueba8.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Raton2 y el Humano2 es: "<<prueba8.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Raton2 y el Raton1 es: "<<prueba8.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Raton2 y el Gusano1 es: "<<prueba8.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Raton2 y el Gusano2 es: "<<prueba8.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Raton2 y la Mosca de Fruta1 es: "<<prueba8.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Raton2 y la Mosca de Fruta2 es: "<<prueba8.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Raton2 y el virus Ebola es: "<<prueba8.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Raton2 y el Pez Cebra es: "<<prueba8.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Gusano1 y el Humano1 es: "<<prueba9.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Gusano1 y el Humano2 es: "<<prueba9.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Gusano1 y el Raton1 es: "<<prueba9.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y el Raton2 es: "<<prueba9.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y el Gusano2 es: "<<prueba9.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y la Mosca de Fruta1 es: "<<prueba9.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y la Mosca de Fruta2 es: "<<prueba9.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y el virus Ebola es: "<<prueba9.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Gusano1 y el Pez Cebra es: "<<prueba9.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Gusano2 y el Humano1 es: "<<prueba10.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Gusano2 y el Humano2 es: "<<prueba10.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Gusano2 y el Raton1 es: "<<prueba10.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y el Raton2 es: "<<prueba10.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y el Gusano1 es: "<<prueba10.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y la Mosca de Fruta1 es: "<<prueba10.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y la Mosca de Fruta2 es: "<<prueba10.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y el virus Ebola es: "<<prueba10.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Gusano2 y el Pez Cebra es: "<<prueba10.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Humano1 es: "<<prueba11.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Humano2 es: "<<prueba11.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Raton1 es: "<<prueba11.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Raton2 es: "<<prueba11.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Gusano1 es: "<<prueba11.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y la Gusano2 es: "<<prueba11.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y la Mosca de Fruta2 es: "<<prueba11.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y el virus Ebola es: "<<prueba11.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta1 y el Pez Cebra es: "<<prueba11.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Humano1 es: "<<prueba12.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Humano2 es: "<<prueba12.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Raton1 es: "<<prueba12.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Raton2 es: "<<prueba12.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Gusano1 es: "<<prueba12.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y la Gusano2 es: "<<prueba12.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y la Mosca de Fruta1 es: "<<prueba12.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y el virus Ebola es: "<<prueba12.Distance(prueba13)<<endl;
cout<<"La distancia entre el Genoma Mosca de Fruta2 y el Pez Cebra es: "<<prueba12.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma de Ebola y el Humano1 es: "<<prueba13.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma de Ebola y el Humano2 es: "<<prueba13.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma de Ebola y el Raton1 es: "<<prueba13.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma de Ebola y el Raton2 es: "<<prueba13.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma de Ebola y el Gusano1 es: "<<prueba13.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma de Ebola y la Gusano2 es: "<<prueba13.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma de Ebola y la Mosca de Fruta1 es: "<<prueba13.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma de Ebola y el Mosca de Fruta2 es: "<<prueba13.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma de Ebola y el Pez Cebra es: "<<prueba13.Distance(prueba14)<<endl;

cout<<"La distancia entre el Genoma Pez Cebra y el Humano1 es: "<<prueba14.Distance(prueba5)<<endl;
 cout<<"La distancia entre el Genoma Pez Cebra y el Humano2 es: "<<prueba14.Distance(prueba6)<<endl;
 cout<<"La distancia entre el Genoma Pez Cebra y el Raton1 es: "<<prueba14.Distance(prueba7)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y el Raton2 es: "<<prueba14.Distance(prueba8)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y el Gusano1 es: "<<prueba14.Distance(prueba9)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y la Gusano2 es: "<<prueba14.Distance(prueba10)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y la Mosca de Fruta1 es: "<<prueba14.Distance(prueba11)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y el Mosca de Fruta2 es: "<<prueba14.Distance(prueba12)<<endl;
cout<<"La distancia entre el Genoma Pez Cebra y el Ebola es: "<<prueba14.Distance(prueba13)<<endl;

return 0;
}
