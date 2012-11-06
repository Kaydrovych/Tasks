// t3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "str.h"
using namespace std;

int _tmain( int argc, _TCHAR* argv[] )
{
	unsigned char* line = ( unsigned char* )calloc( MAX_LINE_LEN, sizeof( unsigned char ) );
	unsigned char c;
	unsigned  choise = -1;

	while( choise )
	{
	  ShowMenu();
	  scanf( "%u", &choise );
	  fflush(stdin);

	  switch( choise )
	  {
		
	    case 0: free( line );
			    return 0;

		case 1: printf( "Input string->" );
				scanf( "%1000[^\n]s", line);
				break;

		case 2: if( StrLen( line ) )
				{
					  printf( "\nString - %s\nLongest word in string - <%s>", line,  MaxWord( line ) );
				}

				else
				{
					  printf("\nString is empty!!!\n" );
				}
				break;

		case 3: if( StrLen( line ) )
				{
					  printf("\nString - %s\nString with substitude words - <%s>\n", line, InvOrdWords( line ) );
				}

				else
				{
					  printf("\nString is empty!!!\n" );
				}
				break;

		case 4: if( StrLen( line ) )
				{
					  printf( "Input character: " );
					  scanf( "%c", &c );
					  printf("\nString - %s\nString with changed words - <%s>\n", line,  HideWord( line, c ) );
					  fflush(stdin);
				}

				else
				{
					   printf("\nString is empty!!!\n" );
				}
			    break;
		
		case 5: if( StrLen( line ) )
				{
					printf("\nString - %s", line );
				}

				else
				{
					   printf("\nString is empty!!!\n" );
				}
				break;

		default: printf( "Error!" );	  
	  }

	 printf( "\nPress any key...");
	 getch();
	 system( "cls" );
	 fflush( stdin );
	 choise = -1;
	}

}

