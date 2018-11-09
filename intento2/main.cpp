#include <iostream>
#include <fstream>        //para los archivos de texto
#include <stdlib.h>      //para los archivos de texto
#include <string>
#include <bits/stdc++.h>
//#include "ArbolBinarioCod.h"
//#include "ArbolBinarioDesc.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

void encode(string in, string dic, string out);
void decode(string arc, string dic, string imp);
//void splitAndPut(string cut, bool cod);
void salida(string words, string out); //la cree solo para probar escribir el archivo de salida por separado

int main() {

    int i;
    int dato;
    bool foo = false;
    int u;
    string rutaA;
    string rutaD;
    string rutaI;
    string str;

    while (!foo){
        cout<<"direccion del archivo de entrada /home/facu/CLionProjects/Proyecto_X/intento2/entrada.txt   --esto cambialo por la ubicacion del archivo en tu compu"<<endl;
        cout<<"direccion del archivo de salida  /home/facu/CLionProjects/Proyecto_X/cmake-build-debug/intento2/salida.txt  --esto cambialo por la ubicacion del archivo en tu compu"<<endl;
        cout << "Elija una opcion:"<<endl;
        cout << "Codificar -------------> 1"<<endl;
        cout << "Decodificar -----------> 2"<<endl;
        cout << "Salir -----------------> 3"<<endl;

        cin >> u;

        switch (u){

            case 1:

                cout << "Ingrese ruta de archivo a codificar:" << endl;
                cin >> rutaA;

                cout << "Ingrese ruta del diccionario:" << endl;
                cin >> rutaD;

                cout << "Ingrese ruta de archivo a imprimir:" << endl;
                cin >> rutaI;
                //verificar que la informacion sea correcta antes de llamar a la otra funcion?
                encode(rutaA, rutaD, rutaI);

                break;

            case 2:

                cout << "Ingrese ruta de archivo a descodificar:" << endl;
                cin >> rutaA;

                cout << "Ingrese ruta del diccionario:" << endl;
                cin >> rutaD;

                cout << "Ingrese ruta de archivo a imprimir:" << endl;
                cin >> rutaI;

                decode(rutaA, rutaD, rutaI);
                break;

            case 3:
                foo = true;
                break;

            default:
                cout<< "Opcion incorrecta."<< endl;
                break;
        }
    }

    system("pause");
    return 0;
}

//codificar
//encode(rutaA, rutaD, rutaI);
//(entrada,diccionario,salida)
void encode(string in, string dic, string out) {
//    ifstream fileDic(dic);  //inicializamos diccionario
//    ifstream diccionario;
//    ifstream fileArc(in);  //              entrada
//    ofstream fileImp(out);  //              salida
//    string str;             //  ?
    string words;            //  la uso para copiar el contenido de los archivos de texto y guardarlos dentro de esta variable



//-----------------------------------------------//IMPORTANTE: LOS ARCHIVOS CREADOS/LEIDOS ESTAN EN LA CARPETA cmake-build-debug/intento2-----------------------------------------------------------------------



//estoy probando leer archivos
    ifstream entry;
    entry.open(in,ios::in);//abrimos el archivo en modo lectura
    //direccion del archivo de entrada /home/facu/CLionProjects/proyecto/intento2/entrada.txt
    if(entry.fail()){
        cout<<"No se pudo abrir el archivo de entrada";
        exit(1);
    }

    while(!entry.eof()) { //mientras no sea final del archivo
        getline(entry,words);
        cout<<words<<endl;  //aca deberiamos buscar en el arbol cada palabra que vayamos sacando para escribirla en el archivo de salida a continuacion
        //funcion para buscar la palabra en el arbol y que me devuelva la palabra codificada
        //al agregar el texto en un archivo ya existente cada vez que entre al programa deberia de borrar lo que exista en el
        //------------------------------------------------------------------------------------------------------------//escribir en el archivo de salida
        salida(words,out);  //esta funcion es la que me escribe el archivo salida.txt
        //salida (palabra,direccion del archivo)

    }
    entry.close();//cerramos el archivo

}


//------------------------------------ decode funciona igual que code, solo que debo buscar al reves en el arbol o en otro arbol diferente
//decode(rutaA, rutaD, rutaI);
//(entrada,diccionario,salida)
void decode(string in, string dic, string out) {
//    ifstream fileDic(dic);  //inicializamos diccionario
//    ifstream diccionario;
//    ifstream fileArc(in);  //              entrada
//    ofstream fileImp(out);  //              salida
//    string str;             //  ?
    string words;            //  la uso para copiar el contenido de los archivos de texto y guardarlos dentro de esta variable



//-----------------------------------------------//IMPORTANTE: LOS ARCHIVOS CREADOS/LEIDOS ESTAN EN LA CARPETA cmake-build-debug/intento2-----------------------------------------------------------------------



//estoy probando leer archivos
    ifstream entry;
    entry.open(in, ios::in);//abrimos el archivo en modo lectura
    //direccion del archivo de entrada /home/facu/CLionProjects/proyecto/intento2/entrada.txt
    if (entry.fail()) {
        cout << "No se pudo abrir el archivo de entrada";
        exit(1);
    }

    while (!entry.eof()) { //mientras no sea final del archivo
        getline(entry, words);
        cout << words
             << endl;  //aca deberiamos buscar en el arbol cada palabra que vayamos sacando para escribirla en el archivo de salida a continuacion
        //funcion para buscar la palabra en el arbol y que me devuelva la palabra codificada
        //al agregar el texto en un archivo ya existente cada vez que entre al programa deberia de borrar lo que exista en el
        //------------------------------------------------------------------------------------------------------------//escribir en el archivo de salida
        salida(words, out);  //esta funcion es la que me escribe el archivo salida.txt
        //salida (palabra,direccion del archivo)

    }
    entry.close();//cerramos el archivo
}

void salida(string words, string out) {

    cout << "entre a la funcion salida" << endl;
    ofstream salida;
    salida.open(out, ios::app); //abrimos el archivo en modo añadir texto

    if (salida.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(2);
    }

    salida << " ";    //pongo el espacio para separar las palabras o futuras frases a ingresar
    salida
            << words; // le mando la palabra que me envia la llamada a la funcion      /DEBERIA sustituirla por la palabra ya codificada
    salida.close();//cerramos el archivo


    /*
    ofstream salida;
    salida.open("/home/facu/CLionProjects/proyecto/cmake-build-debug/intento2/salida.txt",ios::app); //abrimos el archivo en modo añadir texto

    if(salida.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(2);
    }

    salida<<" ";    //pongo el espacio para separar las palabras o futuras frases a ingresar
    salida<<"hola facu"; //a esto me lo escribe dos veces, porque?
    salida.close();//cerramos el archivo
    */
}