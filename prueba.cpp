#include <iostream>
#include <fstream>
using namespace std;

class Jugador
{
private:
    string equipo;
    string nombre;
    string apellido;
    string posicion;
    int experiencia;
    int goles;
    string estado;

public:
    Jugador(string, string, string, string, int, int, string);
    Jugador() = default;
    string getEquipo();
    string getNombre();
    string getApellido();
    string getPosicion();
    int getExperiencia();
    int getGoles();
    string getEstado();
    void setEquipo(string);
    void setNombre(string);
    void setApellido(string);
    void setPosicion(string);
    void setExperiencia(int);
    void setGoles(int);
    void setEstado(string);
    friend ostream &operator<<(ostream &os, const Jugador &obj)
    {
        os << "Jugador| Equipo: " << obj.equipo << ", Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Posición: " << obj.posicion << ", Experiencia: " << obj.experiencia << ", Goles: " << obj.goles << ", Estado: " << obj.estado << endl;
        return os;
    }
};

Jugador::Jugador(string _equipo, string _nombre, string _apellido, string _posicion, int _experiencia, int _goles, string _estado)
{
    equipo = _equipo;
    nombre = _nombre;
    apellido = _apellido;
    posicion = _posicion;
    experiencia = _experiencia;
    goles = _goles;
    estado = _estado;
};

string Jugador::getEquipo()
{
    return equipo;
}

string Jugador::getNombre()
{
    return nombre;
}

string Jugador::getApellido()
{
    return apellido;
}

string Jugador::getPosicion()
{
    return posicion;
}

int Jugador::getExperiencia()
{
    return experiencia;
}

int Jugador::getGoles()
{
    return goles;
}

string Jugador::getEstado()
{
    return estado;
}

void Jugador::setEquipo(string _equipo)
{
    equipo = _equipo;
}

void Jugador::setNombre(string _nombre)
{
    nombre = _nombre;
}

void Jugador::setApellido(string _apellido)
{
    apellido = _apellido;
}

void Jugador::setPosicion(string _posicion)
{
    posicion = _posicion;
}

void Jugador::setExperiencia(int _experiencia)
{
    experiencia = _experiencia;
}

void Jugador::setGoles(int _goles)
{
    goles = _goles;
}

void Jugador::setEstado(string _estado)
{
    estado = _estado;
}

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

void identificarJugador(string jugador, string equipos[], int equiposLongitud, string &equipoJugador, string &nombreJugador, string &apellidoJugador, string &posicionJugador, string &experienciaJugador)
{
    for (int i = 0; i < equiposLongitud; i++)
    {
        string equipo = equipos[i];
        if (jugador.find(equipo) != string::npos)
        {
            equipoJugador = equipo;
            jugador.erase(jugador.find(equipo), equipo.length() + 1);
        }
    }

    int addJugador = 1;

    for (char caracter : jugador)
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
        if (addJugador == 3)
        {
            posicionJugador += caracter;
        }
        if (addJugador == 4)
        {
            experienciaJugador += caracter;
        }
    }
}

int main()
{
    string equipos[20];
    string jugadores[200];
    string directores[30];
    int equiposLongitud = 0, jugadoresLongitud = 0, directoresLongitud = 0;
    procesarEntrada("entrada.in", equipos, equiposLongitud, jugadores, jugadoresLongitud, directores, directoresLongitud);
    string equipoJugador = "";
    string nombreJugador = "";
    string apellidoJugador = "";
    string posicionJugador = "";
    string experienciaJugador = "";

    for (int i = 0; i < jugadoresLongitud; i++)
    {
        identificarJugador(jugadores[i], equipos, equiposLongitud, equipoJugador, nombreJugador, apellidoJugador, posicionJugador, experienciaJugador);
        Jugador jugador = Jugador(equipoJugador, nombreJugador, apellidoJugador, posicionJugador, stoi(experienciaJugador), 0, "Incorporado");
        cout << jugador << endl;
        equipoJugador = "";
        nombreJugador = "";
        apellidoJugador = "";
        posicionJugador = "";
        experienciaJugador = "";
    }

    // cout << "EQUIPOS" << endl;

    // for (int i = 0; i < equiposLongitud; i++)
    // {
    //     cout << equipos[i] << endl;
    // }

    // cout << "\nJUGADORES" << endl;

    // for (int i = 0; i < jugadoresLongitud; i++)
    // {
    //     cout << jugadores[i] << endl;
    // }

    // cout << "\nDIRECTORES TÉCNICOS" << endl;

    // for (int i = 0; i < directoresLongitud; i++)
    // {
    //     cout << directores[i] << endl;
    // }

    return 0;
}