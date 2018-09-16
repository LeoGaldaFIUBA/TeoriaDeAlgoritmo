#include "File.h"

#include <string>
#include <stdlib.h>

File::File(std::string arch, std::ios_base::openmode modo): nombreArchivo(arch),
                                                       modo(modo) {
    this->archivo.open(this->nombreArchivo.c_str(), modo);
    if (this->archivo.fail()) {
        throw std::runtime_error("Error: archivo inexistente.");
    }
}

File::File(const File& orig) {
}

File::~File() {
}

bool File::termino(){
    return this->archivo.eof();
}

int File::leer(){
    std::string linea;
    std::getline(this->archivo,linea);
    return atoi(linea.c_str());
}

