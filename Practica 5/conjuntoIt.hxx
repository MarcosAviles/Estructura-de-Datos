
template <typename T, class CMP>
conjunto<T,CMP>::conjunto(){

}

template <typename T, class CMP>
conjunto<T,CMP>::conjunto (const conjunto<T,CMP> & d){
	typename conjunto<T,CMP>::const_iterator It=d.cbegin();
	It.it=d.cbegin();
	It.elvector=&vm;
	while(It.it!=d.cend()){
		this->insert(*(It.it));
		It++;
	}
	this->comp=d.comp;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::find (const typename conjunto<T,CMP>::value_type & s){
	typename conjunto<T,CMP>::iterator it;
	it=this->begin();
	bool encontrado=false;
	while(it!=this->end() && !encontrado){
		if(*(it.it)==s){
			encontrado=true;
		}
		else{
			it++;
		}
	}
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::find (const typename conjunto<T,CMP>::value_type & s) const{
	typename conjunto<T,CMP>::const_iterator it;
	it=this->cbegin();
	bool encontrado=false;
	while(it!=this->cend() && !encontrado){
		if(*(it.it)==s){
			encontrado=true;
		}
		else{
			it++;
		}
	}
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const typename conjunto<T,CMP>::value_type & e) const{
	size_type cuantos=0;
	typename conjunto<T,CMP>::const_iterator it;
	it=this->find(e);
	if(it!=this->cend()){
		cuantos++;
	}
	return cuantos;
} 


template <typename T, class CMP>
pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert (const typename conjunto<T,CMP>::value_type& val){
	typename conjunto<T,CMP>::iterator it;
	it=this->lower_bound(val);
	if(it==this->end() || (*(it.it))!=val){
		pair<typename conjunto<T,CMP>::iterator, bool> aux;
		aux.first=it;
		aux.second=true;
		this->vm.insert(it.it, val);
		return aux;
	}
}


template <typename T, class CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::erase (const typename conjunto<T,CMP>::iterator position){
	typename conjunto<T,CMP>::iterator it;
	it.it=vm.erase(position.it);
	it.elvector=&vm;
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::size_type  conjunto<T,CMP>::erase (const typename conjunto<T,CMP>::value_type& val){
	size_type cuantos=0;
	typename conjunto<T,CMP>::const_iterator it;
	it=this->find(val);
	while(it!=this->cend()){
		vm.erase(it.it);
		cuantos++;
		it=this->find(val);
	}
	return cuantos;
}

template <typename T, class CMP>
void conjunto<T,CMP>::clear(){
	this->vm.clear();
}

template <typename T, class CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::size() const {
	return this->vm.size();
}

template <typename T, class CMP>
bool conjunto<T,CMP>::empty() const{
	return this->vm.empty();
}

template <typename T, class CMP>
typename conjunto<T,CMP>::conjunto & conjunto<T,CMP>::operator=( const conjunto<T,CMP> & org){
	this->vm=org.vm;
	this->comp=org.comp;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::begin (){
	typename conjunto<T,CMP>::iterator It;
	It.it=vm.begin();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::end (){
	typename conjunto<T,CMP>::iterator It;
	It.it=vm.end();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin () const{
	typename conjunto<T,CMP>::const_iterator It;
	It.it=vm.cbegin();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend () const{
	typename conjunto<T,CMP>::const_iterator It;
	It.it=vm.cend();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator conjunto<T,CMP>::sbegin () {
	typename conjunto<T,CMP>::secure_iterator It;
	It.it=vm.begin();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator conjunto<T,CMP>::csbegin () const{
	typename conjunto<T,CMP>::const_secure_iterator It;
	It.it=vm.cbegin();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator conjunto<T,CMP>::send () {
	typename conjunto<T,CMP>::secure_iterator It;
	It.it=vm.end();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator conjunto<T,CMP>::csend () const {
	typename conjunto<T,CMP>::const_secure_iterator It;
	It.it=vm.cend();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator conjunto<T,CMP>::ibegin() {
	typename conjunto<T,CMP>::impar_iterator It;
	It.it=vm.begin();
	bool impar=false;
	while(It.it!=vm.end() && !impar){
		if((*(It.it)).getPos()%2==0){
			It++;
		}
		else{
			impar=true;
		}
	}
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_impar_iterator conjunto<T,CMP>::cibegin() const{
	typename conjunto<T,CMP>::const_impar_iterator It;
	It=this->ibegin();
	/*It.it=vm.cbegin();
	bool impar=false;
	while(It.it!=vm.cend() && !impar){
		if((*(It.it)).getPos()%2==0){
			It++;
		}
		else{
			impar=true;
		}
	}
	It.elvector=&vm;*/
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator conjunto<T,CMP>::iend() {
	typename conjunto<T,CMP>::impar_iterator It;
	/*It.it=vm.end()-1;
	bool impar=false;
	while(It.it!=vm.begin() && !impar){
		if((*(It.it)).getPos()%2==0){
			It--;
		}
		else{
			impar=true;
		}
	}
	It.elvector=&vm;*/
	It.it=vm.end();
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_impar_iterator conjunto<T,CMP>::ciend() const{
	typename conjunto<T,CMP>::const_impar_iterator It;
	/*It.it=vm.cend()-1;
	bool impar=false;
	while(It.it!=vm.cbegin() && !impar){
		if((*(It.it)).getPos()%2==0){
			It--;
		}
		else{
			impar=true;
		}
	}
	It.elvector=&vm;*/
	It=this->iend();
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const typename conjunto<T,CMP>::value_type& val){
	typename conjunto<T,CMP>::iterator it;
	it.it=std::lower_bound(this->vm.begin(),this->vm.end(),val,this->comp);
	it.elvector=&vm;
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const typename conjunto<T,CMP>::value_type& val) const{
	typename conjunto<T,CMP>::const_iterator It;
	It.it=std::lower_bound(this->vm.cbegin(),this->vm.cend(),val,this->comp);
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const typename conjunto<T,CMP>::value_type& val){
	typename conjunto<T,CMP>::iterator It;
	It.it=std::upper_bound(this->vm.begin(),this->vm.end(),val,this->comp);
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const typename conjunto<T,CMP>::value_type& val) const{
	typename conjunto<T,CMP>::const_iterator It;
	It.it=std::upper_bound(this->vm.cbegin(),this->vm.cend(),val,this->comp);
	It.elvector=&vm;
	return It;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::cheq_rep( ) const{
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

template <typename T, class CMP>
ostream &  operator << ( ostream & sal, const conjunto<T,CMP> & C){
	typename conjunto<T,CMP>::const_iterator It;
	It=C.cbegin();
	while(It!=C.cend()){
		sal << (*(It.it));
		It++;
	}
	return sal;
}