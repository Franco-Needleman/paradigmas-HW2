#include "ejer3.hpp"
#include <cmath>
#include <sstream>

// Entero
Entero::Entero(int i) : val(i) {}

shared_ptr<Numero> Entero::operator+(const Numero& e) const {
    const Entero& ent = dynamic_cast<const Entero&>(e);
    return make_shared<Entero>(val + ent.val);
}

shared_ptr<Numero> Entero::operator-(const Numero& e) const {
    const Entero& ent = dynamic_cast<const Entero&>(e);
    return make_shared<Entero>(val - ent.val);
}

shared_ptr<Numero> Entero::operator*(const Numero& e) const {
    const Entero& ent = dynamic_cast<const Entero&>(e);
    return make_shared<Entero>(val * ent.val);
}

string Entero::to_string() const {
    return std::to_string(val);
}

// Real
Real::Real(double i) : val(i) {}

shared_ptr<Numero> Real::operator+(const Numero& e) const {
    const Real& re = dynamic_cast<const Real&>(e);
    return make_shared<Real>(val + re.val);
}

shared_ptr<Numero> Real::operator-(const Numero& e) const {
    const Real& re = dynamic_cast<const Real&>(e);
    return make_shared<Real>(val - re.val);
}

shared_ptr<Numero> Real::operator*(const Numero& e) const {
    const Real& re = dynamic_cast<const Real&>(e);
    return make_shared<Real>(val * re.val);
}

string Real::to_string() const {
    return std::to_string(val);
}

// Complejo
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

shared_ptr<Numero> Complejo::operator+(const Numero& e) const {
    const Complejo& c = dynamic_cast<const Complejo&>(e);
    return make_shared<Complejo>(real + c.real, imaginario + c.imaginario);
}

shared_ptr<Numero> Complejo::operator-(const Numero& e) const {
    const Complejo& c = dynamic_cast<const Complejo&>(e);
    return make_shared<Complejo>(real - c.real, imaginario - c.imaginario);
}

shared_ptr<Numero> Complejo::operator*(const Numero& e) const {
    const Complejo& c = dynamic_cast<const Complejo&>(e);
    return make_shared<Complejo>(
        real * c.real - imaginario * c.imaginario,
        real * c.imaginario + imaginario * c.real
    );
}

string Complejo::to_string() const {
    string s;
    if (imaginario >= 0)
       s=std::to_string(real)+ "+"+std::to_string(imaginario) + "i";
    else
    s=std::to_string(real)+ std::to_string(imaginario) + "i";
    return s;   
}
