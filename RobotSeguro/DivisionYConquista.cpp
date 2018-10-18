#include "DivisionYConquista.h"
#include "ComparadorDePuntos.h"
#include <algorithm>
#include <cmath>

#define MAXIMO_DE_PUNTOS 3

DivisionYConquista::DivisionYConquista() {
}

DivisionYConquista::~DivisionYConquista() {
}

int DivisionYConquista::cortaElPoligono(Punto a, Punto b, Punto c) {
    return ((b.getY() - a.getY()) * (c.getX() - b.getX()) -
            (c.getY() - b.getY()) * (b.getX() - a.getX()));
}

int DivisionYConquista::getPosicionMayorX(Puntos puntos) {
    int mayor = 0;
    for (int i = 1; i < (int) puntos.size(); i++) {
        if (puntos[i].getX() > puntos[mayor].getX()) {
            mayor = i;
        }
    }
    return mayor;
}

int DivisionYConquista::getPosicionMenorX(Puntos puntos) {
    int menor = 0;
    for (int i = 1; i < (int) puntos.size(); i++) {
        if (puntos[i].getX() < puntos[menor].getX()) {
            menor = i;
        }
    }
    return menor;
}

void DivisionYConquista::hallarUpper(Puntos izq, Puntos der, int& upperIzq, int& upperDer) {
    bool done = 0;
    int tamanioIzq = (int) izq.size();
    int tamanioDer = (int) der.size();
    while (!done) {
        done = 1;
        while (this->cortaElPoligono(der[upperDer], izq[upperIzq], izq[(upperIzq + 1) % tamanioIzq]) >= 0) {
            upperIzq = (upperIzq + 1) % tamanioIzq;
        }
        while (this->cortaElPoligono(izq[upperIzq], der[upperDer], der[(tamanioDer + upperDer - 1) % tamanioDer]) <= 0) {
            upperDer = (tamanioDer + upperDer - 1) % tamanioDer;
            done = 0;
        }
    }
}

void DivisionYConquista::hallarLower(Puntos izq, Puntos der, int& lowerIzq, int& lowerDer) {
    bool done = 0;
    int tamanioIzq = (int) izq.size();
    int tamanioDer = (int) der.size();
    while (!done) {
        done = 1;
        while (this->cortaElPoligono(izq[lowerIzq], der[lowerDer], der[(lowerDer + 1) % tamanioDer]) >= 0) {
            lowerDer = (lowerDer + 1) % tamanioDer;
        }
        while (this->cortaElPoligono(der[lowerDer], izq[lowerIzq], izq[(tamanioIzq + lowerIzq - 1) % tamanioIzq]) <= 0) {
            lowerIzq = (tamanioIzq + lowerIzq - 1) % tamanioIzq;
            done = 0;
        }
    }
}

std::vector<Punto> DivisionYConquista::mergearEnvolturas(Puntos izq, Puntos der) {
    int posMasDerechaDeIzqDeX = this->getPosicionMayorX(izq);
    int posMasIzquierdaDeDerDeX = this->getPosicionMenorX(der);

    int upperIzquierda = posMasDerechaDeIzqDeX;
    int upperDerecha = posMasIzquierdaDeDerDeX;
    this->hallarUpper(izq, der, upperIzquierda, upperDerecha);

    int lowerIzquierda = posMasDerechaDeIzqDeX;
    int lowerDerecha = posMasIzquierdaDeDerDeX;
    this->hallarLower(izq, der, lowerIzquierda, lowerDerecha);       
    
    Puntos ret;
    int ind = upperIzquierda;
    ret.push_back(izq[upperIzquierda]);
    while (ind != lowerIzquierda) {
        ind = (ind + 1) % (int) izq.size();
        ret.push_back(izq[ind]);
    }
    ind = lowerDerecha;
    ret.push_back(der[lowerDerecha]);
    while (ind != upperDerecha) {
        ind = (ind + 1) % (int) der.size();
        ret.push_back(der[ind]);
    }
    return ret;

}

std::vector<Punto> DivisionYConquista::dividir(Puntos puntos) {
    if (puntos.size() <= MAXIMO_DE_PUNTOS) {
        return puntos;
    }
    int mitad = floor(puntos.size() / 2);
    Puntos izquierda, derecha, izquierdaConvexa, derechaConvexa;
    izquierda.assign(puntos.begin(), puntos.begin() + mitad);
    derecha.assign(puntos.begin() + mitad, puntos.end());
    izquierdaConvexa = dividir(izquierda);
    derechaConvexa = dividir(derecha);
    return mergearEnvolturas(izquierdaConvexa, derechaConvexa);
}

void DivisionYConquista::generarEnvolturaConvexa() {
    Puntos puntos = this->puntosSeguros;
    std::sort(puntos.begin(), puntos.end(), Comparador());
    Puntos resultado = dividir(puntos);
    for (size_t i = 1; i < resultado.size(); i++) {
        this->envolturaConvexa[resultado[i]] = resultado[i - 1];
    }
    this->envolturaConvexa[resultado[0]] = resultado[resultado.size() - 1];
}

