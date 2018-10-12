#include "Graham.h"
#include <stack>
#include <vector>
#include <algorithm>

Graham::Graham() {
}

Graham::~Graham() {
}

int Graham::ccw(Punto a, Punto b, Punto c) {
    int area = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

int Graham::sqrDist(Punto a, Punto b)  {
    int dx = a.getX() - b.getX(), dy = a.getY() - b.getY();
    return dx * dx + dy * dy;
}

bool Graham::comparadorPunto(Punto a, Punto b) {
    int order = Graham::ccw(pivote, a, b);
    if (order == 0)
        return sqrDist(pivote, a) < sqrDist(pivote, b);
    return (order == -1);
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

    qsort(&auxiliar, this->puntosSeguros.size() - 1, sizeof (Punto), comparadorPunto(pivote));

}