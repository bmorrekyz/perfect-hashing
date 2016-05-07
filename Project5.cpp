#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <iomanip>
#include <fstream>

#include <stdlib.h>     /* srand, rand */

#include "City.h"
#include "PrimaryHashTable.h"

using namespace std;

#define EXPECTED_ARGC 2


#define PRIME1 16890581
#define PRIME2 17027399 


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
	PrimaryHashTable hashTable1(cities.size(), cities, PRIME1, PRIME2);
	hashTable1.dump();

	// for (int i=0; i < cities.size(); i++)
	// {
	// 	hashTable1.insert(cities[i]);
	// }

	// hashTable1.scanData(cities);

	// return 0;
}


