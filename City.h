#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std; 

class City
{
public:
	City(string name, string coordinates);
	City(string name, double latitude, double longitude);

	void setName(string name);
	void setLatitude(double latitude);
	void setLongitude(double longitude);

	string getName();
	double getLatitude();
	double getLongitude();

	string getCoordinates();
	
	/* overloaded == and != operators */
	bool operator==(City &rhs); 


private:

	string m_name; 
	double m_latitude;
	double m_longitude;
	string m_coordinates;

};

#endif