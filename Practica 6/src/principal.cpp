


#include "clinvar.h"

using namespace std;
	

int main(int argc, char *argv[]){
    clinvar prueba;
    prueba.load("./datos/clinvar_20160831.vcf");
   
    for(clinvar::iterator it=prueba.begin(); it!=prueba.end(); it++){
    	cout<<(*it)<<endl;
    }


    for(clinvar::enfermedad_iterator it=prueba.ebegin(); it!=prueba.eend(); it++){
    	cout<<(*it)<<endl;
    }

    for(clinvar::gen_iterator it=prueba.gbegin(); it!=prueba.gend(); it++){
    	cout<<(*it)<<endl;
    }

    clinvar::iterator it=prueba.find_Mut("rs111033575");
    cout<<(*it)<<endl;

    clinvar::enfermedad_iterator it2=prueba.find_Enf("C1836439:609286");
    cout<<(*it2)<<endl;

    mutacion mutacion1=(*it);  
    vector<enfermedad> aux=prueba.getEnfermedades(mutacion1);
    for(int i=0; i<aux.size(); i++){
    	cout<<aux[i]<<endl;
    }

    list<IDenf> aux2=prueba.getEnfermedades("Auto");
    for(list<IDenf>::iterator it=aux2.begin(); it!=aux2.end(); it++){
    	cout<<(*it)<<endl;
    }

    set<IDmut> aux3=prueba.getMutacionesEnf("CN169374");
    for(set<IDmut>::iterator it=aux3.begin(); it!=aux3.end(); it++){
    	cout<<(*it)<<endl;
    }

    set<IDmut> aux4=prueba.getMutacionesGen("MRPL43:84545");
    for(set<IDmut>::iterator it=aux4.begin(); it!=aux4.end(); it++){
    	cout<<(*it)<<endl;
    }

    prueba.erase("rs11542130");

    set<mutacion,clinvar::ProbMutaciones>aux5=prueba.topKMutaciones(10,"Autosomal");
    set<mutacion,clinvar::ProbMutaciones>::iterator it3=aux5.begin();
    while(it3!=aux5.end()){
        cout<<(*it3)<<endl;
        it3++;
    }
    return 0;
}
 
