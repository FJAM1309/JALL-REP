#include "stdio.h" 
#include "stdlib.h"
#include "time.h"
#include "BML.h"

void EXE ( void )
{
	uint16 u8MilliSeconds = 0;

	uint8 u8TIME_BOMB_A = 0;
	uint8 u8TIME_BOMB_B = 0;
	uint8 u8TIME_BOMB_C = 0;

	static uint8 u8BombA = TIME_BOMB_A;
	static uint8 u8BombB = TIME_BOMB_B;
	static uint8 u8BombC = TIME_BOMB_C;

	static uint8 u8Menu = 0;

	while( u8Menu != 1 )
	{
		printf("\n\nCONFIGURATION MODE\n");

		u8BombA = BOMB_A();
		u8BombB = BOMB_B();
		u8BombC = BOMB_C();

		printf("\nCONFIRM CONFIGURATION MODE(1/0):\n");
		scanf("%d", &u8Menu);
	}

	if( u8BombA == OFF )
	{
       u8BombA = u8TIME_BOMB_A;
	}  
	else 
	{
	   printf("BOMB A ACTIVE, TIME LEFT:%d\n",u8BombA);
       u8BombA--;
	}
	if( u8BombB == OFF )
	{
       u8BombB = u8TIME_BOMB_B;
	}  
	else 
	{
	   printf("BOMB B ACTIVE, TIME LEFT:%d\n",u8BombB);
       u8BombB--;
	}
	if( u8BombC == OFF )
	{
       u8BombC = u8TIME_BOMB_C;
	}  
	else 
	{
	   printf("BOMB C ACTIVE, TIME LEFT:%d\n",u8BombC);
       u8BombC--;
	}

	if(u8BombA == 0 && u8BombB == 0 && u8BombC == 0)
	{
		printf("ALL BOMBS FINISHED, CHANGING TO CONFIGURATION MODE\n");
		u8Menu = 0;
	}
	else
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

uint8 BOMB_A ()
{
	uint8 u8Time = 0;
	printf("active time for bomb A (seconds):");
	scanf("%d", &u8Time);

	u8Time = ( u8Time / TIME_BASE );

	return u8Time;
}

uint8 BOMB_B ()
{
	uint8 u8Time = 0;
	printf("active time for bomb B (seconds):");
	scanf("%d", &u8Time);

	u8Time = ( u8Time / TIME_BASE );

	return u8Time;
}

uint8 BOMB_C ()
{
	uint8 u8Time = 0;
	printf("active time for bomb C (seconds):");
	scanf("%d", &u8Time);

	u8Time = ( u8Time / TIME_BASE );

	return u8Time;
}