#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#include "File.h"
#include "AlgoritmoDeEnvoltura.h"
#include "FuerzaBruta.h"
#include "Graham.h"
#include "DivisionYConquista.h"

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Parametros ingresados incorrectos" << std::endl;
        return 0;
    }    
    AlgoritmoDeEnvoltura *algoritmo;
    if (strcmp(argv[2],"F") == 0) {      
        FuerzaBruta fuerzaBruta;
        algoritmo = &fuerzaBruta;
    } else if (strcmp(argv[2],"G") == 0) {
//        Graham graham;
//        algoritmo = &graham;
    } else if (strcmp(argv[2],"D") == 0) {      
//        DivisionYConquista divisionYConquista;
//        algoritmo = &divisionYConquista;
    } else  {
    	std::cout << "Parametros de algoritmo incorrecto" << std::endl;
    	return 0;
    }
    algoritmo->cargarArchivo(argv[1]);
    algoritmo->generarEnvolturaConvexa();
    algoritmo->calcularMinimo();
    algoritmo->mostrar();
}
