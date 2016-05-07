#include "SecondaryHashTable.h"

SecondaryHashTable::SecondaryHashTable(int numItems,
					unsigned int prime1, unsigned int prime2)
{  
	/* constructor body */
	m_size = numItems * numItems;
	m_prime1 = prime1;
	m_prime2 = prime2;
	m_secondaryTable.reserve(m_size);
	m_numTries = 0; 

	/* generate random numbers a, b, c used in h(x)=((ax+b)%prime2)%tableSize.
	   seed = 0 is a project requirement 
	*/
	m_seed = 0;
	srand(m_seed);

	m_c = rand() % m_prime1 + 1;      
	m_a = rand() % m_prime2 + 1;      
	m_b = rand() % m_prime2;     


	City city("NULL", "NULL"); 
	HashItem dummyItem(city, 0 );

	for (int i = 0; i < m_size; i++)
	{
		m_secondaryTable.push_back(dummyItem);
	}
}


/* PRIVATE: converts a string key to an int representation */
long int SecondaryHashTable::convertKey(string key)
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
unsigned int SecondaryHashTable::myHash(long int hashedValue)
{
	long int hashValue = 0;

	hashValue = (((m_a * hashedValue) + m_b) % m_prime2) % m_size;

	return hashValue;
}


void SecondaryHashTable::insertSecHashTable(HashItem &item) 
{
	// clog << "inserting: " << item.getKey()<< endl;
	
	long int key; 
	key= convertKey(item.getKey());
	// clog << "key: " << key << endl;

	unsigned int position;
	position = myHash(key);

	item.setStatus(1);

	if (m_secondaryTable[position].getStatus() == 0)
	{
		m_secondaryTable[position] = item;  //

	}

	else
	{
		position = reseed(key, item);
	}

	// clog << "\n" << endl;

}

long int SecondaryHashTable::reseed(long int key, HashItem &item)
{
	/* generate random numbers a, b, c used in h(x)=((ax+b)%prime2)%tableSize.
	   seed = 0 is a project requirement 
	*/
	m_seed = m_seed + 1;
	m_numTries = m_numTries + 1;

	srand(m_seed);

	m_c = rand() % m_prime1 + 1;    
	m_a = rand() % m_prime2 + 1;    
	m_b = rand() % m_prime2;   


	insertSecHashTable(item);
}

int SecondaryHashTable::getSize()
{
	return m_size;
}


int SecondaryHashTable::getNumTries()
{
	return m_numTries;
}