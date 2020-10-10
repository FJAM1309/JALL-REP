
#include "stdio.h"
#include "GENFUN.h"

void main ( void )
{

	uint8 au8BufferTest[12] = "hOlA mUnDO!";
	uint8 au8BufferTest2[12] = "Hellen Kell";
	uint8 u8ArrayOcurrences = 0;
	uint8 au8NumberArray[6] = {2,2,4,1,9,12};
	uint8 u8ArrayAverage = 0;
	uint8 n = 0;
	uint8 au8RandomElements[255];


	// func caps on 
	printf("\nCaps On\n");
	printf("Buffer before function %s\n", au8BufferTest);
	GENFUN_vCapsOn( &au8BufferTest[0], 12);
	printf("Buffer after function %s\n", au8BufferTest);


	// func caps off
	printf("\nCaps Off\n");
	printf("Buffer before function %s\n", au8BufferTest);
	GENFUN_vCapsOff( &au8BufferTest[0], 12);
	printf("Buffer after function %s\n", au8BufferTest);


	//func get ocurrence 
	printf("\nGet Ocurrence\n");
	printf("Array:");
	printf("%s\n", au8BufferTest2);
	printf("Ocurrence target: %c\n", ASCII_TARGET_CODE);
	u8ArrayOcurrences = GENFUN_u8GetOccurrence ( &au8BufferTest2[0], ASCII_TARGET_CODE, 12 );
	printf("Ocurrences in array: %i\n", u8ArrayOcurrences);
	

	//func get average
	printf("\nGet Average\n");
	printf("Array of numbers: ");
	for (n = 0; n < 6; n++ )
	{
		printf("%d ", au8NumberArray[n]);
	}
	u8ArrayAverage = GENFUN_u8GetAverage ( &au8NumberArray[0], 6 );
	printf("\nAverage: %d\n", u8ArrayAverage);


	//func memory set
	printf("\nMemory Set\n");
	printf("Buffer before function: %s\n", au8BufferTest);
	printf("Element to fill: %c\n", ASCII_CODE_MEMSET);
	GENFUN_u8MemSet( au8BufferTest, ASCII_CODE_MEMSET, 12 );
	printf("Buffer after function:");
	for (n = 0; n < 12; n++ )
	{
		printf("%c", au8BufferTest[n]);
	}
	


	//func memory copy
	printf("\n\nMemory Copy\n");
	printf("First Buffer: %s\n", au8BufferTest2);
	printf("Second Buffer: ");
	for (n = 0; n < 12; n++ )
	{
		printf("%c", au8BufferTest[n]);
	}
	GENFUN_u8MemCopy( au8BufferTest, au8BufferTest2, 12 );
	printf("\nFirst buffer after function: %s\n", au8BufferTest2);
	printf("Second buffer after function: ");
	for (n = 0; n < 12; n++ )
	{
		printf("%c", au8BufferTest[n]);
	}

	//func sort list
	printf("\n\nSort List\n");
	printf("Sort in: ascending order\n");
	printf("Buffer before function: ");
	for (n = 0; n < 6; n++ )
	{
		printf("%d ", au8NumberArray[n]);
	}
	GENFUN_vSortList ( &au8NumberArray, &au8NumberArray, 6 );
	printf("\nBuffer after function: ");
	for (n = 0; n < 6; n++ )
	{
		printf("%d ", au8NumberArray[n]);
	}


	//func soft signal
	printf("\n\nSoft Signal\n");
	printf("Signal to soften (numeric):\n");

	srand(time(0));
	
	for ( n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{   
    	au8RandomElements[n] = rand() % CHAR_HIGH_THRESHOLD;
	}
	for ( n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{
		printf("%d ", au8RandomElements[n]);
	}
	GENFUN_vSoftSignal ( &au8RandomElements, &au8RandomElements);
	printf("\n\nSoftened Signal (numeric):");
	for (n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{
		printf("%d ", au8RandomElements[n]);
	}


	//func filter signal
	printf("\n\nFilter Signal\n");
	printf("Signal to filter from %d to %d:\n", LOWER_BOUND, UPPER_BOUND );
	for ( n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{   
    	au8RandomElements[n] = rand() % CHAR_HIGH_THRESHOLD;
	}
	for ( n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{
		printf("%d ", au8RandomElements[n]);
	}
	GENFUN_vFilterSignal ( &au8RandomElements, &au8RandomElements, UPPER_BOUND, LOWER_BOUND );
	printf("\n\nFiltered Signal:\n");
	for ( n = 0; n < CHAR_HIGH_THRESHOLD-1; n++ )
	{
		printf("%d ", au8RandomElements[n]);
	}

}

void GENFUN_vCapsOn ( uint8 *pu8Src, uint8 u8SizeOfList )
{
	while( u8SizeOfList != 0 )
	{
		if( *pu8Src >= ASCII_LOW_THRESHOLD_CAPSON_TO_OFF && *pu8Src <= ASCII_HIGH_THRESHOLD_CAPSON_TO_OFF )
		{
			*pu8Src -= ASCII_CONVERSION_FACTOR;
		}
		else
		{
			//nothing to do 
		}
		pu8Src++;
		u8SizeOfList--;
	}
}

void GENFUN_vCapsOff (uint8 *pu8Src, uint8 u8SizeOfList)
{
	while( u8SizeOfList != 0 )
	{
		if( *pu8Src >= ASCII_LOW_TRESHOLD_TO_ON && *pu8Src <= ASCII_HIGH_TRESHOLD_TO_ON )
		{
			*pu8Src += ASCII_CONVERSION_FACTOR	;
		}
		else
		{
			//Nothing to do
		}
		pu8Src++;
		u8SizeOfList--;
	}
}

uint8 GENFUN_u8GetOccurrence ( uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList )
{
	uint8 u8ArrayOcurrences = 0;

	while ( u8SizeOfList != 0 )
	{
		if( *pu8Src ==  u8Target )
		{
			u8ArrayOcurrences++;
		}
		else
		{
			//nothing to do 
		}
	pu8Src++;
	u8SizeOfList--;
	}
return u8ArrayOcurrences;
}

uint8 GENFUN_u8GetAverage( uint8 *pu8Src, uint8 u8SizeOfList )
{
	uint8 AverageOfArray = 0;

	for ( int i = 0; i < u8SizeOfList; ++i ) 
	{
		AverageOfArray += pu8Src[i];
	}
	AverageOfArray = ( AverageOfArray / u8SizeOfList );
	return AverageOfArray;
}

void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList)
{
	uint8 *pu8Dest = pu8Src;

	while ( u8SizeOfList-- > 0 )
	{
		*pu8Dest++ = u8Char2Set;
	}
	return *pu8Src;
}

void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)
{
	for ( int i = 0; i < u8SizeOfList; i++ )
	{
		pu8Src[i] = pu8Dest[i];
	} 
}

void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList)
{
	for ( int i = 0; i < u8SizeOfList; ++i ) 
	{

		for ( int j = i + 1; j < u8SizeOfList; ++j )
		{

			if ( pu8Src[i] > pu8Src[j] ) 
			{
				uint8 u8TemporalVar =  pu8Src[i];
				pu8Src[i] = pu8Src[j];
				pu8Src[j] = u8TemporalVar;
			}
		}
	}
}

void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest)
{
	for ( int i = 0; i<256; i++ )
	{
		pu8Dest[i]=(pu8Src[i] + pu8Src[i+1])/2;
	}

}

void GENFUN_vFilterSignal (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal)
{
for ( int i = 0; i < CHAR_HIGH_THRESHOLD; ++i ) 
	{
		for ( int j = i + 1; j < CHAR_HIGH_THRESHOLD; ++j )
		{
			if ( pu8Src[i] > UPPER_BOUND )  
			{
				pu8Src[i] = UPPER_BOUND;
			}
			else if ( pu8Src[i] < LOWER_BOUND )
			{
				// nothing to do
			}
		}
	}
}