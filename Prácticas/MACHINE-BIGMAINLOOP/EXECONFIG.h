#include "stdio.h" 
#include "stdlib.h"
#include "time.h"
#include "BML.h"
#include "BOMB_A.h"
#include "BOMB_B.h"
#include "BOMB_C.h"


void EXE ( void )
{
	uint16 u8MilliSeconds = 0;

	static uint8 u8BombA = TIME_BOMB_A;
	static uint8 u8BombB = TIME_BOMB_B;
	static uint8 u8BombC = TIME_BOMB_C;

	static uint8 u8Menu = 0;

	while( u8Menu != 1 )
	{
		printf("\n\nCONFIGURATION MODE\n");

		printf("select time for BOMB A (seconds): ");
		scanf("%d", &u8BombA);

		printf("select time for BOMB B (seconds): ");
		scanf("%d", &u8BombB);

		printf("select time for BOMB C (seconds): ");
		scanf("%d", &u8BombC);

		printf("\nCONFIRM CONFIGURATION MODE(1/0):\n");
		scanf("%d", &u8Menu);
	}

	if( u8BombA == OFF )
	{
		//ntd
	}  
	else 
	{
	   BOMB_A( u8BombA );
       u8BombA--;
	}
	if( u8BombB == OFF )
	{
		//ntd
	}  
	else 
	{
		BOMB_B( u8BombB );
		u8BombB--;
	}
	if( u8BombC == OFF )
	{
		//ntd
	}  
	else 
	{
		BOMB_C( u8BombC );
		u8BombC--;
	}

	if(u8BombA == 0 && u8BombB == 0 && u8BombC == 0)
	{
		printf("\n\nALL BOMBS FINISHED, CHANGING TO CONFIGURATION MODE\n\n");
		u8Menu = 0;
	
}	else
	{
		//ntd
	}

	delay( 1000 );
}

void delay ( uint16 u16MilliSeconds )
{
	int milli_seconds = u16MilliSeconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds );
}
