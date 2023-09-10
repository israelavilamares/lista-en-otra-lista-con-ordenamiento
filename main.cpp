#include "listaFunciones.h"
#include "IteradorLista.h"
#include "pasajeros.h"
#include "vuelo.h"
#include <string>
//-------------------------------------
//macros
//------------------------------------
#define PAUSA system("pause");
//#define system("cls") system("cls")



//------------------------------------
// Declaracion de funciones
//------------------------------------


//------------------------------------
// Funciones de vuelo
//------------------------------------
void agregarVuelo();
void modificarVuelo();
void mostrarVuelos();


//------------------------------------
// Funciones de pasajero
//------------------------------------
void ingresarPasajeros();
//apuntador funcion tipo pasajero
Pasajero *insertaPasajero(string cOrigen, string cDestino);
void modificarPasajeros();
//apuntador funcion tipo vuelo
Vuelo *imprimirPasajeros();
void vueloAvailable();

//ordenar
void ordenarVuelos();
//------------------------------------
// creacion de objetos
//------------------------------------
//se declara auto para no especificar el tipo
void ordVueloFech();

auto *listaPasajeros = new ListaFuncion<Pasajero>;
auto *listaVuelos = new ListaFuncion<Vuelo>;



int main()
{
  //  listavuelos Objvuelo;



    int opc;
    do
    {
        system("cls");
        cout<<" ________________________ ";
        cout<<" \n|          menu          |";
        cout<<" \n|________________________| ";
        cout<<"\n(1) Insertar pasajeros ";
        cout<<"\n(2) Mostrar pasajeros";
        cout<<"\n(3) Modificar pasajeros ";
        cout<<"\n(4) Inserta Vuelos ";
        cout<<"\n(5) Modificar Vuelos ";
        cout<<"\n(6) Muestra Vuelos ";
        cout<<"\n(7) ordena Por asientos";
        cout<<"\n(8) Ordena Por Fecha";
        cout<<"\n(0) Salir ";
        cout<<"\n-----------------------------------";
        cout<<"\n Presiona Un Numero Del Menu: ";
        cin>>opc;
        switch(opc)
        {
        case 1:
        system("cls");
        ingresarPasajeros();
        break;

        case 2:
        system("cls");
        imprimirPasajeros();
        PAUSA
        break;

        case 3:
        system("cls");
        modificarPasajeros();
        break;

        case 4:
        system("cls");
        agregarVuelo();
        break;

        case 5:
        system("cls");
        modificarVuelo();
        PAUSA
        break;

        case 6:
        system("cls");
        mostrarVuelos();
        PAUSA
        break;

        case 7:
        system("cls");
        ordenarVuelos();
        PAUSA
        break;


        case 8:
        system("cls");
        ordVueloFech();
        PAUSA
        break;

        case 0:
        cout<<"              saliendo.... ";
        PAUSA
        break;

        default:
            cout<<"    OPCION INVALIDA VUELVE A INGRESAR    ";
            PAUSA


        }
    }while(opc != 0);



    return 0;
}


//ubicarnos sobre cual vuelo sera para ingresar pasajeros
void ingresarPasajeros()
{
    system("cls");
    int NumVuelo, contadorNuevo = 1;
    vueloAvailable();
    IteradorLista<Vuelo> *iteradorenEncuentraVuelos = listaVuelos->obtenerIterador();
    if(iteradorenEncuentraVuelos->Vacia()){
        cout<<"\n   ";
        PAUSA
        return;
    }

    if(!iteradorenEncuentraVuelos->Vacia()){
            cout<<endl<<"Elige el vuelo donde va el pasajero?"<<endl;
            cout<<" ";
            cin>>NumVuelo;
            cout<<endl;
            Vuelo *vueloToday;
        while(!iteradorenEncuentraVuelos->Vacia()){
            vueloToday = iteradorenEncuentraVuelos->obtenerObj();

            if( contadorNuevo == NumVuelo)
            {
                break;
            }

            if(iteradorenEncuentraVuelos->Vacia() && contadorNuevo != NumVuelo){

                cout<<"NO es Opcion Valida.    ";
                cin.get();
                cout<<endl;
                PAUSA
                return;

                }
            contadorNuevo++;
            }
            vueloToday->agregarPasajero(insertaPasajero(vueloToday->dameCiudadOrigen(),
                                                        vueloToday->dameCiudadDestino()));
            vueloToday->pasaPasajero();
        }else
        {
             cout<<"\n  No hay vuelos."<<endl<<endl;
            cout<<"\n agregue un vuelo primero.";
            cout<<"\n\n";


        }

}

