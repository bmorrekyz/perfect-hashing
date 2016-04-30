#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <iomanip>
#include <fstream>

#include "City.h"

using namespace std;

#define EXPECTED_ARGC 2

int main(int argc, char const *argv[])
{	
	
	/*  variables  */
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

			/* even lines mark the end of a City object */
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
	// validate that City data is correctly inserted into a vector
	// for (int i=0; i < cities.size(); i++)
	// {
	// 	clog << cities[i].getName() << endl;
	// 	clog << cities[i].getCoordinates() << endl;
	// 	clog << "\n" << endl;
	// }


	return 0;
}


 