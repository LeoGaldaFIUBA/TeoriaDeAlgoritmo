#ifndef PROGRAMACIONDINAMICA_H
#define PROGRAMACIONDINAMICA_H

#include <vector>

class ProgramacionDinamica {
private:    
    std::vector<int> tarjetas;
    int cantidadDeTarjetas;
    std::vector<int> sobresAEntregar;
    
public:
    ProgramacionDinamica(char* nombreArchivo, int cantidadDeTarjetas); 
    void procesar();
    void mostrarResultados();    
    virtual ~ProgramacionDinamica();

};

#endif /* PROGRAMACIONDINAMICA_H */

