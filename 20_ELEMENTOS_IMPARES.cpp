#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    array<int, 20> numeros = {
        21, 23, 25, 27, 29,
        31, 33, 35, 37, 39, 41, 43, 45, 47, 49,
        1, 3, 5, 7, 9
    };

    cout << "Todos los elementos: " << endl;
    for (int x : numeros)
        cout << x << " ";

    cout << "\n\nMayores de 20 y menores de 50: " << endl;
    for (auto it = numeros.begin(); it != numeros.end(); it++)
    {
        if (*it > 20 && *it < 50)
            cout << *it << " ";
    }

    sort(numeros.begin(), numeros.end());

    cout << "\n\nElementos ordenados: " << endl;
    for (int x : numeros)
        cout << x << " ";

    cout << "\n\nIndices impares menores de 10: " << endl;
    for (int i = 1; i < 10; i += 2)
        cout << numeros[i] << " ";

    return 0;
}