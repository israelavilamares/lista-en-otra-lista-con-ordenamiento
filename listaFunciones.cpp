#include "listaFunciones.h"
//--------------------------------------
//inicializar las varibles o apuntadores
// en el constructor
//---------------------------------------
template<class T>
ListaFuncion<T>::ListaFuncion()
{
    start.siguiente = &fin;
    fin.anterior = &start;
    //este es un apuntador
    //de IteradorLista
    Itfin.mover = fin;
}


template <class T>
IteradorLista<T> *ListaFuncion<T>::obtenerIterador()
{
    return new  IteradorLista<T>(start);
}

template<class T>
bool ListaFuncion<T>::listfull()
{
    Nodo<T> *mover = start->siguiente;
    int contador = 0;
    while(mover != &fin){
        contador ++;
        mover = mover->siguiente;
    }
    if(contador < 100)
    {

        return false;
    }else{

        return true;
    }


}
template<class T>
__attribute__((unused)) void ListaFuncion<T>::insertarInicio(T *Datos)
{
    if(!listfull())
    {
        start->insertarAdelante(Datos);
    }
 /*   else
    {
        cout<<"     ARE FULL THE LIST, LA LISTA ESTA LLENA   ";
    }*/
}

template<class T>
void  ListaFuncion<T>::insertarFinal(T *Datos)
{
     if(!listfull())
    {
        fin->insertarAtras(Datos);
    }else
    {

    cout<<"     ARE FULL THE LIST, LA LISTA ESTA LLENA   ";

    }
}

//proporciona la longitud cadena
template <class T>
int ListaFuncion<T>::tamanio()
{
    Nodo<T>* mueve =  start->siguiente;
    int contador = 0;
    while(mueve != &fin){
        contador ++;
        mueve = mueve->siguiente;
    }
    return contador;
}





template <class T>
bool ListaFuncion<T>::listempty()
{
    if((start->siguiente == &fin) || (fin->anterior == &start))
    {

        return true;
    }else
    {

        return false;
    }
}
template <class T>
__attribute__((unused)) IteradorLista<T> &ListaFuncion<T>::empezar()
{
    //accedemos a los datos de archivo Iteradorlista.h
    //hay esta la funcion de fijar donde insertaremos y
    //el valor de empezar todo
    Itstart.fijaNodo(start.siguiente);
    return Itstart;

}

template<class T>
__attribute__((unused)) IteradorLista<T> &ListaFuncion<T>::terminar()
{
    Itfin->mover = &fin;
    return Itfin;

}


template <class T>
ListaFuncion<T>::~ListaFuncion()=default;
