  
  /** @brief constructor por defecto, inicializa los atributos de clase vacios
*/
  mutacion::mutacion(){
    ID="";
    chr=""; 
    pos=0; 
    common=false;
  }

  /** @brief constructor de copia
  @param[in] m objeto de mutacíon
  */
  mutacion::mutacion(const mutacion& m){
    this->ID=m.ID;
    this->chr=m.chr; 
    this->pos=m.pos; 
    this->ref_alt=m.ref_alt; 
    this->genes=m.genes; 
    this->common=m.common;
    this->caf=m.caf;
    this->enfermedades=m.enfermedades;
    this->clnsig=m.clnsig;
  }

  /** @brief recibe un string y un delimitador, y divide el string por cada delimitador que forme la cadena
  @param[in] str string que contiene la cadena a cortar
  @param[in] delimitador caracter especial para dividir
  @param[in,out] v vector sobre el que se almacenan las partes de la cadena
  */
  void mutacion::dividir_string(const string & str, const string &delimitador, vector<string> &v) {
    char *aux=new char[str.length()+1];
    strcpy(aux, str.c_str());
    char * delimitador_aux=new char[str.length()+1];
    strcpy(delimitador_aux, delimitador.c_str());
    char * partes=strtok(aux, delimitador_aux);
    while (partes != NULL){
      v.push_back(partes);
      partes=strtok(NULL, delimitador_aux);
    }
    delete aux, delimitador_aux;
  }

  /** @brief constructor de mutacion a partir de una linea leida del fichero
  @param[in] str string que contiene la linea del fichero leido
  */
  mutacion::mutacion(const string & str){
    vector<string> cadena;
    dividir_string(str, " \t",cadena); // obtengo un vector de string con la cadena original separada por tabuladores
    this->chr=cadena[0]; // almaceno el chr

    /*--------------------------------*/ 
    this->pos=stoi(cadena[1]); // convierto el pos obtenido de string a numero entero y lo almaceno

    /*-----------------------------------------*/ 
    this->ID=cadena[2]; //almaceno el ID
    /*-------------------------------------*/

    this->ref_alt.push_back(cadena[3]); // almaceno el primer elemento REF
    size_t encuentra;
    encuentra=cadena[4].find(","); // busco en la cadena el caracter , para comprobar que existes mas ALT
    if(encuentra!=string::npos){ // Si lo encuentro vuelvo a dividir y
      vector<string> cadena2; // obtengo un nuevo vector de string con las nuevas ALT
      dividir_string(cadena[4], ",",cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->ref_alt.push_back(cadena2[i]); // Las almaceno en ref_alt
      }
    }
    else{
      this->ref_alt.push_back(cadena[4]); // En caso de que no haya ninguna alternativa almaceno el segundo elemento
    }

    /*------------------------------------------------*/
    string copia=cadena[7]; // extraigo el contenido restante de la cadena separada
    encuentra=copia.find("GENEINFO="); //busco si se encuentra geneinfo en la cadena, que deberia encontrarse siempre en el fichero
    copia=copia.substr(encuentra+9); // Recorto la cadena hasta la posicion obtenida anteriormente
    encuentra=copia.find(";"); //ahora algo el mismo proceso para quedarme con la cadena existente entre geneinfo= y el ;
    copia=copia.substr(0,encuentra);
    encuentra=copia.find("|"); // Busco si se encuentra el caracter | que me va a decir si existen varios genes
    if(encuentra!=string::npos){ // Si los hay atravez del metodo dividir_string obtengo un nuevo vector de string con cada gen separado
      vector<string> cadena2;
      dividir_string(copia, "|",cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->genes.push_back(cadena2[i]); // Los almaceno en el vector de genes, atributo privado de la clase mutacion
      }
    }
    else{
      this->genes.push_back(copia); // En el caso de no encontra "|", nos encontramos con un solo gen, el cual lo almaceno directamente
    }
    /*----------------------------------------------------------*/

    copia=cadena[7]; // Mismo proceso anterior pero para el atributo common, en este caso solo podemos encontrar 0 o 1
    encuentra=copia.find("COMMON");
    if(encuentra!=string::npos){
      copia=copia.substr(encuentra+7);
      if(copia=="1"){
        this->common=true;
      }
      if(copia=="0"){
        this->common=false;
      }
    }
    else{
      this->common=NULL;
    }

    /*----------------------------------------------------------*/
    
    copia=cadena[7]; //Idem de lo anterior, con el único cambio que Caf puede encontrarse o no, por lo que primero buscamos Caf
    encuentra=copia.find("CAF");
    if(encuentra!=string::npos){ // Si lo encontramos seguimos con el proceso
      copia=copia.substr(encuentra+4);
      encuentra=copia.find(";");
      copia=copia.substr(0,encuentra);
      vector<string>cadena2;
      dividir_string(copia, ",", cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->caf.push_back(atof(cadena2[i].c_str()));
      }
    } // Si no lo encontramos no hacemos nada y ahorramos instrucciones insignificantes

    /*----------------------------------------------------------*/

    copia=cadena[7]; // Este caso para las enfermedades, que sigo el mismo patron en este caso primero me centro en los nombres de las enfermedades
    encuentra=copia.find("CLNDBN");
    copia=copia.substr(encuentra+7);
    encuentra=copia.find(";");
    copia=copia.substr(0,encuentra);
    encuentra=copia.find("|");
    if(encuentra!=string::npos){
      vector<string> cadena2;
      dividir_string(copia, "|", cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->enfermedades.push_back(enfermedad()); 
        this->enfermedades[i].setName(cadena2[i]);
      }
    }
    else{
        this->enfermedades.push_back(enfermedad());
        this->enfermedades[0].setName(copia);
    }

    copia=cadena[7];  // Ahora con las IDs de las enfermedades
    encuentra=copia.find("CLNDSDBID");
    copia=copia.substr(encuentra+10);
    encuentra=copia.find(";");
    copia=copia.substr(0,encuentra);
    encuentra=copia.find("|");
    if(encuentra!=string::npos){
      vector<string> cadena2;
      dividir_string(copia, "|", cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->enfermedades[i].setID(cadena2[i]);
      }
    }
    else{
        this->enfermedades[0].setID(copia);
    }

    copia=cadena[7]; // Y por último con las database de las enfermedades
    encuentra=copia.find("CLNDSDB");
    copia=copia.substr(encuentra+8);
    encuentra=copia.find(";");
    copia=copia.substr(0,encuentra);
    encuentra=copia.find("|");
    if(encuentra!=string::npos){
      vector<string> cadena2;
      dividir_string(copia, "|", cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->enfermedades[i].setDatabase(cadena2[i]);
      }
    }
    else{
        this->enfermedades[0].setDatabase(copia);
    }

    /*-----------------------------------------------------------------*/
    copia=cadena[7]; // Para terminar igualmente con el atributo clnsig, con la unica particularidad que convierto un string a entero para poder almacenarlo
    encuentra=copia.find("CLNSIG");
    copia=copia.substr(encuentra+7);
    encuentra=copia.find(";");
    copia=copia.substr(0,encuentra);
    encuentra=copia.find("|");
    if(encuentra!=string::npos){
      vector<string> cadena2;
      dividir_string(copia, "|", cadena2);
      for(int i=0; i<cadena2.size(); i++){
        this->clnsig.push_back(stoi(cadena2[i]));
      }
    }
    else{
        for(int i=0; i<enfermedades.size(); i++){
          this->clnsig.push_back(stoi(copia));
        }
    }

  }   //para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada
 
 /** @brief modifica el valor del atributo ID de mutacion
  @param[in] id string que contiene eñ id de mutacion
  */
  void mutacion::setID(const string & id){
    this->ID=id;
  }

  /** @brief modifica el valor del atributo ID de mutacion
  @param[in] id string que contiene el id de mutacion
  */
  void mutacion::setChr(const string & chr){
    this->chr=chr;
  }

  /** @brief modifica el valor del atributo pos de mutacion
  @param[in] id entero que contiene la posicion de mutacion
  */
  void mutacion::setPos(const unsigned int & pos){
    this->pos=pos;
  }

  /** @brief modifica el vector de string del atributo ref_alt de mutacion
  @param[in] ref_alt vector de string que contiene las referencias y alternativas de la mutacion
  */
  void mutacion::setRef_alt(const std::vector<string> & ref_alt){
    this->ref_alt=ref_alt;
  }

  /** @brief modifica el vector de string del atributo genes de mutacion
  @param[in] genes vector de string que contiene los genes de la mutacion
  */
  void mutacion::setGenes (const std::vector<string> & genes){
    this->genes=genes;
  } 

  /** @brief modifica el vector del booleano del atributo common de mutacion
  @param[in] common booleano que contiene si es comun o no la mutacion en la poblacion
  */
  void mutacion::setCommon (const bool & common){
    this->common=common;
  }

  /** @brief modifica el vector de float del atributo caf de mutacion
  @param[in] caf vector de float que contiene la frecuencia de la mutacion
  */
  void mutacion::setCaf (const std::vector<float> & caf){
    this->caf=caf;
  }

