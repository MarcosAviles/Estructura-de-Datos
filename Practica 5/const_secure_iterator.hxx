template <typename T, class CMP>
conjunto<T, CMP>::const_secure_iterator::const_secure_iterator(){

}

template <typename T, class CMP>
conjunto<T, CMP>::const_secure_iterator::const_secure_iterator(const typename conjunto<T,CMP>::const_secure_iterator &  x){
	assert(x.it<(*elvector).cbegin() || x.it>=(*elvector).cend() || x.elvector!=NULL);
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
const typename conjunto<T,CMP>::value_type & conjunto<T, CMP>::const_secure_iterator::operator*(){
	assert(this->it<(*elvector).cbegin() || this->it>=(*elvector).cend() || this->elvector!=NULL);
	return *it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator++(){
	assert(this->it<(*elvector).cbegin() || this->it>=(*elvector).cend() || this->elvector!=NULL);
	++it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator  conjunto<T,CMP>::const_secure_iterator::operator++(int i){
	assert(this->it<(*elvector).cbegin() || this->it>=(*elvector).cend() || this->elvector!=NULL);
	typename conjunto<T,CMP>::secure_iterator aux(*this);
	++it;
	return aux;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator--(){
	assert(this->it<(*elvector).cbegin() || this->it>=(*elvector).cend() || this->elvector!=NULL);
	--it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator  conjunto<T,CMP>::const_secure_iterator::operator--(int i){
	assert(this->it<(*elvector).cbegin() || this->it>=(*elvector).cend() || this->elvector!=NULL);
	typename conjunto<T,CMP>::secure_iterator aux(*this);
	--it;
	return aux;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::const_secure_iterator::operator==(const typename conjunto<T,CMP>::const_secure_iterator & x) const {
	return this->it==x.it;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::const_secure_iterator::operator!=(const typename conjunto<T,CMP>::const_secure_iterator & x) const {
	return this->it!=x.it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator=(const typename conjunto<T,CMP>::const_secure_iterator & x){
	assert(x.it<(*elvector).begin() || x.it>=(*elvector).end() || x.elvector!=NULL);
	typename conjunto<T,CMP>::const_secure_iterator aux(x);
	return (*aux);
}