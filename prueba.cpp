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
    }
    void listar(Jugador jugadores[], int jugadoresLongitud, bool experiencia, bool goleadores)
    {
        if (experiencia)
        {
            jugadores->ordenarPorExperiencia(jugadores, 0, jugadoresLongitud);
        }
        else if (goleadores)
        {
            jugadores->ordenarPorGoles(jugadores, 0, jugadoresLongitud);
        }
        for (int i = 0; i < jugadoresLongitud; i++)
        {
            // Goleadores
            if (goleadores)
            {
                if (jugadores[i].goles > 0)
                {
                    cout << jugadores[i].mostrarDatos() << " " << jugadores[i].goles;
                    if (jugadores[i].goles == 1)
                        cout << " Gol" << endl;
                    else
                        cout << " Goles" << endl;
                }
            }
            // Posicion
            else
                cout << jugadores[i].mostrarDatos() << endl;
        }
    }
    void actualizarPosiciones(Jugador jugadores[], int jugadoresLongitud, Jugador porteros[], int &porterosLongitud, Jugador defensas[], int &defensasLongitud, Jugador mediocampistas[], int &mediocampistasLongitud, Jugador delanteros[], int &delanterosLongitud)
    {
        int pt = 0, df = 0, md = 0, dl = 0;
        porterosLongitud = defensasLongitud = mediocampistasLongitud = delanterosLongitud = 0;
        for (int i = 0; i < jugadoresLongitud; i++)
        {
            if (jugadores[i].posicion == "Portero")
            {
                porteros[pt++] = jugadores[i];
                porterosLongitud++;
            }
            else if (jugadores[i].posicion == "Defensa")
            {
                defensas[df++] = jugadores[i];
                defensasLongitud++;
            }
            else if (jugadores[i].posicion == "Mediocampista")
            {
                mediocampistas[md] = jugadores[i];
                mediocampistasLongitud++;
            }
            else if (jugadores[i].posicion == "Delantero")
            {
                delanteros[dl++] = jugadores[i];
                delanterosLongitud++;
            }
        }
    }
    void ordenarPorExperiencia(Jugador jugadores[], int inicio, int fin)
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
            ordenarPorExperiencia(jugadores, inicio, der);
        }

        if (fin > izq)
        {
            ordenarPorExperiencia(jugadores, izq, fin);
        }
    }
    void ordenarPorGoles(Jugador jugadores[], int inicio, int fin)
    {
        int izq, der, piv, aux;
        izq = inicio;
        der = fin;
        piv = jugadores[(izq + der) / 2].goles;

        do
        {
            while (jugadores[izq].goles > piv && izq < fin)
            {
                izq++;
            }
            while (jugadores[der].goles < piv && der > inicio)
            {
                der--;
            }
            if (izq <= der)
            {
                aux = jugadores[izq].goles;
                jugadores[izq].goles = jugadores[der].goles;
                jugadores[der].goles = aux;
                izq++;
                der--;
            }
        } while (izq <= der);

        if (inicio <= der)
        {
            ordenarPorGoles(jugadores, inicio, der);
        }

        if (fin > izq)
        {
            ordenarPorGoles(jugadores, izq, fin);
        }
    }
    void eliminar(Jugador jugadores[], int jugadoresLongitud, int jugadorPosicion)
    {
        for (int i = jugadorPosicion; i < jugadoresLongitud; i++)
            jugadores[i] = jugadores[i + 1];
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
    void listar(DirectorTecnico directores[], int directoresLongitud, bool enumerado)
    {
        for (int i = 0; i < directoresLongitud; i++)
        {
            if (enumerado)
                cout << i + 1 << ") ";
            cout << directores[i].mostrarDatos() << endl;
        }
    }
    void agregar(DirectorTecnico &director)
    {
        cin >> director.nombre;
        cin >> director.apellido;
        cin >> director.experiencia;
    }
    void modificar(DirectorTecnico &director)
    {
        int opcion = 0;
        while (opcion != 4)
        {
            cout << "1) Nombre: " << director.nombre << endl;
            cout << "2) Apellido: " << director.apellido << endl;
            cout << "3) Experiencia: " << director.experiencia << endl;
            cout << "4) Volver" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cin >> director.nombre;
                cout << director.mostrarDatos() << endl;
                opcion = 4;
                break;
            case 2:
                cin >> director.apellido;
                cout << director.mostrarDatos() << endl;
                opcion = 4;
                break;
            case 3:
                cin >> director.experiencia;
                cout << director.mostrarDatos() << endl;
                opcion = 4;
                break;
            case 4:
                cout << endl;
                break;
            default:
                break;
            }
        }
    }
    void eliminar(DirectorTecnico directores[], int directoresLongitud, int directorPosicion)
    {
        for (int i = directorPosicion; i < directoresLongitud; i++)
            directores[i] = directores[i + 1];
    }
    void ordenarPorExperiencia(DirectorTecnico directores[], int inicio, int fin)
    {
        int izq, der, piv, aux;
        izq = inicio;
        der = fin;
        piv = directores[(izq + der) / 2].experiencia;

        do
        {
            while (directores[izq].experiencia > piv && izq < fin)
            {
                izq++;
            }
            while (directores[der].experiencia < piv && der > inicio)
            {
                der--;
            }
            if (izq <= der)
            {
                aux = directores[izq].experiencia;
                directores[izq].experiencia = directores[der].experiencia;
                directores[der].experiencia = aux;
                izq++;
                der--;
            }
        } while (izq <= der);

        if (inicio <= der)
        {
            ordenarPorExperiencia(directores, inicio, der);
        }

        if (fin > izq)
        {
            ordenarPorExperiencia(directores, izq, fin);
        }
    }

    string nombre;
    string apellido;
    int experiencia;
};

