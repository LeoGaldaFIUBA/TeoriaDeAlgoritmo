#ifndef GSPROCESADOR_H_
#define GSPROCESADOR_H_

#include <vector>
#include <map>

class GSProcesador {
private:
	typedef std::vector<int> VectorEnteros;
	typedef std::map<int, int> MapaEnteros;
	typedef std::map<int, MapaEnteros> MapaDeMapaEnteros;

	int cantidadRecitales;
	int cantidadBandas;
	int cantidadBandasXRecital;
	int cantidadRecitalesXBanda;
	MapaDeMapaEnteros preferenciasBandas;
	std::map<int, VectorEnteros> preferenciasRecitales;
	VectorEnteros siguienteBanda;
	MapaEnteros recitales;
	VectorEnteros bandas;
	MapaDeMapaEnteros apareo;

public:
	GSProcesador(int N, int M, int X, int Y);
	virtual ~GSProcesador();
	void leerArchivos();
	void procesar();
	void mostrarResultados();

private:
	void leerArchivosBandas();
	void leerArchivosRecitales();
	void agregarApareo(int recital, int banda);
	void sacarApareo(int recital, int banda);
	void incrementarContadorRecital(int recital);
	void decrementarContadorRecital(int recital);
	void actualizarSiguienteBanda(int recital);
        void actualizarApareo(int recital, int banda);
};

#endif /* GSPROCESADOR_H_ */
