#ifndef DIVISIONYCONQUISTA_H
#define DIVISIONYCONQUISTA_H

#include "AlgoritmoDeEnvoltura.h"


class DivisionYConquista : public AlgoritmoDeEnvoltura {
public:
    DivisionYConquista();
    DivisionYConquista(const DivisionYConquista& orig);
    virtual ~DivisionYConquista();
    void generarEnvolturaConvexa();
private:

};

#endif /* DIVISIONYCONQUISTA_H */
