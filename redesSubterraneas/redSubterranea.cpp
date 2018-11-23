#include <cstdlib>
#include <iostream>

#include "Red.h"

#define CANTIDAD_DE_PARAMETROS 2

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    if(argc != CANTIDAD_DE_PARAMETROS+1){        
        std::cout<<"Numero de parametros ingresados incorrectos"<<std::endl;
        return 0;
    }    
    Red red;
    red.cargarMatriz(argv[1]);
    red.agregarDemandas(argv[2]);
    red.calcularFordFulkersen();   
    red.mostrar();
}

