#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream archivo_diccionario;
    string linea;

    // veo si tengo que codificar o decodificar
    if (argv[1][1] == 'c') {
        cout << "Codfico" << endl;
    } else if (argv[1][1] == 'd') {
        cout << "decodfico" << endl;

    } else {
        cout << "error" << endl;
        exit(1);
    }

    archivo_diccionario.open(argv[3]); // en la pos 3 tengo el diccionario

    if(archivo_diccionario.bad()){
        cout << "archivo Diccionario no encontrado" << endl;
        exit(2);
    }

    unsigned long pos;
    string orig;
    string trad;
    while (getline(archivo_diccionario, linea)) {
        pos = linea.find('\t');
        orig = linea.substr(0,pos);
        trad = linea.substr(pos+1,linea.length()-1);
        cout << "orig " << orig << " trad "<< trad << endl;
    }

    archivo_diccionario.close();

    return 0;
}