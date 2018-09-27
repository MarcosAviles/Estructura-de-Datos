/** @brief fichero de implementacion de la clase enfermedad

*/

/** @brief constructor por defecto, inicializa los atributos de clase vacios
*/

enfermedad::enfermedad(){
  this->name=string("");
  this->ID=string("");
  this->database=string("");
}

/** @brief constructor con parametros
	@param[in] name nombre de la enfermedad, 
	@param[in] ID id de la enfermedad, 
	@param[in] database base de datos de enfermadad
	*/
enfermedad::enfermedad(const string & name, const string & ID, const string & database){
	this->name=string(name);
	this->ID=string(ID);
	this->database=string(database);
}
 
 /** @brief modificar el valor del atributo privado name
 @param[in] name nombre de la enfermedad, 
*/
 void enfermedad::setName(const string & name){
 	this->name.assign(name);
 }

 /** @brief modificar el valor del atributo privado ID
 @param[in] Id de la enfermedad, 
*/
 void enfermedad::setID(const string & ID){
 	this->ID.assign(ID);
 }

  /** @brief modificar el valor del atributo privado database
 @param[in] database base de datos de la enfermedad, 
*/
 void enfermedad::setDatabase(const string & database){
 	this->database.assign(database);
 }

 /** @brief devuelve el valor del atributo privado name
 @param[out] name nombre de la enfermedad, 
 @return string name, nombre de la enfermedad
*/
 string enfermedad::getName( ) const{
 	return this->name;
 }

 /** @brief devuelve el valor del atributo privado ID
 @param[out] ID identidad de la enfermedad, 
 @return string id, identidad de la enfermedad
*/
 string enfermedad::getID( ) const{
 	return this->ID;
 }

 /** @brief devuelve el valor del atributo privado database
 @param[out] database base de datos de la enfermedad, 
 @return string database, base de datos de la enfermedad
*/
 string enfermedad::getDatabase( ) const{
 	return this->database;
 }

 /** @brief realiza una copia completa de la enfermedad recibida por parametro
 @param[in] e, objeto de tipo enfermedad
 @param[out] enfermedad, enfermedad que se almacena
 @return enfermedad, se retorna la enfermedad una vez copiada
*/
 enfermedad & enfermedad::operator=(const enfermedad & e){
 	this->name.assign(e.name);
 	this->ID.assign(e.ID);
 	this->database.assign(e.database);
 	return *this;
 }

 /** @brief concatena los atributos de la enfermedad objeto
 @param[out] los atributos del propio objeto enfermedad
 @return string, se retorna la concatenacíon de los atributos
*/
 string enfermedad::toString() const{
 	return this->name+" "+this->ID+" "+this->database+"\n";
 }

// Operadores relacionales

 /** @brief realiza una comparacion campo a campo de la enfermedad para la comprobacion si son iguales dos enfermedades
 @param[in] e, objeto de tipo enfermedad
 @return true si son iguales, false en caso contrario
*/
 bool enfermedad::operator==(const enfermedad & e) const{
 	bool igual=false;
 	if(this->name==e.name){
 		if(this->ID==e.ID){
 			if(this->database==e.database){
 				igual=true;
 			}
 		}
 	}
 	return igual;
 }

/** @brief realiza la llamada al operador== para la comprobacion si son distintas dos enfermedades
 @param[in] e, objeto de tipo enfermedad
 @return true si son distitnas, false en caso contrario
*/
 bool enfermedad::operator!=(const enfermedad & e) const{
 	if(*this==e){
 		return false;
 	}
 	else{
 		return true;
 	}
 }

/** @brief comprueba el nombre de dos enfermedades
	@param[in] e, objeto de tipo enfermedad
 @return true si el nombre de la primera enfermedad es menor en orden alfabético, false en caso contrario
*/
 bool enfermedad::operator<(const enfermedad & e) const{
 	if(this->name>e.name){
 		return true;
 	}
 	else{
 		return false;
 	}

 }	//Orden alfabético por campo name. 

/** @brief encuentra una palabra o parte de una palabra en un string
	@param[in] str, string para buscar
 @return true si se contiene el string, false en caso contrario
*/
 bool enfermedad::nameContains(const string & str) const{
 	size_t encuentra=this->name.find(str);
 	if(encuentra!=string::npos){
 		return true;
 	}
 	else{
 		return false;
 	}
 }
   
 /** @brief sobrecarga de operador para poder imprimir por pantalla un objeto de tipo enfermedad
	@param[in] e, objeto de tipo enfermedad
	 @param[in,out] os objeto ostream sobre el que se devuelve
 	@return os de tipo ostream 
*/
 ostream& operator<< ( ostream& os, const enfermedad & e){
   // @todo implementa esta funcion 
   os << "NAME:" << e.getName() <<" ";
   os << "ID:" << e.getID() <<" ";
   os << "DATABASE:" << e.getDatabase() <<endl;  
   return os;
 }
   
   
 
