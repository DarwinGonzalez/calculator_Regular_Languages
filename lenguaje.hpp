//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Declaración de los métodos y atributos de la clase lenguaje_t 
//========================================================================================

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "cadena.hpp"

using namespace std;

//!  Clase lenguaje_t. 
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase lenguaje_t
*/
class lenguaje_t
{

//! Atributos privados de la clase lenguaje_t
/*! En este apartado declaran las variables solo accecibles por metodos del objeto lenguaje_t */

private:

	//! lengua.
   	/*!Estructura set o conjunto de objetos cadena_t*/
	set<cadena_t> lengua;

	//! sz_.
   	/*!VAtributo tipo int que guarda el numero de elementos del objeto lenguaje_t */
	int sz_;

	//! infinito.
   	/*!Atributo boleano que nos indica si el lenguaje es infinito o finito, siempre iniciado de primeras presuponiendo que es finito*/
	bool infinito = false;


//! Atributos publicos de la clase lenguaje_t
/*! En este apartado declaran las variables accecibles del objeto lenguaje_t */

public:
		lenguaje_t();									//Metodo constructor de la clase lenguaje_t sin paso de parametros
		lenguaje_t(int n);								//Metodo constrcutor de la clase lenguaje_t medinate el paso de parametros
		lenguaje_t(string n);							//Metodo constructor de la clase lenguaje_t mediante un string o palabra
		~lenguaje_t();									//Metodo destructor de la clase lenguaje_t
		void add(string nuevo);							//Metodo para añadir un nuevo string al lenguaje de la clase lenguaje_t
		set<cadena_t> get_lengua();						//Metodo para obtener el conjunto o set de cadenas que compone el lenguaje_t
		void pintar();									//Metodo para mostrar el lenguaje_t por pantalla
		int get_sz();									//Metodo para obtener el numero de elementos del lenguaje_t
		string polaco(string exp);						//Metodo para pasar la expresion regular a notación polaca 
		lenguaje_t calcular(string intro);				//Metodo para calcular el lenguaje a partir de una string de intro 
		void destruir();								//Metodo para destruir y limpiar el atributo lengua
		lenguaje_t inversa();							//Metodo para obtener la inversa de un lenguaje_t
		lenguaje_t concatenar(set<cadena_t> otro);		//Metodo para concatenar los lenguajes_t
		lenguaje_t uni(set<cadena_t> otro);				//Metodo para obtener la unión de lenguajes_t
		lenguaje_t interseccion(set<cadena_t> otro);	//Metodo para obtener la intersección de varios lenguaje_t
		lenguaje_t diferencia(set<cadena_t> otro);		//Metodo para obtener la diferencia de varios lenguajes_t
		void sublenguajes(set<cadena_t> otro);			//Metodo para comprobar si hay sublenguajes
		void igual(set<cadena_t> otro);					//Metodo para comprobar si hay igualdad de lenguaje_t
		lenguaje_t potencia(int pot);					//Metodo para hallar la potencia de un lenguaje_t
		lenguaje_t cierre(int n);						//Metodo para obtener el cierre de Kleene de un lenguaje_t

};


