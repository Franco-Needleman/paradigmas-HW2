#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

class Curso;

class Estudiante {
protected:
    string nombre;
    int legajo;
    vector<pair<string, float>> cursos;

public:
    Estudiante(string n, int l, vector<pair<string, float>> c);

    string getnombre() const;
    int getlegajo() const;
    float getPromedio() const;

    void show_info() const;
    void addcurso(string c, float nota);

    bool operator==(const Estudiante& otro) const;
    bool operator<(const Estudiante& otro) const;
};

#endif
#ifndef CURSO_HPP
#define CURSO_HPP

class Curso {
protected:
    string nombre;
    vector<Estudiante> alumnos;
    int tamaño;

public:
    Curso(Estudiante e, string n);
    Curso(string n);

    // shallow copy constructor
    Curso( const Curso& c, string n);

    void addestudiante(Estudiante e);
    string getNombre() const;
    void removeestudiante(Estudiante e);
    bool searchestudiante(int l);
    bool full() const;
    void alumnosalfabetica();
};

#endif
/*la relacion entre las clases, estudiante y curso, es de agregacion ya que curso(whole) contiene a estudiantes(parts) y estan estrechamente relacionados, 
sin embargo, ambas partes pueden existir por su cuenta sin depender ni relacionarse con la otra*/