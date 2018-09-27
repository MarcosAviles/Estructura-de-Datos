#include "clinvar.h"

clinvar::enfermedad_iterator::enfermedad_iterator(){

}


clinvar::enfermedad_iterator::enfermedad_iterator(const clinvar::enfermedad_iterator &  x){
	this->enfermedad_it=x.enfermedad_it;
}


const enfermedad & clinvar::enfermedad_iterator::operator*(){
	return (*enfermedad_it).second;
}


clinvar::enfermedad_iterator & clinvar::enfermedad_iterator::operator++(){
	++enfermedad_it;
	return (*this);
}

clinvar::enfermedad_iterator  clinvar::enfermedad_iterator::operator++(int i){
	clinvar::enfermedad_iterator aux(*this);
	++enfermedad_it;
	return aux;
}

clinvar::enfermedad_iterator & clinvar::enfermedad_iterator::operator--(){
	--enfermedad_it;
	return (*this);
}


clinvar::enfermedad_iterator  clinvar::enfermedad_iterator::operator--(int i){
	clinvar::enfermedad_iterator aux(*this);
	enfermedad_it--;
	return aux;
}


bool clinvar::enfermedad_iterator::operator==(const clinvar::enfermedad_iterator & x) const {
	return this->enfermedad_it==x.enfermedad_it;
}


bool clinvar::enfermedad_iterator::operator!=(const clinvar::enfermedad_iterator & x) const {
	return this->enfermedad_it!=x.enfermedad_it;
}


clinvar::enfermedad_iterator & clinvar::enfermedad_iterator::operator=(const clinvar::enfermedad_iterator & x){
	this->enfermedad_it=x.enfermedad_it;
	return (*this);
}