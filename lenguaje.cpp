//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Implementacion de los metodos y la clase lenguaje_t
//========================================================================================

#include "lenguaje.hpp"

//Metodo constructor de la clase lenguaje_t sin paso de parametros
lenguaje_t::lenguaje_t()
{
sz_ = 0;
}

//Metodo constrcutor de la clase lenguaje_t medinate el paso de parametros
lenguaje_t::lenguaje_t(int n)
{
	sz_ = 0;
	for(int i = 0; i < n; i++)
	{
		string aux;
		cout << endl << "Introduzca la cadena numero "<< i +1<< " de su lenguaje"<< endl;
		cin >> aux;
		add(aux);
	}
}

//Metodo constructor de la clase lenguaje_t mediante un string o palabra
lenguaje_t::lenguaje_t(string n)
{
	sz_ = 0;
	if (n[0] == '{')
	{
		if(n.size() > 2)
		{
			int i = 0;
			string aux;
			while(n[i] != '}')
			{
				i++;
				if(n[i] != ',' && n[i] != '}')
				{
				
					aux.push_back(n[i]);	
				}
				else
				{
					add(aux);
					aux.clear(); 
				}
			}
		}
	}	
	else	lengua = calcular(polaco(n)).get_lengua();
		
}

//Metodo destructor de la clase lenguaje_t
lenguaje_t::~lenguaje_t()
{
	destruir();
	std::cout<<"Su lenguaje ha sido correctamente destruido"<<std::endl;
}

//Metodo para destruir y limpiar el atributo lengua
void lenguaje_t::destruir()
{
	lengua.clear();

}

//Metodo para pasar la expresion regular a notación polaca 
string lenguaje_t::polaco(string exp )
{
	vector<char> simbolos;
	vector<char> operadores;
	for(int i = 0; i< exp.size(); i++)
	{
		char c = exp[i];
		if(c == '*' || c == '.' || c == '|' || c == '(' || c == ')')
		{ 
			
			switch(c)
			{
				case '|':
					if(operadores.empty()) operadores.push_back(c);
					else
					{
						while(!operadores.empty() && operadores.back() != '(' && operadores.back() != '|')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;

				case '.':
					if(operadores.empty() || operadores.back() == '|' || operadores.back() == '.') operadores.push_back(c);
					else
					{
						while(!operadores.empty() && operadores.back() != '('  && operadores.back() != '|' && operadores.back() != '.')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;
			
				case '*':
					if(operadores.empty() || operadores.back() == '|'|| operadores.back() == '.' || operadores.back() == '*') operadores.push_back(c);
					else
					{
						while((!operadores.empty() && operadores.back() != '('  && operadores.back() != '|' && operadores.back() != '.' )|| operadores.back() != '*')
						{
							simbolos.push_back(operadores.back());
							operadores.pop_back();
						}
						operadores.push_back(c);
					}
					break;

				case '(':
					operadores.push_back(c);
					break;

				case ')':
					while(operadores.back() != '(' && !operadores.empty())
					{
						simbolos.push_back(operadores.back());
						operadores.pop_back();
					}
					operadores.pop_back();
					break;
			}
		}
		else simbolos.push_back(c);
	}
	
	while(!operadores.empty())
	{
		simbolos.push_back(operadores.back());
		operadores.pop_back();	
	}
	cout << endl;
	string end;
	for (int i = 0; i< simbolos.size(); i++)
	{

		end.push_back(simbolos[i]);
		cout << simbolos[i];
	}
	return end;
}


//Metodo para calcular el lenguaje a partir de una string de intro 
lenguaje_t lenguaje_t::calcular(string intro)
{

	vector<lenguaje_t> aux;
	
	for(int i = 0; i< intro.size(); i++)
	{
		char c = intro[i]; 
		if(c == '*' || c == '.' || c == '|' )
		{
			lenguaje_t xua;	
			lenguaje_t uax;
			switch(c)
			{
				case '|':
					
					xua = aux.back();
					aux.pop_back();
					uax = aux.back();
					aux.pop_back();
					uax= uax.uni(xua.get_lengua());
					aux.push_back(uax);
					break;

				case '.':
					xua  = aux.back();
					aux.pop_back();
					uax = aux.back();
					aux.pop_back();
					uax= uax.concatenar(xua.get_lengua());
					aux.push_back(uax);
					break;

				case '*':
					xua  = aux.back();
					aux.pop_back();
					xua = xua.cierre(3);
					aux.push_back(xua);
					infinito = true;
					break;
			}
		}
		else
		{
			lenguaje_t xua;
			string x;
			x.push_back(c);
			xua.add(x);
			aux.push_back(xua);
			sz_ ++;
		}
	}
	lenguaje_t xua = aux.back();
	return xua;
}

//Metodo para añadir un nuevo string al lenguaje de la clase lenguaje_t
void lenguaje_t::add(string nuevo)
{
	cadena_t aux(nuevo);
	lengua.insert(aux);
	sz_++;
}


//Metodo para mostrar el lenguaje_t por pantalla
void lenguaje_t::pintar()
{
	
	cout << "{";
	for(set<cadena_t>::iterator j = lengua.begin(); j != lengua.end(); j++)
	{
			cadena_t aux = *j;
			cout << aux.get_string()<< " , ";
	}
	if (infinito == true){
		cout << ",...}";
	}
	else
	{
		cout << "}";
	}
	cout << endl;
}


//Metodo para obtener la inversa de un lenguaje_t
lenguaje_t lenguaje_t::inversa()
{
	lenguaje_t aux;
	cadena_t xua;
	for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		xua =*i;
		aux.add(xua.inversa());
	}   
	cout << "}";
	return aux;
}


//Metodo para concatenar los lenguajes_t
lenguaje_t lenguaje_t::concatenar(set<cadena_t> otro)
{
	lenguaje_t aux;
	if(!otro.empty()){
		for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena_t xua = *i;
				cadena_t uxa = *j;
			
					aux.add(xua.concatenar(uxa.get_string() ));
				
			}
		}
	}
	else
	{
		for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			cadena_t xua = *i;
			aux.add(xua.get_string());
		}

	}	
	return aux;
}

