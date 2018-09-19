#include "GaleyProcesador.h"
#include "File.h"
#include <string>

GaleyProcesador::GaleyProcesador(int N, int M, int X, int Y) :
    cantidadRecitales(N),cantidadBandas(M),
    cantidadBandasXRecital(X), cantidadRecitalesXBanda(Y) {
}

GaleyProcesador::GaleyProcesador(const GaleyProcesador& orig) {
}

GaleyProcesador::~GaleyProcesador() {
}

void GaleyProcesador::agregarRecital(int recital, int banda, int preferencia) {    
    this->bandas[banda][recital] = preferencia;
//    this->bandas[banda].push_back(recital);
}

void GaleyProcesador::agregarBanda(int banda,int recital){
    this->recitales[recital].push_back(banda);
}

void GaleyProcesador::crearBandas() {    
    for (int i = 0; i < this->cantidadBandas; i++) {              
        std::vector<int> aux;  
        this->feaInicializacion(aux);
        std::string nombre = "banda_" + std::to_string(i);
        File file(nombre, std::ifstream::in);
        int preferencia = 0;            
        while (!file.termino()) {  
            int recital = file.leer();  
            aux.insert(aux.begin() + recital, preferencia);    
            preferencia++;
        }
        this->feaDestruccion(aux);
        this->bandas[i] = aux;
        this->completoBandas.push_back(0);
    }    
}

void GaleyProcesador::crearRecitales() {
    for (int i = 0; i < this->cantidadRecitales; i++) {        
        std::string nombre = "recital_" + std::to_string(i);
        File file(nombre, std::ifstream::in);        
        while (!file.termino()) {            
            int banda = file.leer();
            this->agregarBanda(banda, i);
        }        
        this->siguienteBanda.push_back(0);
        this->completoRecitales.insert(std::pair<int,int>(i,0));
    }        
}


void GaleyProcesador::feaInicializacion(std::vector<int> &aux){
    for (int i = 0; i < this->cantidadBandas; i++) {
        aux.push_back(-1);
    }
}

void GaleyProcesador::feaDestruccion(std::vector<int> &aux){
    Vectorcito::iterator it;
    it = aux.begin();
    
    for(; it != aux.end();){
        if(*it == -1){
            it = aux.erase(it);            
        }        
        else{
            ++it;
        }
    }
}

void GaleyProcesador::leerArchivos() {
    this->crearBandas();
    this->crearRecitales();
//    std::map<int ,Vectorcito>::iterator it;
//    Vectorcito::iterator vecIt;
//    for(it = this->bandas.begin(); it != this->bandas.end(); it++){
//        std::cout<<"numero de banda:"<<it->first<<std::endl;
//        std::cout<<"prefencia: ";
//        for(vecIt = it->second.begin();vecIt != it->second.end(); vecIt++){
//            std::cout<<*vecIt<<"-";
//        }
//        std::cout<<std::endl;
//    }
//    for(it = this->recitales.begin(); it != this->recitales.end(); it++){
//        std::cout<<"numero de recital:"<<it->first<<std::endl;
//        std::cout<<"prefencia: ";
//        for(vecIt = it->second.begin();vecIt != it->second.end(); vecIt++){
//            std::cout<<*vecIt<<"-";
//        }
//        std::cout<<std::endl;
//    }
}

int GaleyProcesador::hayRecitalParaProcesar(){
//    std::cout<<"toma:"<<this->completoRecitales.begin()->second<<std::endl;
    if(this->completoRecitales.empty()){
      return -1;   
    }        
    return this->completoRecitales.begin()->first;    
}

void GaleyProcesador::actualizarEstructura(int numeroBanda, int numeroRecital){
    this->siguienteBanda[numeroRecital]++;
//    int unValor = ++this->siguienteBanda[numeroRecital];    
    int unValor = this->siguienteBanda[numeroRecital];
    std::cout<<"valor:"<<unValor<<std::endl;
    if(unValor == this->cantidadBandas){
        this->completoRecitales.erase(numeroRecital);
    }else{
        this->completoRecitales.at(numeroRecital)++;        
//        this->completoRecitales[numeroRecital]++;
        int sarasonga = this->completoRecitales[numeroRecital];
        if(sarasonga == this->cantidadBandasXRecital){
            this->completoRecitales.erase(numeroRecital);
        }
    }    
}

void GaleyProcesador::agregarElementoAlApareo(int numeroDeBanda, int numeroDeRecital){
//    this->apareo[numeroDeBanda].push_back(numeroDeRecital);    
    int preferencia = this->bandas[numeroDeBanda][numeroDeRecital];    
    this->apareo[numeroDeBanda].insert(std::pair<int,int>(preferencia,numeroDeRecital));
}

void GaleyProcesador::actualizarApareoYAlgunasYerbas(int numeroDeBanda, int numeroDeRecital){
    int recitalAnterior = this->apareo[numeroDeBanda].rbegin()->second;
    int preferenciaAnterior = this->apareo[numeroDeBanda].rbegin()->first;
    int preferenciaActual = this->bandas[numeroDeBanda][numeroDeRecital];
    this->apareo[numeroDeBanda].erase(preferenciaAnterior);
    this->apareo[numeroDeBanda].insert(std::pair<int,int>(preferenciaActual,numeroDeRecital));
        
    this->actualizarEstructura(numeroDeBanda,numeroDeRecital);    
    
    if(this->completoRecitales.find(recitalAnterior) != this->completoRecitales.end()){
        this->completoRecitales[recitalAnterior]--;
    }else{
        this->completoRecitales.insert(std::pair<int,int>(recitalAnterior,this->cantidadBandasXRecital - 1));
    }
}

void GaleyProcesador::procesar(){     
    int numeroDeRecital = this->hayRecitalParaProcesar();
    while(numeroDeRecital >= 0){        
        int numeroDePreferenciaRecital = this->siguienteBanda[numeroDeRecital];
        int numeroDeBanda = this->recitales.at(numeroDeRecital).at(numeroDePreferenciaRecital);                        
        std::cout<<"numero de banda"<<numeroDeBanda<<std::endl;
        if(this->completoBandas.at(numeroDeBanda) < this->cantidadRecitalesXBanda){    
            this->agregarElementoAlApareo(numeroDeBanda,numeroDeRecital);
            this->actualizarEstructura(numeroDeBanda, numeroDeRecital);
            this->completoBandas[numeroDeBanda]++;
        }else{
            std::cout<<"entre al else"<<std::endl;
            int numeroDePreferenciaBanda = this->bandas[numeroDeBanda][numeroDeRecital];
            std::cout<<"numero de pref "<<numeroDePreferenciaBanda<<std::endl;
            if(numeroDePreferenciaBanda < this->apareo[numeroDeBanda].rbegin()->first){
                std::cout<<"actualizar"<<std::endl;
                this->actualizarApareoYAlgunasYerbas(numeroDeBanda,numeroDeRecital);
            }else{
                this->siguienteBanda[numeroDeRecital]++;
                
            }
        }
        numeroDeRecital = hayRecitalParaProcesar();
        std::cout<<"numero recital:"<<numeroDeRecital<<std::endl;
    }    
}


void GaleyProcesador::mostrarResultado(){
    std::cout<<"mostrar Resultado:"<<std::endl;
    for (SuperTMapInt::iterator it = apareo.begin(); it != apareo.end(); it++) {
        std::cout<<"La banda "<<it->first <<" va a asistir a los siguientes recitales:"<<std::endl;
        for (TMapInt::iterator intIt = it->second.begin(); intIt != it->second.end(); intIt++) {
            std::cout<<intIt->second<<std::endl;
        }
    }
}

