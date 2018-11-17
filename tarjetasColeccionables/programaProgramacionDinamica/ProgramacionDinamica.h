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
    void inicializarMatriz(std::vector<std::vector<int>> &matriz);  
    int minimo(int v1, int v2);
    void obtenerTarjetas(std::vector<std::vector<int>> &matriz);
    virtual ~ProgramacionDinamica();

};

#endif /* PROGRAMACIONDINAMICA_H */

