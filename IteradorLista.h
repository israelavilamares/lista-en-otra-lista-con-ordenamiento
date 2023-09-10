#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H
#include "Nodo.h"
template <class T>
class IteradorLista
{
        private:
        //clases amigas permite acceder a datos
        //privados y publicos
        //-------------------------------
        template<typename L>
        friend class ListaFuncion;
        //-------------------------------
        //setter nodo
        //------------------------------
        void fijaNodo(Nodo<T> *);
        //----------------------
        // hacemos un variable
        //apuntador a nodo
        //-----------------------
        Nodo<T> *mover;


    public:
    //-------------------------------------
    //costructor
    //-------------------------------------
    IteradorLista();
    //-----------------------------------------
    //nenecesita asi
    //-----------------------------------------
    explicit IteradorLista(Nodo<T>);
    bool Vacia();
    //-----------------------------------------
    //sobrecarga de operador
    //-----------------------------------------
    void operator ++(int);
    bool operator !=(IteradorLista &);
    bool operator ==(IteradorLista &);
    IteradorLista<T> &operator =(IteradorLista<T> const&);
    //no esta definido el tipo de dato de la
    //funcion ademas es apuntador
    T *obtenerObj();
    //virtual para derivar mas clases
    virtual ~IteradorLista();
};

//---------------------------------
//los valore seran predeterminados
//----------------------------------
template<class T>
IteradorLista<T>::IteradorLista()=default;
//------------------------------
// accedemos a siguiente implemtando en los
//parametros aux para manicular
//------------------------------
template<class T>
IteradorLista<T>::IteradorLista(Nodo<T> aux)
{//cursor es iguala siguiente
        mover = aux.siguiente;
}

template <class T>
T *IteradorLista<T>::obtenerObj(){
    //un apuntador no tipo de dato
    //es universal
    T *nuevo;
    //--------------------------------------
    //si el ultimo no esta vacio
    //nuevo = mover que apunta a objeto otro
    //apuntador mover = mover -> suiguiente
    //con esto se mueve hacia el ultimo
    //-------------------------------------
    if(mover!=NULL){
        nuevo = mover->objeto;
        mover = mover->siguiente;
        return nuevo;
    }else
    {
    return NULL;

    }
}
template <class T>
bool IteradorLista<T>::Vacia(){
    //-----------------------------
    //si siguiente apunta a objeto
    //es diferente de NULL o nada
    //retorna falso y si no
    //verdadere
    //-----------------------------
    if(mover->objeto != NULL){
        return false;
    }else{
        return true;
    }
}

template <class T>
void IteradorLista<T>::fijaNodo(Nodo<T> *new_Nodo){

    mover = new_Nodo;
}

//destructor
template <class T>
IteradorLista<T>::~IteradorLista() = default;

// Sobrecargas de operadores
template <class T>
void IteradorLista<T>::operator++(int){
    mover = mover -> siguiente;
}
template <class T>
bool IteradorLista<T>::operator!=(IteradorLista &nuevoIt){
    return mover != nuevoIt.mover;
}
template <class T>
bool IteradorLista<T>::operator==(IteradorLista &nuevoIt){
    return mover == nuevoIt->mover;
}
template <class T>
IteradorLista<T> &IteradorLista<T>::operator=(IteradorLista<T> const &nuevoIt){
    if(this != &nuevoIt){
        this->mover = nuevoIt->mover;
    }
    return *this;
}





#endif // ITERADORLISTA_H_INCLUDED
