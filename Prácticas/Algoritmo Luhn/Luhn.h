// data types

typedef unsigned char uint8;

// prototypes

uint8 u8LuhnCheck ( uint8 *pu8Data );

// definitions

#define CARD_NUMBER_LENGHT 		16			// lenght of card 
#define ONE_DIGIT_THRESHOLD		9			// for numbers bigger than 9 (two digit)