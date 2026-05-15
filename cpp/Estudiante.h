#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

class Estudiante {
private:
    string cedula;
    string apellidos;
    string nombres;
    double notaFinal;
    string carrera;
    int nivel;

public:
    Estudiante();
    Estudiante(string ced, string ape, string nom, double nota, string carr, int niv);
    
    string getCedula() const;
    string getApellidos() const;
    string getNombres() const;
    double getNotaFinal() const;
    string getCarrera() const;
    int getNivel() const;
    
    void setCedula(string ced);
    void setApellidos(string ape);
    void setNombres(string nom);
    void setNotaFinal(double nota);
    void setCarrera(string carr);
    void setNivel(int niv);
    
    bool operator<(const Estudiante& otro) const;
    bool operator>(const Estudiante& otro) const;
    bool operator==(const Estudiante& otro) const;
    
    void mostrar() const;
    bool aprobado() const;
};

#endif