#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    array<string, 12> paises = {
        "Argentina", "Bolivia", "Brasil", "Chile", "Colombia", 
        "Ecuador", "Paraguay", "Perú", "Uruguay", "Venezuela"
    };

    paises.at(10) = "Guyana";
    paises[11] = "Surinam";

    cout << "=== 2.a: Todos los países después de insertar los restantes ===" << endl;
    for (const string& p : paises) {
        cout << p << " ";
    }
    cout << "\n\n";

    cout << "=== 2.b: Países que inician con C o P ===" << endl;
    for (const string& p : paises) {
        if (!p.empty() && (p[0] == 'C' || p[0] == 'P')) {
            cout << p << endl;
        }
    }
    cout << endl;

    cout << "=== 2.c: Primer y último elemento ===" << endl;
    cout << "Primer país: " << paises.front() << endl;
    cout << "Último país: " << paises.back() << endl << endl;

    sort(paises.begin(), paises.end());
    cout << "=== 2.d: Países ordenados alfabéticamente ===" << endl;
    for (const string& p : paises) {
        cout << p << " ";
    }
    cout << "\n\n";

    return 0;
}