/*
* @file BinOperations.h
* @brief Contains implementation of functions and structs for the Task2 "Means of structural organization of data in C"
* @autor Kaydrovych Yuriy
*/
#ifndef _POINTS_H_
#define _POINTS_H_

struct Point3D
{
	float x;
	float y;
	float z;
};

/** 
*@brief This function calculates distanse from point to origin
*@param [in] Coordinates of point
*@return float
*/
float DistToOrigin( const Point3D &p);

/** 
*@brief This function sorts points by distance to origin
*@param [in] Pointer to array of points
*@param [in] Number of points
*@return void
*/
void Sort( Point3D *p, unsigned size );

/** 
*@brief This function determine whether among them
		are at least three points that have the same coordinate z
*@param [in] Pointer to array of points
*@param [in] Number of points
*@param [in] Number of points that must be with the same coordinate  z
*@return bool
*/
bool IsSameZ( Point3D *p, unsigned size, unsigned nZ );

#endif /*_POINTS_H_*/