#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "Punto.h"


class Segmento {
private:
    Punto punto1;
    Punto punto2;
public:
    Segmento(Punto punto1, Punto punto2);
    Segmento(const Segmento& orig);
    virtual ~Segmento();    
};

#endif /* SEGMENTO_H */

