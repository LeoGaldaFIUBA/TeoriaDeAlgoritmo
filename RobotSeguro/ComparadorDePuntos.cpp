#include "ComparadorDePuntos.h"

ComparadorDePuntos::ComparadorDePuntos(Punto pivote) : pivote(pivote) {
}

int ComparadorDePuntos::ccw(Punto a, Punto b, Punto c) {
    int area = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int ComparadorDePuntos::sqrDist(Punto a, Punto b)  {
    int dx = a.getX() - b.getX(), dy = a.getY() - b.getY();
    return dx * dx + dy * dy;
}

bool ComparadorDePuntos::operator ()(Punto a, Punto b){
    int order = ccw(pivote, a, b);
    if (order == 0)
        return sqrDist(pivote, a) < sqrDist(pivote, b);
    return (order == -1);   
}

ComparadorDePuntos::~ComparadorDePuntos() {
}

