#include "Red.h"
#include "File.h"

#include <sstream>
#include <cmath>

Red::Red() {
}

void Red::cargarMatriz(char* archivoDeRelaciones) {
    File archivo(archivoDeRelaciones, std::ios::in);
    int fila = 0;
    while (!archivo.termino()) {
        std::string linea = archivo.leer();
        this->cargarCapacidades(linea, fila);
        fila++;
    }
    this->fuente = 0;
    this->sumidero = --fila;
}

void Red::cargarCapacidades(std::string &linea, int fila) {
    std::istringstream streamLinea(linea);
    if (!fila) {
        streamLinea.seekg(0, streamLinea.end);
        int longitud = 1 + streamLinea.tellg()/2;                
        streamLinea.seekg(0, streamLinea.beg);
        this->inicializarMatriz(longitud);
    }
    int col = 0;
    for (auto capacidad : linea) {
        this->matrizDeAdyacencia.at(fila).at(col) = capacidad;
        //        this->matrizDeAdyacencia[fila][col] = capacidad;
        col++;
    }
}

void Red::inicializarMatriz(int size) {
    
}

void Red::agregarDemandas(char* archivoDeDemandas) {
    File archivo(archivoDeDemandas, std::ios::in);
    int fila = 0;
    while (!archivo.termino()) {
        std::string linea = archivo.leer();
        std::istringstream streamLinea(linea);
        int demanda;
        streamLinea >> demanda;
        this->matrizDeAdyacencia[fila][this->fuente] = demanda;
        streamLinea >> demanda;
        this->matrizDeAdyacencia[fila][this->sumidero] = demanda;
        fila++;
    }
}

void Red::calcularFordFulkersen() {
    std::cout << "calculando ford fulkersen" << std::endl;
}

void Red::mostrar() {
    for (int i = 0; i < --this->sumidero; i++) {
        for (int j = 0; j < --this->sumidero; j++) {
            std::cout << this->matrizDeAdyacencia[i][j];
        }
        std::cout << std::endl;
    }
}

Red::~Red() {
}

