#include "GSProcesador.h"
#include "File.h"
#include <string>
#include <iostream>

GSProcesador::GSProcesador(int N, int M, int X, int Y) : cantidadRecitales(N),
cantidadBandas(M), cantidadBandasXRecital(X), cantidadRecitalesXBanda(Y) {
}

GSProcesador::~GSProcesador() {
}

void GSProcesador::leerArchivos() {
    leerArchivosBandas();
    leerArchivosRecitales();
}

void GSProcesador::procesar() {
    while (!this->recitales.empty()) {
        int recital = this->recitales.begin()->first;
        int preferenciaRecital = this->siguienteBanda.at(recital);
        int banda = this->preferenciasRecitales.at(recital).at(preferenciaRecital);
        //		std::cout << "Comparar recital " << recital + 1
        //				<< " con banda " << banda + 1 <<std::endl;
        if (this->bandas.at(banda) < this->cantidadRecitalesXBanda) {
            agregarApareo(recital, banda);
            this->bandas[banda]++;
            incrementarContadorRecital(recital);
        } else {
            int preferenciaBanda = this->preferenciasBandas[banda][recital];
            if (preferenciaBanda < this->apareo[banda].rbegin()->first) {
                actualizarApareo(recital, banda);
            }
        }
        actualizarSiguienteBanda(recital);
    }
}

void GSProcesador::actualizarApareo(int recital, int banda) {
    int recitalAnterior = this->apareo[banda].rbegin()->second;
    sacarApareo(recitalAnterior, banda);
    agregarApareo(recital, banda);
    incrementarContadorRecital(recital);
    decrementarContadorRecital(recitalAnterior);
}

void GSProcesador::mostrarResultados() {
    for (MapaDeMapaEnteros::iterator it = apareo.begin(); it != apareo.end(); it++) {
        std::cout << "La banda " << it->first + 1
                << " va a asistir a los siguientes recitales:" << std::endl;
        for (MapaEnteros::iterator intIt = it->second.begin(); intIt != it->second.end(); intIt++) {
            std::cout << intIt->second + 1 << std::endl;
        }
    }
}

void GSProcesador::leerArchivosBandas() {
    for (int i = 0; i < this->cantidadBandas; i++) {
        std::string nombreArchivo = "banda_" + std::to_string(i + 1);
        File archivo(nombreArchivo, std::ifstream::in);
        int preferencia = 0;
        while (!archivo.termino()) {
            int recital = archivo.leer();
            recital--;
            this->preferenciasBandas[i][recital] = preferencia;
            preferencia++;
        }
        this->bandas.push_back(0);
    }
}

void GSProcesador::leerArchivosRecitales() {
    for (int i = 0; i < this->cantidadRecitales; i++) {
        std::string nombreArchivo = "recital_" + std::to_string(i + 1);
        File archivo(nombreArchivo, std::ifstream::in);
        while (!archivo.termino()) {
            int banda = archivo.leer();
            banda--;
            this->preferenciasRecitales[i].push_back(banda);
        }
        this->recitales.insert(std::pair<int, int>(i, 0));
        this->siguienteBanda.push_back(0);
    }
}

void GSProcesador::agregarApareo(int recital, int banda) {
    int preferencia = this->preferenciasBandas[banda][recital];
    this->apareo[banda][preferencia] = recital;
}

void GSProcesador::sacarApareo(int recital, int banda) {
    int preferencia = this->preferenciasBandas[banda][recital];
    this->apareo[banda].erase(preferencia);
}

void GSProcesador::incrementarContadorRecital(int recital) {
    int cantidadBandasEnRecital = ++this->recitales[recital];
    if (cantidadBandasEnRecital == this->cantidadBandasXRecital) {
        this->recitales.erase(recital);
    }
}

void GSProcesador::decrementarContadorRecital(int recital) {
    if (this->recitales.find(recital) != this->recitales.end()) {
        this->recitales[recital]--;
    } else if (this->siguienteBanda[recital] < this->cantidadBandas) {
        this->recitales.insert(std::pair<int, int>(recital, this->cantidadBandasXRecital - 1));
    }
}

void GSProcesador::actualizarSiguienteBanda(int recital) {
    int preferenciaSiguiente = ++this->siguienteBanda[recital];
    if (preferenciaSiguiente == this->cantidadBandas) {
        this->recitales.erase(recital);
    }
}
