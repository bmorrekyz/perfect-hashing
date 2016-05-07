#ifndef HASH_ITEM_H
#define HASH_ITEM_H


#include <string>
#include "City.h"

using namespace std;

class HashItem
{
public:
	HashItem(City &city, int status);

	/* --- GETTERS --- */
	string getKey();
	string getCoordinates();
	int getStatus();

	/* --- SETTERS --- */
	void setStatus(int status);

private:
	string m_key;
	string m_coordinates; // later convert string into latitude and longitude doubles

	int m_status; // 1 = occupied, 0 = empty, 2 = deleted	
};


#endif