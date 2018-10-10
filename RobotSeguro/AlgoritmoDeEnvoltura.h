#ifndef ALGORITMODEENVOLTURA_H
#define ALGORITMODEENVOLTURA_H

#include <vector>

#include "File.h"
#include "Punto.h"
#include "Segmento.h"


class AlgoritmoDeEnvoltura {
private:
protected:
    typedef std::vector<Segmento> Segmentos;
    typedef std::vector<Punto> Puntos;
    std::vector<Punto> puntosSeguros;
    Segmentos envolturaConvexa;
    
    
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

