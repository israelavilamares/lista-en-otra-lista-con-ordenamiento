#ifndef LISTAFUNCIONES_H
#define LISTAFUNCIONES_H
#include "IteradorLista.h"

template<class T>
class ListaFuncion
{

private:
    Nodo<T> start;
    Nodo<T> fin;
    IteradorLista<T> Itstart;
    IteradorLista<T> Itfin;
public:
    //costructor
    ListaFuncion();
    //destructor
    virtual ~ListaFuncion();
    //apuntador obtener iterador
    IteradorLista<T> *obtenerIterador();
    //exepciones
    IteradorLista<T> &empezar();
    IteradorLista<T> &terminar();
    void insertarInicio(T *);
    void insertarFinal(T *);
    int tamanio();
    bool listfull();
    bool listempty();

    //
    //ordenamientos esta funcion convertira los arreglos
    //a ordenamiento
    //
    void arregloOrdenamiento();
    void megaAsieDispon(Nodo<T>** , Nodo<T>** ,int , int);
    void megaSortOriginal(Nodo<T>**, Nodo<T>**, int , int,int);
    //-----------------------------------
    // ordenamiento por fecha
    //-------------------------------------
    void arrOrdenFech();
    void megaFech(Nodo<T>** , Nodo<T>** ,int , int);
    void megaSortFecha(Nodo<T>**, Nodo<T>**, int , int,int);

};


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
    Itfin.mover = &fin;
}


template <class T>
IteradorLista<T> *ListaFuncion<T>::obtenerIterador()
{
    return new  IteradorLista<T>(start);
}

template<class T>
bool ListaFuncion<T>::listfull()
{
    Nodo<T> *mover = start.siguiente;
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
void ListaFuncion<T>::insertarInicio(T *Datos)
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
        fin.insertarAtras(Datos);
    }else
    {

    cout<<" ARE FULL THE LIST, LA LISTA ESTA LLENA   ";

    }
}

//proporciona la longitud cadena
template <class T>
int ListaFuncion<T>::tamanio()
{
    Nodo<T> *mueve =  start.siguiente;
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
    if((start.siguiente == &fin) || (fin.anterior == &start))
    {

        return true;
    }else
    {

        return false;
    }
}
template <class T>
IteradorLista<T> &ListaFuncion<T>::empezar()
{
    //accedemos a los datos de archivo Iteradorlista.h
    //hay esta la funcion de fijar donde insertaremos y
    //el valor de empezar todo
    Itstart.fijaNodo(start.siguiente);
    return Itstart;

}

template<class T>
IteradorLista<T> &ListaFuncion<T>::terminar()
{
    Itfin->mover = &fin;
    return Itfin;

}

//----------------------------
//Este es un ordenamiento recursivo
// Ya que las funciones se mandan a
//llamar a si mismas
//----------------------------
template<class T>
void ListaFuncion<T>::arregloOrdenamiento()
{

    Nodo<T>** arrAux;
    //este es un arreglo temporal
    Nodo<T>** arrNuevo;
    int cont = 0;
    //primero->siguiente
    Nodo<T>* mover;
    mover = start.siguiente;
   //revisar o se cuentan los Vuelos que estan
    cont = tamanio();
    // aqui es donde ordena y
    // se dice si esta vacio
    if(cont < DOS)
    return;
    //agregamos el contador en el en los
    // apuntadores axiliares
    arrAux = new Nodo<T> *[cont];
    arrNuevo = new Nodo<T> *[cont];
    //inicializamos en 0
    cont = 0;
    // Se mandan los elementos de la lista al arreglo
    // o sea que ahora tiene la lista el arreglo temporal
    //arrAux
    while(mover!= &fin){
        arrAux[cont++] = mover;
        mover = mover->siguiente;
    }

    // aqui se ordena
      megaAsieDispon(arrAux, arrNuevo, 0, cont-1);
    // Primer nodo en su campo anterior = inicio
    //primero = anterior
    arrAux[0]->setterfijaPrevio(&start);
    // hay un enlazado para colocar a los nodos dentro del arreglo
    for(int i = 0;i<cont-1;i++){
        arrAux[i]->setterfijaSiguiente(arrAux[i+1]);
        arrAux[i+1]->setterfijaPrevio(arrAux[i]);
    }

    //es ultimo nodo que este en siguiente = fin
    arrAux[cont-1]->setterfijaSiguiente(&fin);
    // Hasta este punto ya regreso todo a lista y
    //esta ordenado
    //Inicializa la lista
    start.siguiente = arrAux[0];
    // Se Elimina
    //para desocupar la memoria
    delete arrAux;
    delete arrNuevo;
}

