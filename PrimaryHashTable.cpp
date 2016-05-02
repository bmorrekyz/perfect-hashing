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
PrimaryHashTable<Object>::PrimaryHashTable(unsigned int tableSize, unsigned int prime1, unsigned int prime2)
{
	/* instantiate a hash table with size=tableSize */
	array.reserve(tableSize);
	m_prime1 = prime1;
	m_prime2 = prime2;

	unsigned int seed = 0;
	srand(seed);
	unsigned int p = m_prime2 - 1; 
	unsigned int p1 = m_prime1 - 1; 

	unsigned int a = rand() % p + 1;
	unsigned int b = rand() % p;
	unsigned int c = rand() % p1 + 1;

	// m_a = a;
	// m_b = b;
	// m_c = c;

	m_a = 12588336;
	m_b = 13007675;
	m_c = 13887798;

	// temporarily instantiate each array cell as empty hash items
	HashItem temp("NULL", "NULL", EMPTY );
	for (unsigned int i = 0; i < tableSize; i++)
	{
		array.push_back(temp);
	}

	zeroCities = 0;

}


template <typename Object>
unsigned int PrimaryHashTable<Object>::myHash(unsigned int hashedValue)
{
	unsigned int hashValue = 0;

	hashValue = ((m_a * hashedValue + m_b) % m_prime2) % array.size();

	return hashValue;

}

template <typename Object>
unsigned int PrimaryHashTable<Object>::convertKey(string key)
{
	unsigned int strValue = 0;

	/* static_cast<int>(key[i]) returns the int of an ascii character */
	for (unsigned int i = 0; i < key.length(); i++)
	{	
		strValue = ((strValue * m_c) + static_cast<int>(key[i])) % m_prime1;
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
void PrimaryHashTable<Object>::dump() 
{
	cout << "p1: " << m_prime1 << endl;
	cout << "p2: " << m_prime2 << endl;
	cout << "a: " << m_a << endl;
	cout << "b: " << m_b << endl;
	cout << "c: " << m_c << endl;

	cout << "\nnumber of cities: " << array.size() << endl;
	// for (int i = 0; i < array.size(); i++ )
	// {
	// 	if(array[i].m_data == EMPTY)
	// 	{
	// 		zeroCities = zeroCities + 1;
	// 	}
	// }

	for (int i=0; i<array.size(); i++)
	{
		if (array[i].m_data == EMPTY) 
		{
			zeroCities = zeroCities + 1;
		}
	}

	clog << "zeroCities = " << zeroCities << endl;

	for (int i=0; i < array.size(); i++)
	{

		// hashTable1.insert(array[i]);
		if (array[i].m_item == "Wyldwood, TX") {
			cout << "Wyldwood, TX has hash = " << myHash(convertKey(array[i].m_item)) << endl;
		}

		else if (array[i].m_item == "Greater Northdale, FL") {
			cout << "Greater Northdale, FL has hash = " << myHash(convertKey(array[i].m_item)) << endl;
		}

	}
}
#endif

