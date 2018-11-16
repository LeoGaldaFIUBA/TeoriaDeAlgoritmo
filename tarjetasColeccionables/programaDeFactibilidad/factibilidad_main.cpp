#include <cstdlib>
#include <iostream>

#include "Factibilidad.h"

#define CANTIDAD_DE_PARAMETROS 1


int main(int argc, char** argv) {  
    if(argc != CANTIDAD_DE_PARAMETROS+1){
        std::cout<<"Numero de parametros ingresados incorrectos"<<std::endl;
        return 0;
    }    
    Factibilidad factibilidad(argv[1]);
    factibilidad.procesar();
    factibilidad.mostrarResultado();
    return 0;
}
