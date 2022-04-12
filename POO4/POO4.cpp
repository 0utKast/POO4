#if 0
#include <iostream>
class Simple
{
private:
	int m_x{ 3 };
	int m_y{ 4 };
};

int main()
{
	Simple simple{ };
	std::cout << simple.m_x << " " << simple.m_y << std::endl;

	return 0;
}






class Simple
{
public:
	int m_x{ 3 };
	int m_y{ 4 };
};

int main()
{
	Simple simple{ 6, 7 }; // Inicialización de lista

	return 0;
}






#include <iostream>

class Fraccion
{
private:
	int m_numerador{};
	int m_denominador{};

public:
	Fraccion() // constructor predeterminado
	{
		m_numerador = 0;
		m_denominador = 1;
	}

	int getNumerador() { return m_numerador; }
	int getDenominador() { return m_denominador; }
	double getValor() { return static_cast<double>(m_numerador) / m_denominador; }
};

int main()
{
	Fraccion frac{}; // Llama al constructor predeterminado de Fraccion()
	std::cout << frac.getNumerador() << '/' << frac.getDenominador() << '\n';

	return 0;
}









#include <cassert>

class Fraccion
{
private:
	int m_numerador{};
	int m_denominador{};

public:
	Fraccion() // constructor predeterminado
	{
		m_numerador = 0;
		m_denominador = 1;
	}

	// Constructor con dos parámetros, uno de los parámetros tiene un valor predeterminado
	Fraccion(int numerador, int denominador = 1)
	{
		assert(denominador != 0); // Si el denominador es 0, lanza una excepción.
		m_numerador = numerador;
		m_denominador = denominador;
	}

	int getNumerador() { return m_numerador; }
	int getDenominador() { return m_denominador; }
	double getValor() { return static_cast<double>(m_numerador) / m_denominador; }
};

int main() {
	Fraccion cincoTercios{ 5, 3 }; // Inicialización de Lista, llama a Fraccion(int, int)
	Fraccion tresCuartos(3, 4); // Inicialización directa, también llama a Fraccion(int, int)
	Fraccion seis{ 6 }; // llama a Fraccion(int, int), segundo parámetro usa el valor predeterminado de 1


}
#endif


#include <iostream>
class Fecha
{
private:
	int m_dia{ 1 };
	int m_mes{ 1 };
	int m_anho{ 2001 };

	// Sin constructors, el compilador 
	// generará uno implícito "Fecha::Fecha( )"
};

int main()
{
	Fecha fecha{}; // Llama al constructor implícito de Fecha()
	std::cout << fecha.m_dia; // no puede acceder a miembros privados


	return 0;
}

#if 0
class Fecha
{
private:
	int m_dia{ 1 };
	int m_mes{ 1 };
	int m_anho{ 2001 };

public:
	Fecha(int dia, int mes, int anho) // constructor normal no predeterminado
	{
		m_dia = dia;
		m_mes = mes;
		m_anho = anho;
	}

	// No se provee un constructor implícito porque tenemos un constructor propio
};

int main()
{
	Fecha fecha{}; // error: No puede instanciar objeto porque el constructor predeterminado no existe
	Fecha nuevoSiglo{ 1, 1, 2001 }; // nuevoSiglo se inicializa a 1, enero, 2001

	return 0;
}


class Fecha
{
private:
	int m_dia{ 1 };
	int m_mes{ 1 };
	int m_anho{ 2001 };

public:
	// Le dice al compilador que cree un constructor predeterminado, incluso
	// aunque haya otros constructos provistos por el usuario.
	Fecha() = default;

	Fecha(int dia, int mes, int anho) // constructor normal no predeterminado
	{
		m_dia = dia;
		m_mes = mes;
		m_anho = anho;
	}
};

int main()
{
	Fecha fecha{}; // fecha es inicializado a 1, Enero, 2001
	Fecha hoy{ 11, 04, 2022 }; // hoy es inicializado a 11, abril, 2022

	return 0;
}


#include <iostream>

class Interna
{
public:
	Interna() { std::cout << "Interna\n"; }
};

class Externa
{
private:
	Interna m_interna; // Externa contiene a Interna como una variable miembro

public:
	Externa() { std::cout << "Externa\n"; }
};

int main()
{
	Externa externa;
	return 0;
}
#endif