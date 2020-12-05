//datatypes

typedef unsigned char uint8;
typedef unsigned short uint16;


// prototypes

void delay ( uint16 u8MilliSeconds );
void CONFIG ( void );
void EXE ( void );

//defines

#define TIME_BOMB_A		4	//2 sec
#define TIME_BOMB_B		3	//1.5 sec 
#define TIME_BOMB_C		5	//2.5 sec

#define OFF				0

#define TIME_BASE		0.5