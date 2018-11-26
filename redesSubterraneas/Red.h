#ifndef RED_H
#define RED_H

#include <vector>
#include <string>


class Red {
private:            
    typedef std::vector<int> VectorType;
    typedef std::vector<VectorType> Matriz;    
    Matriz matrizDeAdyacencia;
    Matriz matrizResidual;
    int fuente;
    int sumidero;
public:
    Red();
    void cargarMatriz(char *archivoDeRelaciones);
    void cargarCapacidades(std::string &linea, int fila);
    Matriz inicializarMatriz(int size);
    void agregarDemandas(char *archivoDeDemandas);
    void calcularFordFulkersen();
    void mostrarResultado();    
    bool BFS(std::vector<int> &parent);
    virtual ~Red();

};

#endif /* RED_H */

