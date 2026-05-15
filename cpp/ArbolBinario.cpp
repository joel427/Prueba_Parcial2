#include "ArbolBinario.h"
#include <iostream>
#include <iomanip>  
#include <queue>
#include <algorithm>

using namespace std;

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

ArbolBinario::~ArbolBinario() {}

Nodo* ArbolBinario::insertarRecursivo(Nodo* nodo, Estudiante estudiante) {
    if (nodo == nullptr) {
        return new Nodo(estudiante);
    }
    
    if (estudiante < nodo->estudiante) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, estudiante);
    } else if (estudiante > nodo->estudiante) {
        nodo->derecho = insertarRecursivo(nodo->derecho, estudiante);
    } else {
        cout << "Error: Ya existe un estudiante con la cédula " << estudiante.getCedula() << endl;
    }
    
    return nodo;
}

void ArbolBinario::insertarEstudiante(Estudiante estudiante) {
    raiz = insertarRecursivo(raiz, estudiante);
    cout << "Estudiante insertado correctamente." << endl;
}

Nodo* ArbolBinario::buscarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) {
        return nullptr;
    }
    
    if (cedula == nodo->estudiante.getCedula()) {
        return nodo;
    } else if (cedula < nodo->estudiante.getCedula()) {
        return buscarRecursivo(nodo->izquierdo, cedula);
    } else {
        return buscarRecursivo(nodo->derecho, cedula);
    }
}

void ArbolBinario::buscarEstudiante(string cedula) {
    Nodo* resultado = buscarRecursivo(raiz, cedula);
    
    if (resultado != nullptr) {
        cout << "\n--- ESTUDIANTE ENCONTRADO ---" << endl;
        cout << "Cédula    : " << resultado->estudiante.getCedula() << endl;
        cout << "Apellidos : " << resultado->estudiante.getApellidos() << endl;
        cout << "Nombres   : " << resultado->estudiante.getNombres() << endl;
        cout << "Nota final: " << resultado->estudiante.getNotaFinal() << endl;
        cout << "Carrera   : " << resultado->estudiante.getCarrera() << endl;
        cout << "Nivel     : " << resultado->estudiante.getNivel() << endl;
    } else {
        cout << "No se encontró ningún estudiante con cédula: " << cedula << endl;
    }
}

Nodo* ArbolBinario::encontrarMinimo(Nodo* nodo) {
    while (nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

Nodo* ArbolBinario::eliminarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) {
        return nullptr;
    }
    
    if (cedula < nodo->estudiante.getCedula()) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, cedula);
    } else if (cedula > nodo->estudiante.getCedula()) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, cedula);
    } else {
        if (nodo->izquierdo == nullptr) {
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (nodo->derecho == nullptr) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }
        
        Nodo* temp = encontrarMinimo(nodo->derecho);
        nodo->estudiante = temp->estudiante;
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->estudiante.getCedula());
    }
    
    return nodo;
}

void ArbolBinario::eliminarEstudiante(string cedula) {
    if (buscarRecursivo(raiz, cedula) == nullptr) {
        cout << "No se encontró el estudiante con cédula: " << cedula << endl;
        return;
    }
    
    raiz = eliminarRecursivo(raiz, cedula);
    cout << "Estudiante eliminado correctamente." << endl;
}

void ArbolBinario::inordenRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->izquierdo);
        nodo->estudiante.mostrar();
        inordenRecursivo(nodo->derecho);
    }
}

void ArbolBinario::recorridoInorden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- RECORRIDO INORDEN ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    inordenRecursivo(raiz);
}

void ArbolBinario::preordenRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        nodo->estudiante.mostrar();
        preordenRecursivo(nodo->izquierdo);
        preordenRecursivo(nodo->derecho);
    }
}

void ArbolBinario::recorridoPreorden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- RECORRIDO PREORDEN ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    preordenRecursivo(raiz);
}

void ArbolBinario::postordenRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->izquierdo);
        postordenRecursivo(nodo->derecho);
        nodo->estudiante.mostrar();
    }
}

void ArbolBinario::recorridoPostorden() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- RECORRIDO POSTORDEN ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    postordenRecursivo(raiz);
}

void ArbolBinario::recorridoPorNiveles() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- RECORRIDO POR NIVELES (BFS) ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    
    queue<Nodo*> cola;
    cola.push(raiz);
    
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        actual->estudiante.mostrar();
        
        if (actual->izquierdo != nullptr) {
            cola.push(actual->izquierdo);
        }
        if (actual->derecho != nullptr) {
            cola.push(actual->derecho);
        }
    }
}