Pasajero* insertaPasajero(string CiuOrigen, string CiuDestino)
{
    string apellidos;
    string nombres;
    int edad;
    int asiento;
    system("cls");
    cout<<endl<<" Inserta Informacion del pasajero "<<endl;
    cout<<"\nIngresa el apellido: ";
    getline(cin,apellidos,'|');
    //cin>>apellido;
    cout<<"\nIngresa el nombre: ";
    getline(cin,nombres,'|');
    //cin>>nombre;
    cout<<"\nIngresa la edad: ";
    cin>>edad;
    cout<<"\nIngresa el asiento: ";
    cin>>asiento;
    auto *pasajero = new Pasajero(apellidos, nombres, edad, asiento, std::move(CiuOrigen), std::move(CiuDestino));
    return pasajero;
}
//saber si los vuelos estan y haci poder ingresar los pasajeros
void vueloAvailable()
{
    //contador de vuelos
    int contVuelos = 1;
    IteradorLista<Vuelo> *iteradorVuelosDisponible = listaVuelos->obtenerIterador();
    Vuelo * vueloNow;
    if(iteradorVuelosDisponible->Vacia())
        {
            cout<<endl<<" No hay vuelos. Ingrese un vuelo"<<endl;
        }
    while(!iteradorVuelosDisponible->Vacia())
        {
            vueloNow = iteradorVuelosDisponible->obtenerObj();
            cout<<"\n("<<contVuelos<<") - "<<vueloNow->dameInform()<<endl;
            contVuelos++;
        }
        cout<<endl<<endl;
}

void agregarVuelo()
{

    char Opc;
    bool bandera = true;
    bool banderaPasajeros = true;
    string ciuOrigen;
    string ciuDestino;
   size_t diaFSalida;
   size_t mesFSalida;
   size_t anioFSalida;
    string fech_Arribo;
    int distVuelo;
    float capCarga;
    int cantPasajeros;
    //system("cls");.
    cout<<endl<<" Ingresa Datos del vuelo";
    cout<<"\nIngresa la ciudad de origen: ";
    //cin>>ciuOrigen;
    getline(cin,ciuOrigen,'|');
    cout<<"\nIngresa la ciudad de destino: ";
   // cin>>ciuDestino;
    getline(cin,ciuDestino,'|');
    cout<<"\nIngresa el dia de salida: ";
    cin>>diaFSalida;
    cout<<"\nIngresa el mes de salida: ";
    cin>>mesFSalida;
    cout<<"\nIngresa el anio de salida: ";
    cin>>anioFSalida;
    cout<<"\nIngresa la fecha de arribo: ";
    cin>>fech_Arribo;
    cout<<"\nIngresa la distancia de vuelo: ";
    cin>>distVuelo;
    cout<<"\nIngresa la capacidad de carga: ";
    cin>>capCarga;
    cout<<"\nIngresa la capacidad de pasajeros: ";
    cin>>cantPasajeros;

     auto *Dentrovuelo = new Vuelo(ciuOrigen, ciuDestino, diaFSalida, mesFSalida, anioFSalida, fech_Arribo,distVuelo, capCarga,
       cantPasajeros, cantPasajeros);
       // Se agrega el vuelo a la lista de vuelos
       listaVuelos->insertarFinal(Dentrovuelo);
    do{
        system("cls");
        cout<<"Quieres Ingresar los Pasajeros?(s-n):  "<<endl;
        cin>>Opc;
        if((Opc == 's') || (Opc == 'S')){
            do{
            Dentrovuelo->agregarPasajero(insertaPasajero(ciuOrigen,ciuDestino));
            Dentrovuelo->pasaPasajero();


            cout<<endl<<"Puedes Seguir Agregando (s-n):  ";
            cin>>Opc;
            if((Opc == 'n') || (Opc == 'N')){
                bandera = false;
            }


        }while(bandera);
        banderaPasajeros=false;

    }else if((Opc == 'n') || (Opc == 'N'))
    {
        banderaPasajeros = false;
    }else
    {
        cout<<"La Opcion no es Valida ";
    }
    }while(banderaPasajeros);
    cout<<"         "<<endl;
    PAUSA
}

