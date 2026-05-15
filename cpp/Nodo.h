#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

class Nodo {
public:
    Estudiante estudiante;
    Nodo* izquierdo;
    Nodo* derecho;
    
    Nodo();
    Nodo(Estudiante est);
};

#endif