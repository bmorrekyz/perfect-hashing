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

	/* get the prime constants pass from main() */
	m_prime1 = prime1;
	m_prime2 = prime2;

	/* --- generate random numbers a, b, c --- */
	/* seed = 0 is a project requirement */
	unsigned int seed = 0;
	srand(seed);

	long int c = rand() % m_prime1 + 1;      
	long int a = rand() % m_prime2 + 1;      
	long int b = rand() % m_prime2;         
	 
	m_a = a;
	m_b = b;
	m_c = c;

	// temporarily instantiate each array cell as empty hash items
	// temporarily because the array should really be a vector of vectors
	HashItem temp("NULL", "NULL", EMPTY );
	for (unsigned int i = 0; i < tableSize; i++)
	{
		array.push_back(temp);
	}

}

/* PRIVATE: converts a string key to an int representation */
template <typename Object>
unsigned int PrimaryHashTable<Object>::convertKey(string key)
{
	long int hashKey = 0;

	/* static_cast<int>(key[i]) returns the dec. of an ascii character */
	for (unsigned int i = 0; i < key.length(); i++)
	{	

		hashKey = ((hashKey * m_c) + static_cast<int>(key[i])) % m_prime1;
	}
	clog << hashKey << endl;
	return hashKey;
}


/* hashedValue is the key converted from string to int */
template <typename Object>
unsigned int PrimaryHashTable<Object>::myHash(long int hashedValue)
{
	long int hashValue = 0;

	hashValue = (((m_a * hashedValue) + m_b) % m_prime2) % array.size();

	return hashValue;

}



template <typename Object>
void PrimaryHashTable<Object>::insert(Object &x)
{
	int position;

	position = myHash(convertKey(x.getName()));

	HashItem insertedItem(x.getName(),x.getCoordinates(), OCCUPIED );

	if (array[position].m_data == EMPTY)
	{	
		array[position] = insertedItem;
		
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


}

template <typename Object>
void PrimaryHashTable<Object>::scanData(vector<City> &x) 
{

	vector< vector<HashItem> > data;
	data.reserve(x.size());

	unsigned int slotNum;

	for (int i = 0; i < x.size(); i++)
	{
		slotNum = myHash(convertKey(x[i].getName()));
		HashItem insertedItem(x[i].getName(),x[i].getCoordinates(), OCCUPIED );
		data[slotNum].push_back(insertedItem);
	}

 	unsigned int zero = 0;
 	unsigned int one = 0;
 	unsigned int two = 0;
 	unsigned int three = 0;
 	unsigned int four = 0;
 	unsigned int five = 0;
 	unsigned int six = 0;
 	unsigned int seven = 0;
 	unsigned int eight = 0;
 	unsigned int nine = 0;

	for (unsigned int i = 0; i < x.size(); i++)
	{

		if (data[i].size() == 0) { zero = zero + 1; }
		else if (data[i].size() == 1) { one = one + 1; }
		else if (data[i].size() == 2) { two = two + 1; }
		else if (data[i].size() == 3) { three = three + 1; }
		else if (data[i].size() == 4) { four = four + 1; }
		else if (data[i].size() == 5) { five = five + 1; }
		else if (data[i].size() == 6) { six = six + 1; }
		else if (data[i].size() == 7) { seven = seven + 1; }
		else if (data[i].size() == 8) { eight = eight + 1; }
		else if (data[i].size() == 9) { nine = nine + 1; }

	}


// 	// sort(slots, slots + x.size());


	
	cout << "# primary slots with " << 0 << " cities: " << zero << endl;
	cout << "# primary slots with " << 1 << " cities: " << one << endl;
	cout << "# primary slots with " << 2 << " cities: " << two << endl;
	cout << "# primary slots with " << 3 << " cities: " << three << endl;
	cout << "# primary slots with " << 4 << " cities: " << four << endl;
	cout << "# primary slots with " << 5 << " cities: " << five << endl;
	cout << "# primary slots with " << 6 << " cities: " << six << endl;
	cout << "# primary slots with " << 7 << " cities: " << seven << endl;
	cout << "# primary slots with " << 8 << " cities: " << eight << endl;
	cout << "# primary slots with " << 9 << " cities: " << nine << endl;
}


#endif

