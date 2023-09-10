#ifndef PASAJEROS_H
#define PASAJEROS_H
#include "variablesExtras.h"
class Pasajero
{
   public:
    //----------------------------------
    //  Costructor con parametro
    //----------------------------------
    Pasajero(string ape, string nom, int eda, int asin, string cOrigen, string cDestino);
    string ObtenerInfo();
    void modificarPasajero(string ape, string nom, int eda, int asin, string cOrigen, string cDestino);
    void modificaCiudad(string cOrigen, string cDestino);
    void modificafull();
    //----------------------------------
    //  destructor sin parametro
    //----------------------------------

    virtual ~Pasajero();

   private:
       //----------------------------
       // ATRIBUTOS
       //----------------------------
        string apellido;
        string nombre;
        string ciudadOrigen;
        string ciudadDestino;
        int edad;
        int asiento;
};





#endif // PASAJEROS_H_INCLUDED
