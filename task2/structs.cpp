// structs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "points.h"

#define MAX_SIZE 1000

int _tmain( )
{
	unsigned i = 0;
	unsigned n = 0;//number of entered points
	bool endInput = false;//CTRL-Z is entered
	Point3D *p = ( Point3D* )malloc( MAX_SIZE*sizeof( Point3D ) );

	printf_s( "---Input points( max - %d )---\n", MAX_SIZE );

	while( !endInput )// CTRL-Z is not entered
	{
		printf_s("\nInput point %u( end - CTRL-Z):", ( n+1 ) );

		while( scanf_s( "%f %f %f", &( p+n )->x, &( p+n )->y, &( p+n )->z ) < 3 )// while entered invalid data
		{
			
			if( feof( stdin ) )
			{
				endInput = true;
				n--;
				break;// stop entering points
			}
			else
			{
				fflush( stdin );
				printf_s( "\nPlease, input correct numbers:" );
			}

		}
		fflush( stdin );
		n++;	
	}
	
	if( n > 0 ) //  number of points is >0 
	{
		Sort( p, n );
		printf_s( "\n---Sorted points---\n" );
		printf_s( "%-20s %-20s %-20s\n", "x", "y", "z" );

		for( i = 0; i < n; i++ )// print points
		{
			printf_s( "%-20f|%-20f|%-20f\n", ( p+i )->x, ( p+i )->y, ( p+i )->z );
		}

		if( IsSameZ( p, n, 3 )  )
		{
			printf_s( "\nThere are >=3 points with the same coordinate z\n" );
		}
		else
		{
			printf_s( "\nThere are not >=3 points with the same coordinate z\n" );
		}

	}

	free( p );
	_getch();

	return 0;
}

