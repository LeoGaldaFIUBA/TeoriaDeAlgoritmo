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
//    std::vector<Punto> envolturaBruta(Puntos puntos);
    void calcularPuntos(std::set<Punto,Comparador> &s, Puntos puntos);
//    void ordenarPuntosAntiHorario(Puntos ret);
    std::vector<Punto> mergearEnvolturas(Puntos izq, Puntos der);
    int cortaElPoligono(Punto a, Punto b, Punto c);
};

#endif /* DIVISIONYCONQUISTA_H */

