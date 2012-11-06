#include "stdafx.h"
#include "str.h"

void ShowMenu(void )
{
	printf( "\n\
			 1. Input string\n\
			 2. Longest word\n\
			 3. Inverted order of words\n\
			 4. Hide words\n\
			 5. Show string\n\
			 0. Exit\n\
			 Your choise-->");
}

unsigned StrLen( const unsigned char* line )
{
	if( line )
	{
		unsigned len = 0;
		while( *( line + len ) )
		{
			len++;
		}
		return  len;
	}

	return 0;
}

/* Task 3.1*/
unsigned char* MaxWord( unsigned char* line)
{
	if( line )
	{
		int wordLen = 0;//lenght of current word
		int maxLen = 0;// lenght of longest word
		unsigned len = StrLen( line );// lenght of the input string
		unsigned char *beginWord = line;// pointer to the begin of current word
		unsigned char *endWord = line;//pointer to the end of word
		unsigned char *maxWord = NULL;//pointer to the longest word
	
		while( endWord  )
		{
			endWord = ( unsigned char* ) memchr( beginWord, ' ' , len - wordLen );

			if( endWord )
			{
				wordLen = endWord - beginWord;
			}

			else
			{
				wordLen = ( line + len - beginWord ) + 1;
			}
			
			if( maxLen < wordLen )
			{
				maxLen = wordLen;
				maxWord=beginWord;
			}

			beginWord = endWord + 1;
		}

		if( maxWord )
		{
			unsigned char* temp = ( unsigned char* )malloc( maxLen + 1 );
			memcpy( temp, maxWord, maxLen );
			*( temp + maxLen ) = '\0';
			return temp;
		}

	}

	return line;
}

/* Task 3.15*/
unsigned char* HideWord( unsigned char* line, unsigned char letter )
{
	unsigned len = StrLen( line );
	unsigned char* hideLine = (unsigned char*)calloc( len, sizeof( unsigned char ) );
	unsigned char* beginWord = hideLine;
	unsigned char* endWord = NULL;
	unsigned wordLen = 0;
	memcpy(hideLine, line, len );

	do
	{
		endWord = ( unsigned char* )memchr( beginWord, ' ', len - wordLen );
		if( endWord )
		{
			wordLen = unsigned( endWord - beginWord );
			beginWord = endWord + 1;
		}

		else
		{
			wordLen = unsigned( hideLine + len + 1 - beginWord );
		}

		if( memchr( beginWord, letter, wordLen ) )
		{
			memset( beginWord, '*', wordLen );
		}

	}
	while( endWord );

	*( hideLine + StrLen(line) ) = '\0';

	return hideLine;
}

/* Task 3.25*/
unsigned char* InvOrdWords( unsigned char* line )
{
	unsigned char* beginWord = line;
	unsigned char* endWord = NULL;
	unsigned char* copyTo = NULL;
	unsigned len = StrLen( line );
	unsigned wordLen = 0;
	unsigned char* invLine = ( unsigned char* ) calloc( len, sizeof( unsigned char ) );
	memset( invLine, ' ', len );

	do
	{
		endWord = ( unsigned char* )memchr( beginWord, ' ', len );

		if( endWord )
		{
			wordLen = unsigned( endWord - beginWord );
			copyTo = invLine + len - wordLen;
			memcpy( copyTo, beginWord, wordLen );
			*( copyTo - 1 ) = ' ';
			len -= wordLen + 1;
			beginWord = endWord + 1;
		}

		else
		{
			memcpy(  invLine , beginWord, len );
		}

	}
	while( endWord );

	*( invLine + StrLen(line) ) = '\0';

	return invLine;
}