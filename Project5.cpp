#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <iomanip>
#include <fstream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

#include "City.h"
#include "PrimaryHashTable.h"

using namespace std;

#define EXPECTED_ARGC 2

#define PRIME1 16890581
#define PRIME2 17027399 


// unsigned int myHash(unsigned int hashedValue)
// {
// 	unsigned int m_a = 12588336;
// 	unsigned int m_b = 13007675;

// 	unsigned int m_prime2 = 17027399;


// 	unsigned int hashValue = 0;


// 	/* func h(x) = ((a * x + b) % m_prime2) % tableSize;  */
// 	hashValue = ((m_a * hashedValue + m_b) % m_prime2) % 1000;

// 	return hashValue;

// }

// unsigned int convertKey(string key)
// {
// 	unsigned int strValue = 0;
// 	unsigned int m_c = 13887798;
// 	unsigned int m_prime1 =  16890581;

// 	/* static_cast<int>(key[i]) returns the int of an ascii character */
// 	for (unsigned int i = 0; i < key.length(); i++)
// 	{	
// 		strValue = ((strValue * m_c) + static_cast<int>(key[i])) % m_prime1;
// 	}
// 	return strValue;
// } 


int main(int argc, char const *argv[])
{	
	
	/* --- variables --- */
	vector<City> cities;
	string fileName;
	unsigned int counter;

	if (argc == EXPECTED_ARGC)
	{
		fileName = argv[1];
	}

	else 
	{
		cerr << "Error opening the input file. " << endl;
		return 0;
	}

	/* -- read data from file --- */
	fstream inFile;
	inFile.open(fileName.c_str());

	if (inFile.is_open())
	{
		string line;

		int lineCount = 1;
		string cityName, coordinates;

		while(getline(inFile, line))
		{

			if (lineCount % 2 != 0) 
			{ 
				cityName = line; 
				lineCount = lineCount + 1;
			}

			/* even line numbers mark the end of a City object */
			else if (lineCount % 2 == 0) 
			{ 
				coordinates = line; 
				lineCount = lineCount + 1;

				City tempCity(cityName, coordinates);
				cities.push_back(tempCity);
			}
		}
	}

	inFile.close();


	/* test code */
	PrimaryHashTable<City> hashTable1(cities.size(), PRIME1, PRIME2);

	for (int i=0; i < cities.size(); i++)
	{

		hashTable1.insert(cities[i]);


	}

	hashTable1.dump();

	return 0;
}


