#include "AlgoritmoDeEnvoltura.h"

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura() {
}

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura(const AlgoritmoDeEnvoltura& orig) {
}

AlgoritmoDeEnvoltura::~AlgoritmoDeEnvoltura() {
}

void AlgoritmoDeEnvoltura::mostrar() {
}

void AlgoritmoDeEnvoltura::cargarArchivo(char* nombre_archivo){
    File archivo(nombre_archivo,std::ios::in);
    while(!archivo.termino()){
        this->puntosSeguros.push_back(archivo.leer());
    }    
}

void AlgoritmoDeEnvoltura::calcularMinimo(){
    
}
