//types

typedef unsigned char uint8;

//prototytpes

void DisplayMap ( uint8 au8MineMap[15][15] );
void DisplayLostMap ( uint8 au8MineMap[15][15] );
int CheckMines ( uint8 au8MineMap[15][15], uint8 u8Column, uint8 u8Row );
void PlaceMines ( uint8 au8MineMap[15][15], uint8 u8GameDifficulty );

//defines

#define TOTAL_CELLS						225
#define UNDERSCORE_ASCII				95
#define EASY_MINES						10
#define MEDIUM_MINES					20
#define HARD_MINES						30
#define HASHTAG_ASCII_CODE				35
#define ATSIGN_ASCII_CODE				64
#define START							9	
#define BOMB 							10
#define ROW 							15
#define COLUMN 							15