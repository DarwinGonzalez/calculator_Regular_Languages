//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Implementacion de los metodos y la clase cadena
//========================================================================================

#include "cadena.hpp"

//Metodo constructor por defecto de la clase cadena_t
cadena_t::cadena_t(){}


//Metodo constructor mediante el paso de parametros de la clase cadena_t
cadena_t::cadena_t(string nueva)
{
	set(nueva);
}


//Metodo para introducir en un set esta palabra nueva
void cadena_t::set(string nueva)
{
	palabra = nueva;
	sz_ = nueva.size();
}


//Metodo para obtener el valor del atributo sz_ o tamaño de cadena
int cadena_t::get_sz()
{
	return sz_;
}


//Metodo para obtener el contenido de la string o palabra contenida en la clase cadena_t
string cadena_t::get_string()
{
	return palabra;
}


//Metodo para poder concatenar cadenas de cadena_t
string cadena_t::concatenar(string add)
{
	string aux;
	aux = palabra;
	if (add != "&")
	{
		for (int i = 0; i <add.size(); i++)
		{
			aux.push_back(add[i]);

		}
	}
	return aux;
}


//Metodo que devuelve si una cadena o string es igual a otro
bool cadena_t::igual(string same)
{
	if( palabra.size()!= same.size() ) return false;
	for(int i=0; i< palabra.size(); i++)
	{
		if(palabra[i] != same[i]) return false;
	} 
	return true;
}


//Metodo que obtiene la inversa de una string
string cadena_t::inversa()
{
	string aux;
	for (int i = 0; i < palabra.size(); i++)
	{
		aux.push_back(palabra[sz_ - 1 - i]);
	}
	return aux;	
}


//Sobrecarga de operador "="
cadena_t& cadena_t::operator=(const cadena_t &rhs)
{
   this->palabra = rhs.palabra;
   this->sz_ = rhs.sz_;
   return *this;
}


//Sobrecarga de operador "=="
int cadena_t::operator==(const cadena_t &rhs) const
{
   if( this->palabra != rhs.palabra) return 0;
   if( this->sz_ != rhs.sz_) return 0;
   return 1;
}


//Sobrecarga de operador "<"
int cadena_t::operator<(const cadena_t &rhs) const
{
   if(this->sz_ < rhs.sz_) return 1;
   if( this->palabra < rhs.palabra ) return 1;
   return 0;
}


//Sobrecarga de operador "<<"
ostream &operator<<(ostream &output, const cadena_t &bbb)
{
   output << " Cadena:" << bbb.palabra << endl;
   return output;
}
