
template <typename T>
bool ComparacionPorID_creciente<T>::operator()(const T &a, const T &b) {
			return (a.getID() < b.getID()); // devuelve verdadero si el ID de a precede al ID de b
}

template <typename T>
bool ComparacionPorID_decreciente<T>::operator()(const T &a, const T &b) {
			return (a.getID() > b.getID()); 
}