#include "Graham.h"
#include "ComparadorDePuntos.h"
#include <stack>
#include <vector>
#include <algorithm>
#include <stdlib.h>

Graham::Graham() {
}

Graham::~Graham() {
}

void Graham::generarEnvolturaConvexa() {
    std::stack<Punto> pila;
    Puntos auxiliar;
    Punto pivote;
    pivote = this->puntosSeguros[0];
    for (auto punto : this->puntosSeguros) {
        if (punto.getY() < pivote.getY() || (punto.getY() == pivote.getY() &&
                punto.getX() < pivote.getX())) {
            pivote = punto;
        }
    }
    
    auxiliar = this->puntosSeguros;

    std::sort(auxiliar.begin(), auxiliar.end(), ComparadorDePuntos(pivote));

    pila.push(auxiliar[0]);
    pila.push(auxiliar[1]);
    pila.push(auxiliar[2]);

    int i = 3;
    while (i < (int) auxiliar.size()) {
        Punto puntoTop = pila.top();
        pila.pop();
        if (estaALaIzquierda((Punto) pila.top(), puntoTop, auxiliar[i]) > 0) {
            pila.push(puntoTop);
            pila.push(auxiliar[i]);
            i++;
        }
    }            
    Punto primero = pila.top();
    while(!pila.empty()){
        Punto puntoTop = pila.top();                
        pila.pop();
        if(!pila.empty()){
            this->envolturaConvexa[puntoTop] = pila.top();  
        }else{
            this->envolturaConvexa[puntoTop] = primero;
        }        
    }             
}

int Graham::estaALaIzquierda(Punto p0, Punto p1, Punto p2) {
    return (p1.getX() - p0.getX())*(p2.getY() - p0.getY()) -
            (p2.getX() - p0.getX())*(p1.getY() - p0.getY());
} 