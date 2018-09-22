#include <list>

class NumerosPrimos
{
private:
	int n;
	std::list<int> numeros_primos;
public:
	NumerosPrimos(int n);
	~NumerosPrimos();
	void procesarErastotenes();
	void procesarFuerzaBruta();
	void mostrarPrimos();
};

