#include "stdio.h"
#include "Luhn.h"

void main ( void )
{
	uint8 au8CardNumber[16] = {2,9,1,9,0,7,2,0,0,1,3,5,5,2,1,2};
	uint8 u8Check = 0;

	printf("CARD NUMBER: ");
	for (int n = 0; n < 16; n++ )
	{
		printf("%d ", au8CardNumber[n]);
	}
	u8Check = u8LuhnCheck( &au8CardNumber[0] );
	if( u8Check == 0 )
	{
		printf("\nCARD NUMBER (PAN) VALID.");
	}
	else
	{
		printf("\nCARD NUMBER (PAN) INVALID.");
	}
}
uint8 u8LuhnCheck ( uint8 *pu8Data )
{
	uint8 u8TempCardNumber = 0;
	uint8 u8Check = 0;
	for ( int i = 0; i < CARD_NUMBER_LENGHT; ++i ) 
	{
		if( i % 2 == 0 )
		{
			// nothing to do
		}
		else
		{
			pu8Data[i] = pu8Data[i]*2;
			if( pu8Data[i] > ONE_DIGIT_THRESHOLD )
			{
				pu8Data[i] = ( pu8Data[i] % 10 ) + 1;
			}
			else
			{
				// nothing to do
			}
		}
		u8TempCardNumber += pu8Data[i];
	}
	u8Check = u8TempCardNumber % 2;
	return u8Check;
}
