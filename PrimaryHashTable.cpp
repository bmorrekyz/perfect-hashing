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

#include "PrimaryHashTable.h"


// Construct a perfect hash table.
PrimaryHashTable::PrimaryHashTable(unsigned int tableSize, vector<City> cityData,
											unsigned int prime1, unsigned int prime2)
{

	m_primTableSize =  cityData.size();
	/* instantiate a hash table with size=tableSize */
	m_array.reserve(m_primTableSize);
	m_2dArrayScan.reserve(m_primTableSize);
	m_PrimaryTable.reserve(m_primTableSize);

	/* get the prime constants pass from main() */
	m_prime1 = prime1;
	m_prime2 = prime2;


	/* generate random numbers a, b, c used in h(x)=((ax+b)%prime2)%tableSize.
	   seed = 0 is a project requirement 
	*/
	m_seed = 0;
	srand(m_seed);

	m_c = rand() % m_prime1 + 1;      
	m_a = rand() % m_prime2 + 1;      
	m_b = rand() % m_prime2;         
	 

	/*   forgot why i fill m_array with NULL City data.
		 seg fault if this code is commented out 
	 */
	City city("NULL", "NULL"); 
	HashItem dummyItem(city, 0 );
	for (unsigned int i = 0; i < m_primTableSize; i++)
	{
		m_array.push_back(dummyItem);
	}

	
	/* Read city data into a 2D vector. Where
		dim1 - hashed cityName value
		dim2 -  all the cities that hashed into m_array[dim1]
		This is necessary to find out the sizes of secondary hash tables
	*/
	unsigned int position;
	for (int i = 0; i < m_primTableSize; i++)
	{
		position = myHash(convertKey(cityData[i].getName()));
		HashItem insertedItem(cityData[i], 1 );
		m_2dArrayScan[position].push_back(insertedItem);
	}


	/* reserve secondary hash tables capacities 
	   m_PrimaryTable stores SecondaryHashTable objects
	*/
	for (int i = 0; i < m_primTableSize; i++)
	{
		SecondaryHashTable secondaryTable(m_2dArrayScan[i].size(), m_prime1, m_prime2);
		m_PrimaryTable[i] = secondaryTable;
	}

	for (int i = 0; i < m_primTableSize; i++)
	{
		position = myHash(convertKey(cityData[i].getName()));
		HashItem insertedItem(cityData[i], 1 );
		m_PrimaryTable[position].insertSecHashTable(insertedItem);		
	}

} // end constructor()


void PrimaryHashTable::insert(HashItem &x)
{
	int position;

	position = myHash(convertKey(x.getKey()));
	
	x.setStatus(1);

	if (m_array[position].getStatus() == 0)
	{	
		m_array[position] = x;	
	}
}	

/* PRIVATE: converts a string key to an int representation */
long int PrimaryHashTable::convertKey(string key)
{
	long int hashKey = 0;

	/* static_cast<int>(key[i]) returns the dec. of an ascii character */
	for (unsigned int i = 0; i < key.length(); i++)
	{	

		hashKey = ((hashKey * m_c) + static_cast<int>(key[i])) % m_prime1;
	}
	return hashKey;
}


/* hashedValue is the key converted from string to int */
unsigned int PrimaryHashTable::myHash(long int hashedValue)
{
	long int hashValue = 0;

	hashValue = (((m_a * hashedValue) + m_b) % m_prime2) % m_array.size();

	return hashValue;
}


void PrimaryHashTable::dump()
{

	int collisionInfo[m_primTableSize];
	int maxCollisions; 
	int maxIndex;

	cout << "\np1: " << m_prime1 << endl;
	cout << "p2: " << m_prime2 << endl;
	cout << "a: " << m_a << endl;
	cout << "b: " << m_b << endl;
	cout << "c: " << m_c << endl;

	cout << "\nnumber of cities: " << m_primTableSize << endl;

	for (int i = 0; i < m_primTableSize; i++)
	{
		collisionInfo[i] = 0;
	}

	for (int i = 0; i < m_primTableSize; i++)
	{
		collisionInfo[m_2dArrayScan[i].size()]++;
	}

	for (int k = m_primTableSize - 1; k >= 0; k--)
	{
		if (collisionInfo[k] != 0 and maxCollisions == 0)
		{
			maxCollisions = k;
		}
	}

	cout << "maximum collisions: " << maxCollisions << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "# primary slots with " << i << " cities: " << collisionInfo[i] << endl;
	}

	cout << "** cities in the slot with most collisions **" << endl;
	getMaxCollisionCities(maxCollisions);
	
}

void PrimaryHashTable::getMaxCollisionCities(int maxCollision)
{
	for (int i = 0; i < m_primTableSize; i++) 
	{
		if (m_2dArrayScan[i].size() == maxCollision)
		{
			for (int j = 0; j < m_2dArrayScan[i].size(); j++)
			{
				cout << m_2dArrayScan[i][j].getKey() << " (" << m_2dArrayScan[i][j].getCoordinates() << ")" << endl;
			}
		}
	}
}