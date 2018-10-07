#include "AlgoritmoDeEnvoltura.h"

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura() {
}

AlgoritmoDeEnvoltura::AlgoritmoDeEnvoltura(const AlgoritmoDeEnvoltura& orig) {
}

AlgoritmoDeEnvoltura::~AlgoritmoDeEnvoltura() {
}

void AlgoritmoDeEnvoltura::cargarArchivo(char* archivo){
    File archivo(archivo);
    while(!archivo.termino()){
        this->puntosSeguros.push_back(archivo.leer());
    }    
}

void AlgoritmoDeEnvoltura::calcularMinimo(){
    
}
