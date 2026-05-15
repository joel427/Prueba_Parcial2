#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "Nodo.h"
#include <queue>

class ArbolBinario {
private:
    Nodo* raiz;
    
    Nodo* insertarRecursivo(Nodo* nodo, Estudiante estudiante);
    Nodo* buscarRecursivo(Nodo* nodo, string cedula);
    Nodo* eliminarRecursivo(Nodo* nodo, string cedula);
    Nodo* encontrarMinimo(Nodo* nodo);
    
    void inordenRecursivo(Nodo* nodo);
    void preordenRecursivo(Nodo* nodo);
    void postordenRecursivo(Nodo* nodo);
    
    int contarNodosRecursivo(Nodo* nodo);
    int calcularAlturaRecursivo(Nodo* nodo);
    
    void buscarMayorNotaRecursivo(Nodo* nodo, Estudiante*& mayor);
    void buscarMenorNotaRecursivo(Nodo* nodo, Estudiante*& menor);
    void mostrarAprobadosRecursivo(Nodo* nodo);
    void mostrarReprobadosRecursivo(Nodo* nodo);

public:
    ArbolBinario();
    ~ArbolBinario();
    
    void insertarEstudiante(Estudiante estudiante);
    void buscarEstudiante(string cedula);
    void eliminarEstudiante(string cedula);
    
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void recorridoPorNiveles();
    
    int contarNodos();
    int calcularAltura();
    
    void buscarNotaMayor();
    void buscarNotaMenor();
    void mostrarAprobados();
    void mostrarReprobados();
    
    bool estaVacio();
};

#endif