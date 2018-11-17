#include <algorithm>

#include "Greedy.h"
#include "File.h"

Greedy::Greedy(char *nombreArchivo, int cantidadDeTarjetas) : cantidadDeTarjetas(cantidadDeTarjetas) {
    File archivo(nombreArchivo, std::ios::in);
    while (!archivo.termino()) {
        this->tarjetas.push_back(archivo.leer());
    }
    std::sort_heap(this->tarjetas.begin(),this->tarjetas.end(),std::greater<int>());
}

void Greedy::procesar() {
    int valorDelSobre = 0;
    for (auto tarjeta : this->tarjetas) {
        while (valorDelSobre + tarjeta <= this->cantidadDeTarjetas) {
            this->sobresAEntregar.push_back(tarjeta);
            valorDelSobre += tarjeta;
        }
        if (valorDelSobre == this->cantidadDeTarjetas) {
            return;
        }
    }
}

void Greedy::mostrarResultados() {
    if (this->sobresAEntregar.size()) {
        std::cout << "los sobres son los siguientes:" << std::endl;
        for (auto elem : this->sobresAEntregar) {
            std::cout << elem << std::endl;
        }
    }else{
        std::cout<<"no hay solucion!"<<std::endl;
    }
}

Greedy::~Greedy() {
}

