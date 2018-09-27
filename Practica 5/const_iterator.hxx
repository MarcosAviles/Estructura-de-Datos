
template <typename T, class CMP>
conjunto<T, CMP>::const_iterator::const_iterator(){

}

template <typename T, class CMP>
conjunto<T, CMP>::const_iterator::const_iterator(const typename conjunto<T,CMP>::iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
conjunto<T, CMP>::const_iterator::const_iterator(const typename conjunto<T,CMP>::const_iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
conjunto<T, CMP>::const_iterator::const_iterator(const typename conjunto<T,CMP>::const_secure_iterator &  x){
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
const typename conjunto<T,CMP>::value_type & conjunto<T, CMP>::const_iterator::operator*(){
	return *it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator++(){
	++it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::const_iterator::operator++(int i){
	typename conjunto<T,CMP>::const_iterator aux(*this);
	++it;
	return aux;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator--(){
	--it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::const_iterator::operator--(int i){
	typename conjunto<T,CMP>::const_iterator aux(*this);
	--it;
	return aux;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::const_iterator::operator==(const typename conjunto<T,CMP>::const_iterator & x) const {
	return this->it==x.it;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::const_iterator::operator!=(const typename conjunto<T,CMP>::const_iterator & x) const {
	return this->it!=x.it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator=(const typename conjunto<T,CMP>::const_iterator & x){
	this->it=x.it;
	this->elvector=x.elvector;
	return (*this);
}