// Clase Equipo
class Equipo
{
public:
    Equipo() = default;
    Equipo(string nombreEquipo)
    {
        nombre = nombreEquipo;
    }
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
    string nombre = "Equipo";
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
    void listar(Equipo equipos[], int equiposLongitud)
    {
        for (int i = 0; i < equiposLongitud; i++)
        {
            cout << i + 1 << ") " << equipos[i].nombre << endl;
        }
    }
    void agregar()
    {
        string nuevoEquipo = "";
        cin >> nuevoEquipo;
        nombre = nuevoEquipo;
    }
    void modificar(Equipo &equipo, Jugador jugadores[], int jugadoresLongitud)
    {
        string antiguoNombre = equipo.nombre;
        string nuevoNombre = "";
        cin >> nuevoNombre;
        equipo.nombre = nuevoNombre;
        for (int i = 0; i < equipo.cantidadJugadores; i++)
        {
            equipo.jugadores[i].equipo = nuevoNombre;
        }
        for (int i = 0; i < jugadoresLongitud; i++)
        {
            if (jugadores[i].equipo == antiguoNombre)
                jugadores[i].equipo = nuevoNombre;
        }
    }
    void eliminar(Equipo equipos[], int equiposLongitud, int equipoPosicion)
    {
        for (int i = equipoPosicion; i < equiposLongitud; i++)
            equipos[i] = equipos[i + 1];
    }
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

// Procesar archivo de jornada.in
void procesarJornada(string jornada)
{
    ifstream archivoJornada;
    archivoJornada.open(jornada);
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
    //cambiar por, bucle que se repite para cantidad de equipos, y subbucle para cantidad de jugadores de equipo
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

int main()
{
    Jugador porteros[100];
    Jugador defensas[100];
    Jugador mediocampistas[100];
    Jugador delanteros[100];
    int cantidadPorteros = 0;
    int cantidadDefensas = 0;
    int cantidadDeMediocampistas = 0;
    int cantidadDelanteros = 0;

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
    jugadores->actualizarPosiciones(jugadores, jugadoresLongitud, porteros, cantidadPorteros, defensas, cantidadDefensas, mediocampistas, cantidadDeMediocampistas, delanteros, cantidadDelanteros);

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
    equipos->listar(equipos, equiposLongitud);

    // Imprimir Jugadores
    cout << "\nJUGADORES" << endl;
    for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << jugadores[i].mostrarDatos() << endl;
    }

    // Imprimir Directores Tecnicos
    cout << "\nDIRECTORES TÉCNICOS" << endl;
    directores->listar(directores, directoresLongitud, false);

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
                    equipos[equiposLongitud].agregar();
                    equiposLongitud++;
                    break;
                case 2:
                {
                    // Código para Modificar
                    equipos->listar(equipos, equiposLongitud);
                    int opcionEquipo = 0;
                    string equipoModificado;
                    cin >> opcionEquipo;
                    equipos->modificar(equipos[opcionEquipo - 1], jugadores, jugadoresLongitud);
                    jugadores->actualizarPosiciones(jugadores, jugadoresLongitud, porteros, cantidadPorteros, defensas, cantidadDefensas, mediocampistas, cantidadDeMediocampistas, delanteros, cantidadDelanteros);
                }
                    break;
                case 3:
                {
                    // Código para Eliminar
                    equipos->listar(equipos, equiposLongitud);
                    int opcionEquipo = 0;
                    string equipoEliminado;
                    cin >> opcionEquipo;
                    equipoEliminado = equipos[opcionEquipo - 1].nombre;
                    equiposLongitud--;
                    equipos->eliminar(equipos, equiposLongitud, opcionEquipo - 1);
                    for (int i = 0; i < jugadoresLongitud; i++)
                    {
                        if (jugadores[i].equipo == equipoEliminado)
                        {
                            jugadoresLongitud--;
                            jugadores->eliminar(jugadores, jugadoresLongitud, i);
                            i--;
                        }
                    }
                    jugadores->actualizarPosiciones(jugadores, jugadoresLongitud, porteros, cantidadPorteros, defensas, cantidadDefensas, mediocampistas, cantidadDeMediocampistas, delanteros, cantidadDelanteros);
                    break;
                }
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
                            equipos[seleccionEquipo].mostrarLesionados();
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
                            jugadores->listar(porteros, cantidadPorteros, false, false);
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Porteros
                            jugadores->listar(porteros, cantidadPorteros, true, false);
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
                            jugadores->listar(defensas, cantidadDefensas, false, false);
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Defensas
                            jugadores->listar(defensas, cantidadDefensas, true, false);
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
                            jugadores->listar(mediocampistas, cantidadDeMediocampistas, false, false);
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Mediocampistas
                            jugadores->listar(mediocampistas, cantidadDeMediocampistas, true, false);
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
                            jugadores->listar(delanteros, cantidadDelanteros, false, false);
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Delanteros
                            jugadores->listar(delanteros, cantidadDelanteros, true, false);
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
                    jugadores->listar(jugadores, jugadoresLongitud, false, true);
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
                    directores->listar(directores, directoresLongitud,  false);
                    break;
                case 2:
                    // Código para Mostrar Los mas experimentados
                    directores->ordenarPorExperiencia(directores, 0, directoresLongitud); 
                    directores->listar(directores, directoresLongitud, false);
                    break;
                case 3:
                    // Código para Agregar
                    directoresLongitud++;
                    directores->agregar(directores[directoresLongitud - 1]);
                    break;
                case 4:
                {
                    // Código para Modificar
                    directores->listar(directores, directoresLongitud, true);
                    int opcionDirector = 0;
                    cin >> opcionDirector;
                    directores->modificar(directores[opcionDirector - 1]);
                    break;
                }
                case 5:
                {
                    // Código para Eliminar
                    int opcionDirector = 0;
                    cin >> opcionDirector;
                    directores->listar(directores, directoresLongitud, true);
                    directoresLongitud--;
                    directores->eliminar(directores, directoresLongitud, opcionDirector - 1);
                    break;
                }
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
                {
                    // Código para Cargar Partidos
                    string direccionJornada = "";
                    cin >> direccionJornada;

                    break;
                }
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
    // jugadores[jugadoresLongitud] = { "Canaimita Patriota", "Javier", "Hernandez", "Defensa", 5, 2, "Incorporado" }; jugadoresLongitud++;
    // listarJugadores("", jugadores, jugadoresLongitud, true);
    // guardarDatosEnArchivo("entrada.in", equipos, equiposLongitud, jugadores, jugadoresLongitud, directores, directoresLongitud);
    for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << jugadores[i].mostrarDatos() << endl;
    }
    return 0;
}