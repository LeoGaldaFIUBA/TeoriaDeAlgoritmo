#ifndef FACTIBILIDAD_H
#define FACTIBILIDAD_H

#include <vector>
#include "File.h"


class Factibilidad {
private:
    std::vector<int> tarjetas;
public:
    Factibilidad(char *nombreArchivo);    
    void procesar();
    void mostrarResultado();
    virtual ~Factibilidad();

};

#endif /* FACTIBILIDAD_H */

