/*****************************************
** File:    PrimaryHash.cpp
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/30/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains an implementation of the PrimaryTable class.
**	
***********************************************/

#include "PrimaryTable.h"


// Construct a perfect hash table.
PrimaryTable::PrimaryTable(vector<City> cityData,
								unsigned int prime1, unsigned int prime2)
{
	m_size =  cityData.size(); // 1000 

	/*  used to scan how many items have the same hash value */
	m_dataScan.reserve(m_size);
	m_primaryTable.reserve(m_size);

	/* get the prime constants pass from main() */
	m_prime1 = prime1;
	m_prime2 = prime2;

	/* generate random numbers a, b, c used in h(x)=((ax+b)%prime2)%tableSize.
	   initialization to seed = 0 is a project requirement */
	m_seed = 0;
	srand(m_seed);

	m_c = rand() % m_prime1 + 1;      
	m_a = rand() % m_prime2 + 1;      
	m_b = rand() % m_prime2;         
	 
	// Read city data into a 2D vector.	
	unsigned int position;
	for (int i = 0; i < m_size; i++)
	{
		position = myHash(convertKey(cityData[i].getName()));
		m_dataScan[position].push_back(cityData[i]);
	}
} 


// PRIVATE: converts a string key to an int representation
long int PrimaryTable::convertKey(string key)
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
unsigned int PrimaryTable::myHash(long int hashedValue)
{
	long int hashValue = 0;

	hashValue = (((m_a * hashedValue) + m_b) % m_prime2) % m_size;

	return hashValue;
}


void PrimaryTable::dumpPrimaryStats()
{
	cout << "\np1: " << m_prime1 << endl;
	cout << "p2: " << m_prime2 << endl;
	cout << "a: " << m_a << endl;
	cout << "b: " << m_b << endl;
	cout << "c: " << m_c << endl;

	cout << "\nnumber of cities: " << m_size << endl;

	printCollisionData();
}


void PrimaryTable::printCollisionData() 
{

	int collisionInfo[m_size];
	int maxCollisions = 0; 
	int maxIndex;

	/* collisionInfo[0 to m_size] = number of cities that hash to the same value */
	for (int numCities = 0; numCities < m_size; numCities++)
	{
		collisionInfo[numCities] = 0;
	}

	/* set how many collision occur for each hash value */
	for (int hashValue = 0; hashValue < m_size; hashValue++)
	{
		collisionInfo[m_dataScan[hashValue].size()]++;
	}

	/* find the index where collision occured */
	int counter = m_size - 1;
	while (counter > 0)
	{
		if ((collisionInfo[counter] != 0) && (maxCollisions == 0))
		{
			maxCollisions = counter;
		}
		counter = counter - 1;		
	}

	cout << "maximum collisions: " << maxCollisions << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "# primary slots with " << i << " cities: " << collisionInfo[i] << endl;
	}

	cout << "** cities in the slot with most collisions **" << endl;

	printMaxCollisionCities(maxCollisions);
}


void PrimaryTable::printMaxCollisionCities(int maxCollision)
{
	for (int i = 0; i < m_size; i++) 
	{
		if (m_dataScan[i].size() == maxCollision)
		{
			for (int j = 0; j < m_dataScan[i].size(); j++)
			{
				cout << m_dataScan[i][j].getName() << \
				" (" << m_dataScan[i][j].getCoordinates() << ")" << endl;
			}
		}
	}
}


void PrimaryTable::dumpSecondaryStats()
{
	bool done, insert;
	int hashingInfo[m_size];
	int numTries;
	int numTables = 0;
	double averageNumTry = 0;

	for (int i = 0; i < m_size; i++)
	{
		hashingInfo[i] = 0;
	}


	for (int i = 0; i < m_size; i++)
	{
		done = false;
		insert = false;
		if (m_dataScan[i].size() == 1)
		{
			SecondaryTable secTable(m_dataScan[i].size(), m_prime1, m_prime2);
			m_primaryTable[i] = secTable;
			secTable.insert(m_dataScan[i][0]);
		}

		else if (m_dataScan[i].size() > 1)
		{
			SecondaryTable secTable(m_dataScan[i].size(), m_prime1, m_prime2);
			m_primaryTable[i] = secTable;
			
			while (done == false)
			{
				for (int j = 0; j < m_dataScan[i].size(); j++)
				{
					if (insert = secTable.insert(m_dataScan[i][j]))
					{
						if (j+1 == m_dataScan[i].size()) 
						{
							done = true;
						}							
					}

					else
					{
						break;
					}
				}
			}

			numTries = secTable.getNumTries();
			hashingInfo[numTries]++;	
		}
	}

	for (int i = 0; i < m_size; i++)
	{
		if (hashingInfo[i] > 0) 
		{ 
			numTables = numTables + hashingInfo[i]; 
			averageNumTry = averageNumTry + i * hashingInfo[i];
		}
	}

	averageNumTry = averageNumTry / numTables;

	for (int i = 1; i < 11; i++)
	{
		cout << "# secondary hash tables trying " << i << " hash functions: " << hashingInfo[i] << endl;
	}

	cout << "number of secondary hash tables with more than one item: " << numTables << endl;
	
	cout << "average # of hash functions tried: " << averageNumTry << endl;

}