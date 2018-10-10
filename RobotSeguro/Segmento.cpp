#include "Segmento.h"

Segmento::Segmento(Punto punto1, Punto punto2): punto1(punto1), punto2(punto2) {
}

Punto Segmento::getPunto1(){
    return this->punto1;
}

Punto Segmento::getPunto2(){
    return this->punto2;
}

Segmento::~Segmento() {
}

