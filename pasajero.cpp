#include "pasajeros.h"
//------------------------------------------------
//costructor inicializamos las variables
// que declaramos en privado toma la variable del
// parametro y le asigna otro atributo
//-------------------------------------------------
Pasajero::Pasajero(string ape, string nom, int eda, int asin, string cOrigen, string cDestino)
{
    apellido = move(ape);
    nombre = move(nom);
    edad = eda;
    asiento = asin;
    ciudadOrigen = move(cOrigen);
    ciudadDestino = move(cDestino);

}


void Pasajero::modificarPasajero(string apell,
                                  string nom,
                                  int eda,
                                  int asin,string ciuOrigen, string ciuDestino){
    //es string
    apellido = move(apell);
    //es string
    nombre = move(nom);
    edad = eda;
    asiento = asin;
    //es string
    ciudadOrigen = move(ciuOrigen);
    //es string
    ciudadDestino = move(ciuDestino);
}

string Pasajero::ObtenerInfo()
{
        //almacenan los datos en la variable
        //cadena retornardato
    string retornarDato;
    retornarDato = apellido;
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += nombre;
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += to_string(edad);
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += to_string(asiento);
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += ciudadOrigen;
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += ciudadDestino;
    retornarDato += CARACTER;
    retornarDato += ESPACIO;
    retornarDato += ESPACIO;
    return retornarDato;
}

void Pasajero::modificaCiudad(string cOrigen, string cDestino){
    ciudadOrigen = move(cOrigen);
    ciudadDestino = move(cDestino);
}
Pasajero::~Pasajero()= default;


