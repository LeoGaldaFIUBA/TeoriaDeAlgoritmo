#ifndef GREEDY_H
#define GREEDY_H

#include <vector>

class Greedy {
private:    
    std::vector<int> tarjetas;
    int cantidadDeTarjetas;
    std::vector<int> sobresAEntregar;
public:
    Greedy(char* nombreArchivo, int cantidadDeTarjetas);
    void procesar();
    void mostrarResultados();
    virtual ~Greedy();

};

#endif /* GREEDY_H */

