#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool validarLinea(string linea, string equipos[], int equiposLongitud)
{
    for (int i = 0; i < equiposLongitud; i++)
    {
        string equipo = equipos[i];
        if (linea.substr(0, equipo.length()) == equipo && linea[equipo.length()] != '-')
        {
            return true;
        }
    }
    return false;
}

void procesarPartido(string entrada, string lineas[], int &cantidadLineas, string equipos[], int equiposLongitud)
{
    ifstream archivoEntrada;
    archivoEntrada.open(entrada);
    string linea;
    while (getline(archivoEntrada, linea))
    {
        if (validarLinea(linea, equipos, equiposLongitud))
        {
            lineas[cantidadLineas++] = linea;
        };
    }
    archivoEntrada.close();
}

string identificarActuaciones(string linea, string equipos[], int equiposLongitud, string &equipoJugador, string &nombreJugador, string &apellidoJugador)
{
    equipoJugador = "";
    nombreJugador = "";
    apellidoJugador = "";
    for (int i = 0; i < equiposLongitud; i++)
    {
        string equipo = equipos[i];
        if (linea.find(equipo) != string::npos)
        {
            equipoJugador = equipo;
            linea.erase(linea.find(equipo), equipo.length() + 1);
        }
    }

    int addJugador = 1;

    for (char caracter : linea)
    {
        if (caracter == ' ')
        {
            addJugador++;
            continue;
        }
        if (addJugador == 1)
        {
            nombreJugador += caracter;
        }
        else if (addJugador == 2)
        {
            apellidoJugador += caracter;
        }
        else if (addJugador == 3)
        {
            break;
        }
    }
    linea.erase(linea.find(nombreJugador), nombreJugador.length() + 1);
    linea.erase(linea.find(apellidoJugador), apellidoJugador.length() + 1);
    return linea;
}

int calcularExperiencia(string linea)
{
    string palabraBuscar;
    string actuaciones[16] = {
        "Tiro al arco",
        "Entrada eficaz",
        "Saludo al publico",
        "Gol",
        "Pase",
        "Atajada",
        "Centro eficaz",
        "Regate",
        "Tiro a las gradas",
        "Entrada a destiempo",
        "Insulto al arbitro",
        "Falta",
        "Tarjeta",
        "Mal despeje",
        "Mano al balon",
        "Cansancio",
    };
    int contador = 0;
    for (int h = 0; h < 16; h++)
    {
        palabraBuscar = actuaciones[h];
        for (int i = 0; i < linea.length(); i++)
        {
            int j = 0;
            while (j < palabraBuscar.length() && i + j < linea.length() && linea[i + j] == palabraBuscar[j])
            {
                j++;
            }
            if (j == palabraBuscar.length() && (i + j == linea.length() || linea[i + j] == ' '))
            {
                if (h < 8)
                    contador++;
                else
                    contador--;
            }
        }
    }
    return contador;
}

int main()
{
    string equipos[10] = {"Caracas FC", "Manchester City", "Inter Miami", "Al Nassr"};
    int equiposLongitud = 4;
    // procesarPartidos("jornada1.in");
    string lineas[100];
    int cantidadLineas = 0;
    string equipoJugador, nombreJugador, apellidoJugador;
    procesarPartido("jornada2.in", lineas, cantidadLineas, equipos, equiposLongitud);
    for (int i = 0; i < cantidadLineas; i++)
    {
        cout << lineas[i] << endl;
        cout << identificarActuaciones(lineas[i], equipos, equiposLongitud, equipoJugador, nombreJugador, apellidoJugador) << endl;
        cout << calcularExperiencia(identificarActuaciones(lineas[i], equipos, equiposLongitud, equipoJugador, nombreJugador, apellidoJugador)) << endl;
        equipos[equipos->buscarEquipo(equipos, equiposLongitud, equipoJugador)].jugadores[equipos[equipos->buscarEquipo(equipos, equiposLongitud, equipoJugador)].buscarJugador(nombreJugador, apellidoJugador)].experiencia += equipos[equipos->buscarEquipo(equipos, equiposLongitud, equipoJugador)].jugadores[equipos[equipos->buscarEquipo(equipos, equiposLongitud, equipoJugador)].buscarJugador(nombreJugador, apellidoJugador)].experiencia + calcularExperiencia(identificarActuaciones(lineas[i], equipos, equiposLongitud, equipoJugador, nombreJugador, apellidoJugador));
    }
}