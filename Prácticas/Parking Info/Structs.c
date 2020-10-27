#include "stdio.h"
#include "Structs.h"

/* Descripcion 

->Crear un programa que simule un estacionamiento con 5 diferentes secciones 0, 1, 2, 3 o 4. Cada seccion tendra un cupo máximo de carros que sera definido por Defines diferentes. 
->Se tiene que usar un arreglo de estructuras para manejar los estacionamientos, la estructura es la de abajo.
->El programa correra en un ciclo infinito y habra funciones aleatorias que metan y saquen carros de las diferentes secciones.
->El programa debe tener una lógica que atienda las peticiones siguientes con funciones:
	*Obtener el número de espacios disponibles de una sección (F1)
	*Obtener el número de espacios no disponibles de una sección (F2)
	*Obtener ganancias de sección(F3)
	*Registrar vehiculo ingresado(F4)
	*Remover vehiculo(F5)
	*Registrar pago de vehiculo ingresado(F6)
*/

/* Funciones */
/*
->(F1) Una función con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios disponibles de esa seccion
->(F2) Una función con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios no disponibles de esa seccion
->(F3) Una función con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de dinero acumulada en esa sección
->(F4) Una función con 1 parametro, la cual reciba la seccion de estacionamiento y permita ingresar un vehiculo a esa seccion
->(F5) Una función con 1 parametro, la cual reciba la seccion de estacionamiento y permita retirar un vehiculo de la cuenta de la seccion
->(F6) Una función con 1 parametro, la cual reciba la seccion de estacionamiento y registre el pago por haber ingresado el vehiculo
*/

tstParkingInfo astMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	uint8 u8SlotAvailable = 0;
	uint8 u8EmptyParking = 0;

	// available slots 
	astMyParks[enSector0].u8AvailableSlots = SECTOR0_SLOTS;
	astMyParks[enSector1].u8AvailableSlots = SECTOR1_SLOTS;
	astMyParks[enSector2].u8AvailableSlots = SECTOR2_SLOTS;
	astMyParks[enSector3].u8AvailableSlots = SECTOR3_SLOTS;
	astMyParks[enSector4].u8AvailableSlots = SECTOR4_SLOTS;

	// not available slots
	astMyParks[enSector0].u8NotAvailableSlots = EMPTY_SLOTS;
	astMyParks[enSector1].u8NotAvailableSlots = EMPTY_SLOTS;
	astMyParks[enSector2].u8NotAvailableSlots = EMPTY_SLOTS;
	astMyParks[enSector3].u8NotAvailableSlots = EMPTY_SLOTS;
	astMyParks[enSector4].u8NotAvailableSlots = EMPTY_SLOTS;




	while ( u8InputAction != 6 )
	{
		fflush(stdin);
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d", u8InputAction );

		printf("\nEnter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("\nSector Selected %d\n", enSector );

		if( enSector < enMaxSectors )
		{
			if( u8InputAction == 1 )
			{
				ShowAvailableSlots( enSector );
			}
			else if( u8InputAction == 2 )
			{
				ShowNotAvailableSlots ( enSector );
			}
			else if( u8InputAction == 3 )
			{
				ShowEarnedMoney( enSector );
			}
			else if( u8InputAction == 4 )
			{
				u8SlotAvailable = 0;
				u8SlotAvailable = u8AddCarToSector( enSector );
				if ( u8SlotAvailable == 1 )
				{
					printf("car successfully added to sector %d\n", enSector);
					u8ImportPaymentOfSlot( enSector );
				}
				else
				{
					printf("car fail to be added to sector %d, sector full \n", enSector);
				}
			}
			else if ( u8InputAction == 5 )
			{
				u8EmptyParking = 0;
				u8EmptyParking = u8RemoveCarFromSector( enSector );
				if ( u8EmptyParking == 1 )
				{
					printf("car successfully removed from sector %d\n", enSector);
				}
				else
				{
					printf("no cars left to remove from sector %d\n", enSector);
				}
			}
			else
			{
				// not a valid option 
			}
			printf("\n\n");
		}
		else
		{
			printf("not a valid sector\n\n");/*Not a valid sector*/
		}

	}
}

