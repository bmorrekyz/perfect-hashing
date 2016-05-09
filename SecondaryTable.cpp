#include "SecondaryTable.h"


SecondaryTable::SecondaryTable(int numItems, unsigned int prime1, unsigned int prime2)
{
	max_size = numItems * numItems;
	// cout << "\n ---- created a new talbe max_size: " << max_size << endl;
	m_prime1 = prime1;
	m_prime2 = prime2;
	m_seed = 0;

	m_numTries = 0;
	srand(m_seed);

	m_c = rand() % m_prime1 + 1;      
	m_a = rand() % m_prime2 + 1;      
	m_b = rand() % m_prime2; 

	City tempCity;
	for (int i = 0; i < max_size; i++)
	{
		m_secondaryTable.push_back(tempCity);
	}
}

bool SecondaryTable::insert(City &city)
{
	// cout << "m_seed " << m_seed << endl;
	unsigned int position;
	position = myHash(convertKey(city.getName()));
	// cout << "inserting: " << city.getName() << " with hash: " << position << endl;
	if (m_secondaryTable[position].getOccupuncy() == 0)
	{
		city.setOccupuncy(1);
		m_secondaryTable[position] = city;
		// cout << "inserted " << city.getName() << " at " << position << endl;
		return true;
	}

	else if (m_secondaryTable[position].getOccupuncy() == 1)
	{	
		// cout << "collision at " << position << endl;
		reseed();
		return false;
	}
}

/* PRIVATE: converts a string key to an int representation */
long int SecondaryTable::convertKey(string key)
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
unsigned int SecondaryTable::myHash(long int hashedValue)
{
	long int hashValue = 0;

	hashValue = (((m_a * hashedValue) + m_b) % m_prime2) % max_size;

	return hashValue;
}


void SecondaryTable::reseed() 
{
	m_seed = m_seed + 1;
	m_numTries = m_numTries + 1;
	srand(m_seed);
	m_c = rand() % m_prime1 + 1; 
	m_a = rand() % m_prime2 + 1;      
	m_b = rand() % m_prime2; 	

	City tempCity;
	for (int i = 0; i < max_size; i++)
	{
		m_secondaryTable[i] = tempCity;
	}
}

int SecondaryTable::getNumTries()
{
	return m_numTries + 1;
}

int SecondaryTable::getSize()
{
	return max_size;
}