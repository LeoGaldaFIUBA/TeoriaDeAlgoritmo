#ifndef RED_H
#define RED_H

#include <vector>
#include <string>


class Red {
private:        
//    std::vector<std::vector<int>> matrizDeAdyacencia;
//    std::vector<std::vector<int>> matrizResidual;
    
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
    void mostrar();    
    bool BFS(std::vector<int> &parent);
    virtual ~Red();

};

#endif /* RED_H */

