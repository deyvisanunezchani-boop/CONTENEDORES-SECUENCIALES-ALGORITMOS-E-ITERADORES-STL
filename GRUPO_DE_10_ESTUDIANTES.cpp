#include <iostream>
#include <array>
#include <fstream>
using namespace std;

class Estudiante
{
private:
    string nombre;
    int nacimiento;
    float gpa;

public:
    Estudiante();
    Estudiante(string, int, float);

    void ingresar();
    void asignar(string, int, float);
    void mostrar();
};

Estudiante::Estudiante()
{
    nombre = "";
    nacimiento = 0;
    gpa = 0;
}

Estudiante::Estudiante(string n, int a, float g)
{
    nombre = n;
    nacimiento = a;
    gpa = g;
}

void Estudiante::ingresar()
{
    cout << "Nombre: ";
    cin >> nombre;

    cout << "Anio de nacimiento: ";
    cin >> nacimiento;

    cout << "GPA: ";
    cin >> gpa;
}

void Estudiante::asignar(string n, int a, float g)
{
    nombre = n;
    nacimiento = a;
    gpa = g;
}

void Estudiante::mostrar()
{
    int edad = 2026 - nacimiento;

    cout << "\nNombre: " << nombre << endl;
    cout << "Nacimiento: " << nacimiento << endl;
    cout << "Edad: " << edad << " anios" << endl;
    cout << "GPA: " << gpa << endl;

    if (gpa >= 3.5)
        cout << "Beca: CALIFICA" << endl;
    else
        cout << "Beca: NO CALIFICA" << endl;
}

int main()
{
    array<Estudiante, 10> estudiantes = {
        Estudiante("Juan", 2000, 3.4),
        Estudiante("Maria", 2005, 2.8)
    };

    cout << "TERCER Y CUARTO ESTUDIANTE" << endl;

    for (int i = 2; i < 4; i++)
    {
        estudiantes[i].ingresar();
    }

    string nombres[3] = {"Gaby", "Patty", "Diana"};
    int nacimientos[3] = {2002, 2004, 2006};
    float gps[3] = {3.8, 3.0, 2.9};

    for (int i = 0; i < 2; i++)
    {
        estudiantes[i + 4].asignar(nombres[i], nacimientos[i], gps[i]);
    }

    ifstream archivo("datos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string nombre;
    int nacimiento;
    float gpa;

    for (int i = 6; i < 10; i++)
    {
        archivo >> nombre >> nacimiento >> gpa;
        estudiantes[i].asignar(nombre, nacimiento, gpa);
    }

    archivo.close();

    cout << "\n===== LISTA DE ESTUDIANTES =====" << endl;

    for (int i = 0; i < 10; i++)
    {
        estudiantes[i].mostrar();
    }

    return 0;
}