int ArbolBinario::contarNodosRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1 + contarNodosRecursivo(nodo->izquierdo) + contarNodosRecursivo(nodo->derecho);
}

int ArbolBinario::contarNodos() {
    int total = contarNodosRecursivo(raiz);
    cout << "Total de estudiantes en el árbol: " << total << endl;
    return total;
}

int ArbolBinario::calcularAlturaRecursivo(Nodo* nodo) {
    if (nodo == nullptr) return -1;
    return 1 + max(calcularAlturaRecursivo(nodo->izquierdo), calcularAlturaRecursivo(nodo->derecho));
}

int ArbolBinario::calcularAltura() {
    int altura = calcularAlturaRecursivo(raiz);
    cout << "Altura del árbol: " << altura << endl;
    return altura;
}

void ArbolBinario::buscarMayorNotaRecursivo(Nodo* nodo, Estudiante*& mayor) {
    if (nodo != nullptr) {
        if (mayor == nullptr || nodo->estudiante.getNotaFinal() > mayor->getNotaFinal()) {
            mayor = &nodo->estudiante;
        }
        buscarMayorNotaRecursivo(nodo->izquierdo, mayor);
        buscarMayorNotaRecursivo(nodo->derecho, mayor);
    }
}

void ArbolBinario::buscarNotaMayor() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    Estudiante* mayor = nullptr;
    buscarMayorNotaRecursivo(raiz, mayor);
    
    if (mayor != nullptr) {
        cout << "\n--- ESTUDIANTE CON MAYOR NOTA ---" << endl;
        cout << "Cédula    : " << mayor->getCedula() << endl;
        cout << "Apellidos : " << mayor->getApellidos() << endl;
        cout << "Nombres   : " << mayor->getNombres() << endl;
        cout << "Nota final: " << mayor->getNotaFinal() << endl;
        cout << "Carrera   : " << mayor->getCarrera() << endl;
        cout << "Nivel     : " << mayor->getNivel() << endl;
    }
}

void ArbolBinario::buscarMenorNotaRecursivo(Nodo* nodo, Estudiante*& menor) {
    if (nodo != nullptr) {
        if (menor == nullptr || nodo->estudiante.getNotaFinal() < menor->getNotaFinal()) {
            menor = &nodo->estudiante;
        }
        buscarMenorNotaRecursivo(nodo->izquierdo, menor);
        buscarMenorNotaRecursivo(nodo->derecho, menor);
    }
}

void ArbolBinario::buscarNotaMenor() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    Estudiante* menor = nullptr;
    buscarMenorNotaRecursivo(raiz, menor);
    
    if (menor != nullptr) {
        cout << "\n--- ESTUDIANTE CON MENOR NOTA ---" << endl;
        cout << "Cédula    : " << menor->getCedula() << endl;
        cout << "Apellidos : " << menor->getApellidos() << endl;
        cout << "Nombres   : " << menor->getNombres() << endl;
        cout << "Nota final: " << menor->getNotaFinal() << endl;
        cout << "Carrera   : " << menor->getCarrera() << endl;
        cout << "Nivel     : " << menor->getNivel() << endl;
    }
}

void ArbolBinario::mostrarAprobadosRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        mostrarAprobadosRecursivo(nodo->izquierdo);
        if (nodo->estudiante.aprobado()) {
            nodo->estudiante.mostrar();
        }
        mostrarAprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBinario::mostrarAprobados() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- ESTUDIANTES APROBADOS (Nota >= 7) ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    mostrarAprobadosRecursivo(raiz);
}

void ArbolBinario::mostrarReprobadosRecursivo(Nodo* nodo) {
    if (nodo != nullptr) {
        mostrarReprobadosRecursivo(nodo->izquierdo);
        if (!nodo->estudiante.aprobado()) {
            nodo->estudiante.mostrar();
        }
        mostrarReprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBinario::mostrarReprobados() {
    if (estaVacio()) {
        cout << "El árbol está vacío." << endl;
        return;
    }
    
    cout << "\n--- ESTUDIANTES REPROBADOS (Nota < 7) ---" << endl;
    cout << left << setw(12) << "Cédula"
         << setw(20) << "Apellidos"
         << setw(15) << "Nombres"
         << setw(8) << "Nota"
         << setw(15) << "Carrera"
         << setw(6) << "Nivel" << endl;
    cout << string(76, '-') << endl;
    mostrarReprobadosRecursivo(raiz);
}

bool ArbolBinario::estaVacio() {
    return raiz == nullptr;
}