//
// Created by facu on 01/11/18.
//

#include <iostream>
//#include "../Cola/Cola.h"
//#include "../Pila/Pila.h"
//#include "../Lista/Lista.h"
#include "../Arbol/ArbolBinario.h"

//U06_Arbol/Arbol/ArbolBinario.h

//del archivo de texto
#include<stdlib.h>
#include<string.h>
#include<fstream>
//hash
//arbol/alguna clase propia que cree yo mismo

using namespace std;

//declaracion de funciones a utilizar
void lectura();

void escribirFrases();

void codec(char);

/*
Enunciado:
Se desea realizar una aplicación que realice la tarea de codificar un texto. El programa debe
recibir dos archivos de texto, el diccionario y el texto a codificar. Luego de codificar el texto original, debe
escribirlo en un nuevo archivo de salida.
El programa debe permitir también, decodificar el texto codificado. Para esto se le pasa el texto
codificado y el diccionario y debe escribir un archivo con el texto original.
El programa deberá recibir como parámetro en línea de comandos las rutas de los distintos
archivos y realizar la tarea dada.
Los parámetros que debe soportar son:
● -c / -d: uno de estos dos parámetros, -c indicará que va a codificar el archivo y -d indica que va a
decodificar el archivo de entrada.
● -l “archivo.dic”:​​ el archivo de texto a utilizar como libro de códigos.
● -i “entrada.txt”:​​ el archivo de texto a codificar o descodificar.
● -o “salida.txt”:​​ el archivo de texto donde se escribirá la salida del programa.
 */

/*
  necesito usar 3 archivos, 2 de entrada y uno de salida
  - entrada.txt //puede ser el archivo a codificar o decodificar //lo voy a ingresar automaticamente al principio, luego lo haria el usuario
  -salida.txt
  -diccionario.txt



 DEBO CREAR CODIFICAR/DECODIFICAR.H ?????   // Escribir/leer documento

 */


void codec(char option) { //como parametro voy a pasarle -c/-d (option) //-// y los archivos de texto (entrada)
    /*en esta funcion voy a llamar a las demas funciones que me van a codificar/decodificar los textos y van a buscar en
    los diccionarios / debo incluir las mismas en un archivo ,h aparte?
    */

    //llamar a la funcion que codifica el texto
    //ingresar el texto y el diccionario

    cout << "ingrese el texto (el programa lo hara automaticamente)" << endl;
    fflush(stdin);
//    cin.getline(apellido, 10, '\n');

    if (option == c)   //codificar


        if (option == d)   //decodificar

}



//al diccionario deberia de guardarlo en un arbol/hash (ver cual funciona mejor/seguro que el arbol)--------------------------------------------------------------------------------------------------------------------------------


void lectura() {
    cola<char> entry;
    int n;                      //lo uso para el for de busqueda y reemplazo
    ifstream archivo;
    string nombreArchivo, texto;

    cout << "Digite el nombre o la ubicacion del archivo o fichero: ";
    getline(cin, nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof()) { //mientras no sea final del archivo
        getline(archivo, texto);
        cout << texto << endl;
        //aca deberia de meter cada palabra que vaya sacando en una cola para
        //luego sacar palabra porpalabra para codificarlas y posteriormente
        //escribirlas en un nuevo archivo de texto (salida.txt)
        entry.encolar;
        //buscar palabra en el arbol binario previamente creado en base al diccionario


        n++;
        //
    }
    archivo.close(); //Cerramos el archivo

    for (int i = 0; i > n; i++) {
        char dato = entry.desencolar;
        diccionario.search(dato);
        //una vez terminado de leer el archivo y de guardarlo en una cola deberia de llamar a laa funcion busque para luego hacer
        //el reemplazo de las palabras

        //una vez que diccionario.search(dato); me devuelva la palabra codificada (falta codificar) llamar a la funcion que
        //me escriba el archivo de salida ya codificado
    }
}

void escribirFrases() {
    ofstream archivo;
    string nombreArchivo, frase;
    char rpt;

    cout << "Digite el nombre del archivo: ";
    getline(cin, nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::out); //Creamos el archivo

    if (archivo.fail()) { //Si a ocurrido algun error
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    do {
        fflush(stdin);
        cout << "Digite una frase: ";
        getline(cin, frase);
        archivo << frase << endl;

        cout << "\nDesea agregar otra frase(S/N): ";
        cin >> rpt;
    } while ((rpt == 'S') || (rpt == 's'));

    archivo.close(); //Cerramos el archivo
}

int main(int argc, char *argv[]) {

    for(int i = 0; i<argc; i ++){
        cout << i << " " << argv[i] << endl;
    }

    char option; //lo uso para el switch case de codificar/decodificar
    cout << "que tarea desea realizar? " << endl;
    cout << "opcion 1) codificar texto " << endl;
    cout << "opcion 2) decodificar texto " << endl;
    cin >> option;

    codec(option); //me ahorro el switch


/*
    switch (option) {

        case 1:
                option=c;
                codec(option);         //llamar a la funcion codec y pasarle como parametros el diccionario y el texto
               break;
        case 2:         //llamar a la funcion que codifica el texto
                option=d;
                codec(option);
            break;
        default:
            cout<<"ingrese una opcion valida "<<endl;
            break;
    }
*/

    system("pause");
    return 0;
}