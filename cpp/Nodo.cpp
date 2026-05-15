#include "Nodo.h"

Nodo::Nodo() {
    izquierdo = nullptr;
    derecho = nullptr;
}

Nodo::Nodo(Estudiante est) {
    estudiante = est;
    izquierdo = nullptr;
    derecho = nullptr;
}