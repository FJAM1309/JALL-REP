// data types

typedef unsigned char uint8;

// prototypes

void GENFUN_vCapsOn ( uint8 *pu8Src, uint8 u8SizeOfList );

void GENFUN_vCapsOff ( uint8 *pu8Src, uint8 u8SizeOfList );

uint8 GENFUN_u8GetOccurrence ( uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList );

uint8 GENFUN_u8GetAverage( uint8 *pu8Src, uint8 u8SizeOfList );

void GENFUN_u8MemSet (uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList);

void GENFUN_u8MemCopy (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);

void GENFUN_vSortList (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList);

void GENFUN_vSoftSignal (uint8 *pu8Src, uint8 *pu8Dest);

void GENFUN_vFilterSignal (uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal);

// definitions 

#define ASCII_HIGH_THRESHOLD_CAPSON_TO_OFF		122			// caps off ascii for z
#define ASCII_LOW_THRESHOLD_CAPSON_TO_OFF		97			// caps off ascii for a

#define ASCII_CONVERSION_FACTOR					32			// diff between lower and uppercase

#define ASCII_HIGH_TRESHOLD_TO_ON				90			// caps on ascii for Z
#define ASCII_LOW_TRESHOLD_TO_ON				65			// caps on ascii for A

#define ASCII_TARGET_CODE						108			// ascii code for l 			
#define ASCII_CODE_MEMSET						36			// ascii code for $

#define CHAR_HIGH_THRESHOLD						256			// randomizer up to maximum 8 bytes

#define UPPER_BOUND								180			// maximum value the graph can go
#define LOWER_BOUND								80			// minimum value the graph can go 