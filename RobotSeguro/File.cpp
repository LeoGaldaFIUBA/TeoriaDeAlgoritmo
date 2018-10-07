#include "File.h"
#include "Punto.h"

#include <string>
#include <stdlib.h>

File::File(std::string arch, std::ios_base::openmode modo): nombreArchivo(arch),
                                                       modo(modo) {
    this->archivo.open(this->nombreArchivo.c_str(), modo);
    if (this->archivo.fail()) {
        throw std::runtime_error("Error: archivo inexistente.");
    }
}

File::~File() {
}

bool File::termino(){
    return this->archivo.eof();
}

Punto File::leer(){        
    Punto punto;
    std::string linea;
    std::getline(this->archivo,linea);
    std::istringstream streamLinea(linea);
    int puntito;
    streamLinea >> puntito;      
    punto.setX(puntito);
    streamLinea >> puntito;     
    punto.setY(puntito);
    return punto;
}
