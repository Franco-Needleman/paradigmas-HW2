#include "ejer1.hpp"
 
Tiempo::Tiempo() : hora(0), minuto(0), segundo(0), es_pm(false) {}

Tiempo::Tiempo(int h) : hora(h), minuto(0), segundo(0), es_pm(false) {}

Tiempo::Tiempo(int h, int m) : hora(h), minuto(m), segundo(0), es_pm(false) {}

Tiempo::Tiempo(int h, int m, int s) : hora(h), minuto(m), segundo(s), es_pm(false) {}

// Constructor con parámetros opcionales
Tiempo::Tiempo(int h, int m, int s, bool pm) : hora(h), minuto(m), segundo(s), es_pm(pm) {}


// Setters
void Tiempo::setHora(int h) { hora = h;}
void Tiempo::setMinuto(int m) { minuto = m;}
void Tiempo::setSegundo(int s) { segundo = s;}
void Tiempo::setEsPM(bool pm) { es_pm = pm;}

// Getters
int Tiempo::getHora() const { return hora; }
int Tiempo::getMinuto() const { return minuto; }
int Tiempo::getSegundo() const { return segundo; }
bool Tiempo::getEsPM() const { return es_pm; }

bool Tiempo::check_tiempo(){
    if(this->getHora() < 0 || this->getHora() > 12 || this->getMinuto() < 0 || this->getMinuto() > 60 || this->getSegundo() < 0 || this->getSegundo() > 60 || (es_pm!=0&&es_pm!=1)){
        std::cout << "valor ingresado incorrecto" << std::endl;
        return false;
        }
    return true;
}

//las funciones mostrar ajustan cada valor a ocupar dos caracteres
void Tiempo::mostrarTiempo() const {
    std::cout << std::setfill('0') << std::setw(2) << hora << "h, "
                << std::setw(2) << minuto << "m, "
                << std::setw(2) << segundo << "s "
                << (es_pm ? "p.m." : "a.m.") << std::endl;
}

void Tiempo::mostrarHora() const {
    std::cout << std::setfill('0') << std::setw(2) << hora << "h "<< std::endl;
}

void Tiempo::mostrarMinuto() const {
    std::cout << std::setfill('0') << std::setw(2) << minuto << "m "<< std::endl;
}

void Tiempo::mostrarSegundo() const {
    std::cout << std::setfill('0') << std::setw(2) << segundo << "s "<< std::endl;
}

void Tiempo::mostrarpm() const {
    std::cout << (es_pm ? "p.m." : "a.m.") << std::endl;
}

void Tiempo::mostrar24() const {
    if (this->getEsPM()){
        std::cout << std::setfill('0') << std::setw(2) << hora+12 << "h, "//si es pm suma 12 pq masaron 12 horas antes del mediodia
                << std::setw(2) << minuto << "m, "
                << std::setw(2) << segundo << "s " << std::endl;
            }
    else {
        std::cout << std::setfill('0') << std::setw(2) << hora << "h, "
                << std::setw(2) << minuto << "m, "
                << std::setw(2) << segundo << "s "<< std::endl;
    }

}



