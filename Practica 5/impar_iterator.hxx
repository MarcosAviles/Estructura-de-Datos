template <typename T, class CMP>
conjunto<T, CMP>::impar_iterator::impar_iterator(){

}

template <typename T, class CMP>
conjunto<T, CMP>::impar_iterator::impar_iterator(const typename conjunto<T,CMP>::impar_iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
const typename conjunto<T,CMP>::value_type &
			 conjunto<T, CMP>::impar_iterator::operator*()
{
	return *it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator & conjunto<T,CMP>::impar_iterator::operator++(){
	bool impar=false;
	if(it<(*elvector).end()){
		++it;
	}
	while(it!=(*elvector).end() && !impar){
		if((*it).getPos()%2==0){
			++it;
		}
		else{
			impar=true;
		}
	}
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator 
	 conjunto<T,CMP>::impar_iterator::operator++(int i){
	typename conjunto<T,CMP>::impar_iterator aux(*this);
	it++;
	return aux;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator & conjunto<T,CMP>::impar_iterator::operator--(){
	bool impar=false;
	if(it>(*elvector).begin()){
		--it;
	}
	while(it!=(*elvector).begin() && !impar){
		if((*it).getPos()%2==0){
			--it;
		}
		else{
			impar=true;
		}
	}
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator  conjunto<T,CMP>::impar_iterator::operator--(int i){
	typename conjunto<T,CMP>::impar_iterator aux(*this);
	it--;
	return aux;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::impar_iterator::operator==(const typename conjunto<T,CMP>::impar_iterator & x) const {
	return this->it==x.it;
}



template <typename T, class CMP>
bool conjunto<T,CMP>::impar_iterator::operator!=(const typename conjunto<T,CMP>::impar_iterator & x) const {
	return this->it!=x.it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::impar_iterator & conjunto<T,CMP>::impar_iterator::operator=(const typename conjunto<T,CMP>::impar_iterator & x){
	this->it=x.it;
	this->elvector=x.elvector;
	return (*this);
}