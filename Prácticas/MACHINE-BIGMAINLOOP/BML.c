#include "stdio.h" 
#include "stdlib.h"
#include "time.h"
#include "BML.h"

void EXE ( void )
{
	uint16 u8MilliSeconds = 0;
	static uint8 u8BombA = TIME_BOMB_A;
	static uint8 u8BombB = TIME_BOMB_B;
	static uint8 u8BombC = TIME_BOMB_C;
	
	if( u8BombA == OFF )
	{
       u8BombA = TIME_BOMB_A;
       printf("BOMB A FINISHED, TURNING OFF");
	}  
	else 
	{
	   printf("BOMB A ACTIVE, TIME LEFT:%d\n",u8BombA);
       u8BombA--;
	}
	if( u8BombB == OFF )
	{
       u8BombB = TIME_BOMB_B;
       printf("BOMB B FINISHED, TURNING OFF");
	}  
	else 
	{
	   printf("BOMB B ACTIVE, TIME LEFT:%d\n",u8BombB);
       u8BombB--;
	}
	if( u8BombC == OFF )
	{
       u8BombA = TIME_BOMB_C;
       printf("BOMB C FINISHED, TURNING OFF");
	}  
	else 
	{
	   printf("BOMB C ACTIVE, TIME LEFT:%d\n",u8BombC);
       u8BombC--;
	}
	delay( 500 );
}

void delay ( uint16 u16MilliSeconds )
{
	clock_t goal = u16MilliSeconds + clock();
	while ( goal > clock() );
}