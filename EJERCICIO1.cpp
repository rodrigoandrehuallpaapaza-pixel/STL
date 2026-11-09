#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    array<int, 20> arr1 = {
        21, 23, 25, 27, 29,
        51, 53, 55, 57, 59, 61, 63, 65, 67, 69,
        11, 13, 15, 17, 19
    };

    cout << "=== 1.a: Todos los elementos ===" << endl;
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << "\n\n";

    cout << "=== 1.b: Elementos mayores de 20 y menores que 50 ===" << endl;
    for (int val : arr1) {
        if (val > 20 && val < 50) {
            cout << val << " ";
        }
    }
    cout << "\n\n";

    sort(arr1.begin(), arr1.end());
    cout << "=== 1.c: Elementos ordenados (Ascendente) ===" << endl;
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << "\n\n";

    cout << "=== 1.d: Elementos en índices impares menores de 10 ===" << endl;
    for (size_t i = 1; i < 10; i += 2) {
        cout << "Índice " << i << ": " << arr1[i] << endl;
    }
    cout << endl;

    return 0;
}