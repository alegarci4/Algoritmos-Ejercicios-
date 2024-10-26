#include <iostream>
#include <fstream>
int main() {
    // Escribir el archivo
    std::ofstream archivoSalida("fichero.txt");
    if (archivoSalida.is_open()) {
        archivoSalida << "Este es el archivo txt creado" << std::endl;
        archivoSalida.close();
    }

    // Lectura de archivo
    std::ifstream archivoEntrada("fichero.txt");
    if (archivoEntrada.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::cout << linea << std::endl;
        }
        archivoEntrada.close();
    }

    return 0;
}


void controlDeNotas(vector<Estudiante>& estudiantes) {
    int codigo;
    while (true) {
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;
        cin.clear();
        cin.ignore();
        cout << "--------------------------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); ++i) {
            if (estudiantes[i].codigoEstudiante == codigo) {
                cout << "Cursos disponibles para " << estudiantes[i].carrera << ":\n";
                vector<string> cursos;
                cout << "--------------------------------------------------------------------\n";

                if (estudiantes[i].carrera == "Ingeniería en Sistemas") {
                    cursos.push_back("Algoritmos");
                    cursos.push_back("Matemática");
                    cursos.push_back("Física");
                    cursos.push_back("Cálculo");
                    cursos.push_back("Álgebra");
                    cursos.push_back("Estadística");
                } else if (estudiantes[i].carrera == "Administración") {
                    cursos.push_back("Fundamentos de administración");
                    cursos.push_back("Comportamiento Organizacional");
                    cursos.push_back("Marketing estrategico");
                    cursos.push_back("Finanzas corporativas");
                    cursos.push_back("Recursos humanos");
                    cursos.push_back("Emprendimiento");
                } else if (estudiantes[i].carrera == "Derecho") {
                    cursos.push_back("Introducción al diseño");
                    cursos.push_back("Derecho constitucional");
                    cursos.push_back("Derecho civil");
                    cursos.push_back("Derecho penal");
                    cursos.push_back("Derecho administrativo");
                    cursos.push_back("Derecho Internacional");
                } else if (estudiantes[i].carrera == "Medicina") {
                	cursos.push_back("Anatomia humana");
                    cursos.push_back("Fisiología");
                    cursos.push_back("Bioquímica");
                    cursos.push_back("Patología");
                    cursos.push_back("Farmacología");
                    cursos.push_back("Medicina preventiva");
                } else if (estudiantes[i].carrera == "Psicología") {
                	cursos.push_back("Psicología general");
                    cursos.push_back("Psicología del desarrollo");
                    cursos.push_back("Psicología social");
                    cursos.push_back("Psicología clinica");
                    cursos.push_back("Psicología educativa");
                    cursos.push_back("Metodología de la investigación");
                } else if (estudiantes[i].carrera == "Arquitectura") {
                	cursos.push_back("Historia de la arquitectura");
                    cursos.push_back("Diseño arquitectonico");
                    cursos.push_back("Estructuras");
                    cursos.push_back("Urbanismo");
                    cursos.push_back("Instalaciones en edificios");
                    cursos.push_back("Representación gráfica");
                }

                
                vector<string> nombresCursos;
                vector<int> notasFinales;
                vector<string> estados;

                for (size_t j = 0; j < estudiantes[i].cursos.size(); ++j) {
                    cout << "Curso: " << estudiantes[i].cursos[j].nombre << endl;
                    cout << " \n";

                    int nota1, nota2, zonaTotal, examenFinal;

                    do {
                        cout << "Ingrese la nota del primer parcial (0-15): ";
                        cin >> nota1;
                    } while (nota1 < 0 || nota1 > 15);

                    do {
                        cout << "Ingrese la nota del segundo parcial (0-15): ";
                        cin >> nota2;
                    } while (nota2 < 0 || nota2 > 15);

                    do {
                        cout << "Ingrese la zona total (0-35): ";
                        cin >> zonaTotal;
                    } while (zonaTotal < 0 || zonaTotal > 35);

                    do {
                        cout << "Ingrese la nota del examen final (0-35): ";
                        cin >> examenFinal;
                    } while (examenFinal < 0 || examenFinal > 35);
                    

                    cout << "--------------------------------------------------------------------\n";

                    int notaFinal = nota1 + nota2 + zonaTotal + examenFinal;
                    string estado = (notaFinal >= 60) ? "Aprobado" : "Reprobado";
					
					estudiantes[i].cursos[j].notas.nota1 = nota1;
                    estudiantes[i].cursos[j].notas.nota2 = nota2;
                    estudiantes[i].cursos[j].notas.zonaTotal = zonaTotal;
                    estudiantes[i].cursos[j].notas.examenFinal = examenFinal;
                    estudiantes[i].cursos[j].notas.notaFinal = nota1 + nota2 + zonaTotal + examenFinal;
                    estudiantes[i].cursos[j].notas.estado = (estudiantes[i].cursos[j].notas.notaFinal >= 60) ? "Aprobado" : "Desaprobado";
                    //Toda esta seccion sue añadida para guardar las notas en memoria y poder ser llamadas en otras funciones, en este caso los reportes academicos
                    
                    nombresCursos.push_back(cursos[j]);
                    notasFinales.push_back(notaFinal);
                    estados.push_back(estado);
                    
                }

                cout << "\n --- Resultados finales ---:\n";
                cout << "====================================================================\n";
                for (size_t j = 0; j < nombresCursos.size(); ++j) {
                    cout << "Curso: " << nombresCursos[j] << "\n";
                    cout << "\n";
                    cout << "Nota final: " << notasFinales[j] << "\n";
                    cout << "Estado: " << estados[j] << "\n";
                    cout << "--------------------------------------------------------------------\n";
                }

                
                char continuar;
                cout << "¿Quieres registrar más notas? (s/n): ";
                cin >> continuar;
                cin.clear();
                cin.ignore();

                if (continuar == 's' || continuar == 'S') {
                    controlDeNotas(estudiantes); 
                }

                return;
            }
        }
        cout << "No se encontró un estudiante con el código: " << codigo << endl;
    }
}
