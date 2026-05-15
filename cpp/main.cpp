#include "ArbolBinario.h"
#include <iostream>
#include <limits>

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "   SISTEMA DE GESTIÓN DE ESTUDIANTES" << endl;
    cout << "                                          " << endl;
    cout << "========================================" << endl;
    cout << "1. Insertar estudiante" << endl;
    cout << "2. Buscar estudiante por cédula" << endl;
    cout << "3. Eliminar estudiante" << endl;
    cout << "4. Recorrido Inorden" << endl;
    cout << "5. Recorrido Preorden" << endl;
    cout << "6. Recorrido Postorden" << endl;
    cout << "7. Recorrido por niveles (BFS)" << endl;
    cout << "8. Contar estudiantes" << endl;
    cout << "9. Calcular altura del árbol" << endl;
    cout << "10. Mostrar estudiante con mayor nota" << endl;
    cout << "11. Mostrar estudiante con menor nota" << endl;
    cout << "12. Mostrar estudiantes aprobados" << endl;
    cout << "13. Mostrar estudiantes reprobados" << endl;
    cout << "14. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Seleccione una opción: ";
}

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ArbolBinario arbol;
    int opcion;
    string cedula, apellidos, nombres, carrera;
    double nota;
    int nivel;
    
    // Datos de ejemplo
    cout << "=== SISTEMA DE ÁRBOL BINARIO DE BÚSQUEDA ===" << endl;
    cout << "Insertando estudiantes de ejemplo..." << endl;
    
    arbol.insertarEstudiante(Estudiante("1234567890", "Garcia", "Ana", 8.5, "Sistemas", 5));
    arbol.insertarEstudiante(Estudiante("0987654321", "Lopez", "Juan", 6.0, "Civil", 3));
    arbol.insertarEstudiante(Estudiante("1112223334", "Ramirez", "Maria", 9.0, "Electrónica", 7));
    arbol.insertarEstudiante(Estudiante("5556667778", "Torres", "Carlos", 5.5, "Mecánica", 2));
    arbol.insertarEstudiante(Estudiante("9998887776", "Flores", "Laura", 7.8, "Sistemas", 4));
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "\n--- INSERTAR NUEVO ESTUDIANTE ---" << endl;
                cout << "Ingrese cédula (10 dígitos): ";
                cin >> cedula;
                if (cedula.length() != 10) {
                    cout << "La cédula debe tener 10 dígitos." << endl;
                    limpiarBuffer();
                    break;
                }
                cout << "Ingrese apellidos: ";
                limpiarBuffer();
                getline(cin, apellidos);
                cout << "Ingrese nombres: ";
                getline(cin, nombres);
                cout << "Ingrese nota final (0-10): ";
                cin >> nota;
                if (nota < 0 || nota > 10) {
                    cout << "La nota debe estar entre 0 y 10." << endl;
                    break;
                }
                cout << "Ingrese carrera: ";
                limpiarBuffer();
                getline(cin, carrera);
                cout << "Ingrese nivel (1-10): ";
                cin >> nivel;
                if (nivel < 1 || nivel > 10) {
                    cout << "El nivel debe estar entre 1 y 10." << endl;
                    break;
                }
                arbol.insertarEstudiante(Estudiante(cedula, apellidos, nombres, nota, carrera, nivel));
                break;
                
            case 2:
                cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
                cout << "Ingrese cédula: ";
                cin >> cedula;
                arbol.buscarEstudiante(cedula);
                break;
                
            case 3:
                cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;
                cout << "Ingrese cédula: ";
                cin >> cedula;
                arbol.eliminarEstudiante(cedula);
                break;
                
            case 4:
                arbol.recorridoInorden();
                break;
            case 5:
                arbol.recorridoPreorden();
                break;
            case 6:
                arbol.recorridoPostorden();
                break;
            case 7:
                arbol.recorridoPorNiveles();
                break;
            case 8:
                arbol.contarNodos();
                break;
            case 9:
                arbol.calcularAltura();
                break;
            case 10:
                arbol.buscarNotaMayor();
                break;
            case 11:
                arbol.buscarNotaMenor();
                break;
            case 12:
                arbol.mostrarAprobados();
                break;
            case 13:
                arbol.mostrarReprobados();
                break;
            case 14:
                cout << "\n¡Gracias por usar el sistema!" << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 14);
    
    return 0;
}