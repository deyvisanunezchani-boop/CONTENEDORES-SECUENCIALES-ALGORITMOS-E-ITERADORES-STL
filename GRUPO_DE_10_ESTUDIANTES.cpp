#include <iostream>
#include <array>
#include <fstream>
using namespace std;

struct Estudiante
{
    string nombre;
    int nacimiento;
    float gpa;
};

int main()
{
    array<Estudiante, 10> estudiantes = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

    for (int i = 2; i < 4; i++)
    {
        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;

        cout << "Anio de nacimiento: ";
        cin >> estudiantes[i].nacimiento;

        cout << "GPA: ";
        cin >> estudiantes[i].gpa;
    }

    string nombres[3] = {"Gaby", "Patty", "Diana"};
    int nacimientos[3] = {2002, 2004, 2006};
    float gps[3] = {3.8, 3.0, 2.9};

    for (int i = 0; i < 2; i++)
    {
        estudiantes[i + 4].nombre = nombres[i];
        estudiantes[i + 4].nacimiento = nacimientos[i];
        estudiantes[i + 4].gpa = gps[i];
    }

    ifstream archivo("datos.txt");

    if (!archivo)
    {
        cout << "\nNo se pudo abrir el archivo." << endl;
        return 1;
    }

    for (int i = 6; i < 10; i++)
    {
        archivo >> estudiantes[i].nombre;
        archivo >> estudiantes[i].nacimiento;
        archivo >> estudiantes[i].gpa;
    }

    archivo.close();

    cout << "\n===== LISTA DE ESTUDIANTES =====" << endl;

    for (int i = 0; i < 10; i++)
    {
        int edad = 2026 - estudiantes[i].nacimiento;

        cout << "\nNombre: " << estudiantes[i].nombre << endl;
        cout << "Nacimiento: " << estudiantes[i].nacimiento << endl;
        cout << "Edad: " << edad << " anios" << endl;
        cout << "GPA: " << estudiantes[i].gpa << endl;

        if (estudiantes[i].gpa >= 3.5)
            cout << "Beca: CALIFICA" << endl;
        else
            cout << "Beca: NO CALIFICA" << endl;
    }

    return 0;
}