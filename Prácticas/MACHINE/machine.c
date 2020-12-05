#include "stdio.h" 
#include "stdlib.h" 
#include "machine.h"


int main(void)
{
	uint8 menu[]="\n 1.PIÑA COLADA \n 2.MARGARITA \n 3.SANGRIA\n";
	tenStates encheckweight = 0;
	tenStates enchange = 0;
	unsigned int u8Delay = 0;
	uint8 u8number=0;
	uint16 u16glass=0;

	while(1)
	{
      printf("put the glass\n You already put the glass?\n");
      printf("if it is yes put 1788 and if it is not put 0\n");
      scanf("%d",&u16glass); 

       if(u16glass==glass)
       {  
          printf("welcome\n select the drink you want:%s",menu);
	      scanf("%d",&u8number);
	      switch(u8number)
	        {
	         	case 1:
	         	{
                    switch  (encheckweight)
	         	        {
	         	        	case enIce:
	         	        	{
                               printf("ice serve\n");
                               u8Delay = PINACOLADA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enPineapplejuice;
	         	        	}

	         	        	case enPineapplejuice:
	         	        	{
                               printf("juice serve\n");
                               u8Delay = PINACOLADA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enEvaporatedmilk;
	         	        	}
                            
                            case enEvaporatedmilk:
	         	        	{
                               printf("evaporation milk serve\n");
                               u8Delay = PINACOLADA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enCoconutcream;
	         	        	}

	         	        	case enCoconutcream:
	         	        	{
                               printf("coco nutcream serve\n");
                               u8Delay = PINACOLADA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enTequila;
	         	        	}
	         	        	case enTequila:
	         	        	{
                               printf("tequila serve\n");
                               u8Delay = PINACOLADA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
	         	        	}
	         	        	case Delay:
	         	        	{
	         	        		printf("all good\n");
	         	        		encheckweight=enchange;
	         	        	}
	         	        }
	         	        printf("drink serve\n");
                        break;
	         	}
	         	break;       
	   	        case 2:
	   	        {
                    switch  (encheckweight)
	         	        {
	         	        	case enTequila:
	         	        	{
                               printf("tequila serve\n");
                               u8Delay = MARGARITA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enLemonjuice;
	         	        	}

	         	        	case enLemonjuice:
	         	        	{
                               printf("juice serve\n");
                               u8Delay = MARGARITA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enIce;
	         	        	}
                            case enIce:
	         	        	{
                               printf("ice serve\n");
                               u8Delay = MARGARITA_TIME;
                               while(u8Delay--);
                               encheckweight=Delay;
	         	        	}
	         	        	case Delay:
	         	        	{
	         	        		printf("all good\n");
	         	        		encheckweight=enchange;
	         	        	}
	         	        }
	         	        printf("drink serve\n");
                        break;
	   	        }
                break;
	   	        case 3:
	   	        {
	   	        	switch  (encheckweight)
	         	        {
	         	        	case enRedwine:
	         	        	{
                               printf("wine serve\n");
                               u8Delay = SANGRIA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enOrangejuice;
	         	        	}

	         	        	case enOrangejuice:
	         	        	{
                               printf("juice serve\n");
                               u8Delay = SANGRIA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enFruts;
	         	        	}
                            
                            case enFruts:
	         	        	{
                               printf("fruts serve\n");
                               u8Delay = SANGRIA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enSoda;
	         	        	}

	         	        	case enSoda:
	         	        	{
                               printf("soda serve\n");
                               u8Delay = SANGRIA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
                               enchange=enIce;
	         	        	}
	         	        	case enIce:
	         	        	{
                               printf("ice serve\n");
                               u8Delay =SANGRIA_TIME ;
                               while(u8Delay--);
                               encheckweight=Delay;
	         	        	}
	         	        	case Delay:
	         	        	{
	         	        		printf("all good\n");
	         	        		encheckweight=enchange;
	         	        	}
	         	        }
	         	        printf("drink serve\n");
                        break;
	   	        }
	   	        default:
	         	     break;
	        
	         }
       } // noting to do 
	}
}
