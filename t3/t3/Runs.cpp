#include "stdafx.h"
#include "Runs.h"
#include "str.h"

void RunTask3_1(void)
{
	unsigned char* line = ( unsigned char* )calloc( MAX_LINE_LEN, sizeof( unsigned char ) );
	unsigned wordLen = 0;
	unsigned maxWordLen = 0;
	unsigned char* maxWord = NULL;
	unsigned char* maxLineWord = NULL;
	line[0]=' ';

	do// input strings 
	{
		printf( "Input line( max - %u characters, CTRL-Z - end of input )--->", MAX_LINE_LEN );
		scanf( "%1000[^\n]s", line);

		maxLineWord = MaxWord( line );
		wordLen = StrLen( maxLineWord );

		printf("\nLongest word in line - <%s>, its lenght - %u\n", maxLineWord, wordLen );
	
		if( maxWordLen <= wordLen )
		{
			maxWordLen = wordLen;
			maxWord = maxLineWord;
		}

		printf( "\n" );
		fflush(stdin);
	}
	while( !feof( stdin ) );

	printf( "Longest word in all lines - %s, its lenght - %u\n", maxWord, maxWordLen );

	free( line );
	_getch();
}