#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "SM.h"

uint8 u8Ice = ICE;
uint8 u8Vodka = VODKA;
uint8 u8CBJuice = CRANBERRY_JUICE;
uint8 u8OJuice = ORANGE_JUICE;
uint8 u8Cola = COLA;
uint8 u8Lime = LIME_JUICE;
uint8 u8Gin = GIN;
uint8 u8Vermouth = VERMOUTH;
uint8 u8Rum = RUM;
uint8 u8Olives = OLIVES;
uint8 u8PeachSchnapps = PEACH_SCHNAPPS; 

void SM_BREWING ( void )
{
	uint8 u8Beverage = 0;
	uint8 u8Product = 0;
	printf("\n\nWelcome to the automatic brewing machine.\n");
	tenStates enCurrentState = enMenu;
	tenIngredients enCurrentIngredient = enIce;
	tenIngredients enNextIngredient = 0;

	while ( 1 )
	{	
		uint8 u8Weight = 0;
		uint8 u8CheckWeight = 0;
		uint8 u8Cup = 0;
		if ( enCurrentState == enMenu )
		{
			u8Beverage = Menu();
			if ( u8Beverage < 4 && u8Beverage != 0 )
			{
				enCurrentState = enCheckInitialWeight;
			}
			else
			{
				printf("\n\n\n\nOption not available, please choose a valid option.\n\n");
				enCurrentState = enMenu;
			}
		}
		else if ( enCurrentState == enCheckInitialWeight )
		{
			printf("place cup?\n");
			printf("selection (y/n): ");
			scanf(" %c", &u8Cup);

			if ( u8Cup == Y_ASCII_CHARACTER )
			{
				printf("cup placed.\n");
				u8Weight = WEIGHT_TRESHOLD_EMPTY;
			}
			else if ( u8Cup == N_ASCII_CHARACTER )
			{
				printf("no cup placed.\n");
			}
			else
			{
				printf("please enter a valid selection.\n\n");
				enCurrentState = enMenu;
			}

			u8CheckWeight = CheckInitialWeight( u8Weight );
			if( u8CheckWeight == TRUE )
			{
				printf("\ncup detected.\n");
				enCurrentState = enServeDrink;
			}
			else
			{
				printf("cup not detected.\n");
				enCurrentState = enCheckInitialWeight;
			}
		}
		else if ( enCurrentState == enServeDrink )
		{
 			switch ( enCurrentIngredient )
			{
				case enIce:
				{
					printf("\nadding ice\n");
					u8Ice--;
					enCurrentIngredient = enDelay;
					enNextIngredient = enWater;
					break;
				}
				case enWater:
				{
					printf("adding water\n");
					enCurrentIngredient = enDelay;
					enNextIngredient = enLime;
					break;
				}
				case enLime:
				{
					printf("adding lime juice\n");
					u8Lime--;
					enCurrentIngredient = enDelay;
					enNextIngredient = enAlcohol;
					break;
				}
				case enAlcohol:
				{
					if( u8Beverage == MARTINI )
					{
						printf("adding 3 oz of gin\n");
						u8Gin--;
						printf("adding 1/2 oz of vermouth\n");
						u8Vermouth--;
						printf("adding an olive\n");
						u8Olives--;
						enCurrentState = enWaitTillServed;
						break;
					}
					else if ( u8Beverage == SEX_ON_THE_BEACH )
					{
						printf("adding 1 1/3 oz of vodka\n");
						u8Vodka--;
						printf("adding 1 1/3 oz of cranberry juice\n");
						u8CBJuice--;
						printf("adding 1 1/3 oz of orange juice\n");
						u8OJuice--;
						printf("adding 2/3 oz of peach schnapps\n");
						u8PeachSchnapps--;
						enCurrentState = enWaitTillServed;
						break;
					}	
					else if ( u8Beverage == CUBA )
					{
						printf("adding 4 oz of cola\n");
						u8Cola--;
						printf("adding 1 2/3 oz of rum\n");
						u8Rum--;
						enCurrentState = enWaitTillServed;
						break;
					}
					else
					{
						//ntd
					}
					break;
				}
				case enDelay:
				{
					delay( DELAY_DEFAULT );
					enCurrentIngredient = enNextIngredient;
				}
				default:
				break;
			}
		}
		else if ( enCurrentState == enWaitTillServed )
		{
			enCurrentIngredient = enIce;
			u8CheckWeight = CheckFinalWeight( u8Weight );
			if ( u8CheckWeight == TRUE )
			{
				delay( DELAY_DEFAULT );
				printf("\nOrder completed, enjoy your drink.\n");
				enCurrentState = enMenu;
			}
			else
			{
				printf("\nOrder not completed, check levels of drinks or cup placement.\n");
			}
		}
		else
		{
			//ntd
		}
	}
}

void delay ( uint16 u16MilliSeconds )
{
	clock_t goal = u16MilliSeconds + clock();
	while ( goal > clock() );
}

uint8 CheckInitialWeight ( uint8 u8Weight )
{
	printf("\n\nchecking for cup\n");
	delay( DELAY_DEFAULT );
	printf(".\n");
	delay( DELAY_DEFAULT );
	printf("..\n");
	delay( DELAY_DEFAULT );
	printf("...\n");
	delay( DELAY_DEFAULT );

	if ( u8Weight == WEIGHT_TRESHOLD_EMPTY )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

uint8 CheckFinalWeight ( uint8 u8Weight )
{
	u8Weight = WEIGHT_TRESHOLD_FULL;
	if ( u8Weight == WEIGHT_TRESHOLD_FULL )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

uint8 CheckForProduct ( uint8 u8Beverage )
{
	if ( u8Beverage == MARTINI )
	{
		if ( u8Ice > 0 && u8Gin > 0 && u8Vermouth > 0 && u8Olives > 0 )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	} 
	else if ( u8Beverage == SEX_ON_THE_BEACH )
	{
		if ( u8Ice > 0 && u8Vodka > 0 && u8OJuice > 0 && u8CBJuice > 0 && u8PeachSchnapps > 0 )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else if ( u8Beverage == CUBA )
	{
		if ( u8Ice > 0 && u8Cola > 0 && u8Rum > 0 && u8Lime > 0 )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		printf("\n\nnot an availabe option.\n");

	}
}

uint8 Menu ()
{
	uint8 u8Beverage;
	printf("\n\nplease select a beverage: \n\n");
	printf("MARTINI 1		-	SEX ON THE BEACH 2		-	CUBA 3\n");
	printf("\nselection: ");
	scanf("%d", &u8Beverage);
	return u8Beverage;
}