#include "ejer1.cpp"


int pedirEntero(const string& mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(99999, '\n'); // Ignora la entrada inválida
            cout << "Entrada inválida. Por favor ingrese un número entero válido." << endl;
        } else {
            cin.ignore(99999, '\n'); // Limpia cualquier carácter adicional
            return numero;
        }
    }
}


void mostrarMenu() {
    cout << "\n--- MENÚ PRINCIPAL ---\n"; // no use << endl pq es mas rapido de esta maner y no afecta a la funcionalidad
    cout << "1. Crear nuevo tiempo\n";
    cout << "2. Mostrar hora completa\n";
    cout << "3. Mostrar solo hora\n";
    cout << "4. Mostrar solo minuto\n";
    cout << "5. Mostrar solo segundo\n";
    cout << "6. Mostrar AM/PM\n";
    cout << "7. Mostrar en formato 24 horas\n";
    cout << "8. Modificar hora\n";
    cout << "9. Modificar minuto\n";
    cout << "10. Modificar segundo\n";
    cout << "11. Modificar AM/PM (0 = AM, 1 = PM)\n";
    cout << "0. Salir\n";
}

int main() {
    Tiempo t= Tiempo();
    int opcion = -1;

    do {
        mostrarMenu();
        opcion = pedirEntero("Seleccione una opción: ");

        switch (opcion) {
            case 1: {
                int tipo;
                cout << "\n--- Crear nuevo Tiempo ---\n";
                cout << "1. sin datos\n";
                cout << "2. solo hora\n";
                cout << "3. horas y minutos\n";
                cout << "4. horas, minutos y segundos\n";
                cout << "5. horas, minutos, segundos y es am/pm\n";
                tipo = pedirEntero("Seleccione una opción: ");

                int h, m, s, pm;
                do{
                    switch (tipo) {
                        case 1:
                            t = Tiempo();
                            break;
                        case 2:
        
                            h = pedirEntero("Hora (1-12): ");
                            t = Tiempo(h);
                            break;
                        case 3:
                            h = pedirEntero("Hora (1-12): ");
                            
                            m = pedirEntero("Minuto (0-59): ");
                            t = Tiempo(h, m);
                            break;
                        case 4:
                            h = pedirEntero("Hora (1-12): ");
                            
                            m = pedirEntero("Minuto (0-59): ");
                            
                            s= pedirEntero("Segundo (0-59): ");
                            
                            t = Tiempo(h, m, s);
                            break;
                        case 5:
                            
                            h = pedirEntero("Hora (1-12): ");

                            m = pedirEntero("Minuto (0-59): ");

                            s= pedirEntero("Segundo (0-59): ");

                            pm = pedirEntero("AM (0) o PM (cualquier numero diferente a 0): ");

                            t = Tiempo(h, m, s, pm);

                                
                            
                            break;
                        default:
                            cout << "opcion invalida\n";
                            break;
                    }
                } while (!t.check_tiempo());

                cout << "Tiempo creado.\n";
                break;
            }

            case 2:
                t.mostrarTiempo();
                break;
            case 3:
                t.mostrarHora();
                break;
            case 4:
                t.mostrarMinuto();
                break;
            case 5:
                t.mostrarSegundo();
                break;
            case 6:
                t.mostrarpm();
                break;
            case 7:
                t.mostrar24();
                break;

            case 8: {
                int nuevaHora;
                nuevaHora = pedirEntero("nueva hora (1-12): ");
                t.setHora(nuevaHora);
                while(!t.check_tiempo()){
                    nuevaHora = pedirEntero("nueva hora (1-12): ");
                    t.setHora(nuevaHora);
                }
                break;
            }

            case 9: {
                int nuevoMinuto;
                nuevoMinuto = pedirEntero("nuevo minuto (0-59): ");
                t.setMinuto(nuevoMinuto);
                while(!t.check_tiempo()){
                    nuevoMinuto = pedirEntero("nuevo minuto (0-59): ");
                    t.setMinuto(nuevoMinuto);
                }
                break;
            }

            case 10: {
                int nuevoSegundo;
                nuevoSegundo= pedirEntero("Nuevo segundo (0-59): ");
                t.setSegundo(nuevoSegundo);
                while(!t.check_tiempo()){
                    nuevoSegundo= pedirEntero("Nuevo segundo (0-59): ");
                    t.setSegundo(nuevoSegundo);
                }
                break;
            }

            case 11:{
                int nuevoPM;
                nuevoPM = pedirEntero("AM (0) o PM (cualquier numero diferente a 0): ");
                t.setEsPM(nuevoPM);
                break;
            }

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
