#ifndef RED_H
#define RED_H

#include <vector>
#include <string>


class Red {
private:
    std::vector<std::vector<int>> matrizDeAdyacencia;
    int fuente;
    int sumidero;
public:
    Red();
    void cargarMatriz(char *archivoDeRelaciones);
    void cargarCapacidades(std::string &linea, int fila);
    void inicializarMatriz(int size);
    void agregarDemandas(char *archivoDeDemandas);
    void calcularFordFulkersen();
    void mostrar();    
    virtual ~Red();

};

#endif /* RED_H */

