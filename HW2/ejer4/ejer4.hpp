#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;
#ifndef CTABNC_HPP
#define CTABNC_HPP




class Ctabnc {
protected:
    double dinero;
    string titular;
public:

    Ctabnc(double d, string t);

    void depo(double d);
    virtual void retirar(double d) = 0;
    virtual void mostrar_info() = 0;
};


#endif
#ifndef AHORRO_HPP
#define AHORRO_HPP
class Corriente;



class Ahorro : public Ctabnc {
private:
    int cant_info;
public:
    Ahorro(double d, string t);
    void retirar(double d) ;
    void mostrar_info() ;
    friend class Corriente;
};

#endif
#ifndef CORRIENTE_HPP
#define CORRIENTE_HPP

class Corriente : public Ctabnc {
    private:
        Ahorro* cta_ahorro;
    public:
        Corriente(double d, string t, Ahorro* cta);
        void retirar(double d) ;
        void mostrar_info() ;
};



#endif