/** @brief modifica el vector de enfermedades del atributo enfermedades de mutacion
  @param[in] enfermedades vector de enfermedades que contiene la enfermedades relacionadas con la mutacion
  */
  void mutacion::setEnfermedades (const std::vector<enfermedad> & enfermedades){
    this->enfermedades=enfermedades;
  }

/** @brief modifica el vector de int del atributo clnsig de mutacion
  @param[in] caf vector de int que contiene los tipos de enfermedades de la mutacion
  */
  void mutacion::setClnsig (const std::vector<int> & clnsig){
    this->clnsig=clnsig;
  }  
  
  /** @brief devuelve el valor del atributo privado ID
 @param[out] ID identidad de la mutacion, 
 @return string id, identidad de la mutacion
*/
  string mutacion::getID( ) const{
    return this->ID;
  }

/** @brief devuelve el valor del atributo privado Chr
 @param[out] Chr cromosoma de la mutacion, 
 @return string Chr, cromosoma de la mutacion
*/
  string mutacion::getChr( ) const{
    return this->chr;
  }

  /** @brief devuelve el valor del atributo privado Pos
 @param[out] pos posicion de la mutacion, 
 @return string pos, posicion de la mutacion
*/
  unsigned int mutacion::getPos( ) const{
    return this->pos;
  }

