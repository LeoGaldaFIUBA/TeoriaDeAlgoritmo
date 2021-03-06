#include "NumerosPrimos.h"
#include <vector>
#include <iostream>

NumerosPrimos::NumerosPrimos(int n): n(n){
}


NumerosPrimos::~NumerosPrimos(){
}

void NumerosPrimos::procesarErastotenes(){
	//Inicializo vector primos
	std::vector<bool> primos;
	primos.push_back(false); //Inicializo 0
	primos.push_back(false); //Inicializo 1
	for (int i = 2; i <= this->n; i++) {
		primos.push_back(true);
	}
        
        int p;
	for (p = 2; (p * p) <= this->n; p++){ 
		if (primos.at(p) == true){
			// Marcar como false todos los multiplos de p 
			for (int i = (p * 2); i <= this->n; i += p){
				primos.at(i) = false;
			}
			this->numeros_primos.push_back(p);
		}
	}

	//Almaceno los primos
	for (; p <= n; p++){
		if (primos[p]) {
			this->numeros_primos.push_back(p);
		}
	}
}

void NumerosPrimos::procesarFuerzaBruta(){
	for (int i = 2; i <= this->n; i++) {
		bool esPrimo = true;
		int j = 2;
		while ((j < i) && (esPrimo == true)) {
			if (i % j == 0) {
				esPrimo = false;
			}
			j ++;
		}
		if (esPrimo) {
			this->numeros_primos.push_back(i);
		}
	}
}

void NumerosPrimos::mostrarPrimos(){
	std::cout << "Numeros primos hasta " << this->n << std::endl;
	std::list<int>::iterator it = this->numeros_primos.begin();
	for (; it != this->numeros_primos.end(); it++) {
		std::cout << *it << " - ";
	}
	std::cout << std::endl;
}