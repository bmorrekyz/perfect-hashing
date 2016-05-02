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
	City(string name, long double latitude, long double longitude);
	~City();

	void setName(string name);
	void setLatitude(long double latitude);
	void setLongitude(long double longitude);

	string getName();
	long double getLatitude();
	long double getLongitude();

	string getCoordinates();
	
	/* overloaded == and != operators */
	bool operator==(City &rhs); 


private:

	string m_name; 
	long double m_latitude;
	long double m_longitude;
	string m_coordinates;

};

#endif