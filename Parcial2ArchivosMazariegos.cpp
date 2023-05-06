#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
void crear_archivos();
void agregar_texto();
void encontrar_archivo();

void crear_archivos() {
    // Preguntar al usuario cuántos archivos desea crear
    int num_archivos;
    cout << "¿Cuántos archivos desea crear? ";
    cin >> num_archivos;

    // Verificar si la cantidad de archivos es par o impar
    if (num_archivos % 2 == 0) {
        // Crear los archivos en la subcarpeta "par" dentro de "Mis documentos"
        string directorio = string(getenv("HOME")) + "/Mis documentos/par";
        system(("mkdir -p " + directorio).c_str());
        for (int i = 1; i <= num_archivos; i++) {
            string archivo = directorio + "/documento" + to_string(i) + ".txt";
            ofstream fs(archivo);
            for (int j = 1; j <= i; j++) {
                fs << "Línea " << j << " del documento " << i << endl;
            }
            fs.close();
        }

    } else {
        // Crear los archivos en el escritorio con el nombre "impar"
        string directorio = string(getenv("HOME")) + "/Escritorio";
        string archivo = directorio + "/impar.txt";
        ofstream fs(archivo);
        fs << "Línea 1 del documento impar" << endl;
        fs.close();
        for (int i = 2; i <= num_archivos; i++) {
            archivo = directorio + "/documento" + to_string(i) + ".txt";
            ofstream fs(archivo);
            for (int j = 1; j <= i; j++) {
                fs << "Línea " << j << " del documento " << i << endl;
            }
            fs.close();
        }
    }
}
void agregar_texto() {
    // Preguntar al usuario cuál es la ruta de la carpeta de archivos
    string ruta;
    cout << "Ingrese la ruta de la carpeta de archivos: ";
    cin >> ruta;

    // Obtener una lista de archivos en la ruta especificada
    system(("ls -1 " + ruta + " > lista_archivos.txt").c_str());
    ifstream lista_fs("lista_archivos.txt");
    string archivo;
    while (getline(lista_fs, archivo)) {
        string ruta_completa = ruta + "/" + archivo;
        ofstream fs(ruta_completa, ios::app);
        int num_lineas = stoi(archivo.substr(9, archivo.size() - 13));
        fs << "Línea " << num_lineas + 1 << " del documento " << archivo.substr(9, archivo.size() - 13) << endl;
        fs.close();
    }
    lista_fs.close();
    system("rm lista_archivos.txt");
}
void encontrar_archivo(){
    string encontrar_archivo_mas_pequeno(string ruta) {
        // Abrir la carpeta de archivos
        DIR* dir = opendir(ruta.c_str());
}
