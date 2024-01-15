#include <iostream>
#include <fstream>
using namespace std;

void procesarEntrada(string entrada, string equipos[], int &equiposLongitud, string jugadores[], int &jugadoresLongitud, string directores[], int &directoresLongitud)
{
    ifstream archivoEntrada;
    archivoEntrada.open(entrada);
    string linea, add;
    while (getline(archivoEntrada, linea))
    {
        if (linea == "E")
        {
            add = "equipo";
            continue;
        }
        else if (linea == "J")
        {
            add = "jugador";
            continue;
        }
        else if (linea == "D")
        {
            add = "directorTecnico";
            continue;
        }
        if (add == "equipo")
        {
            equipos[equiposLongitud++] = linea;
        }
        if (add == "jugador")
        {
            jugadores[jugadoresLongitud++] = linea;
        }
        if (add == "directorTecnico")
        {
            directores[directoresLongitud++] = linea;
        }
    }
};

int main()
{
    string equipoJugador;
    string nombreJugador;
    string apellidoJugador;
    string posicionJugador;
    string experienciaJugador;
    string jugador = "Caracas FC Alain Baroja Portero 70";

    string equiposPrueba[4] = {"Caracas FC", "Manchester City", "Inter Miami", "Al Nassr"};
    string posicionesPrueba[5] = {"Portero", "Defensa", "Mediocampista", "Delantero", "Goleador"};

    for (string equipo : equiposPrueba)
    {
        if (jugador.find(equipo) != string::npos)
        {
            equipoJugador = equipo;
            jugador.erase(jugador.find(equipo), equipo.length() + 1);
        }
    }

    for (string posicion : posicionesPrueba)
    {
        if (jugador.find(posicion) != string::npos)
        {
            posicionJugador = posicion;
            jugador.erase(jugador.find(posicion), posicion.length() + 1);
        }
    }

    experienciaJugador = jugador.substr(jugador.length() - 2);
    jugador.erase(jugador.length() - 3);
    cout << "Nombre Jugador: " << jugador << endl;
    cout << "Equipo Jugador: " << equipoJugador<< endl;
    cout << "Posicion Jugador: " << posicionJugador<< endl;
    cout << "Experiencia Jugador: " << experienciaJugador<< endl;

    // ofstream archivoSalida;
    // archivoSalida.open("entrada.in");

    // for (int i = 0; i<10;i++){
    //     archivoSalida << i << endl;
    // }

    // archivoSalida.close();

    string equipos[20];
    string jugadores[200];
    string directores[30];
    int equiposLongitud = 0, jugadoresLongitud = 0, directoresLongitud = 0;
    procesarEntrada("entrada.in", equipos, equiposLongitud, jugadores, jugadoresLongitud, directores, directoresLongitud);

    cout << "EQUIPOS" << endl;

    for (int i = 0; i < equiposLongitud; i++)
    {
        cout << equipos[i] << endl;
    }

    cout << "\nJUGADORES" << endl;

    for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << jugadores[i] << endl;
    }

    cout << "\nDIRECTORES TÉCNICOS" << endl;

    for (int i = 0; i < directoresLongitud; i++)
    {
        cout << directores[i] << endl;
    }

    return 0;
}