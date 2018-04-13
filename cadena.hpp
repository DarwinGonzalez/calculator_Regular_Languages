//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Declaración e implementacion de los metodos y la clase cadena
//========================================================================================

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//!  Clase cadena_t. 
/*!
  Una clase destinada a la declaración de atributos y metodos de la clase cadena_t
*/
class cadena_t
{

//! Atributos privados de la clase cadena_t
/*! En este apartado declaran las variables solo accecibles por metodos del objeto cadena_t */

private:
	
	//! palabra.
   	/*!Variable tipo string que almacena la cadena de entrada*/
	string palabra;

	//! sz_.
   	/*!Atributo que almacena el tamaño de la palabra*/
	int sz_;

//! Atributos publicos de la clase cadena_t.
/*! En este apartado se declaran las variable sy metodos publicos del objeto cadena_t. */

public:
		cadena_t();														//Metodo constructor por defecto de la clase cadena_t
		cadena_t(string nueva);											//Metodo constructor mediante el paso de parametros de la clase cadena_t
		void set(string nueva);											//Metodo para introducir en un set esta palabra nueva
		int get_sz();													//Metodo para obtener el valor del atributo sz_ o tamaño de cadena
		string get_string();											//Metodo para obtener el contenido de la string o palabra contenida en la clase cadena_t
		int concatenar();												//Metodo para obtner la concatenación
		int* pintar();													//Metodo para poder pintar las cadenas de cadena_t
		string concatenar(string add);									//Metodo para poder concatenar cadenas de cadena_t
		bool igual( string same);										//Metodo que devuelve si una cadena o string es igual a otro
		string inversa();												//Metodo que obtiene la inversa de una string
		cadena_t& operator=(const cadena_t &rhs);						//Sobrecarga de operador "="
		int operator==(const cadena_t &rhs) const;						//Sobrecarga de operador "=="
		int operator<(const cadena_t &rhs) const;						//Sobrecarga de operador "<"
		friend ostream &operator<<(ostream &, const cadena_t &);		//Sobrecarga de operador "<<"
};



