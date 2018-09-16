#ifndef GALEYPROCESADOR_H
#define GALEYPROCESADOR_H

#include <vector>
#include <map>

class GaleyProcesador {
private:
    int cantidadRecitales;
    int cantidadBandas;
    int cantidadBandasXRecital;
    int cantidadRecitalesXBanda;
    typedef std::vector<int> Vectorcito;    
    std::map<int ,Vectorcito> bandas;
    std::map<int , Vectorcito> recitales;
    std::map<int , std::map<int,int>> apareo;
//    std::map<int , Vectorcito> apareo;
    Vectorcito siguienteBanda;
    std::map<int,int> completoRecitales;
    Vectorcito completoBandas;    
    
public:
    GaleyProcesador(int N, int M,int X,int Y);
    GaleyProcesador(const GaleyProcesador& orig);    
    virtual ~GaleyProcesador();
    void leerArchivos();
    void agregarRecital(int recital, int banda, int preferencia);
    void agregarBanda(int banda,int recital);
    void crearBandas();
    void crearRecitales();    
    void procesar();
    int hayRecitalParaProcesar();
    void actualizarEstructura(int numeroBanda, int numeroRecital);
    void agregarElementoAlApareo(int numeroDeBanda,int numeroDeRecital);
    void actualizarApareoYAlgunasYerbas(int numeroDeBanda,int numeroDeRecital);
};

#endif /* GALEYPROCESADOR_H */

