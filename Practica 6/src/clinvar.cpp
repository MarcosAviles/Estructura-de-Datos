#include "clinvar.h"

void clinvar::load(const string & s) {
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
    }while (cadena.find('#')!=string::npos && !fe.eof());

    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() ){ 
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        //cout << mut<< endl;
        // Insertar mutación en el conjunto
        this->insert( mut);
        getline(fe,cadena,'\n');
    }
    fe.close();
  } // else 
  fe.close();
 }

 void clinvar::insert (const mutacion & x){
 	pair<set<mutacion>::iterator,bool> it;
 	it=mutDB.insert(x);

 	if(it.second==true){


 	IDm_map.insert(pair<IDmut,set<mutacion>::iterator>(x.getID(),it.first));

 	vector<string> gen=x.getGenes();
 	list<set<mutacion>::iterator> lista;
 	map<IDgen, list< set<mutacion>::iterator>>::iterator it_map;
 	for(int i=0; i<gen.size(); i++){
 		lista.clear();
 		it_map=gen_map.find(gen[i]);
 		if(it_map!=gen_map.end()){
 			(*it_map).second.push_back(it.first);
 		}
 		else{
 			lista.push_back(it.first);
 			gen_map.insert(pair<IDgen, list<set<mutacion>::iterator>>(gen[i],lista));
 		}
 	}

	vector<enfermedad> enf=x.getEnfermedades();
	map<IDenf,enfermedad>::iterator it_en; 
	for(int i=0; i<enf.size(); i++){
		it_en=EnfDB.find(enf[i].getID());
		IDenf_map.insert(pair<IDenf,set<mutacion>::iterator>(enf[i].getID(),it.first));
		if(it_en==EnfDB.end()){
			EnfDB.insert(pair<IDenf,enfermedad>(enf[i].getID(),enf[i]));
		}
	}	
	
	}

 }

 bool clinvar::erase (IDmut ID){
 	unordered_map<IDmut, set<mutacion>::iterator>::iterator it=IDm_map.find(ID);
 	mutacion x=(*(*it).second);
 	set<mutacion>::iterator it2=(*it).second;
 	int numero=mutDB.erase(x);

 	if(numero>0){

 	IDm_map.erase(it);

 	vector<enfermedad> enf=x.getEnfermedades();
 	map<IDenf,enfermedad>::iterator it_en;
 	multimap<IDenf,set<mutacion>::iterator>::iterator it_en2;
 	for(int i=0; i<enf.size(); i++){
 		it_en=EnfDB.find(enf[i].getID());
 		it_en2=IDenf_map.find(enf[i].getID());
 		if(it_en!=EnfDB.end()){
 			IDenf_map.erase((*it_en).first);
 		}
 		if(it_en2!=IDenf_map.end()){
 			IDenf_map.erase((*it_en2).first);
 		}
 	}

 	vector<string> genes=x.getGenes();
 	clinvar::gen_iterator itg;
 	for(int i=0; i<genes.size(); i++){
		itg.itmap=gen_map.find(genes[i]);
		itg.itlist=(*itg.itmap).second.begin();
		itg.ptrclinvar=&(*this);
		while(itg.itlist!=(*itg.itmap).second.end()){
			if((*itg)==x){
				(*itg.itmap).second.erase(itg.itlist);
			}
			itg.itlist++;
		}
		itg.itlist=(*itg.itmap).second.begin();
		if(itg.itlist==(*itg.itmap).second.end()){
			gen_map.erase((*itg.itmap).first);
		}
	}
		
 	}
 	return numero>0;
 }

 clinvar::iterator clinvar::find_Mut (IDmut ID){
 	clinvar::iterator it=this->begin();
 	bool encontrado=false;
 	while(it!=this->end() && !encontrado){
 		if((*it).getID()==ID){
 			encontrado=true;
 		}
 		else{
 			it++;
 		}
 	}
 	return it;
 }

clinvar::enfermedad_iterator clinvar::find_Enf(IDenf ID){
	clinvar::enfermedad_iterator it=this->ebegin();
	bool encontrado=false;
	while(it!=this->eend() && !encontrado){
		if((*it).getID()==ID){
			encontrado=true;
		}
		else{
			it++;
		}
	}
	return it;
}
	
