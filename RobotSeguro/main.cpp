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
    AlgoritmoDeEnvoltura* algoritmo;
    if (strcmp(argv[2],"F") == 0) {
        algoritmo = new FuerzaBruta();
    } else if (strcmp(argv[2],"G") == 0) {
        algoritmo = new Graham();
    } else if (strcmp(argv[2],"D") == 0) {
        algoritmo = new DivisionYConquista();
    } else  {
    	std::cout << "Parametros de algoritmo incorrecto" << std::endl;
    	return 0;
    }
    algoritmo->cargarArchivo(argv[1]);
    algoritmo->generarEnvolturaConvexa();
    algoritmo->calcularMinimo();
    algoritmo->mostrar();
    delete(algoritmo);
}
