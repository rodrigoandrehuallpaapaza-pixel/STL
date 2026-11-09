#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Estudiante {
private:
    string nombre;
    int anioNacimiento;
    double gpa;

public:
    Estudiante() : nombre(""), anioNacimiento(0), gpa(0.0) {}
    
    Estudiante(string nom, int anio, double g) {
        nombre = nom;
        anioNacimiento = anio;
        gpa = g;
    }

    string getNombre() const {
        return nombre;
    }

    int getAnioNacimiento() const {
        return anioNacimiento;
    }

    double getGPA() const {
        return gpa;
    }

    void setDatos(string nom, int anio, double g) {
        nombre = nom;
        anioNacimiento = anio;
        gpa = g;
    }
};

int main() {
    array<Estudiante, 10> estudiantes;

    estudiantes[0] = Estudiante("Juan", 2000, 3.4);
    estudiantes[1] = Estudiante("Maria", 2005, 2.8);

    cout << "=== 3.a: Ingrese los datos para el 3er y 4to estudiante ===" << endl;
    for (int i = 2; i <= 3; ++i) {
        string nom;
        int anio;
        double g;
        cout << "Estudiante " << (i + 1) << ":" << endl;
        cout << "  Nombre: ";
        cin >> nom;
        cout << "  Año de nacimiento: ";
        cin >> anio;
        cout << "  GPA: ";
        cin >> g;
        estudiantes[i].setDatos(nom, anio, g);
    }
    cout << endl;

    string nombresArr[3] = {"Gaby", "Patty", "Diana"};
    int nacimientosArr[3] = {2002, 2004, 2006};
    double gpaArr[3] = {3.8, 3.0, 2.9};

    estudiantes[4] = Estudiante(nombresArr[0], nacimientosArr[0], gpaArr[0]);
    estudiantes[5] = Estudiante(nombresArr[1], nacimientosArr[1], gpaArr[1]);

    ifstream archivo("datos.txt");
    if (archivo.is_open()) {
        int idx = 6;
        string nom;
        int anio;
        double g;
        while (idx < 10 && archivo >> nom >> anio >> g) {
            estudiantes[idx].setDatos(nom, anio, g);
            idx++;
        }
        archivo.close();
    } else {
        cout << "Aviso: No se pudo abrir el archivo 'datos.txt'." << endl;
    }

    int anioActual = 2026;
    cout << "=== 3.d: Reporte General de Estudiantes ===" << endl;
    cout << left << setw(15) << "Nombre" 
         << setw(12) << "Nacimiento" 
         << setw(8) << "Edad" 
         << setw(8) << "GPA" 
         << "Beca" << endl;
    cout << string(50, '-') << endl;

    for (const auto& est : estudiantes) {
        int edad = anioActual - est.getAnioNacimiento();
        string beca = (est.getGPA() >= 3.5) ? "Sí califica" : "No califica";
        
        cout << left << setw(15) << est.getNombre() 
             << setw(12) << est.getAnioNacimiento() 
             << setw(8) << edad 
             << setw(8) << fixed << setprecision(2) << est.getGPA() 
             << beca << endl;
    }

    return 0;
}