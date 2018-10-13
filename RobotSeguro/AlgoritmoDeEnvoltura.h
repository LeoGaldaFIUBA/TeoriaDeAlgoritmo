#ifndef ALGORITMODEENVOLTURA_H
#define ALGORITMODEENVOLTURA_H

#include <vector>
#include <map>

#include "File.h"
#include "Punto.h"

class AlgoritmoDeEnvoltura {
private:
protected:
    struct Comparador {
        bool operator()(const Punto& p1, const Punto& p2) const {
            return p1.getX() < p2.getX();
        }
    };
    
    typedef std::map<Punto, Punto, Comparador> Segmentos;
    typedef std::vector<Punto> Puntos;
    Puntos puntosSeguros;
    Puntos camino1;
    Puntos camino2;
    Segmentos envolturaConvexa;


public:
    AlgoritmoDeEnvoltura();    
    virtual ~AlgoritmoDeEnvoltura();
    void mostrar();
    virtual void generarEnvolturaConvexa();
    void calcularMinimo();
    void cargarArchivo(char* archivo);

};

#endif /* ALGORITMODEENVOLTURA_H */

