#include "SentinelLinkedList.h"



void DemostracionSentinelLinkedList()
{
	// primero que todo, probar el constructor declarando una variable de este tipo.
	SentinelLinkedList<string> mySentinelLinkedList;

	// esa cosa se crea vacía, hay que meterle algún elemento
	mySentinelLinkedList.Append("Juan");

	// meter un elemento nuevo cuando ya no solo está NIL
	mySentinelLinkedList.Append("Maria");
	mySentinelLinkedList.Append("Pedro");

	// probemos a buscar un valor que sí está
	if (mySentinelLinkedList.Contains("Maria"))
	{
		cout << "La lista con centinela SÍ contiene a Maria" << endl;
	}
	else
	{
		cout << "La lista con centinela NO contiene a Maria" << endl;
	}

	// probemos a buscar un valor que No está
	if (mySentinelLinkedList.Contains("Juancho"))
	{
		cout << "La lista con centinela SÍ contiene a Juancho" << endl;
	}
	else
	{
		cout << "La lista con centinela NO contiene a Juancho" << endl;
	}

	cout << "el valor del nodo en posición -1 es: " <<  mySentinelLinkedList.ObtenerValorPorIndice(-1) << endl;

	// Probando PopBack
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Pedro" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Maria" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que el valor sea Juan" << endl;
	cout << "haciendo pop back: " << mySentinelLinkedList.PopBack() << " se espera que marque error porque ya debe estar vacía" << endl;

	SentinelLinkedList<string> mySentinelLinkedListADestruirse;

	// esa cosa se crea vacía, hay que meterle algún elemento
	mySentinelLinkedListADestruirse.Append("Usuario a destruirse");
	


	/*  INICIO DEL CÓDIGO DE PRUEBA DE FUNCIONES DE LA TAREA 2 DEL SEGUNDO PARCIAL    */
	SentinelLinkedList<string> miListaTarea;

	miListaTarea.PushFront("Luis Diego");
	cout << "Front: " << miListaTarea.Front() << endl; // Debe ser Luis Diego
	cout << "Back:" << miListaTarea.Back() << endl;   // Debe ser Luis Diego

	miListaTarea.PushFront("Juan Manu");
	cout << "Front: " << miListaTarea.Front() << endl; // Ahora Juan Manu es el primero
	cout << "Back" << miListaTarea.Back() << endl;   // Luis Diego sigue siendo el ultimo

	miListaTarea.PushFront("Emi");
	cout << "Front:" << miListaTarea.Front() << endl; // Ahora Emi es el primero
	cout << "Back:" << miListaTarea.Back() << endl;   // Luis Diego sigue siendo el ultimo

	//Probando PopFront

	cout << "PopFront:" << miListaTarea.PopFront() << endl;
	cout << "Nuevo Front:" << miListaTarea.Front() << endl; // Juan Manu es ahora el primero

	cout << "PopFront " << miListaTarea.PopFront() << endl;
	cout << "Nuevo Front:"<< miListaTarea.Front() << endl; // Luis Diego es ahora el primero

	cout << "PopFront:" << miListaTarea.PopFront() << endl;
	// En este punto la lista ya está vacía.

	//Probando PopFront en lista vacia
	//PopFront() deberia dar error y devolver valor por defecto (una cadena vacia)
	cout << miListaTarea.PopFront() << endl;
	/*  FIN DEL CÓDIGO DE PRUEBA DE FUNCIONES DE LA TAREA 2 DEL SEGUNDO PARCIAL    */




	///////////////// COSA APARTE, EJEMPLO DE CÓMO HACER CASOS DE PRUEBA A GRANDES RASGOS ///////////////
	///*
	//Begin with a letter.
	//Use only letters (a-z, A-Z), numbers (0-9) and whitespace ( ). 
	//Must be 3 to 24 characters long. 
	//Not case sensitive.
	//*/
	//string username = "Juancho3000";
	//// checamos si el primer caracter no es una letra
	//bool esLetraMayuscula = (username[0] >= 65 && username[0] <= 90);
	//bool esLetraMinuscula = (username[0] >= 97 && username[0] <= 122);
	//if (!esLetraMinuscula && !esLetraMayuscula)
	//{
	//	// imprimimos error porque no es una letra.
	//	cout << "El nombre debe comenzar con una letra pero comienza con: " << username[0] << endl;
	//}
	//// cadena con letra minuscula // sí debe funcionar
	//// cadena con letra mayuscula // sí debe funcionar
	//// cadena sin letra // debe imprimir error
	//// ya sabemos checar si es letra (tanto mayúscula como minúscula)
	//// números del 0 al 9 son del 48 al 57
	//// espacio en blanco es 32
	//for (int i = 0; i < username.size(); i++)
	//{
	//	esLetraMayuscula = (username[i] >= 65 && username[i] <= 90);
	//	esLetraMinuscula = (username[i] >= 97 && username[i] <= 122);
	//	bool esUnaLetra = esLetraMayuscula || esLetraMinuscula;
	//	bool esNumero = (username[i] >= 48 && username[i] <= 57);
	//	bool esEspacioEnBlanco = username[i] == 32;
	//	// si alguno de ellos no es una letra Y no es un número Y no es un espacio en blanco
	//	if (!esUnaLetra &&
	//		!esNumero &&
	//		!esEspacioEnBlanco)
	//	{
	//		cout << "El nombre contiene un caracter que no es número ni letra ni espacio en blanco: " << username[i] << endl;
	//	}
	//}
	//// puras letras
	//// puros números (excepto el primero que tiene que ser letra)
	//// puro espacio en blanco (excepto el primero que tiene que ser letra)
	//// combinar letras y números
	//// combinar letras y espacios
	//// números y espacios
	//// hacer algunas pruebas con mayúsculas y minúsculas
	//// Debe tener entre 3 y 24 caracteres.
	//if (username.size() < 3 || username.size() > 24)
	//{
	//	cout << "El nombre contiene más o menos caracteres que lo establecido: " << username.size() << endl;
	//}
	//// cadena de menos de 3
	//// cadena de 3 
	//// cadena de 3 < X < 24
	//// cadena de 24
	//// cadena de más de 24
}