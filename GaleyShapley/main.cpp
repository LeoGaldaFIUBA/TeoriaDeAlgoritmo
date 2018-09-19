#include <cstdlib>
#include <iostream>

#include "GaleyProcesador.h"

#define CANTIDAD_DE_PARAMETROS 4


/*
 * 
 */
int main(int argc, char** argv) {
    std::cout<<"hola tp"<<std::endl;    
    if(argc != CANTIDAD_DE_PARAMETROS+1){
        std::cout<<"ingresa bien los parametros salame"<<std::endl;
        return 0;
    }    
    GaleyProcesador galeyProcesador(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));    
    galeyProcesador.leerArchivos();
    galeyProcesador.procesar();
    std::cout<<"fin procesador"<<std::endl;
    galeyProcesador.mostrarResultado();
    return 0;
}

