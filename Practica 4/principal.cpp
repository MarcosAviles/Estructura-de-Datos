#include "mutacion.h"
#include "enfermedad.h"
#include "conjunto.h"
#include "functor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <stdlib.h>


using namespace std;
	
	/** @brief lee un fichero de mutaciones, linea a linea
	@param[in] s nombre del fichero
  @param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
	@return true si la lectura ha sido correcta, false en caso contrario
	*/
template <class CMP>
bool load(conjunto<mutacion,CMP> &  cm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 } 
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{ 
      getline(fe,cadena,'\n'); 
    }while (cadena.find("#")==0 && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() ){ 
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
    }
    fe.close();
    return true;
  } // else
  fe.close();
  return false;
 }



int main(int argc, char *argv[]){

  conjunto<mutacion,less<mutacion>> a;
  load(a, "clinvar_20160831.vcf");
  //conjunto<mutacion,greater<mutacion>> b;
  //load(b, "clinvar_20160831.vcf");
  conjunto<mutacion,ComparacionPorID_creciente<mutacion>> c;
  load(c, "clinvar_20160831.vcf");
  //conjunto<mutacion,ComparacionPorID_decreciente<mutacion>> d;
  //load(d, "clinvar_20160831.vcf");
  conjunto<enfermedad,less<enfermedad>> e;
  //conjunto<enfermedad,greater<enfermedad>> f;

  for (mutacion m:a ){
    for (enfermedad enf:m.getEnfermedades()){
      e.insert(enf);
      f.insert(enf);
    }
      
  }
  //cout<<a<<endl;
  //cout<<b<<endl;
  //cout<<c<<endl;
  //cout<<d<<endl;
  //cout<<e<<endl;
  //cout<<f<<endl;
   return 0;
}



