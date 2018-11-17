#include <climits>
#include <algorithm>

#include "ProgramacionDinamica.h"
#include "File.h"

ProgramacionDinamica::ProgramacionDinamica(char* nombreArchivo, int cantidadDeTarjetas) : cantidadDeTarjetas(cantidadDeTarjetas) {
    File archivo(nombreArchivo, std::ios::in);
    while (!archivo.termino()) {
        this->tarjetas.push_back(archivo.leer());
    }
    std::sort(this->tarjetas.begin(),this->tarjetas.end());     
}


void ProgramacionDinamica::procesar() {
        std::vector<int> matrizHechaVector;
        matrizHechaVector.push_back(0);
        this->sobresAEntregar.push_back(0);
        for(int i = 1; i <= this->cantidadDeTarjetas; i++){
            matrizHechaVector.push_back(9999);
            this->sobresAEntregar.push_back(9999);
        }
        this->tarjetas.insert(this->tarjetas.begin(),0);        
        
        int minimo = 999999;
        int coin = 999999;
        for(int i = 1; i <= this->cantidadDeTarjetas; i++){
            minimo = 999999;
            for(int j = 1; j < (int) this->tarjetas.size() ; j++){
                if((this->tarjetas[j] <= i) && (1 + matrizHechaVector[i - this->tarjetas[j]] < minimo)){
                    minimo = 1+ matrizHechaVector[i - this->tarjetas[j]];
                    coin = j;
                }
            }
            matrizHechaVector[i] = minimo;
            this->sobresAEntregar[i] = coin;
        }
}

void ProgramacionDinamica::mostrarResultados() {
    int a = this->cantidadDeTarjetas;
    std::cout << "los sobres son los siguientes:" << std::endl;
    while(a > 0){
        std::cout<< this->tarjetas[this->sobresAEntregar[a]]<<std::endl;
        a -= this->tarjetas[this->sobresAEntregar[a]];
    }
}

ProgramacionDinamica::~ProgramacionDinamica() {
}

