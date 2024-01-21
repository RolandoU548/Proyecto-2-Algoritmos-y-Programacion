#include <iostream>
#include <fstream>
using namespace std;

// Clase Jugador
class Jugador
{
public:
    string equipo;
    string nombre;
    string apellido;
    string posicion;
    int experiencia;
    int goles;
    string estado;
    Jugador(string, string, string, string, int, int, string);
    Jugador() = default;
    friend ostream &operator<<(ostream &os, const Jugador &obj)
    {
        os << "Jugador| Equipo: " << obj.equipo << ", Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Posición: " << obj.posicion << ", Experiencia: " << obj.experiencia << ", Goles: " << obj.goles << ", Estado: " << obj.estado;
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

// Clase Director Tecnico
class DirectorTecnico
{
public:
    DirectorTecnico(string, string, int);
    DirectorTecnico() = default;
    string nombre;
    string apellido;
    int experiencia;
    friend ostream &operator<<(ostream &os, const DirectorTecnico &obj)
    {
        os << "Director Técnico| Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Experiencia: " << obj.experiencia;
        return os;
    }
};

DirectorTecnico::DirectorTecnico(string _nombre, string _apellido, int _experiencia)
{
    nombre = _nombre;
    apellido = _apellido;
    experiencia = _experiencia;
};

class Equipo {
public:
    Equipo(string, Jugador[], int);
    Equipo() = default;
    string nombre;
    Jugador jugadores[20];
};

Equipo::Equipo(string _nombre, Jugador _jugadores[], int n) {
    nombre = _nombre;
    for (int i = 0; i < n; i++) {
        jugadores[i] = _jugadores[i];
    }
}

// Procesar archivo entrada.in
void procesarEntrada(string entrada, string equiposPrev[], int &equiposPrevLongitud, string jugadoresPrev[], int &jugadoresPrevLongitud, string directoresPrev[], int &directoresPrevLongitud)
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
            equiposPrev[equiposPrevLongitud++] = linea;
        }
        if (add == "jugador")
        {
            jugadoresPrev[jugadoresPrevLongitud++] = linea;
        }
        if (add == "directorTecnico")
        {
            directoresPrev[directoresPrevLongitud++] = linea;
        }
    }
};

// Procesar Datos de Línea de Jugadores Y Añadirlos a su Equipo
void identificarJugador(string jugador, string equiposPrev[], int equiposPrevLongitud, string &equipoJugador, string &nombreJugador, string &apellidoJugador, string &posicionJugador, string &experienciaJugador)
{
    for (int i = 0; i < equiposPrevLongitud; i++)
    {
        string equipo = equiposPrev[i];
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
        else if (addJugador == 3)
        {
            posicionJugador += caracter;
        }
        else if (addJugador == 4)
        {
            experienciaJugador += caracter;
        }
    }
}

// Procesar Datos de Línea de Directores Tecnicos
void identificarDirectorTecnico(string directorTecnico, string &nombreDirectorTecnico, string &apellidoDirectorTecnico, string &experienciaDirectorTecnico)
{
    int addDirectorTecnico = 1;

    for (char caracter : directorTecnico)
    {
        if (caracter == ' ')
        {
            addDirectorTecnico++;
            continue;
        }
        if (addDirectorTecnico == 1)
        {
            nombreDirectorTecnico += caracter;
        }
        else if (addDirectorTecnico == 2)
        {
            apellidoDirectorTecnico += caracter;
        }
        else if (addDirectorTecnico == 3)
        {
            experienciaDirectorTecnico += caracter;
        }
    }
}
 
int main()
{
    // Jugador *jugadoresEjemplo = new Jugador[5];
    // Jugador jugadoresEjemplo[5];
    // Equipo equipoEjemplo("Equipo 1", jugadoresEjemplo, 5);
    string equiposPrev[20];
    string jugadoresPrev[100];
    string directoresPrev[30];
    int equiposPrevLongitud = 0, jugadoresPrevLongitud = 0, directoresPrevLongitud = 0;
    procesarEntrada("entrada.in", equiposPrev, equiposPrevLongitud, jugadoresPrev, jugadoresPrevLongitud, directoresPrev, directoresPrevLongitud);
    string equipoJugador, nombreJugador, apellidoJugador, posicionJugador, experienciaJugador, nombreDirectorTecnico, apellidoDirectorTecnico, experienciaDirectorTecnico;
    equipoJugador = nombreJugador = apellidoJugador = posicionJugador = experienciaJugador = nombreDirectorTecnico = apellidoDirectorTecnico = experienciaDirectorTecnico = "";

    // Crear lista de objetos de jugadores
    Jugador *jugadores = new Jugador[100];
    
    int jugadoresLongitud = 0;
    for (int i = 0; i < jugadoresPrevLongitud; i++)
    {
        identificarJugador(jugadoresPrev[i], equiposPrev, equiposPrevLongitud, equipoJugador, nombreJugador, apellidoJugador, posicionJugador, experienciaJugador);
        Jugador jugador = Jugador(equipoJugador, nombreJugador, apellidoJugador, posicionJugador, stoi(experienciaJugador), 0, "Incorporado");
        jugadores[i] = jugador;
        jugadoresLongitud++;
        equipoJugador = nombreJugador = apellidoJugador = posicionJugador = experienciaJugador = "";
    }

    // Crear lista de objetos de equipos
    Equipo *equipos = new Equipo[20];

    // Crear lista de objetos de Directores Tecnicos
    DirectorTecnico *directores = new DirectorTecnico[30];
    int directoresLongitud = 0;
    for (int i = 0; i < directoresPrevLongitud; i++)
    {
        identificarDirectorTecnico(directoresPrev[i], nombreDirectorTecnico, apellidoDirectorTecnico, experienciaDirectorTecnico);
        DirectorTecnico director = DirectorTecnico(nombreDirectorTecnico, apellidoDirectorTecnico, stoi(experienciaDirectorTecnico));
        directores[i] = director;
        directoresLongitud++;
        nombreDirectorTecnico = apellidoDirectorTecnico = experienciaDirectorTecnico = "";
    }

// Imprimir Equipos
    cout << "EQUIPOS" << endl;

    for (int i = 0; i < equiposPrevLongitud; i++)
    {
        cout << equiposPrev[i] << endl;
    }

// Imprimir Jugadores
    cout << "\nJUGADORES" << endl;

    for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << jugadores[i] << endl;
    }

// Imprimir Directores Tecnicos
    cout << "\nDIRECTORES TÉCNICOS" << endl;

    for (int i = 0; i < directoresLongitud; i++)
    {
        cout << directores[i] << endl;
    }

    return 0;
}