#include "Nodo.h"

template <class T>
Nodo<T>::Nodo(){
    siguiente = NULL;
    anterior = NULL;
    objeto = NULL;
}
//-------------------------------------------
//getter puede tener acceso a los propiedades
//privadas por eso dame va hacer siq¿guiente
// Metodo dame siguiente objeto
//-------------------------------------------

template <class T>
Nodo<T> *Nodo<T>::dameSiguiente(){
    return siguiente;
}

//---------------------------------
//getter
//accede a la parte privada y obtiene dameobjeto
// Metodo dame objeto va a retornar objeto
//---------------------------------
template <class T>
T *Nodo<T>::dameObjeto(){ // Metodo dame objeto
    return objeto;
}


template <class T>
void Nodo<T>::insertarAdelante(T *Obj){
    //auto *nuevoNodo = new Nodo();
    //cramos un nuevonodo
   Nodo *new_Nodo = new Nodo();
   this -> siguiente->anterior = new_Nodo;
    new_Nodo -> siguiente = this -> siguiente;
    new_Nodo -> anterior = this;
    this -> siguiente = new_Nodo;
    this -> siguiente -> objeto = Obj;
}

template <class T>
void Nodo<T>::insertarAtras(T *Obj){
    Nodo *new_Nodo = new Nodo();
    this -> anterior -> siguiente = new_Nodo;
    new_Nodo -> siguiente = this;
    new_Nodo -> anterior = this -> anterior;
    this -> anterior = new_Nodo;
    this -> anterior -> objeto = Obj;
}
template<class T>
void Nodo<T>::fijaPrevio(Nodo<T> *new_Nodo) {
    this->anterior = new_Nodo;
}

template<class T>
void Nodo<T>::fijaSiguiente(Nodo<T> *new_Nodo) {
    this->anterior = new_Nodo;
}
//----------------
// destructor
//----------------
template <class T>
Nodo<T>::~Nodo() = default;
