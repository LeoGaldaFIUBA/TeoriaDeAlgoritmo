#include <cstdlib>
#include <iostream>

#include "GSProcesador.h"

#define CANTIDAD_DE_PARAMETROS 4


int main(int argc, char** argv) {  
    if(argc != CANTIDAD_DE_PARAMETROS+1){
        std::cout<<"Numero de parametros ingresados incorrectos"<<std::endl;
        return 0;
    }    
    GSProcesador galeyProcesador(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    galeyProcesador.leerArchivos();
    galeyProcesador.procesar();
    galeyProcesador.mostrarResultados();
    return 0;
}

