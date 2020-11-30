#include "stdio.h" 
#include "stdlib.h" 
#include "BML.h"

void BML (void)
{
	static unit8 u8BombA = TIME_BOMB_A;
	static unit8 u8BombB = TIME_BOMB_B;
	static unit8 u8BombC = TIME_BOMB_C;
	
	if(u8BombA == 0)
	{
       u8BombA = TIME_BOMB_A;
       // MonitorBombA();
	}  
	else 
	{
	   printf("BOMB A ACTIVE, TIME LEFT:%d\n",u8BombA);
       u8BombA--;
	}
	if(u8BombB == 0)
	{
       u8BombB = TIME_BOMB_B;
       //MonitorBombB();
	}  
	else 
	{
	   printf("BOMB B ACTIVE, TIME LEFT:%d\n",u8BombB);
       u8BombB--;
	}
	if(u8BombC == 0)
	{
       u8BombA = TIME_BOMB_C;
       MonitorBombC();
	}  
	else 
	{
	   printf("BOMB A ACTIVE, TIME LEFT:%d\n",u8BombC);
       u8BombC--;
	}
	delay(.5)

}
