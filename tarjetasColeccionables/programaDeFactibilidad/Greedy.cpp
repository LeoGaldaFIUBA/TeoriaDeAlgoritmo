#include <algorithm>

#include "Greedy.h"
#include "File.h"

Greedy::Greedy(std::vector<int> base_sobres) : tarjetas(base_sobres) {
    std::sort_heap(this->tarjetas.begin(),this->tarjetas.end(),std::greater<int>());
}

int Greedy::procesar(int cantidadDeTarjetas) {
    int valorDelSobre = 0;
    this->sobresAEntregar.clear();
    for (auto tarjeta : this->tarjetas) {
        while (valorDelSobre + tarjeta <= cantidadDeTarjetas) {
            this->sobresAEntregar.push_back(tarjeta);
            valorDelSobre += tarjeta;
        }
        if (valorDelSobre == cantidadDeTarjetas) {
            return this->sobresAEntregar.size();
        }
    }
    return 0;
}

Greedy::~Greedy() {
}

