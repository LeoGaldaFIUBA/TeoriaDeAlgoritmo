#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <iostream>

class File {
private:
    std::string nombreArchivo;
    std::ios_base::openmode modo;
    std::fstream archivo;       
public:
    File(std::string nombre, std::ios_base::openmode modo);
    virtual ~File();
    bool termino();
    int leer();

};

#endif /* FILE_H */

