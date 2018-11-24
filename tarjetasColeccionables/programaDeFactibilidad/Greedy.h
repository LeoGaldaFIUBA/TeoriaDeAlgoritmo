#ifndef GREEDY_H
#define GREEDY_H

#include <vector>

class Greedy {
private:    
    std::vector<int> tarjetas;
    std::vector<int> sobresAEntregar;
public:
    Greedy(std::vector<int> base_sobres);
    int procesar(int cantidadDeTarjetas);
    virtual ~Greedy();

};

#endif /* GREEDY_H */