//Metodo para obtener el conjunto o set de cadenas que compone el lenguaje_t
set<cadena_t> lenguaje_t::get_lengua()
{
	return lengua;
}


//Metodo para obtener la intersección de varios lenguaje_t
lenguaje_t lenguaje_t::interseccion(set<cadena_t> otro)
{
	lenguaje_t aux;
	for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
		{
			cadena_t xua = *i;
			cadena_t uxa = *j;
			if( xua == uxa)
			{
				aux.add(xua.get_string() );
			}
		}
	}
	return aux;
}


//Metodo para obtener la unión de lenguajes_t
lenguaje_t lenguaje_t::uni(set<cadena_t> otro)
{
	lenguaje_t aux;
	for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		cadena_t xua = *i;
		aux.add(xua.get_string());
	}
	for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
	{
		cadena_t xua = *j;
		aux.add(xua.get_string());
	}
	return aux;
}


//Metodo para obtener la diferencia de varios lenguajes_t
lenguaje_t lenguaje_t::diferencia(set<cadena_t> otro)
{
	lenguaje_t aux;
	for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
	{
		bool a = false;
		cadena_t xua = *i;
		for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
		{
			
			cadena_t uxa = *j;
			if( xua == uxa)
			{
				a = true;
			}
		}
		if ( a == false) aux.add(xua.get_string() );
	}

	for(set<cadena_t>::iterator i = otro.begin(); i != otro.end(); i++)
	{
		bool a = false;
		cadena_t xua = *i;
		for(set<cadena_t>::iterator j = lengua.begin(); j != lengua.end(); j++)
		{
			
			cadena_t uxa = *j;
			if( xua == uxa)
			{
				a = true;
			}
		}
		if ( a == false) aux.add(xua.get_string() );
	}
	return aux;
}


//Metodo para comprobar si hay sublenguajes
void lenguaje_t::sublenguajes(set<cadena_t> otro)
{
	bool a = false;
	if(sz_ <= otro.size() )
	{
		for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			bool b = false;
			for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena_t xua = *i;
				cadena_t uxa = *j;
				if( xua == uxa)
				{
					b = true;
				}
			}
			if (b == false) a = true;
		}
		if(a == false) cout << endl << "La cadena A es subcadena de la cadena B"<< endl;
		else cout << endl << "La cadena A no es subcadena de la cadena B"<< endl;
	}
	else cout << endl << "La cadena A no es subcadena de la cadena B"<< endl;

}


//Metodo para comprobar si hay igualdad de lenguaje_t
void lenguaje_t::igual(set<cadena_t> otro)
{
	bool a = false;
	if(sz_ == otro.size() )
	{
		for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			bool b = false;
			for(set<cadena_t>::iterator j = otro.begin(); j != otro.end(); j++)
			{
				cadena_t xua = *i;
				cadena_t uxa = *j;
				if( xua == uxa)
				{
					b = true;
				}
			}
			if (b == false) a = true;
		}
		if(a == false) cout << endl << "La cadena A es igual a la cadena B"<< endl;
		else cout << endl << "La cadena A no es igual a la cadena B"<< endl;
	}
	else cout << endl << "La cadena A no es igual a la cadena B"<< endl;

}


//Metodo para hallar la potencia de un lenguaje_t
lenguaje_t lenguaje_t::potencia(int pot)
{
	int j = pot;
	
	lenguaje_t aux;
	lenguaje_t xua;
	if(j == 0)
	{
		aux.add("&");	
		return aux;
	}
	for(set<cadena_t>::iterator i = lengua.begin(); i != lengua.end(); i++)
		{
			cadena_t xua = *i;
			aux.add(xua.get_string());
		}
	if( j-1 > 0)
	{
		j--;
		xua = potencia(j);
		
	}
	
	return aux.concatenar(xua.get_lengua());

}


//Metodo para obtener el cierre de Kleene de un lenguaje_t
lenguaje_t lenguaje_t::cierre(int n)
{
	lenguaje_t aux;
	for (int i = 0; i< n; i++)
	{
		aux = aux.uni(potencia(i).get_lengua());
	}
	return aux;
}