/** @brief devuelve el atributo privado ref_alt 
 @param[out] ref_alt vector de string de referencias y alternativas de la mutacion, 
 @return string ref_alt, vector de string 
*/
  const std::vector<string> & mutacion::getRef_alt () const{
    return this->ref_alt;
  }

/** @brief devuelve el atributo privado genes
 @param[out] genes vector de string de los genes de la mutacion, 
 @return string genes, vector de string 
*/
  const std::vector<string> & mutacion::getGenes () const{
    return this->genes;
  }

/** @brief devuelve el atributo privado common 
 @param[out] common booleano que identifica si es comun la mutacion en la poblacion, 
 @return bool common 
*/

  bool mutacion::getCommon () const{
    return this->common;
  }

/** @brief devuelve el atributo privado Caf
 @param[out] Caf vector de float de la frecuencia de la mutacion, 
 @return ref_alt, vector de float 
*/
  const std::vector<float> & mutacion::getCaf () const{
    return this->caf;
  }

/** @brief devuelve el atributo privado enfermedades
 @param[out] enfermedades vector de enfermedades relacionadas con la mutacion, 
 @return enfermedades, vector de enfermedades 
*/
  const std::vector<enfermedad> & mutacion::getEnfermedades () const{
    return this->enfermedades;
  }

/** @brief devuelve el atributo privado clnsig
 @param[out] Clnsig vector de enteros con el tipo de cada enfermedad de la mutacion, 
 @return clnsig, vector de enteros 
*/
  const std::vector<int> & mutacion::getClnsig () const{
    return this->clnsig;
  }
    
/** @brief realiza una copia completa de la mutacion recibida por parametro
 @param[in] m, objeto de tipo mutacion
 @param[out] mutacion, mutacion que se almacena
 @return mutacion, se retorna la mutacion una vez copiada
*/
  mutacion & mutacion::operator=(const mutacion & m){
    this->ID=m.ID;
    this->chr=m.chr; 
    this->pos=m.pos; 
    this->ref_alt=m.ref_alt; 
    this->genes=m.genes; 
    this->common=m.common;
    this->caf=m.caf;
    this->enfermedades=m.enfermedades;
    this->clnsig=m.clnsig;
    return *this;
  }

 /** @brief realiza una comparacion campo a campo de la mutacion recibida por parametro para la comprobacion si son iguales dos mutaciones
 @param[in] m, objeto de tipo mutacion
 @return true si son iguales, false en caso contrario
*/
  bool mutacion::operator==(const mutacion & m) const{
    int aux_chr=0;
    int aux_chr2=0;
    if(this->chr=="X"){
      aux_chr=23;
    }
    else if(this->chr=="Y"){
      aux_chr=24;
    }
    else if(this->chr=="MT"){
      aux_chr=25;
    }
    else{
      aux_chr=stoi(this->chr);
    }

    if(m.chr=="X"){
      aux_chr2=23;
    }
    else if(m.chr=="Y"){
      aux_chr2=24;
    }
    else if(m.chr=="MT"){
      aux_chr2=25;
    }
    else{
      aux_chr2=stoi(m.chr);
    }
    bool iguales=false;
    if(this->ID==m.ID){
      if(aux_chr==aux_chr2){
        if(this->pos==m.pos){
          for(int i=0; i<this->ref_alt.size(); i++){
            if(this->ref_alt[i]==m.ref_alt[i]){
              iguales=true;
            }
            else{
              iguales=false;
              break;
            }
          }
        }
        if(iguales){
          for(int i=0; i<this->genes.size(); i++){
            if(this->genes[i]==m.genes[i]){
              iguales=true;
            }
            else{
              iguales=false;
              break;
            }
          }
        }
        if(iguales){
          if(this->common==m.common){
            for(int i=0; i<this->caf.size(); i++){
              if(this->caf[i]==m.caf[i]){
                iguales=true;
              }
              else{
                iguales=false;
                break;
              }
            }
          }
        }
        if(iguales){
          for(int i=0; i<enfermedades.size(); i++){
            iguales=enfermedades[i]==m.enfermedades[i];
            if(!iguales){
              break;
            }
          }
        }
        if(iguales){
          for(int i=0; i<this->clnsig.size(); i++){
            if(this->clnsig[i]==m.clnsig[i]){
              iguales=true;
            }
            else{
              iguales=false;
              break;
            }
          }
        }
      }
    }
    return iguales;
  }

