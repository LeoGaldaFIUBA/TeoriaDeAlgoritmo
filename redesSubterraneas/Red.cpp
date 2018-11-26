#include "Red.h"
#include "File.h"

#include <sstream>
#include <cmath>
#include <csignal>
#include <climits>
#include <algorithm>
#include <queue>

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
    Matriz matriz;
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
        this->matrizDeAdyacencia[fila][this->sumidero] = demanda;
        fila++;
    }
}

bool Red::BFS(std::vector<int> &parent){
    int n = this->matrizResidual.size();
    VectorType visitado;
    for(int i = 0; i < n; i++){
        visitado.push_back(false);
    }    
        
    std::queue<int> nodos;
    
    nodos.push(this->fuente);
    visitado[this->fuente] = true;
    parent[this->fuente] = -1;
    
    while(!nodos.empty()){
        int u = nodos.front();
        nodos.pop();
        
        for(int i = 0; i < n; i++){
            int v = i;
            int capacidad = this->matrizResidual[u][v];
            
            if(!visitado[v] && capacidad){
                nodos.push(v);
                parent[v] = u;
                visitado[v] = true;
            }
        }
    }
    
    if(visitado[this->sumidero]){
        return true;
    }
    return false;
}


void Red::calcularFordFulkersen() {
    int flujoMaximo = 0;
    this->matrizResidual = this->matrizDeAdyacencia;
    std::vector<int> parent;   
    for(int i = 0; i <= this->sumidero; i++){
        parent.push_back(-1);
    }
    while(this->BFS(parent)){
        int pathFlow = INT_MAX;
        int v = this->sumidero;
        int u;
        while(v != this->fuente){
            u = parent[v];
            int capacidad = this->matrizResidual[u][v];
            pathFlow = std::min(pathFlow,capacidad);
            v = u;
        }
        v = this->sumidero;
        while (v != this->fuente) {
            u = parent[v];
            this->matrizResidual[u][v] -= pathFlow;
            this->matrizResidual[v][u] += pathFlow;
            v = u;
        }
        flujoMaximo += pathFlow;    
    }    
//    std::cout<< "flujo Maximo:"<<flujoMaximo<<std::endl;
}

void Red::mostrarResultado() {    
    bool resultado = true;
    for (int i = 0; i <= this->sumidero; i++) {
        if(this->matrizResidual[i][this->sumidero]){
            resultado = false;
        }            
    }
    if(resultado){
        std::cout<<"Es factible proporcionar un servicio adecuado"<<std::endl;
    }else{
        std::cout<<"No es factible proporcionar un servicio adecuado"<<std::endl;
    }
    
//    std::cout<<"matriz de adyacencias"<<std::endl;
//    for (int i = 0; i <= this->sumidero; i++) {
//        for (int j = 0; j <= this->sumidero; j++) {
//            std::cout << this->matrizDeAdyacencia[i][j]<<"-";
//        }
//        std::cout << std::endl;
//    }
    
//    std::cout<<"matriz residual"<<std::endl;
//    for (int i = 0; i <= this->sumidero; i++) {
//        for (int j = 0; j <= this->sumidero; j++) {
//            std::cout << this->matrizResidual[i][j]<<"-";
//        }
//        std::cout << std::endl;
//    }
}

Red::~Red() {
}

