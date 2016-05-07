#include "City.h"


City::City(string name, string coordinates)
{
	m_name = name;
	m_coordinates = coordinates;
}

City::City(string name, double latitude, double longitude)
{
	m_name = name;
	m_latitude = latitude;
	m_longitude = longitude;
}


void City::setName(string name)
{
	if (name.length() > 0) 
	{
		m_name = name;
	}

	else
	{
		cerr << "Error: city name cannot be empty" << endl;
	}
}

void City::setLatitude(double latitude)
{
	if (latitude > 0 )
	{
		m_latitude = latitude;
	}

	else
	{
		cerr << "Error: latitude cannot be 0" << endl;
	}
}

void City::setLongitude(double longitude)
{
	if (longitude > 0 )
	{
		m_longitude = longitude;
	}

	else
	{
		cerr << "Error: longitude cannot be 0" << endl;
	}
}


string City::getName()
{
	return m_name;
}

double City::getLatitude()
{	
	
	return m_latitude;
}

double City::getLongitude()
{
	return m_longitude;
}

string City::getCoordinates()
{
	return m_coordinates;
}

bool City::operator==(City &rhs)
{
	if ((getName() == rhs.getName()) && (getCoordinates() == rhs.getCoordinates()))
	{
		return true;
	}

	else return false;
}