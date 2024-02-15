#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void quickSort(int array[], int inicio, int fin)
{
    int izq, der, piv, aux;
    izq = inicio;
    der = fin;
    piv = array[(izq + der) / 2];

    do
    {
        while (array[izq] < piv && izq < fin)
        {
            izq++;
        }
        while (array[der] > piv && der > inicio)
        {
            der--;
        }
        if (izq <= der)
        {
            aux = array[izq];
            array[izq] = array[der];
            array[der] = aux;
            izq++;
            der--;
        }
    } while (izq <= der);

    if (inicio <= der)
    {
        quickSort(array, inicio, der);
    }

    if (fin > izq)
    {
        quickSort(array, izq, fin);
    }
}

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
    string estado = "Incorporado";
    Jugador(string _equipo, string _nombre, string _apellido, string _posicion, int _experiencia, int _goles, string _estado = "Incorporado")
    {
<<<<<<< HEAD
        os << "Jugador| Equipo: " << obj.equipo << ", Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Posicion: " << obj.posicion << ", Experiencia: " << obj.experiencia << ", Goles: " << obj.goles << ", Estado: " << obj.estado;
        return os;
=======
        equipo = _equipo;
        nombre = _nombre;
        apellido = _apellido;
        posicion = _posicion;
        experiencia = _experiencia;
        goles = _goles;
        estado = _estado;
    };
    Jugador() = default;
    string mostrarDatos()
    {
        return equipo + " " + nombre + " " + apellido + " " + posicion + " " + to_string(experiencia);
>>>>>>> baeb878e94d2452dccc3729f7461de8aeb1d4530
    }
};

// Clase Director Tecnico
class DirectorTecnico
{
public:
    DirectorTecnico(string _nombre, string _apellido, int _experiencia)
    {
        nombre = _nombre;
        apellido = _apellido;
        experiencia = _experiencia;
    };
    DirectorTecnico() = default;
    string mostrarDatos()
    {
        return nombre + " " + apellido + " " + to_string(experiencia);
    }
    string nombre;
    string apellido;
    int experiencia;
<<<<<<< HEAD
    friend ostream &operator<<(ostream &os, const DirectorTecnico &obj)
    {
        os << "Director Tecnico| Nombre: " << obj.nombre << ", Apellido: " << obj.apellido << ", Experiencia: " << obj.experiencia;
        return os;
    }
};

DirectorTecnico::DirectorTecnico(string _nombre, string _apellido, int _experiencia)
{
    nombre = _nombre;
    apellido = _apellido;
    experiencia = _experiencia;
=======
>>>>>>> baeb878e94d2452dccc3729f7461de8aeb1d4530
};

