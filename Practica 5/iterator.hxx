
template <typename T, class CMP>
conjunto<T, CMP>::iterator::iterator(){

}

template <typename T, class CMP>
conjunto<T, CMP>::iterator::iterator(const typename conjunto<T,CMP>::iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
conjunto<T, CMP>::iterator::iterator(const typename conjunto<T,CMP>::secure_iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
const typename conjunto<T,CMP>::value_type & conjunto<T, CMP>::iterator::operator*(){
	return *it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator++(){
	++it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::iterator::operator++(int i){
	typename conjunto<T,CMP>::iterator aux(*this);
	++it;
	return aux;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator--(){
	--it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::iterator::operator--(int i){
	typename conjunto<T,CMP>::iterator aux(*this);
	it--;
	return aux;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::iterator::operator==(const typename conjunto<T,CMP>::iterator & x) const {
	return this->it==x.it;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::iterator::operator!=(const typename conjunto<T,CMP>::iterator & x) const {
	return this->it!=x.it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator=(const typename conjunto<T,CMP>::iterator & x){
	this->it=x.it;
	this->elvector=x.elvector;
	return (*this);
}