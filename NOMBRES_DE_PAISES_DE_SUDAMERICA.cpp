#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<string, 12> paises = {
        "Argentina", "Bolivia", "Brasil", "Chile", "Colombia",
        "Ecuador", "Guyana", "Paraguay", "Peru", "Surinam"
    };

    paises.at(10) = "Uruguay";
    paises[11] = "Venezuela";

    cout << "Paises que empiezan con C o P:" << endl;

    for (string pais : paises)
    {
        if (pais[0] == 'C' || pais[0] == 'P')
            cout << pais << endl;
    }

    cout << "\nPrimer y ultimo elemento :" << endl;
    cout << "Primer pais: " << paises.front() << endl;
    cout << "Ultimo pais: " << paises.back() << endl;

    return 0;
}