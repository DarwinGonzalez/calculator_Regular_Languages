//======================================================================================== 
// Practica Computabilidad y Algoritmia
// Autor Darwin Gonzalez Suarez
// Programa principal
//========================================================================================
 
#include <iostream>
#include <string>
#include "cadena.hpp"
#include "lenguaje.hpp"


int main()
{
	string aux;
	int opt = 50;
	lenguaje_t A;
	lenguaje_t B;
	
	system("clear");
	std::cout<<std::endl;
	std::cout<<"\t\t<< COMPUTABILIDAD Y ALGORITMIA >>"<<std::endl;
	std::cout<<" << ====================== CALCULADORA LENGUAJES ====================== >>"<<std::endl;
	std::cout<<std::endl;

	std::cout << "Indique como desea usted introducir su lenguaje: "<< std::endl;
	std::cout << "\t[1]. Mediante cadenas o palabras. "<< std::endl;
	std::cout << "\t[2]. Mediante una expresion regular que determine ese lenguaje."<< std::endl;
	std::cout<<std::endl;
	std::cout<<"[Opcion] >> ";	
	std::cin >> opt;
	
	if(opt == 1)
	{
		std::cout << std::endl << "Introduzca el numero de cadenas para su Lenguaje A (|L(A)|):  ";
		std::cin >> opt;
		lenguaje_t LA(opt);
	
		std::cout << std::endl << "Introduzca el numero de cadenas para su lenguaje B (|L(B)|):  ";
		std::cin >> opt;
		lenguaje_t LB(opt);
		
		A = LA;
		B = LB;
	}
	
	else
	{
		if (opt == 2)
		{
			std::cout << std::endl << "Introduzca su expresion regular nº (1):  ";
			std::cin >> aux;
			lenguaje_t LA(aux);			

			std::cout << endl << "Introduzca su expresion regular nº (2):  "; 
			std::cin >> aux;
			lenguaje_t LB(aux);
			A = LA;
			B = LB;
		}

	}
	
	
	opt = 50;
	while(opt != 0)
	{
	
	std::cout << std::endl << "================MENU================";
	std::cout << std::endl << "[1]. INVERSA ( I^-1)";
	std::cout << std::endl << "[2]. CONCATENACION ( . )";
	std::cout << std::endl << "[3]. UNION ( | )";
	std::cout << std::endl << "[4]. INTERSECCION";
	std::cout << std::endl << "[5]. DIFERENCIA";
	std::cout << std::endl << "[6]. SUBLENGUAJES";
	std::cout << std::endl << "[7]. IGUALDAD DE LENGUAJES";
	std::cout << std::endl << "[8]. POTENCIA";
	std::cout << std::endl << "[9]. CIERRE DE KLEENE ( * )";
	std::cout << std::endl << "[0]. SALIR DEL PROGRAMA";
	std::cout << std::endl << "====================================";
	std::cout<<std::endl<<"[Opcion] >> ";	
	std::cin >> opt;
		
		switch(opt)
		{

			case 1:
				A.inversa().pintar();
				break;

			case 2:
				A.concatenar(B.get_lengua()).pintar();
				break;

			case 3:
				A.uni(B.get_lengua()).pintar();
				break;

			case 4:
				A.interseccion(B.get_lengua()).pintar();
				break;

			case 5:
				A.diferencia(B.get_lengua()).pintar();
				break;

			case 6:
				A.sublenguajes(B.get_lengua());
				break;

			case 7:
				A.igual(B.get_lengua());
				break;

			case 8:
				std::cout <<std::endl << "Indique la potencia a la que quiere elevar:  "<< std::endl;
				std::cin >> opt;
				A.potencia(opt).pintar();
				opt = 100;
				break;

			case 9:
				std::cout <<endl << "Indique el numero maximo de iteraciones que quiere realizar:  "<< std::endl;
				std::cin >> opt;
				A.cierre(opt).pintar();
				break;

		}
	}
}
