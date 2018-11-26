#include "Red.h"
#include "File.h"

#include <sstream>
#include <cmath>
#include <csignal>

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
    this->sumidero = fila;
}

void Red::cargarCapacidades(std::string &linea, int fila) {
    std::istringstream streamLinea(linea);
    if (!fila) {
        streamLinea.seekg(0, streamLinea.end);
        int longitud = 1 + streamLinea.tellg()/2;                
        streamLinea.seekg(0, streamLinea.beg);
        this->matrizDeAdyacencia = this->inicializarMatriz(longitud);
    }
    int col = 0;
    int capacidad;
    while(streamLinea >> capacidad){
        this->matrizDeAdyacencia[fila][col] = capacidad;
        col++;
    }
}

std::vector<std::vector<int>> Red::inicializarMatriz(int size) {   
    std::vector<std::vector<int>> matriz;
    for(int i = 0; i < size; i++){
        std::vector<int> row;
        matriz.push_back(row);
        for(int j = 0; j < size; j++){
            matriz[i].push_back(0);
        }
    }
    return matriz;
}

void Red::agregarDemandas(char* archivoDeDemandas) {    
    File archivo(archivoDeDemandas, std::ios::in);
    int fila = 0;
    while (!archivo.termino()) {
        std::string linea = archivo.leer();
        std::istringstream streamLinea(linea);
        int demanda;
        streamLinea >> demanda;
        this->matrizDeAdyacencia[this->fuente][fila] = demanda;
        streamLinea >> demanda;
        int max = this->sumidero - 1;
        this->matrizDeAdyacencia[fila][max] = demanda;
        fila++;
    }
}

void Red::calcularFordFulkersen() {
    std::cout << "calculando ford fulkersen" << std::endl;
}

void Red::mostrar() {
    for (int i = 0; i < this->sumidero; i++) {
        for (int j = 0; j < this->sumidero; j++) {
            std::cout << this->matrizDeAdyacencia[i][j]<<"-";
        }
        std::cout << std::endl;
    }
}

Red::~Red() {
}

