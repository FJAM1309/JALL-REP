#include "stdio.h"
#define menu AND 1,OR 2,XOR 3

int main()
{
    unsigned char U8bitsvar;
    unsigned char U8num;
    unsigned short U16num;
    unsigned long U32num;
    unsigned char U8bitsel;
    printf("ponga la variable");
    scanf("%c",&U8bitsvar);
    
    if(U8bitsvar==8||U8bitsvar==16||U8bitsvar==32)
    {
      printf(menu);
      scanf("%c",&U8num);
      if(U8num<=3&&U8num>0)
      {
        printf("ingrese el mismo numero");
        scanf("%c",&U8bitsel);
        if(U8bitsel<U8bitsvar)
        {
             if(U8num==1)
             {
               value&=~(1<<U8bitsel);
             }
             if else(U8num==2)
             {
               value|=(1<<U8bitsel);
             }
             if else(U8num==3)
             {
               value^=(1<<U8bitsel);
             }
          printf("%s\n",value);
          return (menu);
        }
        else
        {
          printf("error");
          return (menu);
        }
      }
      else
      {
        printf("error");
        return (menu);
      }
    }
    else (U8num!=1|2|3)
    {
      printf("error");
      return 0;
    }