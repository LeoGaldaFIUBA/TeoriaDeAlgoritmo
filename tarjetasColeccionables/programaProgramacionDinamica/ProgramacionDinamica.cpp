#include <climits>

#include "ProgramacionDinamica.h"
#include "File.h"

ProgramacionDinamica::ProgramacionDinamica(char* nombreArchivo, int cantidadDeTarjetas): cantidadDeTarjetas(cantidadDeTarjetas) {
    File archivo(nombreArchivo, std::ios::in);
    while (!archivo.termino()) {
        this->tarjetas.push_back(archivo.leer());
    }
}

void ProgramacionDinamica::inicializarMatriz(std::vector<std::vector<int>> &matriz){
    for(int i = 0; i < (int) this->tarjetas.size(); i++){
        matriz[i][0] = 0; 
    }
    
    for(int j = 0; j < this->cantidadDeTarjetas; j++){
        matriz[0][j] = INT_MAX;
    }
}


void ProgramacionDinamica::procesar(){     
    std::vector<std::vector<int>> matriz(this->tarjetas.size()+1,std::vector<int>(this->cantidadDeTarjetas + 1));
    this->inicializarMatriz(matriz);
    for(int i = 0; i < (int) this->tarjetas.size(); i++){
        for(int j = 0; j < this->cantidadDeTarjetas; j++){
            if(j < this->tarjetas[i - 1]){
                matriz[i][j] = matriz[i-1][j];
            }else{
                
            }
        }
    }
    
//    int matriz[][];
//    this->sobresAEntregar[0] = 0;    
//    int minimo;
//    for(int i = 1; i <= this->cantidadDeTarjetas; i++){
//        minimo = INT_MAX;
//        for(int j = 1; j <= (int) this->tarjetas.size() ; j++){
//            if((this->tarjetas[j] <= i) && (matrizHechaVector[i - this->tarjetas[j]] < minimo)){
//                minimo = matrizHechaVector[i - this->tarjetas[j]];
//            }
//        }
//        matrizHechaVector[i] = 1 + minimo;
//    }
//    std::cout<<"valores del array:"<<std::endl;
//    for(int w = 0; w < this->cantidadDeTarjetas; w++){
//        std::cout<<matrizHechaVector[w]<<std::endl;
//    }
    
    
//    std::vector<int> matrizHechaVector;
//    matrizHechaVector.insert(matrizHechaVector.begin(),0);    
////    int matriz[][];
////    this->sobresAEntregar[0] = 0;    
//    int minimo;
//    for(int i = 1; i <= this->cantidadDeTarjetas; i++){
//        minimo = INT_MAX;
//        for(int j = 1; j <= (int) this->tarjetas.size() ; j++){
//            if((this->tarjetas[j] <= i) && (matrizHechaVector[i - this->tarjetas[j]] < minimo)){
//                minimo = matrizHechaVector[i - this->tarjetas[j]];
//            }
//        }
//        matrizHechaVector[i] = 1 + minimo;
//    }
//    std::cout<<"valores del array:"<<std::endl;
//    for(int w = 0; w < this->cantidadDeTarjetas; w++){
//        std::cout<<matrizHechaVector[w]<<std::endl;
//    }
}

void ProgramacionDinamica::mostrarResultados(){
    if (this->sobresAEntregar.size()) {
        std::cout << "los sobres son los siguientes:" << std::endl;
        for (auto elem : this->sobresAEntregar) {
            std::cout << elem << std::endl;
        }
    }else{
        std::cout<<"no hay solucion!"<<std::endl;
    }    
}

ProgramacionDinamica::~ProgramacionDinamica() {
}

