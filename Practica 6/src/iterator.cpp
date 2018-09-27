#include "clinvar.h"

clinvar::iterator::iterator(){

}


clinvar::iterator::iterator(const clinvar::iterator &  x){
	this->it=x.it;
}


const mutacion & clinvar::iterator::operator*(){
	return *it;
}


clinvar::iterator & clinvar::iterator::operator++(){
	++it;
	return (*this);
}

clinvar::iterator  clinvar::iterator::operator++(int i){
	clinvar::iterator aux(*this);
	++it;
	return aux;
}

clinvar::iterator & clinvar::iterator::operator--(){
	--it;
	return (*this);
}


clinvar::iterator  clinvar::iterator::operator--(int i){
	clinvar::iterator aux(*this);
	it--;
	return aux;
}


bool clinvar::iterator::operator==(const clinvar::iterator & x) const {
	return this->it==x.it;
}


bool clinvar::iterator::operator!=(const clinvar::iterator & x) const {
	return this->it!=x.it;
}


clinvar::iterator & clinvar::iterator::operator=(const clinvar::iterator & x){
	this->it=x.it;
	return (*this);
}