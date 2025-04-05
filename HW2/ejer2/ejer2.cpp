#include "ejer2.hpp"


Estudiante::Estudiante(string n, int l, vector<pair<string, float>> c) 
: nombre(n), legajo(l), cursos(c) {}


string Estudiante::getnombre() const { return nombre; }

int Estudiante::getlegajo() const { return legajo; }

float Estudiante::getPromedio() const {
    float sumaNotas = 0.0;
    for (const auto& curso : cursos) {
        sumaNotas += curso.second;
    }
    return cursos.empty() ? 0.0f : sumaNotas / cursos.size();
}

void Estudiante::show_info()const{
    cout <<"nombre: "<< nombre <<" legajo: " << legajo  << " promedio: " << this->getPromedio()  << endl;
}

void Estudiante::addcurso(string c, float nota){
    cursos.push_back({c, nota});
}

bool Estudiante::operator==(const Estudiante& otro) const{
    return legajo == otro.getlegajo();
}

bool Estudiante::operator<(const Estudiante& otro) const {
    return nombre < otro.nombre;  
}

Curso::Curso(Estudiante e, string n) : nombre(n), tamaño(1)  { alumnos.push_back(e); } 
Curso::Curso(string n) : nombre(n), alumnos(), tamaño(0)  {}

Curso::Curso(const Curso& c, string n):nombre(n), alumnos(c.alumnos) ,tamaño(c.tamaño){}
/*elegi hacer shallow copy debido a que si bien los cursos comparten estudiantes no es logico que exista una "copia"
del estudiante, los dos cursos apuntan al mismo estudiante para indicar que pertenecen al mismo y uno ov arios de los cursos dejarian de apuntar 
en caso de que se de de baja*/

void Curso::addestudiante (Estudiante e){
    if (tamaño < 20){
        alumnos.push_back(e);
        tamaño++;
    } else {
        cout << "tamaño maximo alcanzado" << endl;
    }
}

string Curso::getNombre() const {
    return nombre;
}

void Curso::removeestudiante(Estudiante e){
    for (auto it = alumnos.begin(); it != alumnos.end(); ++it){
        if (*it == e){
            alumnos.erase(it);
            tamaño--;
            break;
        }
    }
}

bool Curso::searchestudiante(int l){
    for (Estudiante e2 : alumnos ){
        if (e2.getlegajo() == l){
            return true;
        }
    }
    return false;
}

bool Curso::full() const{
    return tamaño == 20;
}

void Curso::alumnosalfabetica(){
    sort(alumnos.begin(), alumnos.end());// esto funciona porque esta sobrecargado el comparador <
    for (Estudiante e2 : alumnos ){
        e2.show_info();
    }
}

