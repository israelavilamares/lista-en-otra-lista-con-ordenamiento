#ifndef NODO_H
#define NODO_H
#include "variablesExtras.h"
template<class T>
class Nodo
{

    private:
    //apuntador de la clase nodo
    Nodo<T> *siguiente;
    Nodo<T> *anterior;
    //apuntador de tipo T osea
    //que puede ser cualquier dato
    T *objeto;

     //-----------------------------------------
        //hamemos amigos de las clases para obtener
        //los datos que estan en privado
        //typename aqui tiene que puede ser de cualquier
        //tipo.
        //------------------------------------------
        template<typename L>
        friend class ListaFuncion;
        template<typename L>
        friend class IteradorLista;

     public:
         //costructor
        Nodo();
        void insertarAdelante(T *);
        void insertarAtras(T *);
        //----------
        //setter
        //----------
        void setterfijaPrevio(Nodo<T> *);
        void setterfijaSiguiente(Nodo<T> *);
        //----------
        //getter
        //----------
        Nodo<T> *dameSiguiente();
        T *dameObjeto();
        //
        //quicksort............
        //
        //Nodo<T> *particionQuick( Nodo<T> *, Nodo<T>*);
        //void _quicksort(Nodo *, Nodo *);
        //Nodo<T> *lastnode(Nodo *);
        //void swap ( int* , int*);
       // void swap ( string* , string*);
        //
        //
        //

        //virtual para derivar mas clases
        virtual ~Nodo();



};

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
    return this->objeto;
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
void Nodo<T>::setterfijaPrevio(Nodo<T> *new_Nodo) {
    this->anterior = new_Nodo;
}

template<class T>
void Nodo<T>::setterfijaSiguiente(Nodo<T> *new_Nodo) {
    this->siguiente = new_Nodo;
}

/*
template<class T>
Nodo<T> *Nodo<T>::particionQuick(Nodo<T> * primero, Nodo<T> *ultimo)
{
    Nodo* aux = new Nodo();
    Nodo<T>* ultimo = new Nodo();
    this->anterior = ultimo;
        aux = ultimo;

       // T pivote = Pasajero->asiento;
}
*/
//----------------
// destructor
//----------------
template <class T>
Nodo<T>::~Nodo() = default;

#endif // NODO_H_INCLUDED
