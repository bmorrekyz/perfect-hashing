#include "HashItem.h"

HashItem::HashItem(City &city, int status)
{
	m_key = city.getName();
	m_coordinates = city.getCoordinates(); 
	m_status = status;
}

/* --- GETTERS --- */
string HashItem::getKey()
{
	return m_key;
}


string HashItem::getCoordinates()
{
	return m_coordinates;
}


int HashItem::getStatus()
{
	return m_status;
}



/* --- SETTERS --- */

void HashItem::setStatus(int status)
{
	m_status = status;
}

