/*****************************************
** File:    PrimaryHash.h
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/30/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains an interface of the PrimaryHashTable class.
**	
** 
***********************************************/


#ifndef PRIMARY_HASH_TABLE_H
#define PRIMARY_HASH_TABLE_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>     /* srand(), rand() */
#include <math.h>
#include <algorithm>    /* sort() */

#include "City.h"

using namespace std;

template <typename Object>

class PrimaryHashTable
{
public:

	/*	Description:    
		Pre-condition:  
		Post-condition:	default constructor
	*/
	PrimaryHashTable(unsigned int tableSize, unsigned int prime1, unsigned int prime2);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void insert(Object &x);

	/* to keep track of the vector cell occupuncy */
	enum TYPE { OCCUPIED, EMPTY, DELETED };

	/* ----- temporaty functions ----- */

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void dump();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	void scanData(vector<City> &x);

private:

	struct HashItem
	{
		string m_item;
		string m_coordinates; // later convert string into latitude and longitude doubles
		TYPE m_data;

		HashItem( string key, string coordinates, TYPE choice )
			: m_item(key), m_coordinates(coordinates), m_data(choice) 
			{	/* empty constructor body */ }
	};

	/* primary hash table - nested vector structure */
	// vector< vector<HashItem> > array;

	vector<HashItem> array;
	unsigned int m_prime1;
	unsigned int m_prime2;

	/* used in the string to int conversion */
	//  1 < c <= p
	unsigned int m_c;  

	/* used in universal hash function */
	//  1 < a <= p
	unsigned int m_a;

	//  0 < b <= p
	unsigned int m_b;

	/* --- INTERNAL METHODS --- */

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	unsigned int convertKey(string key);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	unsigned int myHash(long int hashedValue);
	
};

#include "PrimaryHashTable.cpp"

#endif