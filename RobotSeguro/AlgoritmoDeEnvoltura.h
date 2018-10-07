#ifndef ALGORITMODEENVOLTURA_H
#define ALGORITMODEENVOLTURA_H

#include <vector>

#include "File.h"
#include "Punto.h"
#include "Segmento.h"


class AlgoritmoDeEnvoltura {
private:
protected:
    std::vector<Punto> puntosSeguros;
    std::vector<Segmento> envolturaConvexa;
    
    
public:
    AlgoritmoDeEnvoltura();
    AlgoritmoDeEnvoltura(const AlgoritmoDeEnvoltura& orig);
    virtual ~AlgoritmoDeEnvoltura();
    void mostrar();
    virtual void generarEnvolturaConvexa() = 0;
    void calcularMinimo();
    void cargarArchivo(char* archivo);

};

#endif /* ALGORITMODEENVOLTURA_H */

