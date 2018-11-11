//
// Created by facu on 11/11/18.
//

#ifndef PROGRAMACION3_NODOARBOL_H
#define PROGRAMACION3_NODOARBOL_H


template<class T>
class NodoArbol {
private:
    NodoArbol<T> *izq;
    NodoArbol<T> *der;
    T dato;
public:
    NodoArbol() {
        izq = nullptr;
        der = nullptr;
    }

    NodoArbol(T d) {
        izq = nullptr;
        der = nullptr;
        dato = d;
    }

    T getDato() const { return dato; }

    void setDato(T dato) { this->dato = dato; }

    void setIzq(NodoArbol<T> *r) { this->izq = r; }

    void setDer(NodoArbol<T> *r) { this->der = r; }

    NodoArbol *getIzq() const { return izq; }

    NodoArbol *getDer() const { return der; }

    // void actualizar(T dato) {}

//    void print(bool esDerecho, string identacion) {
//        if (der != NULL) {
//            der->print(true, identacion + (esDerecho ? "     " : "|    "));
//        }
//        cout << identacion;
//        if (esDerecho) {
//            cout << " /";
//        } else {
//            cout << " \\";
//        }
//        cout << "-- ";
//        cout << dato << endl;
//        if (izq != NULL) {
//            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
//        }
//    }
};

#endif //PROGRAMACION3_NODOARBOL_H
