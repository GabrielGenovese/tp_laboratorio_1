int suma(int numero1,int numero2,int* resultado)
{
	int retorno = 0;

	if(numero1|| numero2)
	{
		*resultado = numero1 + numero2;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}



int resta(int numero1,int numero2,int* resultado)
{
	int retorno = 0;

	if(numero1 || numero2)
	{
		*resultado = numero1 - numero2;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}



int multiplicacion(int numero1,int numero2,int* resultado)
{
	int retorno = 0;

	if(numero1 || numero2)
	{
		*resultado = numero1 * numero2;
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}



int division (int numero1,int numero2,float* resultado)
{
	int retorno = 0;

	if(numero1 && numero2)
	{
		*resultado = (float)numero1 / numero2;
	}
	else
	{
		retorno = 1;
	}
	return retorno;
}



int factorial(int numero,long int* resultado)
{

	long int acumulador = 1;
	int retorno = 0;

	if (numero > -1)
	{
		if(numero <13)
		{
			for(int i = numero; i > 0; i--)
			{
				acumulador *= i;
			}
			*resultado = acumulador;
		}
		else
		{
			retorno = 1;
		}

	}
	else
	{
		retorno = -1;
	}

	return retorno;
}
