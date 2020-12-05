//datatypes

typedef unsigned char uint8;
typedef unsigned short uint16;


// prototypes

void delay ( uint16 u8MilliSeconds );
void CONFIG ( void );
void EXE ( void );

uint8 BOMB_A ();
uint8 BOMB_B ();
uint8 BOMB_C ();


//defines

#define TIME_BOMB_A		8	//2 sec
#define TIME_BOMB_B		3	//1.5 sec 
#define TIME_BOMB_C		5	//2.5 sec

#define OFF				0

#define TIME_BASE		1