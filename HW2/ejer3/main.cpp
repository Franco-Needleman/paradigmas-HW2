#include "ejer3.cpp"
#include <iostream>
using namespace std;

int main() {
    // === ENTEROS ===
    auto e1 = Entero(5);
    auto e2 = Entero(3);

    auto e_suma = e1+e2;
    auto e_resta = e1-e2;
    auto e_producto = e1*e2;

    cout << "ENTERO:\n";
    cout << "e1 = " << e1.to_string() << "\n";
    cout << "e2 = " << e2.to_string() << "\n";
    cout << "e1 + e2 = " << e_suma->to_string() << "\n";
    cout << "e1 - e2 = " << e_resta->to_string() << "\n";
    cout << "e1 * e2 = " << e_producto->to_string() << "\n\n";

    // === REALES ===
    auto r1 = Real(4.5);
    auto r2 = Real(2.0);

    auto r_suma = r1+r2;
    auto r_resta = r1-r2;
    auto r_producto = r1*r2;

    cout << "REAL:\n";
    cout << "r1 = " << r1.to_string() << "\n";
    cout << "r2 = " << r2.to_string() << "\n";
    cout << "r1 + r2 = " << r_suma->to_string() << "\n";
    cout << "r1 - r2 = " << r_resta->to_string() << "\n";
    cout << "r1 * r2 = " << r_producto->to_string() << "\n\n";

    // === COMPLEJOS ===
    auto c1 = Complejo(4.5, 2.0);
    auto c2 = Complejo(2.0, 4.5);

    auto c_suma = c1+c2;
    auto c_resta = c1-c2;
    auto c_producto = c1*c2;

    cout << "COMPLEJO:\n";
    cout << "c1 = " << c1.to_string() << "\n";
    cout << "c2 = " << c2.to_string() << "\n";
    cout << "c1 + c2 = " << c_suma->to_string() << "\n";
    cout << "c1 - c2 = " << c_resta->to_string() << "\n";
    cout << "c1 * c2 = " << c_producto->to_string() << "\n";

    return 0;
}