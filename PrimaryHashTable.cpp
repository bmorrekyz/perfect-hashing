/*****************************************
** File:    PrimaryHash.cpp
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/30/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains an implementation of the PrimaryHashTable class.
**	
** 
***********************************************/

#ifndef PRIMARY_HASH_TABLE_CPP
#define PRIMARY_HASH_TABLE_CPP

#include "PrimaryHashTable.h"


// Construct the hash table.
template <typename Object>
PrimaryHashTable<Object>::PrimaryHashTable(int tableSize, long int prime1, long int prime2)
{
	/* instantiate a hash table with size=tableSize */
	array.reserve(tableSize);
	m_prime1 = prime1;
	m_prime2 = prime2;

	HashItem temp("NULL", "NULL", EMPTY );
	// temporarily instantiate each array cell as empty hash items
	for (int i = 0; i < tableSize; i++)
	{
		array.push_back(temp);
	}
}


template <typename Object>
unsigned int PrimaryHashTable<Object>::myHash(int hashedValue)
{
	unsigned int hashValue = 0;
	srand (time(NULL));
	long int p = m_prime2 - 1; 
	unsigned int a = rand() % p + 1;
	unsigned int b = rand() % p + 1;

	/* func h(x) = ((a * x + b) % m_prime2) % tableSize;  */
	hashValue = ((a * hashedValue + b) % m_prime2) % 1000;

	return hashValue;

}

template <typename Object>
unsigned int PrimaryHashTable<Object>::convertKey(string key)
{
	/* initialize random seed: */
	srand (time(NULL));

	unsigned int c = rand() % m_prime1 + 1;

	long int strValue = 0;

	/* static_cast<int>(key[i]) returns the int of an ascii character */
	for (unsigned int i = 0; i < key.length(); i++)
	{
		strValue = (strValue + static_cast<int>(key[i])*c) % m_prime1;
	}

	return strValue;
}

template <typename Object>
void PrimaryHashTable<Object>::insert(Object &x)
{
	int position;

	position = myHash(convertKey(x.getName()));

	HashItem insertItem(x.getName(),x.getCoordinates(), OCCUPIED );

	if (array[position].m_data == EMPTY)
	{	
		array[position] = insertItem;
	}


}	

template <typename Object>
void PrimaryHashTable<Object>::printTable() 
{
	for (int i = 0; i < array.size(); i++ )
	{
		clog << i << ": " << array[i].m_item << endl;
	}
}
#endif