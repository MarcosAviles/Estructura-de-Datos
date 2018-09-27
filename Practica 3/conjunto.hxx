
conjunto::conjunto( ){
	
}

conjunto::conjunto (const conjunto & d){
	const_iterator It=d.cbegin();
	while(It!=d.cend()){
		this->agregar(*It);
		It++;
	}
}

pair<conjunto::value_type,bool>  conjunto::find (const string & chr, const unsigned int & pos) const{
	pair<conjunto::value_type,bool> aux;
	aux.second=false;
	const_iterator it=this->cbegin();
	bool encontrado=false;
	while(it!=this->cend() && !encontrado){
		aux.first=(*it);
		if(((*it).getChr())==chr && ((*it).getPos())==pos){
			aux.second=true;
			encontrado=true;
		}
		else{
			it++;
		}
		
	}
	return aux;
}

pair<conjunto::value_type,bool>  conjunto::find (const string & ID) const{
	pair<conjunto::value_type,bool> aux;
	aux.second=false;
	bool encontrado=false;
	const_iterator it=this->cbegin();
	while(it!=this->cend() && !encontrado){
		aux.first=(*it);
		if(((*it).getID())==ID){
			aux.second=true;
			encontrado=true;
		}
		else{
			it++;
		}
		
	}
	return aux;
}

	
pair<conjunto::value_type,bool>  conjunto::find (const conjunto::value_type & e) const{
	pair<conjunto::value_type,bool> aux=find(e.getID());
	return aux;
}

conjunto::size_type conjunto::count (const string & chr, const unsigned int & pos) const{
	size_type cuantos=0;
	const_iterator it=this->cbegin();
	while(it!=this->cend()){
		if(((*it).getChr())==chr && ((*it).getPos())==pos){
			cuantos++;
		}
		it++;
	}
	return cuantos;
}

conjunto::size_type conjunto::count (const string & ID) const{
	size_type cuantos=0;
	const_iterator it=this->cbegin();
	while(it!=this->cend()){
		if(((*it).getID())==ID){
			cuantos++;
		}
		it++;
	}
	return cuantos;
}

conjunto::size_type conjunto::count (const conjunto::value_type & e) const{
	size_type cuantos=count(e.getChr(), e.getPos());
	return cuantos;
}

