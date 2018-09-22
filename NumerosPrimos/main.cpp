#include <iostream>
#include <cstdlib>
#include "NumerosPrimos.h"

int main(int argc, char**argv)
{
	if (argc != 3) {
		std::cout << "Parametros ingresados incorrectos" << std::endl;
		return 0;
	}

	NumerosPrimos numerosPrimos(atoi(argv[1]));
	
	if (strcmp(argv[2],"E") == 0) {
		numerosPrimos.procesarErastotenes();
	}
	else if (strcmp(argv[2],"F") == 0) {
		numerosPrimos.procesarFuerzaBruta();
	}	
	else {
		std::cout << "Los parametros validos son E o F" << std::endl;
		return 0;
	}

	numerosPrimos.mostrarPrimos();
	return 0;
}
