#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std; 

class City
{
public:
	City();
	City(string name, string coordinates);

	void setName(string name);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	void setOccupuncy(int result);
	
	string getName();
	double getLatitude();
	double getLongitude();
	string getCoordinates();
	int getOccupuncy();
	
	/* overloaded == and != operators */
	bool operator==(City &rhs); 


private:

	string m_name; 
	double m_latitude;
	double m_longitude;
	string m_coordinates;
	int m_occupuncy;

};

#endif