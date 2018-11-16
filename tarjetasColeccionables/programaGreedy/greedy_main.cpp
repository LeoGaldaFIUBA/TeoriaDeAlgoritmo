#include <cstdlib>
#include <iostream>

#include "Greedy.h"

#define CANTIDAD_DE_PARAMETROS 2


int main(int argc, char** argv) {  
    if(argc != CANTIDAD_DE_PARAMETROS+1){
        std::cout<<"Numero de parametros ingresados incorrectos"<<std::endl;
        return 0;
    }        
    Greedy greedy(argv[1],std::atoi(argv[2]));
    greedy.procesar();
    greedy.mostrarResultados();
    return 0;
}
