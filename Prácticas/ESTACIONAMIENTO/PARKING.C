#include "stdio.h" 
#include "stdlib.h" 
#include "GENFUN.H"

int main(void)
{
	uint8 location[rows][columns]={{0}};
	uint8 u8number=0;
	uint8 menu[]="\n 1.spaces \n 2.take out the car \n 3.how many cars there are \n 4.gain \n 5.go out";
	while(1)
	{
       printf("welcome to the parking\n select the number you want:%s",menu);
	   scanf("%d",&u8number);
	   switch(u8number)
	   {
	   	case 1:u8spaces(location);
	   	break;
	   	case 2:u8takeout(location);
	   	break;
	   	case 3:printf("there are %d cars\n",u8counter(location));
	   	break;
	   	case 4:u8gain(location);
	   	break;
	   	case 5:exit(0);
	   }
	}
	
}
void  u8spaces(uint8 location[rows][columns])
{
	uint8 u8x,u8y,cars;
	uint8 out=0;
	uint8 i=0;
	uint8 j,k,sum;

    printf("where are you going to park?\n");
	u8Diagram(location);
	printf("rows,columns \n" );
    scanf("%d%d",&u8x,&u8y);
    printf("How many cars?\n");
    scanf("%i",&cars);
	   if(cars>=1)
	    {
	       for(i=0;i<cars;i++)
              {
                 if(location[u8x][u8y+i]==0)
                 {
                    location[u8x][u8y+i]=1;
                    u8Diagram(location); 
                    intput++;
                 }
                 else
                 {
                   printf("sorry,the space is occupy");
                   for(j=0;j<rows&&out==0;j++)
                   {   
                       for(k=0;k<columns;k++)
                       {
                           if(location[j][k]==0)
                           {
                               printf("positions are suggested%d,%d",j,k);
                               location[j][k]=1;
                               out=1;
                               u8Diagram(location);
                               break;
                           }
                       }
                   }
                 }
              }
             printf("Nice the reservation is:%d,%d",u8x,u8y);
      	}
      	else
      	{
      	    //noting to do 
      	}
    	
	   if (sum>=25)
	     {
	         printf("sorry,no more space");
	     }
		
}
void  u8takeout(uint8 location[rows][columns])
{
    uint8 u8x,u8y,cars;
    uint8 i;
	printf("where are you going to park?\n");
	u8Diagram(location);
	printf("rows,columns \n" );
	scanf("%d%d",&u8x,&u8y);
	printf("How many cars?");
    scanf("%i",&cars);

	for(i=0;i<cars;i++)
              {
                 location[u8x][u8y-i]=0;
              } 
    u8Diagram(location);          
}
uint32 u8counter(uint8 location[rows][columns])
{
    uint8 counter=0;
    uint8 k,j;
    for(j=0;j<rows;j++)
                   {   
                       for(k=0;k<columns;k++)
                       {
                           if(location[j][k]==1)
                           {
                            counter++;  
                           }
                       }
                   }   
    return counter;
}
uint32 u8gain(uint8 location[rows][columns])
{
    uint8 earnings,cars;
    cars=u8counter(location);
    earnings=intput*25;
    printf("the number of cars: %d and the earnings: %d\n",cars,earnings);
}
void u8Diagram(uint8 location[rows][columns])
{
    uint8 i,j;
    for(j=0;j<5;j++)
    {
        for(i=0;i<5;i++)
        {
            if(location[j][i]=='*')
                printf("*");
            else 
                printf("%i",location[j][i]);
        }
        puts("");
    }
}