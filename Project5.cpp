#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <iomanip>
#include <fstream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "City.h"

using namespace std;

#define EXPECTED_ARGC 2

#define PRIME1 16890581
#define PRIME2 17027399 

unsigned int myHash(int hashedValue)
{
	unsigned int hashValue = 0;
	srand (time(NULL));
	long int p = PRIME2 - 1; 
	unsigned int a = rand() % p + 1;
	unsigned int b = rand() % p + 1;

	/* func h(x) = ((a * x + b) % prime2) % tableSize;  */
	hashValue = ((a * hashedValue + b) % PRIME2) % 1000;

	return hashValue;

}

unsigned int convertKey(string key)
{
	/* initialize random seed: */
	srand (time(NULL));

	unsigned int c = rand() % PRIME1 + 1;

	long int strValue = 0;

	/* static_cast<int>(key[i]) returns the int of an ascii character */
	for (unsigned int i = 0; i < key.length(); i++)
	{
		strValue = (strValue + static_cast<int>(key[i])*c) % PRIME1;
	}

	return strValue;
}


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

	for (int i=0; i < cities.size(); i++)
	{
		if (myHash(convertKey(cities[i].getName())) > 990)
		{cout << myHash(convertKey(cities[i].getName())) << endl;}

	}

	return 0;
}


 