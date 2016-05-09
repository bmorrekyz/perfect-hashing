#ifndef SECONDARY_TABLE_H
#define SECONDARY_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>     /* srand(), rand() */
#include <math.h>
#include <algorithm>    /* sort() */

#include "City.h"

using namespace std;

class SecondaryTable
{
public:
	SecondaryTable(int numItems, unsigned int prime1, unsigned int prime2);

	bool insert(City &city);

	int getNumTries();

	int getSize();

private:

	vector<City> m_secondaryTable;
	int max_size;
	int m_numTries;
	
	unsigned int m_prime1;
	unsigned int m_prime2;

	/* used in the string to int conversion; 1 < c <= p */
	long int m_c;  

	/* used in universal hash function; 1 < a <= p and 0 < b <= p  */
	long int m_a;
	long int m_b;

	unsigned int m_seed;

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


	void reseed();
};
#endif