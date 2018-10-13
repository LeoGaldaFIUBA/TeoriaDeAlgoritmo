#ifndef GRAHAM_H
#define GRAHAM_H

#include "AlgoritmoDeEnvoltura.h"

class Graham : public AlgoritmoDeEnvoltura {
private:    
public:
    Graham();
    virtual ~Graham();
    void generarEnvolturaConvexa();
    int estaALaIzquierda(Punto p0, Punto p1, Punto p2);
};

#endif /* GRAHAM_H */

