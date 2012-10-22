#include "stdafx.h"
#include "points.h"


/*-------------------------------------------------------*/
float DistToOrigin( const Point3D &p )
{
	return sqrt( p.x*p.x + p.y*p.y + p.z*p.z );
}

/*-------------------------------------------------------*/
void Sort( Point3D *p, unsigned size )
{
	unsigned i = 0, j = 0;
	Point3D *temp = ( Point3D* )malloc( sizeof(Point3D ) );

	for( i = size-1; i > 0 ; i-- )
	{
		for( j = 0; j < i; j++ )
		{
			if( DistToOrigin( *( p+i ) ) < DistToOrigin( *( p+j ) ) )
			{
				
				*temp = *( p+j );
				*( p+j ) = *( p+j+1 );
				*( p+j+1 ) = *temp;

			}
		}
	}
	
	free( temp );
	return;
}

/*-------------------------------------------------------*/
bool IsSameZ( Point3D *p, unsigned size, unsigned nZ )
{
	unsigned i = 0, j = 0;
	unsigned countZ = 0;
	Point3D *temp = ( Point3D* )malloc( sizeof( Point3D ) );

	for( i = size-1; i > 0; i-- )
	{
		for( j = 0; j < i; j++ )
		{
			if( ( p+i )->z  ==  ( p+j )->z  )
			{
				
				countZ++;

			}
		}

		if( countZ >= nZ )
		{
			return true;
		}

		countZ=0;
	}

	free( temp );
	return false;
}