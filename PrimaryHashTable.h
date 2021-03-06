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
#include "SecondaryHashTable.h"
#include "HashItem.h"

using namespace std;

class PrimaryHashTable
{
public:

	/*	Description:    PrimaryHashTable
		Pre-condition:  valid hash table size, city data, and two primes > table size.
		Post-condition:	default constructor
	*/
	PrimaryHashTable(unsigned int tableSize, vector<City> cityData,
					unsigned int prime1, unsigned int prime2);

	/*	Description:    insert()
		Pre-condition:  
		Post-condition:	
	*/	
	void insert(HashItem &x);

	/* ----- temporaty functions ----- */
	void dump();


private:

	int m_primTableSize;

	/* m_array 	*/
	vector<HashItem> m_array;

	vector< vector<HashItem> > m_2dArrayScan;

	/* primary hash table - nested vector structure */
	vector<SecondaryHashTable> m_PrimaryTable;



	vector<City> m_cityData;
	unsigned int m_prime1;
	unsigned int m_prime2;

	/* used in the string to int conversion 
	   1 < c <= p */
	long int m_c;  

	/* used in universal hash function 
	   1 < a <= p and 0 < b <= p  */
	long int m_a;
	long int m_b;

	unsigned int m_seed;

	/* --- --- INTERNAL METHODS --- --- */

	/*	Description:    convertKey()
		Pre-condition:  a valid string to be hashed
		Post-condition:	returns the hash value of a string
	*/	
	long int convertKey(string key);

	/*	Description:    myHash()
		Pre-condition:  a valid long int representation of a key
		Post-condition:	returns the position to which a string key hashes
	*/	
	unsigned int myHash(long int hashedValue);

	void getMaxCollisionCities(int maxCollision);
};


#endif