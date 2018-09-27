#include "clinvar.h"

clinvar::gen_iterator::gen_iterator(){

}


clinvar::gen_iterator::gen_iterator(const clinvar::gen_iterator &  x){
	this->itmap=x.itmap;
	this->itlist=x.itlist;
	this->ptrclinvar=x.ptrclinvar;
}


const mutacion & clinvar::gen_iterator::operator*(){
	return *(*itlist);
}


clinvar::gen_iterator & clinvar::gen_iterator::operator++(){
	itlist++;
	if(itlist==(*itmap).second.end()){
		itmap++;
		itlist=(*itmap).second.begin();
		if(itmap==ptrclinvar->gen_map.end()){
			itmap=ptrclinvar->gen_map.end();
			itlist=(*itmap).second.begin();
		}
	}
	return (*this);

}

clinvar::gen_iterator  clinvar::gen_iterator::operator++(int i){
	clinvar::gen_iterator aux(*this);
	itlist++;
	if(itlist==(*itmap).second.end()){
		itmap++;
		itlist=(*itmap).second.begin();
		if(itmap==ptrclinvar->gen_map.end()){
			itmap=ptrclinvar->gen_map.end();
			itlist=(*itmap).second.begin();
		}
	}
	return aux;
}

bool clinvar::gen_iterator::operator==(const clinvar::gen_iterator & x) const {
	return this->itmap==x.itmap  && this->itlist==x.itlist && this->ptrclinvar==x.ptrclinvar;
}


bool clinvar::gen_iterator::operator!=(const clinvar::gen_iterator & x) const {
	return this->itmap!=x.itmap  || this->itlist!=x.itlist || this->ptrclinvar!=x.ptrclinvar;
}


clinvar::gen_iterator & clinvar::gen_iterator::operator=(const clinvar::gen_iterator & x){
	this->itmap=x.itmap;
	this->itlist=x.itlist;
	this->ptrclinvar=x.ptrclinvar;
	return (*this);
}