template<class T>
void ListaFuncion<T>::megaAsieDispon(Nodo<T>** arrAux,Nodo<T>** arrNuevo,int izq,int der)
{
   int divide;
   //si primero es menor a ultimo
    if(izq < der){
        //asi se empieza(5,3,4,2,1,6)
        //divide en 2 para tener divide repetidamente
        //los elementos del array haciendo esta funcion
        //haciendo estas funcion recursiva
        //el resultado es que queden asi(5) (3) (4) (2) (1) (6)
        //aun que no esten ordenados
        divide = (izq + der)/2;
        megaAsieDispon(arrAux, arrNuevo, izq, divide);
        megaAsieDispon(arrAux, arrNuevo, divide+1, der);
        //Llama a la función
        // mergeSortChido para empezar a
        //construir el array ordenado.
        megaSortOriginal(arrAux, arrNuevo, izq, divide+1, der);
        //aqui acaba la primera funcion del
        //ordenamiento megesort
    }
}


template<class T>
void ListaFuncion<T>::megaSortOriginal(Nodo<T>** arrAux, Nodo<T>** arrNuevo, int izquierda , int derecha,int posUlt)
{
   //apunta al primer de la subarray
    int primAux = izquierda;
   //apunta al ultimo de la subarray
    int finIzq = derecha;

    int numElem;
    // para mantener el indice ordenado
    numElem = posUlt - izquierda+1;

    // estos son para llamara los datos
    //y ademas como clasificadores
    //para decir que uno es para la izquierda
    //y otro para la derecha
    T *objIzquierda, *objDerecha;

    while((izquierda <= finIzq) && (derecha <= posUlt)){
        objIzquierda = arrAux[izquierda]->dameObjeto();
        objDerecha = arrAux[derecha]->dameObjeto();
        if((objIzquierda->dameAsientosDisponibles()) < (objDerecha->dameAsientosDisponibles()))

            arrNuevo[primAux++] = arrAux[izquierda++];
        else
            arrNuevo[primAux++] = arrAux[derecha++];
    }
    while(izquierda <= finIzq)
            arrNuevo[primAux++] = arrAux[izquierda++];

        while(derecha <= posUlt)
           arrNuevo[primAux++] = arrAux[derecha++];

           //por ultimo se hace el religado y se manda
           //ya ligados
        for(int i=0;i < numElem;i++, posUlt--)
            arrAux[posUlt] = arrNuevo[posUlt];
}

template<class T>
void ListaFuncion<T>::arrOrdenFech()
{
    Nodo<T>** arrAux;
    //este es un arreglo temporal
    Nodo<T>** arrNuevo;
    int cont = 0;
    //primero->siguiente
    Nodo<T>* mover;
    mover = start.siguiente;
   //revisar o se cuentan los Vuelos que estan
    cont = tamanio();
    // aqui es donde ordena y
    // se dice si esta vacio
    if(cont < DOS)
    return;
    //agregamos el contador en el en los
    // apuntadores axiliares
    arrAux = new Nodo<T> *[cont];
    arrNuevo = new Nodo<T> *[cont];
    //inicializamos en 0
    cont = 0;
    // Se mandan los elementos de la lista al arreglo
    // o sea que ahora tiene la lista el arreglo temporal
    //arrAux
    while(mover!= &fin){
        arrAux[cont++] = mover;
        mover = mover->siguiente;
    }

    // aqui se ordena
      megaFech(arrAux, arrNuevo, 0, cont-1);
    // Primer nodo en su campo anterior = inicio
    //primero = anterior
    arrAux[0]->setterfijaPrevio(&start);
    // hay un enlazado para colocar a los nodos dentro del arreglo
    for(int i = 0;i<cont-1;i++){
        arrAux[i]->setterfijaSiguiente(arrAux[i+1]);
        arrAux[i+1]->setterfijaPrevio(arrAux[i]);
    }

    //es ultimo nodo que este en siguiente = fin
    arrAux[cont-1]->setterfijaSiguiente(&fin);
    // Hasta este punto ya regreso todo a lista y
    //esta ordenado
    //Inicializa la lista
    start.siguiente = arrAux[0];
    // Se Elimina
    //para desocupar la memoria
    delete arrAux;
    delete arrNuevo;


}



template<class T>
void ListaFuncion<T>::megaFech(Nodo<T>** arrAux, Nodo<T>** arrBuffer ,int izq, int der)
{

    int divide;
   //si primero es menor a ultimo
    if(izq < der){
        //asi se empieza(5,3,4,2,1,6)
        //divide en 2 para tener divide repetidamente
        //los elementos del array haciendo esta funcion
        //haciendo estas funcion recursiva
        //el resultado es que queden asi(5) (3) (4) (2) (1) (6)
        //aun que no esten ordenados
        divide = (izq + der)/2;
        megaFech(arrAux, arrBuffer, izq, divide);
        megaFech(arrAux, arrBuffer, divide+1, der);
        //Llama a la función
        // mergeSortChido para empezar a
        //construir el array ordenado.
        megaSortFecha(arrAux, arrBuffer, izq, divide+1, der);
        //aqui acaba la primera funcion del
        //ordenamiento megesort
    }

}