/*F1*/
void ShowAvailableSlots ( tenParkingSectors enCurrentSector )
{
	uint8 u8ShowAvailable = 0;

	if ( enCurrentSector == enSector0 )
	{
		u8ShowAvailable = astMyParks[enSector0].u8AvailableSlots;
		printf("\nsector 0 available slots: %d\n", u8ShowAvailable);
	}
	else if ( enCurrentSector == enSector1 )
	{
		u8ShowAvailable = astMyParks[enSector1].u8AvailableSlots;
		printf("\nsector 1 available slots: %d\n", u8ShowAvailable);
	}
	else if ( enCurrentSector == enSector2 )
	{
		u8ShowAvailable = astMyParks[enSector2].u8AvailableSlots;
		printf("\nsector 2 available slots: %d\n", u8ShowAvailable);
	}
	else if ( enCurrentSector == enSector3 )
	{	
		u8ShowAvailable = astMyParks[enSector3].u8AvailableSlots;
		printf("\nsector 3 available slots: %d\n", u8ShowAvailable);
	}
	else if ( enCurrentSector == enSector4 )
	{
		u8ShowAvailable = astMyParks[enSector4].u8AvailableSlots;
		printf("\nsector 4 available slots %d\n", u8ShowAvailable);
	}
	else
	{
		// nothing to do
	}
}

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
	uint8 u8ShowNotAvailable = 0;

	if ( enCurrentSector == enSector0 )
	{
		u8ShowNotAvailable = astMyParks[enSector0].u8NotAvailableSlots;
		printf("\nsector 0 not available slots: %d\n", u8ShowNotAvailable);
	}
	else if ( enCurrentSector == enSector1 )
	{
		u8ShowNotAvailable = astMyParks[enSector1].u8NotAvailableSlots;
		printf("\nsector 1 not available slots: %d\n", u8ShowNotAvailable);
	}
	else if ( enCurrentSector == enSector2 )
	{
		u8ShowNotAvailable = astMyParks[enSector2].u8NotAvailableSlots;
		printf("\nsector 2 not available slots: %d\n", u8ShowNotAvailable);
	}
	else if ( enCurrentSector == enSector3 )
	{	
		u8ShowNotAvailable = astMyParks[enSector3].u8NotAvailableSlots;
		printf("\nsector 3 not available slots: %d\n", u8ShowNotAvailable);
	}
	else if ( enCurrentSector == enSector4 )
	{
		u8ShowNotAvailable = astMyParks[enSector4].u8NotAvailableSlots;
		printf("\nsector 4 not available slots %d\n", u8ShowNotAvailable);
	}
	else
	{
		// nothing to do
	}
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector )
{
	uint8 u8ShowMoney = 0;
	if ( enCurrentSector == enSector0 )
	{
		u8ShowMoney = astMyParks[enSector0].u32MoneyEarn;
		printf("\nmoney in sector %d is $%d", enCurrentSector, u8ShowMoney);
	}
	else if ( enCurrentSector == enSector1 )
	{
		u8ShowMoney = astMyParks[enSector1].u32MoneyEarn;
		printf("\nmoney in sector %d is $%d", enCurrentSector, u8ShowMoney);
	}
	else if ( enCurrentSector == enSector2 )
	{
		u8ShowMoney = astMyParks[enSector2].u32MoneyEarn;
		printf("\nmoney in sector %d is $%d", enCurrentSector, u8ShowMoney);
	}
	else if ( enCurrentSector == enSector3 )
	{
		u8ShowMoney = astMyParks[enSector3].u32MoneyEarn;
		printf("\nmoney in sector %d is $%d", enCurrentSector, u8ShowMoney);
	}
	else if ( enCurrentSector == enSector4 )
	{
		u8ShowMoney = astMyParks[enSector4].u32MoneyEarn;
		printf("\nmoney in sector %d is $%d", enCurrentSector, u8ShowMoney);
	}
	else
	{
		//nothing to do 
	}
}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{
	if ( enCurrentSector == enSector0 )
	{
		if ( astMyParks[enSector0].u8AvailableSlots > 0 )
		{
			astMyParks[enSector0].u8AvailableSlots--;
			astMyParks[enSector0].u8NotAvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector1 )
	{
		if ( astMyParks[enSector1].u8AvailableSlots > 0 )
		{
			astMyParks[enSector1].u8AvailableSlots--;
			astMyParks[enSector1].u8NotAvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector2 )
	{
		if ( astMyParks[enSector2].u8AvailableSlots > 0 )
		{
			astMyParks[enSector2].u8AvailableSlots--;
			astMyParks[enSector2].u8NotAvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if( enCurrentSector == enSector3 )
	{
		if ( astMyParks[enSector3].u8AvailableSlots > 0 )
		{
			astMyParks[enSector3].u8AvailableSlots--;
			astMyParks[enSector3].u8NotAvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector4 )
	{
		if ( astMyParks[enSector4].u8AvailableSlots > 0 )
		{
			astMyParks[enSector4].u8AvailableSlots--;
			astMyParks[enSector4].u8NotAvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else
	{
		//nothing to do 
	}
}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{
	if ( enCurrentSector == enSector0 )
	{
		if ( astMyParks[enSector0].u8NotAvailableSlots > 0 )
		{
			astMyParks[enSector0].u8NotAvailableSlots--;
			astMyParks[enSector0].u8AvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector1 )
	{
		if ( astMyParks[enSector1].u8NotAvailableSlots > 0 )
		{
			astMyParks[enSector0].u8NotAvailableSlots--;
			astMyParks[enSector0].u8AvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector2 )
	{
		if ( astMyParks[enSector2].u8NotAvailableSlots > 0 )
		{
			astMyParks[enSector0].u8NotAvailableSlots--;
			astMyParks[enSector0].u8AvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if( enCurrentSector == enSector3 )
	{
		if ( astMyParks[enSector3].u8NotAvailableSlots > 0 )
		{
			astMyParks[enSector0].u8NotAvailableSlots--;
			astMyParks[enSector0].u8AvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else if ( enCurrentSector == enSector4 )
	{
		if ( astMyParks[enSector4].u8NotAvailableSlots > 0 )
		{
			astMyParks[enSector0].u8NotAvailableSlots--;
			astMyParks[enSector0].u8AvailableSlots++;
			return PARKING_LOT_AVAILABLE;
		}
		else
		{
			return PARKING_LOT_UNAVAILABLE;
		}
	}
	else
	{
		//nothing to do 
	}
}
/*F6*/
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{
	if ( enCurrentSector == enSector0 )
	{
		astMyParks[enSector0].u32MoneyEarn += PARKING_COST;
	}
	else if ( enCurrentSector == enSector1 )
	{
		astMyParks[enSector1].u32MoneyEarn += PARKING_COST;
	}
	else if ( enCurrentSector == enSector2 )
	{
		astMyParks[enSector2].u32MoneyEarn += PARKING_COST;
	}
	else if ( enCurrentSector == enSector3 )
	{
		astMyParks[enSector3].u32MoneyEarn += PARKING_COST;
	}
	else if ( enCurrentSector == enSector4 )
	{
		astMyParks[enSector4].u32MoneyEarn += PARKING_COST;
	}
	else
	{
		//nothing to do 
	}
}