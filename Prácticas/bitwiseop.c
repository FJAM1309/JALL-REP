#include "stdio.h"

typedef unsigned long u32Var;

/*PM -> Buen codigo, replicaste tal cual el diagrama, solo arreglar detalles*/
void main ( void )
{
	u32Var BitsVar = 0;			/*PM -> Recuerda la notacion hungara para las variables u32BitsVar*/
	u32Var OpToDo = 0;
	u32Var BitSel = 0;
	u32Var VarRes = 0;

	printf( "de cuantos bits es tu variable: " );
	scanf( "%d", &BitsVar );


	if( BitsVar == 8 || BitsVar == 16 || BitsVar == 32 )
	{
		while( 1 )
		{

			printf( "1-Op AND\n" );
			printf( "2-Op OR\n" );
			printf( "3-Op XOR\n" );
			printf( "seleccione la operacion deseada: " );
			scanf( "%d", &OpToDo );

			if( OpToDo > 3 || OpToDo <= 0 )			/* PM -> Recuerda usar #defines en lugar de numeros magicos*/
			{
				printf( "error. Por favor seleccione una opcion valida." );
			}
			else
			{
				printf( "corrimiento para la operacion:" );
				scanf( "%d", &BitSel );
			}
			if( BitSel < BitsVar )
			{
				if( OpToDo == 1 )					/* PM -> Recuerda usar #defines en lugar de numeros magicos*/
				{
					VarRes&=~( 1<<BitSel );
				}
				else if( OpToDo == 2 )				/* PM -> Recuerda usar #defines en lugar de numeros magicos*/
				{
					VarRes|=( 1<<BitSel );
				}
				else
				{
					VarRes^=( 1<<BitSel );	
				}
				printf( "\n\nel resultado es: %d\n\n", VarRes );
			}
			else
			{
				printf( "\nerror. Corrimiento mayor al numero de bits.\n" );
			}

		}
	}
	else
	{
		printf( "\nerror. Tamaño de la variable debe ser 8, 16 o 32.\n\n" );
	}

}
