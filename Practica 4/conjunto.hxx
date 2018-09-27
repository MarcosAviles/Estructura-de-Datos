
template <typename T, class CMP>
conjunto<T,CMP>::conjunto(){

}

template <typename T, class CMP>
conjunto<T,CMP>::conjunto (const conjunto<T,CMP> & d){
	const_iterator It=d.cbegin();
	while(It!=d.cend()){
		this->insert(*It);
		It++;
	}
	this->comp=d.comp;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::find (const value_type & s){
	iterator it=this->begin();
	bool encontrado=false;
	while(it!=this->end() && !encontrado){
		if((*it)==s){
			encontrado=true;
		}
		else{
			it++;
		}
	}
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::find (const value_type & s) const{
	const_iterator it=this->cbegin();
	bool encontrado=false;
	while(it!=this->cend() && !encontrado){
		if((*it)==s){
			encontrado=true;
		}
		else{
			it++;
		}
	}
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const value_type & e) const{
	size_type cuantos=0;
	const_iterator it=this->find(e);
	if(it!=this->cend()){
		cuantos++;
	}
	return cuantos;
} 


template <typename T, class CMP>
pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert (const value_type& val){
	iterator it=this->lower_bound(val);
	//if(it==this->end() || it==this->begin()){
		pair<typename vector<T>::iterator, bool> aux;
		aux.first=it;
		aux.second=true;
		this->vm.insert(it, val);
		return aux;
	//}
}


template <typename T, class CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::erase (const iterator position){
	iterator it=vm.erase(position);
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::size_type  conjunto<T,CMP>::erase (const value_type& val){
	size_type cuantos=0;
	const_iterator it=this->find(val);
	while(it!=this->cend()){
		vm.erase(it);
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
	iterator It;
	It=vm.begin();
	if(It==vm.end()){
		return vm.end();
	}
	else{
		return It;
	}
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::end (){
	return vm.end();
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin () const{
	const_iterator It;
	It=vm.cbegin();
	if(It==vm.cend()){
		return vm.cend();
	}
	else{
		return It;
	}
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend () const{
	return vm.cend();
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const value_type& val){
	iterator it=std::lower_bound(this->begin(),this->end(),val,this->comp);
	return it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const value_type& val) const{
	const_iterator It=std::lower_bound(this->cbegin(),this->cend(),val,this->comp);
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const value_type& val){
	iterator It=std::upper_bound(this->begin(),this->end(),val,this->comp);
	return It;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const value_type& val) const{
	const_iterator It=std::upper_bound(this->cbegin(),this->cend(),val,this->comp);
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
	typename conjunto<T,CMP>::const_iterator It=C.cbegin();
	while(It!=C.cend()){
		sal << (*It);
		It++;
	}
	return sal;
}