template<class T>
void ListaFuncion<T>::megaSortFecha(Nodo<T>** arrAux , Nodo<T>** arrBuffer,int izquierda , int derecha,int posUlt)
{
     //apunta al primer de la subarray
    int primAux = izquierda;
   //apunta al ultimo de la subarray
    int finIzq = derecha;

    int numElem;
    // para mantener el indice ordenado
    numElem = posUlt - izquierda+1;

    // estos son para llamara los datos
    //y ademas como clasificadores
    //para decir que uno es para la izquierda
    //y otro para la derecha
    T *objIzquierda, *objDerecha;
   // T *sumaizq = (objIzquierda->diafechagetter()) + (objIzquierda->mesfechagetter()) + (objIzquierda->aniofechagetter());
   // T *sumaDer;
    // poner todas las variables en una sola

    while((izquierda <= finIzq) && (derecha <= posUlt)){

        objIzquierda = arrAux[izquierda]->dameObjeto();

        objDerecha = arrAux[derecha]->dameObjeto();

       if( ( (objIzquierda->mesfechagetter()) && (objIzquierda->aniofechagetter())) > ( (objDerecha->mesfechagetter()) && (objDerecha->aniofechagetter() ) ) )
            arrBuffer[primAux++] = arrAux[izquierda++];
        else
            arrBuffer[primAux++] = arrAux[derecha++];
    }
    while(izquierda <= finIzq)
            arrBuffer[primAux++] = arrAux[izquierda++];

        while(derecha <= posUlt)
           arrBuffer[primAux++] = arrAux[derecha++];

           //por ultimo se hace el religado y se manda
           //ya ligados
        for(int i=0;i < numElem;i++, posUlt--)
            arrAux[posUlt] = arrBuffer[posUlt];
}
/*
template<class T>
void ListaFuncion<T>::megaSortFecha(Nodo<T>** arrAux , Nodo<T>** arrBuffer,int izquierda , int derecha,int posUlt)
{
     //apunta al primer de la subarray
    int primAux = izquierda;
   //apunta al ultimo de la subarray
    int finIzq = derecha;

    int numElem;
    // para mantener el indice ordenado
    numElem = posUlt - izquierda+1;

    // estos son para llamara los datos
    //y ademas como clasificadores
    //para decir que uno es para la izquierda
    //y otro para la derecha
    T *objIzquierda, *objDerecha;
    //mes---------------------------
    T *objIzquierdaM, *objDerechaM;

    //año
    T *objIzquierdaA, *objDerechaA;


   // T *sumaizq = (objIzquierda->diafechagetter()) + (objIzquierda->mesfechagetter()) + (objIzquierda->aniofechagetter());
   // T *sumaDer;
    // poner todas las variables en una sola

    while((izquierda <= finIzq) && (derecha <= posUlt)){
//dia-----------------------------------------------
        objIzquierda = arrAux[izquierda]->dameObjeto();

        objDerecha = arrAux[derecha]->dameObjeto();
//mes----------------------------
        objIzquierdaM = arrAux[izquierda]->dameObjeto();

        objDerechaM = arrAux[derecha]->dameObjeto();
//año-----------------------------

        objIzquierdaA = arrAux[izquierda]->dameObjeto();

        objDerechaA = arrAux[derecha]->dameObjeto();
//----------------------------------
       if( (objIzquierda->diafechagetter()) < (objDerecha->diafechagetter() ) )
            arrBuffer[primAux++] = arrAux[izquierda++];
        else
            arrBuffer[primAux++] = arrAux[derecha++];

    if( (objIzquierdaM->mesfechagetter()) < (objDerechaM->mesfechagetter() ) )
            arrBuffer[primAux++] = arrAux[izquierda++];
        else
            arrBuffer[primAux++] = arrAux[derecha++];

     if( (objIzquierdaA->aniofechagetter()) < (objDerechaA->aniofechagetter() ) )
            arrBuffer[primAux++] = arrAux[izquierda++];
        else
            arrBuffer[primAux++] = arrAux[derecha++];

    }
    while(izquierda <= finIzq)
            arrBuffer[primAux++] = arrAux[izquierda++];

        while(derecha <= posUlt)
           arrBuffer[primAux++] = arrAux[derecha++];

           //por ultimo se hace el religado y se manda
           //ya ligados
        for(int i=0;i < numElem;i++, posUlt--)
            arrAux[posUlt] = arrBuffer[posUlt];
}*/
template<class T>
ListaFuncion<T>::~ListaFuncion()= default;

#endif // LISTAFUNCIONES_H_INCLUDED