vector<enfermedad> clinvar::getEnfermedades(mutacion & mut){
	vector<enfermedad> aux;
	clinvar::iterator it=this->find_Mut(mut.getID());
	if(it!=this->end()){
		aux=(*it).getEnfermedades();
	}
	return aux;

}

list<IDenf> clinvar::getEnfermedades(string keyword){
	list<IDenf> aux;
	clinvar::enfermedad_iterator it=this->ebegin();
	while(it!=this->eend()){
		if((*it).nameContains(keyword)){
			aux.push_back((*it.enfermedad_it).first);
		}
		it++;
	}
	return aux;

}

set<IDmut> clinvar::getMutacionesEnf (IDenf ID){
	set<IDmut> aux;
	mutacion aux2;
	multimap<IDenf,set<mutacion>::iterator>::iterator it=IDenf_map.begin();
	while(it!=IDenf_map.end()){
		if((*it).first==ID){
			aux.insert((*(*it).second).getID());		
		}
		it++;
	}
	return aux;
}
	
set<IDmut> clinvar::getMutacionesGen (IDgen ID){
	set<IDmut> aux;
	clinvar::gen_iterator it;
	it.itmap=gen_map.find(ID);
	it.itlist=(*it.itmap).second.begin();
	it.ptrclinvar=&(*this);
	while(it.itlist!=(*it.itmap).second.end()){
		aux.insert((*it).getID());
		it.itlist++;
	}
	return aux;


}

set<mutacion,clinvar::ProbMutaciones> clinvar::topKMutaciones (int k, string keyword){
	list<IDenf> aux=this->getEnfermedades(keyword);
	set<mutacion> aux2;
	list<IDenf>::iterator it=aux.begin();
	multimap<IDenf,set<mutacion>::iterator>::iterator it2;
	while(it!=aux.end()){
		it2=IDenf_map.find((*it));
		aux2.insert((*(*it2).second));
		it++;
	}

	typedef priority_queue<mutacion,vector<mutacion>,ProbMutaciones> pri_queue;
	pri_queue cola;
	set<mutacion>::iterator it3=aux2.begin();
	while(it3!=aux2.end()){
		if(cola.size()<k){
			cola.push((*it3));
		}
		else{ // (cola.top(),(*it3))
			if((1-(cola.top().getCaf()[0]))<(1-(*it3).getCaf()[0])){
				cola.pop();
				cola.push((*it3));
			}
		}
		it3++;
	}

	set<mutacion,clinvar::ProbMutaciones> aux3;
	while(!cola.empty()){
		aux3.insert(cola.top());
		cola.pop();
	}
	return aux3;
}

clinvar::iterator clinvar::begin(){
	clinvar::iterator It;
	It.it=mutDB.begin();
	return It;
}

clinvar::iterator clinvar::end(){
	clinvar::iterator It;
	It.it=mutDB.end();
	return It;
}

clinvar::iterator clinvar::lower_bound(string cromosoma, unsigned int posicion){
	clinvar::iterator it;
	mutacion val;
	val.setChr(cromosoma);
	val.setPos(posicion);
	it.it=mutDB.lower_bound(val);
	return it;
}
	
clinvar::iterator clinvar::upper_bound(string cromosoma, unsigned int posicion){
	clinvar::iterator it;
	mutacion val;
	val.setChr(cromosoma);
	val.setPos(posicion);
	it.it=mutDB.upper_bound(val);
	return it;
}

clinvar::enfermedad_iterator clinvar::ebegin(){
	clinvar::enfermedad_iterator It;
	It.enfermedad_it=EnfDB.begin();
	return It;

}

clinvar::enfermedad_iterator clinvar::eend(){
	clinvar::enfermedad_iterator It;
	It.enfermedad_it=EnfDB.end();
	return It;

}

clinvar::gen_iterator clinvar::gbegin(){
	clinvar::gen_iterator it;
	it.itmap=gen_map.begin();
	it.itlist=(*gen_map.begin()).second.begin();
	it.ptrclinvar=&(*this);
	return it;
}

clinvar::gen_iterator clinvar::gend(){
	clinvar::gen_iterator it;
	it.itmap=gen_map.end();
	it.itlist=(*gen_map.end()).second.begin();
	it.ptrclinvar=&(*this);
	return it;
}
