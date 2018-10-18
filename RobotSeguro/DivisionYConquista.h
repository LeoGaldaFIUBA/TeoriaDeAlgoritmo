#ifndef DIVISIONYCONQUISTA_H
#define DIVISIONYCONQUISTA_H

#include "AlgoritmoDeEnvoltura.h"
#include <set>


class DivisionYConquista : public AlgoritmoDeEnvoltura {
private:
    
public:
    DivisionYConquista();
    virtual ~DivisionYConquista();
    void generarEnvolturaConvexa();    
    std::vector<Punto> dividir(Puntos puntos);    
    std::vector<Punto> mergearEnvolturas(Puntos izq, Puntos der);
    int cortaElPoligono(Punto a, Punto b, Punto c);
    int getPosicionMayorX(Puntos puntos);
    int getPosicionMenorX(Puntos puntos);
    void hallarUpper(Puntos izq, Puntos der, int &upperIzq, int &upperDer);
    void hallarLower(Puntos izq, Puntos der, int &lowerIzq, int &lowerDer);
};

#endif /* DIVISIONYCONQUISTA_H */

