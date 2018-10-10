#include "AlgoritmoDeEnvoltura.h"

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura() {
}

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura(const AlgoritmoDeEnvoltura& orig) {
}

AlgoritmoDeEnvoltura::~AlgoritmoDeEnvoltura() {
}

void AlgoritmoDeEnvoltura::mostrar() {
    Segmentos::iterator it;
    for (it = this->envolturaConvexa.begin(); it < this->envolturaConvexa.end(); it++) {        
        std::cout<<"punto 1: "<<it->getPunto1().getX()<<"-"<<it->getPunto1().getY()<<std::endl;
        std::cout<<"punto 2: "<<it->getPunto2().getX()<<"-"<<it->getPunto2().getY()<<std::endl;        
        std::cout<<"---------------------------------_"<<std::endl;
    }    
}

void AlgoritmoDeEnvoltura::cargarArchivo(char* nombre_archivo){
    File archivo(nombre_archivo,std::ios::in);
    while(!archivo.termino()){
        this->puntosSeguros.push_back(archivo.leer());
    }    
}

void AlgoritmoDeEnvoltura::calcularMinimo(){
    std::cout<<"calcular minimo"<<std::endl;
}
