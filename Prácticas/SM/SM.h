//datatypes

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32; 

typedef enum
{
	enMenu = 0,
	enCheckInitialWeight,
	enServeDrink,
	enWaitTillServed,
	enMaxStates
}tenStates;

typedef enum
{
	enIce = 0,
	enWater,
	enLime,
	enAlcohol,
	enDelay,
	enMaxIngredients
}tenIngredients;

//prototypes

uint8 CheckInitialWeight ( uint8 u8Weight );
uint8 CheckFinalWeight ( uint8 u8Weight );
void delay ( uint16 u16MilliSeconds );
void Drinks ( uint8 u8Beverage );
uint8 CheckForProduct ( uint8 u8Beverage );
uint8 Menu (  );

//defines

#define WEIGHT_TRESHOLD_EMPTY		0		//empty cup
#define WEIGHT_TRESHOLD_FULL		10		//full cup
#define TRUE						1
#define FALSE						0

#define MARTINI						1
#define SEX_ON_THE_BEACH			2
#define CUBA						3

#define DELAY_DEFAULT 				1000	// 1 sec

#define VODKA						5	 	//servings
#define CRANBERRY_JUICE				30 		//servings
#define ORANGE_JUICE				60 		//servings
#define COLA						30 		//servings
#define LIME_JUICE					60 		//servings
#define GIN							5	 	//servings
#define VERMOUTH					20	 	//servings
#define RUM							1	 	//servings
#define OLIVES						24		//olives
#define PEACH_SCHNAPPS				60		//servings
#define ICE							99		//servings
 