// Clase Equipo
class Equipo
{
public:
    Equipo(string _nombre, Jugador _jugadores[], int _cantidadJugadores)
    {
        nombre = _nombre;
        cantidadJugadores = _cantidadJugadores;
        for (int i = 0; i < _cantidadJugadores; i++)
        {
            jugadores[i] = _jugadores[i];
            if (_jugadores[i].posicion == "Portero")
            {
                porteros[cantidadPorteros++] = _jugadores[i];
            }
            else if (_jugadores[i].posicion == "Delantero")
            {
                delanteros[cantidadDelanteros++] = _jugadores[i];
            }
            else if (_jugadores[i].posicion == "Defensa")
            {
                defensas[cantidadDefensas++] = _jugadores[i];
            }
        }
    };
    void ordernarPorExperiencia(int inicio, int fin)
    {
        int izq, der, piv, aux;
        izq = inicio;
        der = fin;
        piv = jugadores[(izq + der) / 2].experiencia;

        do
        {
            while (jugadores[izq].experiencia > piv && izq < fin)
            {
                izq++;
            }
            while (jugadores[der].experiencia < piv && der > inicio)
            {
                der--;
            }
            if (izq <= der)
            {
                aux = jugadores[izq].experiencia;
                jugadores[izq].experiencia = jugadores[der].experiencia;
                jugadores[der].experiencia = aux;
                izq++;
                der--;
            }
        } while (izq <= der);

        if (inicio <= der)
        {
            ordernarPorExperiencia(inicio, der);
        }

        if (fin > izq)
        {
            ordernarPorExperiencia(izq, fin);
        }
    }
    Equipo() = default;
    string nombre;
    Jugador jugadores[21];
    Jugador porteros[7];
    Jugador delanteros[7];
    Jugador defensas[7];
    int cantidadJugadores = 0;
    int cantidadPorteros = 0;
    int cantidadDelanteros = 0;
    int cantidadDefensas = 0;
    string mostrarDatos()
    {
        return nombre + " " + to_string(cantidadJugadores);
    }
    void mostrarJugadores()
    {
        for (int i = 0; i < cantidadJugadores; i++)
        {
            cout << jugadores[i].mostrarDatos() << endl;
        }
    };
    void mostrarLesionados()
    {
        for (int i = 0; i < cantidadJugadores; i++)
        {
            if (jugadores[i].estado == "Lesionado")
            {
                cout << jugadores[i].mostrarDatos() << endl;
            }
        }
    };
};

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

// Actualizar datos de salida entrada.in
void guardarDatosEnArchivo(string archivo, Equipo equipos[], int equiposLongitud, Jugador jugadores[], int jugadoresLongitud, DirectorTecnico directores[], int directoresLongitud)
{
    ofstream archivoSalida;
    archivoSalida.open(archivo);

    archivoSalida << "E" << endl;
    for (int i = 0; i < equiposLongitud; i++)
    {
        archivoSalida << equipos[i].nombre << endl;
    }

    archivoSalida << "J" << endl;
    for (int i = 0; i < jugadoresLongitud; i++)
    {
        archivoSalida << jugadores[i].equipo << " " << jugadores[i].nombre << " " << jugadores[i].apellido << " " << jugadores[i].posicion << " " << jugadores[i].experiencia << endl;
    }
    
    archivoSalida << "D" << endl;
    for (int i = 0; i < directoresLongitud; i++)
    {
        archivoSalida << directores[i].nombre << " " << directores[i].apellido << " " << directores[i].experiencia << endl;
    }
}

// Mostrar lista de Equipos
void listarEquipos(Equipo equipos[], int equiposLongitud)
{
    for (int i = 0; i < equiposLongitud; i++)
    {
        cout << equipos[i].nombre << endl;
    }
}

// Mostrar lista de Jugadores
void listarJugadores(string posicion, Jugador jugadores[], int jugadoresLongitud, bool mejores)
{
    if (mejores)
    {
        if (posicion == "")
        {
            //funcion ordenar segun goles
        }
        else
        {
            //funcion ordenar segun experiencia
        }
    }
    for (int i = 0; i < jugadoresLongitud; i++)
    {
        //Goleadores
        if (posicion == "")
        {
            if (jugadores[i].goles > 0)
            {
                cout << jugadores[i].equipo << " " << jugadores[i].nombre << " " << jugadores[i].apellido << " " << jugadores[i].posicion << " " << jugadores[i].experiencia << " " << jugadores[i].goles;
                if (jugadores[i].goles == 1)
                    cout << " Gol";
                else
                    cout << " Goles";
            }
        }
        //Posicion
        if (posicion == jugadores[i].posicion)
            cout << jugadores[i].equipo << " " << jugadores[i].nombre << " " << jugadores[i].apellido << " " << jugadores[i].posicion << " " << jugadores[i].experiencia << endl;
    }
    
}

// Mostrar lista de Directores
void listarDirectores(DirectorTecnico directores[], int directoresLongitud, bool experimentados)
{
    if (experimentados)
    {
        //funcion ordenar
    }
    for (int i = 0; i < directoresLongitud; i++)
    {
        cout << directores[i].nombre << " " << directores[i].apellido << " " << directores[i].experiencia << endl;
    }
}

