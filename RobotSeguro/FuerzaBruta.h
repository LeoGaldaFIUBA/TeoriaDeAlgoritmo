#ifndef FUERZABRUTA_H
#define FUERZABRUTA_H

#include "AlgoritmoDeEnvoltura.h"


class FuerzaBruta : public AlgoritmoDeEnvoltura{
private:    
    
public:
    FuerzaBruta();
    FuerzaBruta(const FuerzaBruta& orig);
    virtual ~FuerzaBruta();
    void generarEnvolturaConvexa();
    int area(Punto p1, Punto p2, Punto p3);

};

#endif /* FUERZABRUTA_H */

