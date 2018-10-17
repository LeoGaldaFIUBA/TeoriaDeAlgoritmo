#include "DivisionYConquista.h"
#include "ComparadorDePuntos.h"
#include <algorithm>
#include <cmath>

#define MAXIMO_DE_PUNTOS 4

DivisionYConquista::DivisionYConquista() {
}

DivisionYConquista::~DivisionYConquista() {
}

int DivisionYConquista::cortaElPoligono(Punto a, Punto b, Punto c) {
    return ((b.getY() - a.getY()) * (c.getX() - b.getX()) -
            (c.getY() - b.getY()) * (b.getX() - a.getX()));
}

std::vector<Punto> DivisionYConquista::mergearEnvolturas(Puntos izq, Puntos der) {
    int tamanioIzq = izq.size();
    int tamanioDer = der.size();

    int posMasDerechaDeIzqDeX = 0, posMasIzquierdaDeDerDeX = 0;
    for (int i = 1; i < tamanioIzq; i++) {
        if (izq[i].getX() > izq[posMasDerechaDeIzqDeX].getX()) {
            posMasDerechaDeIzqDeX = i;
        }
    }
    for (int i = 1; i < tamanioDer; i++) {
        if (der[i].getX() < der[posMasIzquierdaDeDerDeX].getX()) {
            posMasIzquierdaDeDerDeX = i;
        }
    }


    //-----------------------------------------------------------------------------    
    int inda = posMasDerechaDeIzqDeX, indb = posMasIzquierdaDeDerDeX;
    bool done = 0;
    while (!done) {
        done = 1;
        while (this->cortaElPoligono(der[indb], izq[inda], izq[(inda + 1) % tamanioIzq]) >= 0) {
            inda = (inda + 1) % tamanioIzq;
        }
        while (this->cortaElPoligono(izq[inda], der[indb], der[(tamanioDer + indb - 1) % tamanioDer]) <= 0) {
            indb = (tamanioDer + indb - 1) % tamanioDer;
            done = 0;
        }
    }
    int uppera = inda, upperb = indb;
    //-----------------------------------------------------------------------------
    inda = posMasDerechaDeIzqDeX;
    indb = posMasIzquierdaDeDerDeX;
    done = 0;
    while (!done) {
        done = 1;
        while (this->cortaElPoligono(izq[inda], der[indb], der[(indb + 1) % tamanioDer]) >= 0)
            indb = (indb + 1) % tamanioDer;
        while (this->cortaElPoligono(der[indb], izq[inda], izq[(tamanioIzq + inda - 1) % tamanioIzq]) <= 0) {
            inda = (tamanioIzq + inda - 1) % tamanioIzq;
            done = 0;
        }
    }
    int lowera = inda, lowerb = indb;
    //-----------------------------------------------------------------------------
    Puntos ret;
    int ind = uppera;
    ret.push_back(izq[uppera]);
    while (ind != lowera) {
        ind = (ind + 1) % tamanioIzq;
        ret.push_back(izq[ind]);
    }
    ind = lowerb;
    ret.push_back(der[lowerb]);
    while (ind != upperb) {
        ind = (ind + 1) % tamanioDer;
        ret.push_back(der[ind]);
    }
    return ret;

}

void DivisionYConquista::calcularPuntos(std::set<Punto, Comparador> &s, Puntos puntos) {
    int tamanio = puntos.size();
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            int a1 = puntos[i].getY() - puntos[j].getY();
            int b1 = puntos[j].getX() - puntos[i].getX();
            int c1 = puntos[i].getX() * puntos[j].getY() - puntos[i].getY() * puntos[j].getX();
            int pos = 0, neg = 0;
            for (int k = 0; k < tamanio; k++) {
                if (a1 * puntos[k].getX() + b1 * puntos[k].getY() + c1 <= 0)
                    neg++;
                if (a1 * puntos[k].getX() + b1 * puntos[k].getY() + c1 >= 0)
                    pos++;
            }
            if (pos == tamanio || neg == tamanio) {
                s.insert(puntos[i]);
                s.insert(puntos[j]);
            }
        }
    }
}

//void DivisionYConquista::ordenarPuntosAntiHorario(Puntos ret) {
//    Punto medio;
//    int n = ret.size();
//    for (int i = 0; i < n; i++) {
//        medio.setX(medio.getX() + ret[i].getX());
//        medio.setY(medio.getY() + ret[i].getY());
//        ret[i].setX(ret[i].getX() * n);
//        ret[i].setY(ret[i].getY() * n);
//    }
//    sort(ret.begin(), ret.end(), ComparadorDePuntos(medio));
//    for (int i = 0; i < n; i++) {
//        ret[i].setX(ret[i].getX() / n);
//        ret[i].setY(ret[i].getY() / n);
//    }
//}

//std::vector<Punto> DivisionYConquista::envolturaBruta(Puntos puntos) {
//    std::set<Punto, Comparador> s;
//    Puntos ret;
//    this->calcularPuntos(s, puntos);
//    ret.assign(s.begin(), s.end());
//    this->ordenarPuntosAntiHorario(ret);
//    return ret;
//}

std::vector<Punto> DivisionYConquista::dividir(Puntos puntos) {
    if (puntos.size() < MAXIMO_DE_PUNTOS) {
//        return this->envolturaBruta(puntos);
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
    
    std::cout << "total:" << std::endl;
    for (auto elem : resultado) {
        std::cout << elem.getX() << "-" << elem.getY() << std::endl;
    }
    for (size_t i = 1; i < resultado.size(); i++) {        
        this->envolturaConvexa[resultado[i-1]] = resultado[i];
    }
    this->envolturaConvexa[resultado[resultado.size()]] = resultado[0];

}

