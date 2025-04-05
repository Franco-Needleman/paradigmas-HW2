#include "ejer4.cpp"


// Función para ingresar un número decimal de forma segura
double pedir_double(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Entrada invalida. Por favor ingrese un numero.\n";
        } else {
            cin.ignore(99999, '\n');
            return valor;
        }
    }
}



int main() {
    vector<shared_ptr<Ctabnc>> cuentas;

    string titular;
    double monto_ahorro, monto_corriente;

    cout << "--- Crear Cuentas (Ahorro + Corriente) ---\n";
    cout << "Titular: ";
    getline(cin, titular);

    monto_ahorro = pedir_double("Monto inicial en Ahorro: ");
    monto_corriente = pedir_double("Monto inicial en Corriente: ");

    auto ahorro = make_shared<Ahorro>(monto_ahorro, titular);
    cuentas.push_back(ahorro);

    auto corriente = make_shared<Corriente>(monto_corriente, titular, ahorro.get());
    cuentas.push_back(corriente);

    int opcion;
    do {
        cout << "\n--- Menu de Operaciones ---\n";// no use << endl pq es mas rapido de esta maner y no afecta a la funcionalidad
        cout << "1. Depositar en Ahorro\n";
        cout << "2. Depositar en Corriente\n";
        cout << "3. Retirar de Ahorro\n";
        cout << "4. Retirar de Corriente\n";
        cout << "5. Mostrar info Ahorro\n";
        cout << "6. Mostrar info Corriente\n";
        cout << "0. Salir\n";

        opcion = pedir_double("Opcion: ");

        switch (opcion) {
            case 1: {
                double monto = pedir_double("Monto a depositar en Ahorro: ");
                cuentas[0]->depo(monto);
                break;
            }
            case 2: {
                double monto = pedir_double("Monto a depositar en Corriente: ");
                cuentas[1]->depo(monto);
                break;
            }
            case 3: {
                double monto = pedir_double("Monto a retirar de Ahorro: ");
                cuentas[0]->retirar(monto);
                break;
            }
            case 4: {
                double monto = pedir_double("Monto a retirar de Corriente: ");
                cuentas[1]->retirar(monto);
                break;
            }
            case 5:
                cuentas[0]->mostrar_info();
                break;
            case 6:
                cuentas[1]->mostrar_info();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "opcion invalida\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}