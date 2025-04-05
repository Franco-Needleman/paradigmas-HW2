#ifndef TIEMPO_HPP
#define TIEMPO_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Tiempo {
private:
    int hora;
    int minuto;
    int segundo;
    bool es_pm;

public:
    
    Tiempo();
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h, int m, int s);
    Tiempo(int h, int m, int s, bool pm);

    void setHora(int h);
    void setMinuto(int m);
    void setSegundo(int s);
    void setEsPM(bool pm);

    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;
    bool getEsPM() const;

    bool check_tiempo();

    void mostrarTiempo() const;
    void mostrarHora() const;
    void mostrarMinuto() const;
    void mostrarSegundo() const;
    void mostrarpm() const;
    void mostrar24() const;
};

#endif