void modificarPasajeros()
{
    int contadorNuevo = 1;
    int numPasajero;
    int edad;
    int asiento;
    string nombre;
    string apellido;
    Vuelo* vueloNow;
    vueloNow = imprimirPasajeros();
     if(vueloNow == NULL){
        cout<<"\n      ";
        PAUSA
        return;
    }
    ListaFuncion<Pasajero>* listaNueva;
    IteradorLista<Pasajero> *iteraPasajeros;
    Pasajero *PasajeroNow;
    IteradorLista<Vuelo> *iteradorEncuentraVuelo = listaVuelos->obtenerIterador();
    if(!iteradorEncuentraVuelo->Vacia())
    {
        cout<<"Que Numero de pasajero quieres modificar: ";
        cin>>numPasajero;
        cout<<endl;
        system("cls");
        listaNueva = vueloNow->dameListaPasajeros();
        contadorNuevo = 1;
       iteraPasajeros = listaNueva->obtenerIterador();
        if(listaNueva->listempty())
        {
             cout<<endl<<"No hay pasajeros"<<endl;
            cout<<"\n";
            PAUSA
            return;

        }
        while(!iteradorEncuentraVuelo->Vacia())
        {
            PasajeroNow = iteraPasajeros->obtenerObj();

        if(contadorNuevo == numPasajero)
        {
            break;
        }

        if((iteradorEncuentraVuelo->Vacia()) && (contadorNuevo != numPasajero)){
                cout<<" Esta Vacia o El nuemero de avion Es incorrecto ";
                cout<<"\n   ";PAUSA
                return;
            }
            contadorNuevo++;
        }
        cout<<"\nModificar pasajero "<<endl;
        cout<<"\nIngresa el apellido: ";
        //cin>>apellido;
        getline(cin,apellido,'|');
        cout<<"\nIngresa el nombre: ";
        //cin>>nombre;
        getline(cin,nombre,'|');
        cout<<"\nIngresa la edad: ";
        cin>>edad;
        cout<<"\nIngresa el asiento: ";
        cin>>asiento;
        PasajeroNow->modificarPasajero(apellido,nombre,edad,asiento,vueloNow->dameCiudadOrigen(),vueloNow->dameCiudadDestino());
    }else{
        cout<<endl<<"Primero Introducce un Vuelo."<<endl;
    }
     cout<<"\n       ";
     PAUSA

}

Vuelo *imprimirPasajeros()
{
    int contador = 1;
    int numVuelo;
    Vuelo *vueloNow = nullptr;
    IteradorLista<Vuelo> *iteradorVuelosEncuentra = listaVuelos->obtenerIterador();
    Pasajero *pasajero;
    IteradorLista<Pasajero> *iteradorPasajeros;
    ListaFuncion<Pasajero> *listaTem;
   vueloAvailable();
   if(!iteradorVuelosEncuentra->Vacia()){
        cout<<"\nIngresa el vuelo Numero de vuelo quieras para pasajeros: "<<endl;
        cin>>numVuelo;
        // Itera en mostrar el vuelo
        while(!iteradorVuelosEncuentra->Vacia()){
                vueloNow = iteradorVuelosEncuentra->obtenerObj();
                listaTem = vueloNow->dameListaPasajeros();
                if(contador == numVuelo){
                    break;
                }
                 if((iteradorVuelosEncuentra->Vacia()) && (contador != numVuelo)){
                    cout<<" Error verifique ES invalido";
                    cout<<" ";
                    PAUSA
                    return nullptr;
                }

                listaTem = nullptr;
                contador++;
        }
        iteradorPasajeros = listaTem->obtenerIterador();
        contador = 1;
        if(listaTem->listempty()){
            cout<<"Esta vacio. Ingrese pasajeros"<<endl;
            PAUSA;
            return nullptr;
        }
        // Itera en mostrar el pasajero
        while(!iteradorPasajeros->Vacia()){
            pasajero = iteradorPasajeros->obtenerObj();
            cout<<endl<<"("<<contador<<") -  "<<pasajero->ObtenerInfo()<<endl;
            contador++;
            PAUSA
        }
   }
   return vueloNow;
}

