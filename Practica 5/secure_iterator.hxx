template <typename T, class CMP>
conjunto<T, CMP>::secure_iterator::secure_iterator(){

}

template <typename T, class CMP>
conjunto<T, CMP>::secure_iterator::secure_iterator(const typename conjunto<T,CMP>::secure_iterator &  x){
	assert(x.it<(*elvector).begin() || x.it>=(*elvector).end() || x.elvector!=NULL);
	this->it=x.it;
	this->elvector=x.elvector;
}

template <typename T, class CMP>
const typename conjunto<T,CMP>::value_type & conjunto<T, CMP>::secure_iterator::operator*(){
	assert(it<(*elvector).begin() || it>=(*elvector).end() || elvector!=NULL);
	return *it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator++(){
	assert(it<(*elvector).begin() || it>=(*elvector).end() || elvector!=NULL);
	++it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator  conjunto<T,CMP>::secure_iterator::operator++(int i){
	assert(this->it<(*elvector).begin() || this->it>=(*elvector).end() || this->elvector!=NULL);
	typename conjunto<T,CMP>::secure_iterator aux(*this);
	++it;
	return aux;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator--(){
	assert(this->it<(*elvector).begin() || this->it>=(*elvector).end() || this->elvector!=NULL);
	--it;
	return (*this);
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator  conjunto<T,CMP>::secure_iterator::operator--(int i){
	assert(this->it<(*elvector).begin() || this->it>=(*elvector).end() || this->elvector!=NULL);
	typename conjunto<T,CMP>::secure_iterator aux(*this);
	--it;
	return aux;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::secure_iterator::operator==(const typename conjunto<T,CMP>::secure_iterator & x) const {
	return this->it==x.it;
}

template <typename T, class CMP>
bool conjunto<T,CMP>::secure_iterator::operator!=(const typename conjunto<T,CMP>::secure_iterator & x) const {
	return this->it!=x.it;
}

template <typename T, class CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator=(const typename conjunto<T,CMP>::secure_iterator & x){
	assert(x.it<(*elvector).begin() || x.it>=(*elvector).end() || x.elvector!=NULL);
	typename conjunto<T,CMP>::secure_iterator aux(x);
	return (*aux);
}