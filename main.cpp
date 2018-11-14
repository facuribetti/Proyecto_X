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


int main(int argc, char *args[]) {

    for (int i = 0; i < argc; i++) {
        cout << i << args[i] << endl;
    }


    if (args[1][1] == 'c') {
        cout << "codifico";
    } else if (args[1][1] == 'd')
        cout << "decodifico";
    else
        cout << "error";

    cout << endl << args[3];

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