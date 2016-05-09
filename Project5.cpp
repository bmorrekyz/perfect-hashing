#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <iomanip>
#include <fstream>

#include "City.h"
#include "PrimaryTable.h"

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
	PrimaryTable hashTable1(cities, PRIME1, PRIME2);

	hashTable1.dumpPrimaryStats();
	hashTable1.dumpSecondaryStats();
	 	
	return 0;
}