void modificarVuelo()
{
    //varibles que se cambian
    string ciuOrigen;
    string ciuDestino;
   size_t diaFSalida;
   size_t mesFSalida;
   size_t anioFSalida;
    string fechArribo;
    int distVuelo;
    float cantCarga;
    int cantPasajeros;
    //variables de la funcion
    int numVuelo;
    int contador = 1;
    system("cls");
    vueloAvailable();
    Pasajero *pasajero;
    ListaFuncion<Pasajero> *listaTem;
    IteradorLista<Pasajero> *iteradorPasajeros;
    IteradorLista<Vuelo> *iteradorVuelosCambia = listaVuelos->obtenerIterador();
    if(!iteradorVuelosCambia->Vacia()){
        cout<<endl<<"Cual vuelo Vas modificar: ";
        cin>>numVuelo;
        cout<<endl;
        Vuelo *vueloNow;
        while(!iteradorVuelosCambia->Vacia()){
            vueloNow = iteradorVuelosCambia->obtenerObj();
            if(contador == numVuelo){
                break;
            }
            if((iteradorVuelosCambia->Vacia()) && (contador != numVuelo)){
                cout<<" La Opcion que Ha Ingresado No es valida";
                cout<<"\n ";
                PAUSA
                return;
            }
            contador++;


        }
        system("cls");
        cout<<endl<<"  Modifica un vuelo "<<endl;
        cout<<"\nIngresa la ciudad de origen: ";
       // cin>>ciuOrigen;
        getline(cin,ciuOrigen,'|');
        cout<<"\nIngresa la ciudad de destino: ";
        //cin>>ciuDestino;
        getline(cin,ciuDestino,'|');
        cout<<"\nIngresa el dia de salida: ";
        cin>>diaFSalida;
        cout<<"\nIngresa el mes de salida: ";
        cin>>mesFSalida;
        cout<<"\nIngresa el anio de salida: ";
        cin>>anioFSalida;
        cout<<"\nIngresa la fecha de arribo: ";
        cin>>fechArribo;
        cout<<"\nIngresa la distancia de vuelo: ";
        cin>>distVuelo;
        cout<<"\nIngresa la capacidad de carga: ";
        cin>>cantCarga;
        cout<<"\nIngresa la capacidad de pasajeros: ";
        cin>>cantPasajeros;
        vueloNow->modificaVuelo(ciuOrigen, ciuDestino,diaFSalida,mesFSalida,anioFSalida, fechArribo, distVuelo, cantCarga, cantPasajeros,vueloNow->dameAsientosDisponibles());
        listaTem = vueloNow->dameListaPasajeros();
        cantPasajeros -= listaTem->tamanio();
        vueloNow->fijaAsientosDisponibles(cantPasajeros);
        iteradorPasajeros = listaTem->obtenerIterador();
         while(!iteradorPasajeros->Vacia()){ // Mientras que no esté vacía la lista
            pasajero = iteradorPasajeros->obtenerObj(); // Avanza el iterador al obtener el siguiente objeto
            pasajero->modificaCiudad(ciuOrigen, ciuDestino);
        }


    }
}
void mostrarVuelos()
{

    char opc;
    size_t cont = 0;
    size_t contPasa = 0;
    IteradorLista<Vuelo> *iteradorVuelos = listaVuelos->obtenerIterador();
    ListaFuncion<Pasajero> *lisTem;
    IteradorLista<Pasajero> *iteradorPasajeros;
    Pasajero *pasajero;
    Vuelo *vueloNow;
    system("cls");
    if(iteradorVuelos->Vacia()){
        cout<<"\nNo hay vuelos."<<endl;
        PAUSA
        return;
    }
    //mostrar los vuelos
    while(!iteradorVuelos->Vacia()){
        vueloNow = iteradorVuelos->obtenerObj();
        lisTem = vueloNow->dameListaPasajeros();
        cout<<" "<<vueloNow->dameInform()<<endl;
        cout<<"Quieres ver los pasajeros del vuelo(s-n): ";
        cin>>opc;
        if(opc == 's' || opc == 'S'){
            system("cls");
            cont++;
                cout<<endl<<"informacion del vuelo "<<endl;
                cout<<"----------------------------------";
                cout<<endl<<"("<<cont<<")"<<vueloNow->dameInform();
                cout<<"\n\n\n";
                iteradorPasajeros = lisTem->obtenerIterador();
                if(lisTem->listempty())
                    {
                    cout<<endl<<"No hay pasajeros "<<endl;
                    PAUSA
                    return;
                    }
                    //mostrando los pasajeros con el while
                while(!iteradorPasajeros->Vacia()){ // Mientras que no esté vacía la lista
                pasajero = iteradorPasajeros->obtenerObj();   // Avanza el iterador al obtener el siguiente objeto
                contPasa++;
                cout<<"("<<contPasa<<")"<<"***********pasajeros***************"<<endl;
                cout<<pasajero->ObtenerInfo()<<endl;
                }
                cout<<"**************terminan pasajeros de este vuelo****************"<<endl;
                cout<<endl;

                cout<<"\nSIGUIENTE VUELO"<<endl;


        }else if(opc == 'n' || opc == 'N')
        {

        }else
        {
            cout<<"Opcion Es Invalida";
            iteradorVuelos = listaVuelos->obtenerIterador();

        }

    }
    PAUSA

}

void ordenarVuelos()
{
    listaVuelos->arregloOrdenamiento();
     cout<<"Ya Esta Ordenado por Asientos ......";
}

void ordVueloFech()
{
        listaVuelos->arrOrdenFech();
     cout<<"Ya Esta Ordenado por Fecha ......";

}
