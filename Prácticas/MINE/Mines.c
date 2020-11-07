#include "stdio.h"
#include "Mines.h"
#include "stdlib.h"
#include "time.h"

void main ( void )
{
	uint8 u8InitChoice = 0;
	uint8 u8GameDifficulty = 0;
	uint8 u8Column = 0;
	uint8 u8Row = 0;
	uint8 au8MineMap[15][15] = {{START}};
	uint8 u8Cell = 0;
	uint8 u8CheckMines = 0;
	uint8 u8GameScore = 0;
	uint8 u8Bombs = 0;


	for(int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			au8MineMap[i][j] = START;
		}
	}

	srand(time(NULL));

		while ( u8InitChoice == 0 )
		{
			printf("\nwelcome to minesweeper!\n");
			printf("start game?\n(1) yes\n(0) no\n");
			scanf("%d", &u8InitChoice);
		}


			printf("\nchoose game difficulty\n");
			printf("1.- baby (easy - for unexperienced players)\n");
			printf("2.- bring it on (normal - for somwhat experienced players)\n");
			printf("3.- the devil himself (hard - hardest difficulty, for players who want a challenge)\n");
			printf("selection: ");
			scanf("%d", &u8GameDifficulty);

			switch(u8GameDifficulty)
		  	{
			case 1: u8Bombs = EASY_MINES;
			break;

			case 2: u8Bombs = MEDIUM_MINES;
			break;

			case 3: u8Bombs = HARD_MINES;
		    break;

		    default: u8InitChoice = 0;
		    break;
		    }

			PlaceMines ( au8MineMap, u8GameDifficulty );
			DisplayMap ( au8MineMap );

	while ( 1 )
	{

		printf("row: ");
		scanf("%d", &u8Row);
		fflush (stdin);

		printf("column: ");
		scanf("%d", &u8Column);
		fflush (stdin);

		u8CheckMines = CheckMines ( au8MineMap, u8Column, u8Row );
		if ( u8CheckMines == 255)
		{
			system ( "cls" );
			DisplayLostMap ( au8MineMap );
			printf("btoom! game over! \nyour score: %d", u8GameScore);
			u8InitChoice = 0;

			break;
		}
		else
		{
			u8GameScore++;
			au8MineMap[u8Row][u8Column] = u8CheckMines;
		}
		
		if ( u8GameScore == TOTAL_CELLS - u8Bombs  )
		{
			system("cls");
			printf("\nyou won!!!! congratulations!\nyour score: %d points\n\n", u8GameScore);
			DisplayLostMap ( au8MineMap );
			break;
		}

		DisplayMap ( au8MineMap );
	}
}

int CheckMines ( uint8 au8MineMap[15][15], uint8 u8Column, uint8 u8Row )
{
	uint8 u8CellNumber = 0;

	if ( au8MineMap[u8Row][u8Column] == BOMB )			// same cell
	{
		return 255;
	}
	if ( au8MineMap[u8Row-1][u8Column] == BOMB && u8Column != 0 )	 // left
	{
		u8CellNumber++;
	}
	else if ( au8MineMap[u8Row-1][u8Column+1] == BOMB ) // left bottom corner
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row][u8Column+1] == BOMB ) 	// bottom
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row+1][u8Column+1] == BOMB ) // bottom right corner
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row+1][u8Column] == BOMB && u8Column != 14 ) 	// right
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row+1][u8Column-1] == BOMB ) // right top corner
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row][u8Column-1] == BOMB ) 	// top
	{
		u8CellNumber++;
	}
	if ( au8MineMap[u8Row-1][u8Column-1] == BOMB ) // top left corner
	{
		u8CellNumber++;
	}

	return u8CellNumber;
}

void DisplayLostMap ( uint8 au8MineMap[15][15] )
{
	for ( int i = 0; i < COLUMN - 5; i++ )
	{
	  	printf("%d ", i);
	}
	for ( int i = 0; i < 5; i++ )
	{
	  	printf("%d ", i);
	}
	printf("\n");
		for ( int i = 0; i < COLUMN; i++ )
	{
		printf("%c%c", UNDERSCORE_ASCII, UNDERSCORE_ASCII);
	}
	printf("\n");
	for ( int i = 0; i < COLUMN; i++ )
	{
		for ( int j = 0; j < ROW; j++ )
		{
			if ( au8MineMap[i][j] == START )
			{
				printf("%c ", HASHTAG_ASCII_CODE);
			}
			else if ( au8MineMap[i][j] == BOMB )
			{
				printf("%c ", ATSIGN_ASCII_CODE);
			}
			else
			{
				printf("%d ", au8MineMap[i][j] );
			}
		}
	    printf("| %d", i);   
		puts("");
	}
}

void DisplayMap ( uint8 au8MineMap[15][15] )
{
	for ( int i = 0; i < COLUMN - 5; i++ )
	{
	  	printf("%d ", i);
	}
	for ( int i = 0; i < 5; i++ )
	{
	  	printf("%d ", i);
	}
	printf("\n");
		for ( int i = 0; i < COLUMN; i++ )
	{
		printf("%c%c", UNDERSCORE_ASCII, UNDERSCORE_ASCII);
	}
	printf("\n");
	for ( int i = 0; i < COLUMN; i++ )
	{
		for ( int j = 0; j < ROW; j++ )
		{
			if ( au8MineMap[i][j] == START )
			{
				printf("%c ", HASHTAG_ASCII_CODE);
			}
			else if ( au8MineMap[i][j] == BOMB )
			{
				printf("%c ", HASHTAG_ASCII_CODE);
			}
			else
			{
				printf("%d ", au8MineMap[i][j] );
			}
		}
	    printf("| %d", i);   
		puts("");
	}
}

void PlaceMines ( uint8 au8MineMap[15][15], uint8 u8GameDifficulty )
{
	uint8 u8Mines = 0, u8Column = 0, u8Row = 0;

	if ( u8GameDifficulty == 1 )
	{
		u8Mines = EASY_MINES;
		printf("difficulty selected: EASY - 10 MINES\n\n");
		printf("\n\n");
		while ( u8Mines != 0 )
		{
			u8Row = rand()%(ROW);
			u8Column = rand()%(COLUMN);
			if ( au8MineMap[u8Row][u8Column] == START )
			{
				au8MineMap[u8Row][u8Column] = BOMB;
				u8Mines--;
			}
			else
			{
				// nothing to do 
			}
		}
	}
	else if ( u8GameDifficulty == 2 )
	{
		u8Mines = MEDIUM_MINES;				
		printf("difficulty selected: MEDIUM - 20 MINES\n\n");
		while ( u8Mines != 0 )
		{
			u8Row = rand()%(ROW);
			u8Column = rand()%(COLUMN);		
			if ( au8MineMap[u8Row][u8Column] == START )
			{
				au8MineMap[u8Row][u8Column] = BOMB;
				u8Mines--;
			}
			else
			{
				// nothing to do 
			}
		}
	}
	else if ( u8GameDifficulty == 3 )
	{
		u8Mines = HARD_MINES;
		printf("difficulty selected: HARD - 30 MINES\n\n");
		while ( u8Mines != 0 )
		{
			u8Row = rand()%(ROW);
			u8Column = rand()%(COLUMN);
			if ( au8MineMap[u8Row][u8Column] == START )
			{
				au8MineMap[u8Row][u8Column] = BOMB;
				u8Mines--;
			}
			else
			{
				// nothing to do 
			}
		}
	}
	else
	{
		// nothing to do 
	}
}