int main()
{
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
        Jugador jugador = Jugador(equipoJugador, nombreJugador, apellidoJugador, posicionJugador, stoi(experienciaJugador), 0);
        jugadores[i] = jugador;
        jugadoresLongitud++;
        equipoJugador = nombreJugador = apellidoJugador = posicionJugador = experienciaJugador = "";
    }

    // Crear lista de objetos de equipos
    Equipo equipos[20];
    int equiposLongitud = equiposPrevLongitud;
    for (int i = 0; i < equiposPrevLongitud; i++)
    {
        string equipo = equiposPrev[i];
        Jugador *jugadoresAux = new Jugador[100];
        int jugadoresPorEquipo = 0, indiceJugador = 0;
        for (int j = 0; j < jugadoresLongitud; j++)
        {
            if (equipo == jugadores[j].equipo)
            {
                jugadoresPorEquipo++;
                jugadoresAux[indiceJugador] = Jugador(jugadores[j].equipo, jugadores[j].nombre, jugadores[j].apellido, jugadores[j].posicion, jugadores[j].experiencia, jugadores[j].goles, jugadores[j].estado);
                indiceJugador++;
            }
        }
        Equipo equipoAux(equipo, jugadoresAux, jugadoresPorEquipo);
        equipos[i] = equipoAux;
        equipos[i].ordernarPorExperiencia(0, equipos[i].cantidadJugadores - 1);
    }

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
    for (int i = 0; i < equiposLongitud; i++)
    {
        cout << equipos[i].mostrarDatos() << endl;
    }

    // Imprimir Jugadores
    cout << "\nJUGADORES" << endl;
    for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << jugadores[i].mostrarDatos() << endl;
    }

    // Imprimir Directores Tecnicos
<<<<<<< HEAD
    cout << "\nDIRECTORES TECNICOS" << endl;

=======
    cout << "\nDIRECTORES TÉCNICOS" << endl;
>>>>>>> baeb878e94d2452dccc3729f7461de8aeb1d4530
    for (int i = 0; i < directoresLongitud; i++)
    {
        cout << directores[i].mostrarDatos() << endl;
    }

    // MENU PRINCIPAL
    int opcion1 = 0;
    int opcion2 = 0;
    int opcion3 = 0;
    int opcion4 = 0;
    int opcion5 = 0;

    while (opcion1 != 5)
    {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Equipos" << endl;
        cout << "2. Jugadores" << endl;
        cout << "3. Directores Tecnicos" << endl;
        cout << "4. Partidos" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
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
                    int seleccionEquipo;
                    cout << endl;
                    do
                    {
                        for (int i = 0; i < equiposLongitud; i++)
                        {
                            cout << i + 1 << ") " << equipos[i].nombre << endl;
                        }
                        cin >> seleccionEquipo;
                        seleccionEquipo--;
                    } while (seleccionEquipo < 0 || seleccionEquipo >= equiposLongitud);
                    cout << equipos[seleccionEquipo].nombre << endl;

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
                                    cout << endl;
                                    equipos[seleccionEquipo].mostrarJugadores();
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
                            equipos[seleccionEquipo].mostrarJugadores();
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
                cout << "\nSUBMENU - Directores Tecnicos" << endl;
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
    //jugadores[jugadoresLongitud] = { "Canaimita Patriota", "Javier", "Hernandez", "Defensa", 5, 2, "Incorporado" };
    //jugadoresLongitud++;
    //listarJugadores("", jugadores, jugadoresLongitud, true);
    //guardarDatosEnArchivo("entrada1.txt", equipos, equiposLongitud, jugadores, jugadoresLongitud, directores, directoresLongitud);
    //listarEquipos(equipos, equiposLongitud);
    //listarDirectores(directores, directoresLongitud, true);
    return 0;
}