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

int main(int argc, char *args[]) {

    //par
    //string
    //ifstream
    Par in;
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

    cout << endl << args[3]<<endl;

    //creo el arbol binario
    ifstream dictionary;
    dictionary.open(args[3]);
    if (dictionary.fail()) {
        cout << "No se pudo abrir el archivo de entrada";
        exit(1);
    }

    while (!dictionary.eof()) { //mientras no sea final del archivo
//        getline(dictionary, words); //copio to-do el contenido del diccionario en el string words
//        stringstream ss(words);
//        string item;
//        char delim = '\t';
//        while (getline(ss, item, delim)) {
            while(getline(dictionary,words)){
            unsigned long count = words.find('\t');
            in.set(words.substr(0, count), words.substr(count+1, words.length()));
            dic.put(in);
            cout << "split " << in << endl;
        }
    }

    Par buscar("bancales","");
    string encontre = dic.search(buscar).getTraduccion();
    cout << endl << encontre << endl;

//    Par pp("hola", "chau");
//    dic.put(pp);
//    Par abuscar("hola", "");
//    string res = dic.search(abuscar).getTraduccion();
//    cout << endl << res;
//    exit(0);

// args[3]   archivo de diccionario
// args[5]   archivo de entrada
// args[7]   archivo de salida.

// 1
// Cargar diccionario
}