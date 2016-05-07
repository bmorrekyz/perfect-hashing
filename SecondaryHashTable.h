#ifndef SECONDARY_HASH_TABLE_H
#define SECONDARY_HASH_TABLE_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>     /* srand(), rand() */
#include <math.h>
#include <algorithm>    /* sort() */

#include "City.h"
#include "HashItem.h"

using namespace std;


class SecondaryHashTable
{
public:
	SecondaryHashTable(int numItems,
					unsigned int prime1, unsigned int prime2);


	void insertSecHashTable(HashItem &item);

	
	int getSize();
	
	int getNumTries();
	
private:

	vector<HashItem> m_secondaryTable;	
	int m_size;
	int m_numTries;

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

	long int reseed(long int key, HashItem &item);
};

#endif