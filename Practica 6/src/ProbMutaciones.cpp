#include "clinvar.h"

bool clinvar::ProbMutaciones::operator()(const mutacion &x, const mutacion &z){
	return (1-(x.getCaf()[0]))<(1-z.getCaf()[0]);
}