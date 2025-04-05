#include "ejer2.cpp"

float pedirEntero(const string& mensaje) {
    float numero;// uso float para tambien usar la funcion para notas, en el caso que se cambie a int se va a redondear y no va a generar problemas
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(99999, '\n');
            cout << "Entrada inválida. Por favor ingrese un número entero válido." << endl;
        } else {
            cin.ignore(99999, '\n');
            return numero;
        }
    }
}

string pedirString(const string& mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

Curso* buscarCurso(vector<Curso>& cursos, const string& nombreCurso) {
    for (Curso& curso : cursos) {//recorro el vector de cursos
        if (curso.getNombre() == nombreCurso) {
            return &curso;
        }
    }
    return nullptr;
}

Estudiante* buscarEstudiante(vector<Estudiante>& estudiantes, int legajo) {
    for (Estudiante& est : estudiantes) {// recorro el vector estudiantes
        if (est.getlegajo() == legajo) {
            return &est;
        }
    }
    return nullptr;
}

int main() {
    vector<Curso> cursos;
    vector<Estudiante> estudiantes;

    int opcion;
    do {
        cout << "\n--- Menú de Opciones ---\n";// no use << endl pq es mas rapido de esta maner y no afecta a la funcionalidad
        cout << "1. Crear curso\n";
        cout << "2. Agregar estudiante a curso\n";
        cout << "3. Listar estudiantes de curso ordenados\n";
        cout << "4. Buscar estudiante por legajo en curso\n";
        cout << "5. Eliminar estudiante de curso\n";
        cout << "6. Mostrar información de un estudiante\n";
        cout << "7. Agregar curso y nota a estudiante\n";
        cout << "0. Salir\n";
        opcion = pedirEntero("Seleccione una opción: ");

        switch(opcion) {
            case 1: {
                string nombreCurso = pedirString("Ingrese nombre del curso: ");
                cursos.push_back(Curso(nombreCurso));
                cout << "Curso creado correctamente.\n";
                break;
            }
            case 2: {
                if (cursos.empty()){
                    cout << "Primero debe crear un curso.\n";
                    break;
                }
                string nombre = pedirString("Ingrese nombre del estudiante: ");
                int legajo = pedirEntero("Ingrese legajo del estudiante: ");
                string nombreCurso = pedirString("Ingrese nombre del curso para agregar al estudiante: ");

                Curso* cursoPtr = buscarCurso(cursos, nombreCurso);
                if (cursoPtr) {
                    Estudiante nuevoEstudiante(nombre, legajo, {});
                    cursoPtr->addestudiante(nuevoEstudiante);
                    estudiantes.push_back(nuevoEstudiante);
                    cout << "Estudiante agregado correctamente.\n";
                } else {
                    cout << "Curso no encontrado.\n";
                }
                break;
            }
            case 3: {
                string nombreCurso = pedirString("Ingrese nombre del curso: ");
                Curso* cursoPtr = buscarCurso(cursos, nombreCurso);
                if (cursoPtr) {
                    cursoPtr->alumnosalfabetica();
                } else {
                    cout << "Curso no encontrado.\n";
                }
                break;
            }
            case 4: {
                int legajo = pedirEntero("Ingrese legajo del estudiante: ");
                string nombreCurso = pedirString("Ingrese nombre del curso: ");
                Curso* cursoPtr = buscarCurso(cursos, nombreCurso);
                if (cursoPtr) {
                    if (cursoPtr->searchestudiante(legajo)) {
                        cout << "Estudiante encontrado en el curso.\n";
                    } else {
                        cout << "Estudiante no encontrado en el curso.\n";
                    }
                } else {
                    cout << "Curso no encontrado.\n";
                }
                break;
            }
            case 5: {
                int legajo = pedirEntero("Ingrese legajo del estudiante a eliminar: ");
                string nombreCurso = pedirString("Ingrese nombre del curso: ");
                Curso* cursoPtr = buscarCurso(cursos, nombreCurso);
                if (cursoPtr) {
                    cursoPtr->removeestudiante(Estudiante("", legajo, {}));
                    cout << "Estudiante eliminado del curso.\n";
                } else {
                    cout << "Curso no encontrado.\n";
                }
                break;
            }
            case 6: {
                int legajo = pedirEntero("Ingrese legajo del estudiante para mostrar información: ");
                Estudiante* estPtr = buscarEstudiante(estudiantes, legajo);
                if (estPtr) {
                    estPtr->show_info();
                } else {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 7: {
                int legajo = pedirEntero("Ingrese legajo del estudiante: ");
                string nombreCurso = pedirString("Ingrese nombre del curso: ");
                float nota = pedirEntero("ingrese nota del estudiante: ");
                

                Estudiante* estPtr = buscarEstudiante(estudiantes, legajo);
                if (estPtr) {
                    estPtr->addcurso(nombreCurso, nota);
                    cout << "Curso y nota agregados correctamente.\n";
                } else {
                    cout << "Estudiante no encontrado.\n";
                }
                break;
            }
            case 0:
                cout << "Saliendo del menú.\n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }

    } while(opcion != 0);

    return 0;
}
