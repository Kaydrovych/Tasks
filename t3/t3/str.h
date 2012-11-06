/*
* @file str.h
* @brief Contains implementation of functions and structs for the Task3 "Strings and functions"
* @autor Kaydrovych Yuriy
*/

#ifndef _STR_H_
#define _STR_H_

#define MAX_LINE_LEN 1000

void ShowMenu(void );

/** 
*@brief This function find  lenght of string
*@param [in] String
*@return unsigned - lenght  of string		
*/
unsigned StrLen( const unsigned char* line );

/** Task 3.1
*@brief This function find longest word in the string
*@param [in] String
*@return unsigned char* - pointer to the
		 longest word		
*/
unsigned char*  MaxWord( unsigned char* line);

/** Task 3.15
*@brief This function set all characters in the word, that contain given letter
*@param [in] unsigned char* line - given string
*@param [in] unsigned char letter  - given character
*@return unsigned char* - pointer to modified string		
*/
unsigned char* HideWord( unsigned char* line, unsigned char letter );


/** Task 3.25
*@brief This function generates from given sentence new one with inverted word order.
*@param [in] unsigned char* line - given sentence
*@return unsigned char* - pointer to sentence with inverted word order	
*/
unsigned char* InvOrdWords( unsigned char* line );

unsigned Search( unsigned char* line, unsigned char* find );

#endif /*_POINTS_H_*/