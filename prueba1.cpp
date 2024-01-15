#include <iostream>
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

void Jugador::setEquipo(string _equipo){
    equipo = _equipo;
}

void Jugador::setNombre(string _nombre){
    nombre = _nombre;
}

void Jugador::setApellido(string _apellido){
    apellido = _apellido;
}

void Jugador::setPosicion(string _posicion){
    posicion = _posicion;
}

void Jugador::setExperiencia(int _experiencia){
    experiencia = _experiencia;
}

void Jugador::setGoles(int _goles){
    goles = _goles;
}

void Jugador::setEstado(string _estado){
    estado = _estado;
}

class DirectorTecnico
{
public:
    DirectorTecnico(string, string, int);
    string nombre;
    string apellido;
    int experiencia;
    friend ostream &operator<<(ostream &os, const DirectorTecnico &obj)
    {
        os << "Director Técnico| Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Experiencia: " << obj.experiencia << endl;
        return os;
    }
};

DirectorTecnico::DirectorTecnico(string _nombre, string _apellido, int _experiencia)
{
    nombre = _nombre;
    apellido = _apellido;
    experiencia = _experiencia;
};

int main()
{
    Jugador j1 = Jugador("Los Chutadores Entusiastas", "Pepito", "Hernandez", "Mediocampista", 54, 34, "Lesionado");
    // cout << j1;
    // Jugador j2 = Jugador("Los Penaltis Rumberos", "Juan", "Amezquita", "Portero", 77, 27, "Incorporado");
    // cout << j2;
    // DirectorTecnico dt1 = DirectorTecnico("Lionel ", "Scaloni ", 7);
    // cout << dt1;
    Jugador *jugadores = new Jugador[5];
    jugadores[0] = j1;
    for (int i = 0; i < 5; i++)
    {
        cout << jugadores[i];
    }
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0;
    int opcion4 = 0;

    while (opcion1 != 5)
    {
        cout << "MENÚ PRINCIPAL" << endl;
        cout << "1. Equipos" << endl;
        cout << "2. Jugadores" << endl;
        cout << "3. Directores Técnicos" << endl;
        cout << "4. Partidos" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion1;

        switch (opcion1)
        {
        case 1: // Equipos
            while (opcion2 != 5)
            {
                cout << "\nSUBMENÚ - Equipos" << endl;
                cout << "1. Agregar" << endl;
                cout << "2. Modificar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Listar Todos" << endl;
                cout << "5. Volver al menú principal" << endl;
                cout << "Elige una opción: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    // Código para Agregar
                    break;
                case 2:
                    // Código para Modificar
                    break;
                case 3:
                    // Código para Eliminar
                    break;
                case 4:
                    // Código para la Listar Todos
                    while (opcion3 != 5)
                    {
                        cout << "\nSUBSUBMENÚ - Listar Todos" << endl;
                        cout << "1. Jugadores" << endl;
                        cout << "2. Mejores Jugadores" << endl;
                        cout << "3. Lesionados" << endl;
                        cout << "4. Los Nuevos" << endl;
                        cout << "5. Volver al submenú Equipos" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Ver Jugadores
                            while (opcion4 != 5)
                            {
                                cout << "\nSUBSUBSUBMENÚ - Jugadores" << endl;
                                cout << "1. Todos" << endl;
                                cout << "2. Agregar" << endl;
                                cout << "3. Modificar" << endl;
                                cout << "4. Eliminar" << endl;
                                cout << "5. Volver al subsubmenú Listar Todos" << endl;
                                cout << "Elige una opción: ";
                                cin >> opcion4;

                                switch (opcion4)
                                {
                                case 1:
                                    // Código para Ver Todos
                                    break;
                                case 2:
                                    // Código para Agregar
                                    break;
                                case 3:
                                    // Código para Modificar
                                    break;
                                case 4:
                                    // Código para Eliminar
                                    break;
                                case 5:
                                    // Regresar al subsubmenú Listar Todos
                                    cout << endl;
                                    break;
                                default:
                                    cout << "\nOpción inválida." << endl;
                                    break;
                                }
                            }
                            break;
                        case 2:
                            // Código para Ver Mejores Jugadores
                            break;
                        case 3:
                            // Código para Ver Lesionados
                            break;
                        case 4:
                            // Código para Ver Los Nuevos
                            break;
                        case 5:
                            // Regresar al submenú Equipos
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                        opcion4 = 0;
                    }
                    break;
                case 5:
                    // Regresar al menú principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpción inválida." << endl;
                    break;
                }
                opcion3 = 0; // Reiniciar la opción del subsubmenú
            }
            break;
        case 2: // Jugadores
            while (opcion2 != 6)
            {
                cout << "\nSUBMENU - Jugadores" << endl;
                cout << "1. Porteros" << endl;
                cout << "2. Defensas" << endl;
                cout << "3. Mediocampistas" << endl;
                cout << "4. Delanteros" << endl;
                cout << "5. Goleadores" << endl;
                cout << "6. Volver al menú principal" << endl;
                cout << "Elige una opción: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    // Código para Mostrar Porteros
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Porteros" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenú Jugadores" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Mostrar Todos los Porteros
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Porteros
                            break;
                        case 3:
                            // Regresar al submenú Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                    }
                    break;
                case 2:
                    // Código para Mostrar Defensas
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Defensas" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenú Jugadores" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Mostrar Todos los Defensas
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Defensas
                            break;
                        case 3:
                            // Regresar al submenú Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                    }
                    break;
                case 3:
                    // Código para Mostrar Mediocampistas
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Mediocampistas" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenú Jugadores" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Mostrar Todos los Mediocampistas
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Mediocampistas
                            break;
                        case 3:
                            // Regresar al submenú Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                    }
                    break;
                case 4:
                    // Código para la Mostrar Delanteros
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Delanteros" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenú Jugadores" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Mostrar Todos los Delanteros
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Delanteros
                            break;
                        case 3:
                            // Regresar al submenú Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                    }
                    break;
                case 5:
                    // Código para la Mostrar Goleadores
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Goleadores" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenú Jugadores" << endl;
                        cout << "Elige una opción: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Código para Mostrar Todos los Goleadores
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Goleadores
                            break;
                        case 3:
                            // Regresar al submenú Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpción inválida." << endl;
                            break;
                        }
                    }
                    break;
                case 6:
                    // Regresar al menú principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpción inválida." << endl;
                    break;
                }
                opcion3 = 0; // Reiniciar la opción del subsubmenú
            }
            break;
        case 3: // Directores Tecnicos
            while (opcion2 != 6)
            {
                cout << "\nSUBMENU - Directores Técnicos" << endl;
                cout << "1. Todos" << endl;
                cout << "2. Los más experimentados" << endl;
                cout << "3. Agregar" << endl;
                cout << "4. Modificar" << endl;
                cout << "5. Eliminar" << endl;
                cout << "6. Volver al menú principal" << endl;
                cout << "Elige una opción: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    // Código para Mostrar Todos
                    break;
                case 2:
                    // Código para Mostrar Los mas experimentados
                    break;
                case 3:
                    // Código para Agregar
                    break;
                case 4:
                    // Código para Modificar
                    break;
                case 5:
                    // Código para Eliminar
                    break;
                case 6:
                    // Regresar al menú principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpción inválida." << endl;
                    break;
                }
            }
            break;
        case 4: // Partidos
            while (opcion2 != 2)
            {
                cout << "\nSUBMENU - Partidos" << endl;
                cout << "1. Cargar Partidos" << endl;
                cout << "2. Volver al menú principal" << endl;
                cout << "Elige una opción: ";
                cin >> opcion2;

                switch (opcion2)
                {
                case 1:
                    // Código para Cargar Partidos
                    break;
                case 2:
                    // Regresar al menú principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpción inválida." << endl;
                    break;
                }
            }
            break;
        case 5: // Salir
            cout << "Saliendo del programa. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
            break;
        }
        opcion2 = 0; // Reiniciar la opción del submenú
    }
    return 0;
}