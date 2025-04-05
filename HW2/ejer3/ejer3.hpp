#ifndef NUMS_HPP
#define NUMS_HPP

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

class Numero{
public:
    virtual shared_ptr<Numero> operator+(const Numero& e) const = 0;
    virtual shared_ptr<Numero> operator-(const Numero& e) const = 0;
    virtual shared_ptr<Numero> operator*(const Numero& e) const = 0;
    virtual string to_string() const = 0;
    virtual ~Numero() {};
};

#endif
#ifndef ENTERO_HPP
#define ENTERO_HPP

class Entero : public Numero{
private:
    int val;
public:
    Entero(int i);
    shared_ptr<Numero> operator+(const Numero& e) const override;
    shared_ptr<Numero> operator*(const Numero& e) const override;
    shared_ptr<Numero> operator-(const Numero& e) const override;
    string to_string() const override;
};

#endif
#ifndef REAL_HPP
#define REAL_HPP

class Real : public Numero{
private:
    double val;
public:
    Real(double i);
    shared_ptr<Numero> operator+(const Numero& e) const override;
    shared_ptr<Numero> operator*(const Numero& e) const override;
    shared_ptr<Numero> operator-(const Numero& e) const override;
    string to_string() const override;
};

#endif
#ifndef COMPLEJO_HPP
#define COMPLEJO_HPP

class Complejo : public Numero{
private:
    double real;
    double imaginario;
public:
    Complejo(double r, double i);
    shared_ptr<Numero> operator+(const Numero& e) const override;
    shared_ptr<Numero> operator*(const Numero& e) const override;
    shared_ptr<Numero> operator-(const Numero& e) const override;
    string to_string() const override;
};

#endif
