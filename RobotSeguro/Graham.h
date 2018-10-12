#ifndef GRAHAM_H
#define GRAHAM_H

#include "AlgoritmoDeEnvoltura.h"


class Graham : public AlgoritmoDeEnvoltura {
private:    
public:
    Graham();
    virtual ~Graham();
    void generarEnvolturaConvexa();
    bool comparadorPunto(Punto a, Punto b);
    int sqrDist(Punto a, Punto b);
    int ccw(Punto a, Punto b, Punto c);
};

#endif /* GRAHAM_H */