/** @brief comprueba el chr y pos de dos mutaciones, compara primero el chr si es menor el objeto local que el recibido por parametro. En caso de ser iguales se compara la posicion de ambas
  @param[in] m, objeto de tipo mutacion
 @return true si la mutacion local es menor que la mutacion recibida por parametro, false en caso contrario
*/
  bool mutacion::operator<(const mutacion & m) const{
    int aux_chr=0;
    int aux_chr2=0;
    if(this->chr=="X"){
      aux_chr=23;
    }
    else if(this->chr=="Y"){
      aux_chr=24;
    }
    else if(this->chr=="MT"){
      aux_chr=25;
    }
    else{
      aux_chr=stoi(this->chr);
    }

    if(m.chr=="X"){
      aux_chr2=23;
    }
    else if(m.chr=="Y"){
      aux_chr2=24;
    }
    else if(m.chr=="MT"){
      aux_chr2=25;
    }
    else{
      aux_chr2=stoi(m.chr);
    }

    if(aux_chr==aux_chr2)
     return (this->pos<m.pos);
    else
      return(aux_chr<aux_chr2);
      
    
  }     //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros). 

  bool mutacion::operator>(const mutacion & m) const{
    int aux_chr=0;
    int aux_chr2=0;
    if(this->chr=="X"){
      aux_chr=23;
    }
    else if(this->chr=="Y"){
      aux_chr=24;
    }
    else if(this->chr=="MT"){
      aux_chr=25;
    }
    else{
      aux_chr=stoi(this->chr);
    }

    if(m.chr=="X"){
      aux_chr2=23;
    }
    else if(m.chr=="Y"){
      aux_chr2=24;
    }
    else if(m.chr=="MT"){
      aux_chr2=25;
    }
    else{
      aux_chr2=stoi(m.chr);
    }

    if(aux_chr==aux_chr2)
     return (this->pos>m.pos);
    else
      return(aux_chr>aux_chr2);
  } 
/** @brief sobrecarga de operador para poder imprimir por pantalla un objeto de tipo mutacion
  @param[in] m, objeto de tipo mutacion
   @param[in,out] os objeto ostream sobre el que se devuelve
  @return os de tipo ostream 
*/
  ostream& operator<< ( ostream& os, const mutacion& m){
    os << "ID:" << m.getID() <<endl;
    os << "CHR:" << m.getChr() <<endl;
    os << "POS:" << m.getPos() <<endl;
    vector<string> v=m.getRef_alt();
    for(int i=0; i<v.size(); i++){
      os << "REF_ALT:" << v[i] <<endl;
    }
    vector<string> y=m.getGenes();
    for(int i=0; i<y.size(); i++){
      os << "GENES:" << y[i] <<endl;
    }
    os << "COMMON:" << m.getCommon() <<endl;
    vector<float> z=m.getCaf();
    for(int i=0; i<z.size(); i++){
      os << "CAF:" << z[i] <<endl;
    }
    vector<enfermedad> e=m.getEnfermedades();
    for(int i=0; i<e.size(); i++){
      os << e[i];
    }

    vector<int> w=m.getClnsig();
    for(int i=0; i<w.size(); i++){
      os << "CLNSIG:" << w[i] <<endl;
    }
    return os;
  }  

