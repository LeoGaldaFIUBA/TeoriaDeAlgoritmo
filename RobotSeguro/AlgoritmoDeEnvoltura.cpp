#include "AlgoritmoDeEnvoltura.h"

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura() {
}

AlgoritmoDeEnvoltura::~AlgoritmoDeEnvoltura() {
}

void AlgoritmoDeEnvoltura::mostrar() {    
    Puntos::iterator it;    
    std::cout<<"Camino 1: Longitud "<< this->camino1.size() <<std::endl;  
    std::cout<<"Recorrido: ";
    for (it = this->camino1.begin(); it < this->camino1.end(); it++) {                    
        std::cout<<"["<<it->getX()<<","<<it->getY()<<"] -";                
    }    
    std::cout<<std::endl;
    std::cout<<"Camino 2: Longitud "<< this->camino2.size() <<std::endl;  
    std::cout<<"Recorrido: ";
    for (it = this->camino2.end(); it > this->camino2.begin();) {
        it--;
        std::cout<<"["<<it->getX()<<","<<it->getY()<<"] -";
    }    
    std::cout<<std::endl;
    std::cout<<"Camino Seleccionado: ";
    if(camino1.size() < camino2.size()){
        std::cout<<"1"<<std::endl;
    }else{
        std::cout<<"2"<<std::endl;
    }
    
}

void AlgoritmoDeEnvoltura::cargarArchivo(char* nombre_archivo){
    File archivo(nombre_archivo,std::ios::in);
    while(!archivo.termino()){
        this->puntosSeguros.push_back(archivo.leer());
    }    
}

void AlgoritmoDeEnvoltura::calcularMinimo(){    
    Punto puntoConvexo = this->puntosSeguros[0];    
    while(puntoConvexo.distinto(this->puntosSeguros[1])){
        camino1.push_back(puntoConvexo);
        puntoConvexo = this->envolturaConvexa[puntoConvexo];
    }
    camino1.push_back(puntoConvexo);
    
    while(puntoConvexo.distinto(this->puntosSeguros[0])){
        camino2.push_back(puntoConvexo);
        puntoConvexo = this->envolturaConvexa[puntoConvexo];
    }   
    camino2.push_back(puntoConvexo);
}

