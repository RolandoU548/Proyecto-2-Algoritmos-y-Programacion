#include <iostream>
#include <fstream>
#include <string>
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
    void agregar(Jugador &jugador, string nombreEquipo, string nombre, string apellido, string posicion, int experiencia)
    {
        jugador.equipo = nombreEquipo;
        jugador.nombre = nombre;
        jugador.apellido = apellido;
        jugador.posicion = posicion;
        jugador.experiencia = experiencia;
    }
    void listar(Jugador jugadores[], string posicion, int jugadoresLongitud, bool goleadores)
    {
        if (goleadores)
        {
            for (int i = 0; i < jugadoresLongitud; i++)
            {
                if (jugadores[i].goles > 0 && jugadores[i].estado == "Incorporado")
                {
                    cout << jugadores[i].equipo << " " << jugadores[i].nombre << " " << jugadores[i].apellido << " " << jugadores[i].goles;
                    if (jugadores[i].goles == 1)
                        cout << " Gol" << endl;
                    else
                        cout << " Goles" << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < jugadoresLongitud; i++)
            {
                if (jugadores[i].posicion == posicion && jugadores[i].estado == "Incorporado")
                    cout << jugadores[i].mostrarDatos() << endl;
            }
        }
    }

    void actualizarJugadoresOrdenados(Jugador jugadores[], Jugador jugadoresOrdenados[], int jugadoresLongitud)
    {
        for (int i = 0; i < jugadoresLongitud; i++)
        {
            jugadoresOrdenados[i] = jugadores[i];
        }
        ordenarPorExperiencia(jugadoresOrdenados, 0, jugadoresLongitud);
    }

    void actualizarJugadoresGoleadores(Jugador jugadores[], Jugador jugadoresGoleadores[], int jugadoresLongitugd)
    {
        for (int i = 0; i < jugadoresLongitugd; i++)
        {
            jugadoresGoleadores[i] = jugadores[i];
        }
        ordenarPorGoles(jugadoresGoleadores, 0, jugadoresLongitugd);
    }

    void ordenarPorExperiencia(Jugador jugadores[], int inicio, int fin)
    {
        int izq, der, piv;
        Jugador aux;
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
                aux = jugadores[izq];
                jugadores[izq] = jugadores[der];
                jugadores[der] = aux;
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
        int izq, der, piv;
        Jugador aux;
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
                aux = jugadores[izq];
                jugadores[izq] = jugadores[der];
                jugadores[der] = aux;
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
    void mostrarNuevos(Jugador nuevos[], int jugadoresLongitud, string nombreEquipo)
    {
        int cont = 0;
        for (int i = jugadoresLongitud - 1; i >= 0; i--)
        {
            if (cont >= 5)
                break;
            else if (nuevos[i].equipo == nombreEquipo)
            {
                cout << nuevos[i].mostrarDatos() << endl;
                cont++;
            }
        }
    }
    int buscarIndiceJugador(Jugador jugadores[], int jugadoresLongitud)
    {
        for (int i = 0; i < jugadoresLongitud; i++)
        {
            if (equipo == jugadores[i].equipo && nombre == jugadores[i].nombre && apellido == jugadores[i].apellido && posicion == jugadores[i].posicion && experiencia == jugadores[i].experiencia)
                return i;
        }
    }
    int buscarJugador(Jugador jugadores[], int cantidadJugadores, string nombre, string apellido)
    {
        for (int i = 0; i < cantidadJugadores; i++)
        {
            if (jugadores[i].nombre == nombre && jugadores[i].apellido == apellido)
            {
                return i;
            }
        }
        return -1;
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
        while (opcion < 1 || opcion > 4)
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
                break;
            case 2:
                cin >> director.apellido;
                cout << director.mostrarDatos() << endl;
                break;
            case 3:
                cin >> director.experiencia;
                cout << director.mostrarDatos() << endl;
                break;
            default:
                cout << endl;
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
        int izq, der, piv;
        DirectorTecnico aux;
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
                aux = directores[izq];
                directores[izq] = directores[der];
                directores[der] = aux;
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
    string nombre = "Equipo";
    Jugador jugadores[50];
    Jugador jugadoresOrdenados[50];
    int cantidadJugadores = 0;
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
        }
    };
    void ordernarPorExperiencia(int inicio, int fin)
    {
        int izq, der, piv;
        Jugador aux;
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
                aux = jugadores[izq];
                jugadores[izq] = jugadores[der];
                jugadores[der] = aux;
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
    void agregarJugador(string nombre, string apellido, string posicion, int experiencia)
    {
        jugadores[cantidadJugadores].nombre = nombre;
        jugadores[cantidadJugadores].apellido = apellido;
        jugadores[cantidadJugadores].posicion = posicion;
        jugadores[cantidadJugadores].experiencia = experiencia;
        jugadores[cantidadJugadores].equipo = this->nombre;
        cantidadJugadores++;
    };
    void eliminarJugador(int jugadorPosicion)
    {
        for (int i = jugadorPosicion; i < cantidadJugadores; i++)
        {
            jugadores[i] = jugadores[i + 1];
        }
        cantidadJugadores--;
    }
    void mostrarJugadores()
    {
        for (int i = 0; i < cantidadJugadores; i++)
        {
            if (jugadores[i].estado == "Incorporado")
                cout << jugadores[i].mostrarDatos() << endl;
        }
    }
    void mostrarMejoresJugadores()
    {
        jugadoresOrdenados->actualizarJugadoresOrdenados(jugadores, jugadoresOrdenados, cantidadJugadores);

        for (int i = 0; i < cantidadJugadores; i++)
        {
            if (jugadoresOrdenados[i].estado == "Incorporado")
                cout << jugadoresOrdenados[i].mostrarDatos() << endl;
        }
    }
    void mostrarLesionados()
    {
        for (int i = 0; i < cantidadJugadores; i++)
        {
            if (jugadores[i].estado == "Lesionado")
            {
                cout << jugadores[i].mostrarDatos() << endl;
            }
        }
    }
    Jugador seleccionarJugador(Jugador jugadores[], int jugadoresLongitud)
    {
        Jugador jugadoresIncorporados[50];
        int jugadoresIncorporadosLongitud = 0;
        int numRef;

        for (int i = 0; i < jugadoresLongitud; i++)
        {
            if (jugadores[i].estado == "Incorporado")
            {
                jugadoresIncorporados[jugadoresIncorporadosLongitud] = jugadores[i];
                jugadoresIncorporadosLongitud++;
            }
        }

        for (int i = 0; i < jugadoresIncorporadosLongitud; i++)
        {
            cout << i + 1 << ") " << jugadoresIncorporados[i].mostrarDatos() << endl;
        }
        cin >> numRef;
        return jugadoresIncorporados[numRef - 1];
    }
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
    archivoEntrada.close();
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
void procesarJornada(string jornada, Jugador jugadores[])
{
    ifstream archivoJornada;
    string actuacion = "";
    string actuaciones[16] = {
        "Tiro al arco",
        "Entrada eficaz",
        "Saludo al publico",
        "Gol",
        "Pase",
        "Atajada",
        "Centro eficaz",
        "Regate",
        "Turo a las gradas",
        "Entrada a destiempo",
        "Insulto al arbitro",
        "Falta",
        "Tarjeta",
        "Mal despeje",
        "Mano al balon",
        "Casancio",
    };

    archivoJornada.open(jornada);

    archivoJornada.close();
}

void actuacionJugador(Jugador &jugador, string actuaciones[16], string actuacion)
{
    for (int i = 0; i < 16; i++)
    {
        if (actuacion == "Reincorporacion")
        {
            jugador.estado = "Incorporado";
            jugador.experiencia++;
        }
        else if (actuacion == "Lesion")
        {
            jugador.estado = "Lesionado";
            jugador.experiencia--;
        }
        if (actuacion == actuaciones[i])
        {
            if (i <= 7)
            {
                jugador.experiencia++;
            }
            else if (i >= 8)
            {
                jugador.experiencia--;
            }
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
    for (int i = 0; i < equiposLongitud; i++)
    {
        for (int j = 0; j < equipos[i].cantidadJugadores; j++)
        {
            archivoSalida << equipos[i].jugadores[j].equipo << " " << equipos[i].jugadores[j].nombre << " " << equipos[i].jugadores[j].apellido << " " << equipos[i].jugadores[j].posicion << " " << equipos[i].jugadores[j].experiencia << endl;
        }
    }

    archivoSalida << "D" << endl;
    for (int i = 0; i < directoresLongitud; i++)
    {
        archivoSalida << directores[i].nombre << " " << directores[i].apellido << " " << directores[i].experiencia << endl;
    }
    archivoSalida.close();
}

int main()
{
    Jugador nuevos[100];
    Jugador jugadoresOrdenados[100];
    Jugador jugadoresGoleadores[100];

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

    for (int i = 0; i < jugadoresLongitud; i++)
    {
        nuevos[i] = jugadores[i];
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
                cout << "\nSUBMENU - Equipos" << endl;
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
                    break;
                }
                case 3:
                {
                    // Codigo para Eliminar
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
                    break;
                }
                case 4:
                    // Codigo para la Listar Todos
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

                    while (opcion3 != 5)
                    {
                        cout << "\nSUBSUBMENU - Listar Todos" << endl;
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
                                cout << "\nSUBSUBSUBMENU - Jugadores" << endl;
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
                                    {
                                        string nombreJugador, apellidoJugador, posicionJugador;
                                        int experienciaJugador;
                                        cin >> nombreJugador;
                                        cin >> apellidoJugador;
                                        cin >> posicionJugador;
                                        cin >> experienciaJugador;
                                        equipos[seleccionEquipo].agregarJugador(nombreJugador, apellidoJugador, posicionJugador, experienciaJugador);
                                        jugadores->agregar(jugadores[jugadoresLongitud], equipos[seleccionEquipo].nombre, nombreJugador, apellidoJugador, posicionJugador, experienciaJugador);
                                        nuevos[jugadoresLongitud] = jugadores[jugadoresLongitud];
                                        jugadoresLongitud++;
                                        break;
                                    }
                                case 3:
                                    // Codigo para Modificar
                                    {
                                        int numRefJugador;
                                        int numRefEquipo;
                                        int numRefNuevo;
                                        Jugador jugadorRef;
                                        string nuevoDato;
                                        int nuevaExp;
                                        cout << endl;

                                        jugadorRef = equipos->seleccionarJugador(equipos[seleccionEquipo].jugadores, equipos[seleccionEquipo].cantidadJugadores);
                                        // Buscar jugador seleccionado en global
                                        numRefJugador = jugadorRef.buscarIndiceJugador(jugadores, jugadoresLongitud);
                                        // Buscar jugador seleccionado en equipo
                                        numRefEquipo = jugadorRef.buscarIndiceJugador(equipos[seleccionEquipo].jugadores, equipos[seleccionEquipo].cantidadJugadores);
                                        // Buscar jugador seleccionado en nuevos
                                        numRefNuevo = jugadorRef.buscarIndiceJugador(nuevos, jugadoresLongitud);

                                        int opcion = 0;
                                        while (opcion < 1 || opcion > 5)
                                        {
                                            cout << "1) Nombre: " << jugadorRef.nombre << endl;
                                            cout << "2) Apellido: " << jugadorRef.apellido << endl;
                                            cout << "3) Posicion: " << jugadorRef.posicion << endl;
                                            cout << "4) Experiencia: " << jugadorRef.experiencia << endl;
                                            cout << "5) Volver" << endl;
                                            cin >> opcion;

                                            switch (opcion)
                                            {
                                            case 1:
                                                cin >> nuevoDato;
                                                equipos[seleccionEquipo].jugadores[numRefEquipo].nombre = jugadores[numRefJugador].nombre = nuevos[numRefNuevo].nombre = nuevoDato;
                                                break;
                                            case 2:
                                                cin >> nuevoDato;
                                                equipos[seleccionEquipo].jugadores[numRefEquipo].apellido = jugadores[numRefJugador].apellido = nuevos[numRefNuevo].apellido = nuevoDato;
                                                break;
                                            case 3:
                                                cin >> nuevoDato;
                                                equipos[seleccionEquipo].jugadores[numRefEquipo].posicion = jugadores[numRefJugador].posicion = nuevos[numRefNuevo].posicion = nuevoDato;
                                                break;
                                            case 4:
                                                cin >> nuevaExp;
                                                equipos[seleccionEquipo].jugadores[numRefEquipo].experiencia = jugadores[numRefJugador].experiencia = nuevos[numRefNuevo].experiencia = nuevaExp;
                                                break;
                                            default:
                                                cout << endl;
                                                break;
                                            }
                                        }
                                        break;
                                    }

                                case 4:
                                    // Codigo para Eliminar
                                    {
                                        int numRefJugador;
                                        int numRefEquipo;
                                        int numRefNuevo;
                                        Jugador jugadorRef;
                                        cout << endl;

                                        jugadorRef = equipos->seleccionarJugador(equipos[seleccionEquipo].jugadores, equipos[seleccionEquipo].cantidadJugadores);
                                        // Buscar jugador seleccionado en global
                                        numRefJugador = jugadorRef.buscarIndiceJugador(jugadores, jugadoresLongitud);
                                        // Buscar jugador seleccionado en equipo
                                        numRefEquipo = jugadorRef.buscarIndiceJugador(equipos[seleccionEquipo].jugadores, equipos[seleccionEquipo].cantidadJugadores);
                                        // Buscar jugador seleccionado en nuevos
                                        numRefNuevo = jugadorRef.buscarIndiceJugador(nuevos, jugadoresLongitud);

                                        equipos[seleccionEquipo].eliminarJugador(numRefEquipo);
                                        jugadores->eliminar(jugadores, jugadoresLongitud, numRefJugador);
                                        nuevos->eliminar(nuevos, jugadoresLongitud, numRefNuevo);
                                        jugadoresLongitud--;
                                        break;
                                    }
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
                            // Codigo para Ver Mejores Jugadores
                            cout << endl;
                            equipos[seleccionEquipo].mostrarMejoresJugadores();
                            break;
                        case 3:
                            // Codigo para Ver Lesionados
                            cout << endl;
                            equipos[seleccionEquipo].mostrarLesionados();
                            break;
                        case 4:
                            // Codigo para Ver Los Nuevos
                            cout << endl;
                            nuevos->mostrarNuevos(nuevos, jugadoresLongitud, equipos[seleccionEquipo].nombre);
                            break;
                        case 5:
                            // Regresar al submenu Equipos
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                            break;
                        }
                        opcion4 = 0;
                    }
                    break;
                case 5:
                    // Regresar al menu principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpcion invalida." << endl;
                    break;
                }
                opcion3 = 0; // Reiniciar la opcion del subsubmenu
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
                cout << "6. Volver al menu principal" << endl;
                cout << "Elige una opcion: ";
                cin >> opcion2;


                switch (opcion2)
                {
                case 1:
                    // Codigo para Mostrar Porteros
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Porteros" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenu Jugadores" << endl;
                        cout << "Elige una opcion: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Codigo para Mostrar Todos los Porteros
                            for (int i = 0; i < equiposLongitud; i++)
                            {
                                jugadores->listar(equipos[i].jugadores, "Portero", equipos[i].cantidadJugadores, false);
                            }
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Porteros
                            jugadores->actualizarJugadoresOrdenados(jugadores, jugadoresOrdenados, jugadoresLongitud);
                            jugadores->listar(jugadoresOrdenados, "Portero", jugadoresLongitud, false);
                            break;
                        case 3:
                            // Regresar al submenu Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                            break;
                        }
                    }
                    break;
                case 2:
                    // Codigo para Mostrar Defensas
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Defensas" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenu Jugadores" << endl;
                        cout << "Elige una opcion: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Codigo para Mostrar Todos los Defensas
                            for (int i = 0; i < equiposLongitud; i++)
                            {
                                jugadores->listar(equipos[i].jugadores, "Defensa", equipos[i].cantidadJugadores, false);
                            }
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Defensas
                            jugadores->actualizarJugadoresOrdenados(jugadores, jugadoresOrdenados, jugadoresLongitud);
                            jugadores->listar(jugadoresOrdenados, "Defensa", jugadoresLongitud, false);
                            break;
                        case 3:
                            // Regresar al submenu Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                            break;
                        }
                    }
                    break;
                case 3:
                    // Codigo para Mostrar Mediocampistas
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Mediocampistas" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenu Jugadores" << endl;
                        cout << "Elige una opcion: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Codigo para Mostrar Todos los Mediocampistas
                            for (int i = 0; i < equiposLongitud; i++)
                            {
                                jugadores->listar(equipos[i].jugadores, "Mediocampista", equipos[i].cantidadJugadores, false);
                            }
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Mediocampistas
                            jugadores->actualizarJugadoresOrdenados(jugadores, jugadoresOrdenados, jugadoresLongitud);
                            jugadores->listar(jugadoresOrdenados, "Mediocampista", jugadoresLongitud, false);
                            break;
                        case 3:
                            // Regresar al submenu Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                            break;
                        }
                    }
                    break;
                case 4:
                    // Codigo para la Mostrar Delanteros
                    while (opcion3 != 3)
                    {
                        cout << "\nSUBSUBMENU - Delanteros" << endl;
                        cout << "1. Todos" << endl;
                        cout << "2. Los Mejores" << endl;
                        cout << "3. Volver al submenu Jugadores" << endl;
                        cout << "Elige una opcion: ";
                        cin >> opcion3;

                        switch (opcion3)
                        {
                        case 1:
                            // Codigo para Mostrar Todos los Delanteros
                            for (int i = 0; i < equiposLongitud; i++)
                            {
                                jugadores->listar(equipos[i].jugadores, "Delantero", equipos[i].cantidadJugadores, false);
                            }
                            break;
                        case 2:
                            // Código para Mostrar Los Mejores Delanteros
                            jugadores->actualizarJugadoresOrdenados(jugadores, jugadoresOrdenados, jugadoresLongitud);
                            jugadores->listar(jugadoresOrdenados, "Delantero", jugadoresLongitud, false);
                            break;
                        case 3:
                            // Regresar al submenu Jugadores
                            cout << endl;
                            break;
                        default:
                            cout << "\nOpcion invalida." << endl;
                            break;
                        }
                    }
                    break;
                case 5:
                    // Codigo para la Mostrar Goleadores
                    jugadores->actualizarJugadoresGoleadores(jugadores, jugadoresGoleadores, jugadoresLongitud);
                    cout << "se actualizo " << endl;
                    jugadores->listar(jugadoresGoleadores, "", jugadoresLongitud, true);
                    break;
                case 6:
                    // Regresar al menu principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpcion invalida." << endl;
                    break;
                }
                opcion3 = 0; // Reiniciar la opcion del subsubmenu
            }
            break;
        case 3: // Directores Tecnicos
            while (opcion2 != 6)
            {
                cout << "\nSUBMENU - Directores Tecnicos" << endl;
                cout << "1. Todos" << endl;
                cout << "2. Los mas experimentados" << endl;
                cout << "3. Agregar" << endl;
                cout << "4. Modificar" << endl;
                cout << "5. Eliminar" << endl;
                cout << "6. Volver al menu principal" << endl;
                cout << "Elige una opcion: ";
                cin >> opcion2;
                cout << endl;

                switch (opcion2)
                {
                case 1:
                    // Codigo para Mostrar Todos
                    directores->listar(directores, directoresLongitud, false);
                    break;
                case 2:
                    // Codigo para Mostrar Los mas experimentados
                    directores->ordenarPorExperiencia(directores, 0, directoresLongitud);
                    directores->listar(directores, directoresLongitud, false);
                    break;
                case 3:
                    // Codigo para Agregar
                    directores->agregar(directores[directoresLongitud]);
                    directoresLongitud++;
                    break;
                case 4:
                {
                    // Codigo para Modificar
                    int opcionDirector = 0;
                    do
                    {
                        directores->listar(directores, directoresLongitud, true);
                        cin >> opcionDirector;
                        opcionDirector--;
                    } while (opcionDirector < 0 || opcionDirector >= directoresLongitud);
                    directores->modificar(directores[opcionDirector]);
                    break;
                }
                case 5:
                {
                    // Codigo para Eliminar
                    directores->listar(directores, directoresLongitud, true);
                    int opcionDirector = 0;
                    cin >> opcionDirector;
                    directoresLongitud--;
                    directores->eliminar(directores, directoresLongitud, opcionDirector - 1);
                    break;
                }
                case 6:
                    // Regresar al menu principal
                    cout << endl;
                    break;
                default:
                    cout << "\nOpcion invalida." << endl;
                    break;
                }
            }
            break;
        case 4: // Partidos
            while (opcion2 != 2)
            {
                cout << "\nSUBMENU - Partidos" << endl;
                cout << "1. Cargar Partidos" << endl;
                cout << "2. Volver al menu principal" << endl;
                cout << "Elige una opcion: ";
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
            cout << "Opcion invalida." << endl;
            break;
        }
        opcion2 = 0; // Reiniciar la opcion del submenu
    }
    guardarDatosEnArchivo("entrada.in", equipos, equiposLongitud, jugadores, jugadoresLongitud, directores, directoresLongitud);
    // jugadores[jugadoresLongitud] = { "Canaimita Patriota", "Javier", "Hernandez", "Defensa", 5, 2, "Incorporado" }; jugadoresLongitud++;
    // listarJugadores("", jugadores, jugadoresLongitud, true);

    /*for (int i = 0; i < jugadoresLongitud; i++)
    {
        cout << nuevos[i].mostrarDatos() << endl;
    }*/

    return 0;
}