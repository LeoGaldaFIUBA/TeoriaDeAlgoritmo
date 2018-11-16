#include <iostream>

#include "Factibilidad.h"

Factibilidad::Factibilidad(char *nombreArchivo) {    
    File archivo(nombreArchivo, std::ios::in);
    while (!archivo.termino()) {
        this->tarjetas.push_back(archivo.leer());
    }
}

void Factibilidad::procesar(){
    std::cout<<"procesando..."<<std::endl;
    for (auto tarjeta : tarjetas) {
        std::cout<<tarjeta<<std::endl;
    }

}

void Factibilidad::mostrarResultado(){
    std::cout<<"por su pollo que se pueda procesar en Greedy papaa!!!!"<<std::endl;
}

Factibilidad::~Factibilidad() {
}

