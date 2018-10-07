#include "Punto.h"

Punto::Punto() {
}

Punto::Punto(const Punto& orig) {
}

Punto::~Punto() {
}

void Punto::setY(int y) {
    this->y = y;
}

int Punto::getY() const {
    return y;
}

void Punto::setX(int x) {
    this->x = x;
}

int Punto::getX() const {
    return x;
}

bool Punto::distinto(Punto otroPunto){
    if((this->x != otroPunto.x) || (this->y != otroPunto.y)){
        return true;
    }
    return false;
}
