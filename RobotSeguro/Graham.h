#ifndef GRAHAM_H
#define GRAHAM_H

#include "AlgoritmoDeEnvoltura.h"


class Graham : public AlgoritmoDeEnvoltura {
private:
    
public:
    Graham();
    virtual ~Graham();
    void generarEnvolturaConvexa();
};

#endif /* GRAHAM_H */

