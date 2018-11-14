#include <iostream>
#include <fstream>        //para los archivos de texto
#include <stdlib.h>      //para los archivos de texto
#include <string>
#include <bits/stdc++.h>
#include "ArbolBinario.h"
#include "par.h"
//#include "ArbolBinarioCod.h"
//#include "ArbolBinarioDesc.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

ArbolBinario <Par> dic;
void salida(string words, string out);

void salida(string words, string out) {
    ofstream salida;
    salida.open(out, ios::app); //abrimos el archivo en modo añadir texto

    if (salida.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(2);
    }

    salida << " ";    //pongo el espacio para separar las palabras o futuras frases a ingresar
    salida << words; // le mando la palabra que me envia la llamada a la funcion      /DEBERIA sustituirla por la palabra ya codificada
    salida.close();//cerramos el archivo
}

int main(int argc, char *args[]) {

    //par
    //string
    //ifstream
    Par in; //in: lo uso para crear el arbol
    string words;


    for (int i = 0; i < argc; i++) {
        cout << i << args[i] << endl;
    }

    if (args[1][1] == 'c') {
        cout << "codifico";
    } else if (args[1][1] == 'd')
        cout << "decodifico";
    else
        cout << "error";

    cout << endl << args[3] << endl;

    // args[3]   archivo de diccionario
    // args[5]   archivo de entrada
    // args[7]   archivo de salida.

    //creo el arbol binario
    ifstream dictionary;
    dictionary.open(args[3]);
    if (dictionary.fail()) {
        cout << "No se pudo abrir el archivo de entrada";
        exit(1);
    }
    while (!dictionary.eof()) { //mientras no sea final del archivo
        while (getline(dictionary, words)) {
            unsigned long count = words.find('\t');
            in.set(words.substr(0, count), words.substr(count + 1, words.length()));
            dic.put(in);
            //cout << "split " << in << endl;
        }
    }

//    string h = "multiprogramo";
//    Par buscar(h,"");
//    string encontre = dic.search(buscar).getTraduccion();
//    cout << endl << encontre << endl;
    //dic.inorder();
/*
    Par pp("hola", "chau");
    dic.put(pp);
    Par abuscar("hola", "");
    string res = dic.search(abuscar).getTraduccion();
    cout << endl << res;
    exit(0);
*/
    //pregunto con un if si codifico o decodifico-----------------------------------------------------------------------
    if (args[1][1] == 'c') {
        ifstream entry;
        entry.open(args[5]);
        //entry.open(args[5], ios::in);//abrimos el archivo en modo lectura

        if (entry.fail()) {
            cout << "No se pudo abrir el archivo de entrada";
            exit(1);
        }

        while (!entry.eof()) { //mientras no sea final del archivo
            while (getline(entry, words)) {
                if (words != "") {
                    Par buscar;
                    stringstream ss(words);
                    string item;
                    char delim = ' ';
                    while (getline(ss, item, delim)) {
                        //dic.put(item);
                        cout << "split " << item << endl;

                        //unsigned long count = words.find(' ');

                        buscar.set(item,"");

                        //buscar.set(words.substr(0, count), words.substr(count + 1, words.length()));

                        string encontre;

                        //buscar.set(words, "");  //me busca la frase completa, necesito cortarla por palabras
                        encontre = dic.search(buscar).getTraduccion();
                        cout << endl;
                        cout << encontre << endl;
                        salida(encontre, args[7]);
                    }
                    }
                //in.set(words.substr(0, count), words.substr(count+1, words.length()));
                //dic.put(in);
                //cout << in << endl;


            }
        }

    } else if (args[1][1] == 'd') {
        ifstream entry;
        entry.open(args[5]);
        //entry.open(args[5], ios::in);//abrimos el archivo en modo lectura

        if (entry.fail()) {
            cout << "No se pudo abrir el archivo de entrada";
            exit(1);
        }

        while (!entry.eof()) { //mientras no sea final del archivo
            while (getline(entry, words)) {
                if (words != "") {
                    if{
                        Par buscar;
                        stringstream ss(words);
                        string item;
                        char delim = ' ';
                        while (getline(ss, item, delim)) {
                            //dic.put(item);
                            cout << "split " << item << endl;

                            //unsigned long count = words.find(' ');

                            buscar.set("",item);

                            //buscar.set(words.substr(0, count), words.substr(count + 1, words.length()));

                            string encontre;

                            //buscar.set(words, "");  //me busca la frase completa, necesito cortarla por palabras
                            encontre = dic.search(buscar).getOriginal();
                            cout << endl;
                            cout << encontre << endl;
                            salida(encontre, args[7]);
                    }

                    }
                }

            }
        }

// 1
// Cargar diccionario
// 2
//leer archivo de entrada
    }
}
