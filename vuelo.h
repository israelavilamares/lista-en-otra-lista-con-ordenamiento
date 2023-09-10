#ifndef VUELO_H
#define VUELO_H

#include "listaFunciones.h"
#include "pasajeros.h"
class Vuelo{


    public:
        //
        //costructor parametrizado
        //
    Vuelo(string , string , int cdiaFSalida ,int cmesFSalida ,int anioFSalida , string , int ,
            float , int , int aDisponibles);
      void modificaVuelo(string , string , int cdiaFSalida,int cmesFSalida,int canioFSalida, string ,
             int, float , int , int aDisponibles);

        ListaFuncion<Pasajero> *dameListaPasajeros();
        void agregarPasajero(Pasajero *obj);
        void fijaAsientosDisponibles(int asientos);
        int dameAsientosDisponibles() const;
        //setter de fecha de salida
        void diafechasetter(int);
        void mesfechasetter(int);
        void aniofechasetter(int);
        //getter de fecha de salida

        int diafechagetter()const;
        int mesfechagetter()const;
        int aniofechagetter()const;

        //  int fechaSalisa()const;

        void pasaPasajero();
        string dameCiudadOrigen();
        string dameCiudadDestino();
        string dameInform();

        virtual ~Vuelo();


    private:
        ListaFuncion<Pasajero> *listpasajeros;
        string ciudadOrigen;
        string ciudadDestino;
        int diaFSalida;
        int mesFSalida;
        int anioFSalida;
        string fechaArribo;
        int distanciaVuelo;
        float capacidadCarga;
        int capacidadPasajeros;
        int asientosDisponibles;
};



#endif // VUELO_H_INCLUDED
