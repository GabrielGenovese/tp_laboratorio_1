int suma(int numero1,int numero2,int* resultado)
{
	*resultado = numero1 + numero2;
	return 0;
}



int resta(int numero1,int numero2,int* resultado)
{
	*resultado = numero1 - numero2;
	return 0 ;
}



int multiplicacion(int numero1,int numero2,int* resultado)
{
	*resultado = numero1 * numero2;
	return 0;
}



int division (int numero1,int numero2,int *bandera,float* resultado)
{
	if(numero2)
	{
		*resultado = (float)numero1 / numero2;
	}
	else
	{
		*bandera = 1;
	}
	return 0;
}



int factorial(int numero,int* resultado)
{
	int acumulador = 1;

	for(int i = numero; i > 0; i--)
	{
		acumulador *= i;
	}

	*resultado = acumulador;
	return 0;
}
