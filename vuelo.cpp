#include "vuelo.h"

Vuelo::Vuelo(string cOrigen, string cDestino, int cdiaFSalida,int cmesFSalida,int canioFSalida ,
             string fArribo, int dVuelo, float cCarga, int cPasajeros, int aDisponibles)
{
    ciudadOrigen = move(cOrigen);
    ciudadDestino = move(cDestino);
    diaFSalida = cdiaFSalida;
    mesFSalida = cmesFSalida;
    anioFSalida = canioFSalida;
    fechaArribo = move(fArribo);
    distanciaVuelo = dVuelo;
    capacidadCarga = cCarga;
    capacidadPasajeros = cPasajeros;
    asientosDisponibles = aDisponibles;
    listpasajeros = new ListaFuncion<Pasajero>;
}

ListaFuncion<Pasajero> *Vuelo::dameListaPasajeros(){
    return listpasajeros;
}

void Vuelo::agregarPasajero(Pasajero *obj){
    if(listpasajeros->tamanio()< asientosDisponibles){
        listpasajeros -> insertarFinal(obj);
    }
}

void Vuelo::fijaAsientosDisponibles(int asientosA){
    asientosDisponibles = asientosA;
}

void Vuelo::diafechasetter(int adiaFSalida)
{
    diaFSalida = adiaFSalida;


}
void Vuelo::mesfechasetter(int amesFSalida)
{

    mesFSalida = amesFSalida;


}
void Vuelo::aniofechasetter(int salidafechanio)
{
    anioFSalida = salidafechanio;
}

/*int Vuelo::fechaSalisa()const
{
    int fechaSal;
    fechaSal = this->diaFSalida;
    fechaSal += this->mesFSalida;
    fechaSal += this->anioFSalida;

    return fechaSal;

}
*/

int Vuelo::diafechagetter()const{

    return this->diaFSalida;
}

int Vuelo::mesfechagetter()const{

    return this->mesFSalida;
}
int Vuelo::aniofechagetter()const{
    //int fechaSalida
  //  fechaSalida = ani

    return this->anioFSalida;
}

string Vuelo::dameInform(){
    string Datos;
    Datos = ciudadOrigen;
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += ciudadDestino;
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(diaFSalida);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(mesFSalida);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(anioFSalida);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += fechaArribo;
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(distanciaVuelo);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(capacidadCarga);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(capacidadPasajeros);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += to_string(asientosDisponibles);
    Datos += CARACTER;
    Datos += ESPACIO;
    Datos += ESPACIO;
    return Datos;
}
string Vuelo::dameCiudadOrigen(){
    return ciudadOrigen;
}
string Vuelo::dameCiudadDestino(){
    return ciudadDestino;
}
int Vuelo::dameAsientosDisponibles() const{
    return asientosDisponibles;
}

void Vuelo::modificaVuelo(string cOrigen, string cDestino, int cdiaFSalida,int cmesFSalida,int canioFSalida, string fArribo,
    int dVuelo, float cCarga, int cPasajeros, int aDisponibles){
    ciudadOrigen = move(cOrigen);
    ciudadDestino = move(cDestino);
    diaFSalida = cdiaFSalida;
    mesFSalida = cmesFSalida;
    anioFSalida = canioFSalida;
    fechaArribo = move(fArribo);
    distanciaVuelo = dVuelo;
    capacidadCarga = cCarga;
    capacidadPasajeros = cPasajeros;
    asientosDisponibles = aDisponibles;
}
void Vuelo::pasaPasajero(){
    asientosDisponibles--;
}

Vuelo::~Vuelo()=default;