bool conjunto::insert( const conjunto::value_type & e){
	pair<conjunto::value_type, bool> aux=this->find(e.getChr(), e.getPos());
	if(!aux.second){
		aux=this->find(e.getID());
		if(!aux.second){
			const_iterator it=this->lower_bound(e);
			this->vm.insert(it, e);
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}

void conjunto::agregar(const conjunto::value_type & e){
	this->vm.push_back(e);
}

bool conjunto::erase(const string & chr, const unsigned int & pos){
	const_iterator it=this->cbegin();
	bool encontrado=false;
	while(it!=this->cend() && !encontrado){
		if((*it).getChr()==chr && (*it).getPos()==pos){
			encontrado=true;
			it=this->vm.erase(it);
		}
		else{
			it++;
		}
	}
	return encontrado;
}

bool conjunto::erase(const string & ID){
	const_iterator it=this->cbegin();
	bool encontrado=false;
	while(it!=this->cend() && !encontrado){
		if((*it).getID()==ID){
			encontrado=true;
			it=this->vm.erase(it);
		}
		else{
			it++;
		}
		
	}
	return encontrado;
}

bool conjunto::erase(const conjunto::value_type & e){
	bool borrado=this->erase(e.getID());
	return borrado;
}

void conjunto::erase(const const_iterator &it){
	this->vm.erase(it);
}

void conjunto::clear(){
	this->vm.clear();
}

conjunto::size_type conjunto::size() const {
	size_type tam=this->vm.size();
	return tam;
}

bool conjunto::empty() const{
	return this->vm.empty();
}

conjunto & conjunto::operator=( const conjunto & org){
	this->vm=org.vm;
	return *this;
}

conjunto::iterator conjunto::begin (){
	iterator It;
	It=vm.begin();
	if(It==vm.end()){
		return vm.end();
	}
	else{
		return It;
	}
}

conjunto::iterator conjunto::end (){
	iterator It;
	It=vm.end();
	return It;
}

conjunto::const_iterator conjunto::cbegin () const{
	const_iterator It;
	It=vm.cbegin();
	if(It==vm.cend()){
		return vm.cend();
	}
	else{
		return It;
	}
}

conjunto::const_iterator conjunto::cend () const{
	const_iterator It;
	It=vm.cend();
	return It;
}

conjunto::const_iterator conjunto::lower_bound (const string & chr, const unsigned int & pos) const{
	const_iterator It=this->cbegin();
	bool encontrado=false;
	while(It!=this->cend() && !encontrado){
			if(!((*It).esMenor(chr,pos))){
				encontrado=true;
			}
			else if((*It).getChr()==chr){
					if((*It).getPos()==pos){
						encontrado=true;
					}
				}
			else{
				It++;
			}
			// si es mayor se devuelve el iterador de esa mutación	
	}
	if(!encontrado){
		return this->cend(); // si no existe o no se encuentra se devuelve end
	}
	else{
		return It;
	}
	
}

conjunto::const_iterator conjunto::lower_bound (const conjunto::value_type & e) const{
	const_iterator It=this->cbegin();
	bool encontrado=false;
	while(It!=this->cend() && !encontrado){
			if(!(*It<e)){
				encontrado=true;
			}
			else if((*It)==e){
				encontrado=true;
			}
			else{
				It++;
			}
			// si es mayor o igual se devuelve el iterador de esa mutación
	}
	if(!encontrado){
		return this->cend(); // si no existe o no se encuentra se devuelve end
	}
	else{
		return It;
	}
} 

conjunto::const_iterator conjunto::upper_bound (const string & chr, const unsigned int & pos) const{
	const_iterator It=this->cbegin();
	bool encontrado=false;
	while(It!=this->cend() && !encontrado){
			if(!((*It).esMenor(chr,pos))){
				encontrado=true;
			}
			else{
				It++;
			}
			// si es mayor se devuelve el iterador de esa mutación
	}
	if(!encontrado){
		return this->cend(); // si no existe o no se encuentra se devuelve end
	}
	else{
		return It;
	}
}

conjunto::const_iterator conjunto::upper_bound (const conjunto::value_type & e) const{
	const_iterator It=this->cbegin();
	bool encontrado=false;
	while(It!=this->cend() && !encontrado){
			if(!(*It<e)){
				encontrado=true;
				It--;
			}
			else{
				It++;
			}
			// si es mayor se devuelve el iterador de esa mutación
	}
	if(!encontrado){
		return this->cend(); // si no existe o no se encuentra se devuelve end
	}
	else{
		return It;
	}
}

bool conjunto::cheq_rep( ) const{
	bool check=false;
	bool check_conjunto=true;
	string aux_chr;
	int aux_chr2;
	for(int i=0; i<this->vm.size(); i++){
		aux_chr=this->vm[i].getChr();
        if(aux_chr=="X" || aux_chr=="Y" || aux_chr=="MT"){
           check=true;
        }
        else{
          aux_chr2=atoi(vm[i].getChr().c_str());
          if(aux_chr2>=1 && aux_chr2<=22){
            check=true;
          }
        }
        if(!check){
        	check_conjunto=false;
        	break;
        }
        else{
        	check=false;
        }
	}
	if(check_conjunto){
		for(int i=0; i<this->vm.size()-1; i++){
			check=this->vm[i]<this->vm[i+1];
			if(!check){ 
				check_conjunto=false;
				break;
			}
		}
	}
	return check_conjunto;
}

ostream &  operator << ( ostream & sal, const conjunto & C){
	vector<mutacion>::const_iterator It=C.cbegin();
	while(It!=C.cend()){
		sal << (*It);
		It++;
	}
}