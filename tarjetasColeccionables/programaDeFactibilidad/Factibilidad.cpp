#include <iostream>
#include <algorithm>

#include "Factibilidad.h"
#include "Greedy.h"

#define SIN_SOLUCION 0
#define SIN_OPTIMO 1
#define OPTIMO 2

Factibilidad::Factibilidad(char *nombreArchivo) {    
    File archivo(nombreArchivo, std::ios::in);
    while (!archivo.termino()) {
        this->tarjetas.push_back(archivo.leer());
    }
    std::sort(this->tarjetas.begin(),this->tarjetas.end());
    this->resultado = SIN_SOLUCION;
    this->contraejemplo = 0;
}

void Factibilidad::procesar(){
	if (this->tarjetas.at(0) != 1) {
		return;
	}
	int N = this->tarjetas.size();
	if (N == 3) {
		int r = this->tarjetas[2] % this->tarjetas[1];
		int q = this->tarjetas[2] / this->tarjetas[1];
		if ((0 <= r) && (r < (this->tarjetas[1] - q))){
			this->contraejemplo = this->tarjetas[2] + this->tarjetas[1] - 1;
			this->resultado = SIN_OPTIMO;
			return;
		}
	} else if (N > 3) {
		int limite_inferior = this->tarjetas[2] + 1;
		int limite_superior = this->tarjetas[N - 1] + this->tarjetas[N - 2];
		Greedy greedy(this->tarjetas);
		for (int x = limite_inferior; x < limite_superior; x++){
			int g_x = greedy.procesar(x);
			for (auto tarjeta : this->tarjetas){
				if (tarjeta < x) {
					int g = greedy.procesar(x - tarjeta);
					if (g_x > (g + 1)) {
						this->contraejemplo = x;
						this->resultado = SIN_OPTIMO;
						return;
					}
				}
			}
		}
	}
	this->resultado = OPTIMO;
}

void Factibilidad::mostrarResultado(){
    switch (this->resultado){
    case SIN_SOLUCION:
    	std::cout << "El algoritmo Greedy podría no tener solución" << std::endl;
    	break;
    case SIN_OPTIMO:
    	std::cout << "El algoritmo Greedy podría no dar una solución óptima." << std::endl;
    	std::cout << "El minimo contrajemplo se encuentra en: " << this->contraejemplo << std::endl;
    	break;
    case OPTIMO:
        std::cout << "El algoritmo Greedy puede resolver el problema" << std::endl;
        break;
    }
}

Factibilidad::~Factibilidad() {
}

