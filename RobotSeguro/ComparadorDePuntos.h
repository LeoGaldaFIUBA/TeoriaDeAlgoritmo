#ifndef COMPARADORDEPUNTOS_H
#define COMPARADORDEPUNTOS_H

#include "Punto.h"

class ComparadorDePuntos {
private:
    Punto pivote;
public:
    ComparadorDePuntos(Punto pivote);
    virtual ~ComparadorDePuntos();
    bool operator()(Punto a, Punto b);
    int sqrDist(Punto a, Punto b);
    int ccw(Punto a, Punto b, Punto c);
};

#endif /* COMPARADORDEPUNTOS_H */

