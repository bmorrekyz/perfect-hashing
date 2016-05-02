/*****************************************
** File:    PrimaryHash.h
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/30/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains an interface of the PrimaryHashTable class.
**	
** 
***********************************************/


#ifndef PRIMARY_HASH_TABLE_H
#define PRIMARY_HASH_TABLE_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

template <typename Object>

class PrimaryHashTable
{
public:

	PrimaryHashTable(int tableSize, long int prime1, long int prime2);
	
	// void makeEmpty();

	// Object find(Object &item);

	void insert(Object &x);

	// void remove(Object &x);

	enum TYPE { OCCUPIED, EMPTY, DELETED };

	/* temporaty functions */

	void printTable();

private:

	
	struct HashItem
	{
		string m_item;
		string m_coordinates;
		TYPE m_data;

		HashItem( string key, string coordinates, TYPE choice )
			: m_item(key), m_coordinates(coordinates), m_data(choice) 
			{	/* empty constructor body */ }
	};

	vector<HashItem> array;
	long int m_prime1;
	long int m_prime2;

	/* --- INTERNAL METHODS --- */
	unsigned int myHash(int hashedValue);
	unsigned int convertKey(string key);	
};

#include "PrimaryHashTable.cpp"

#endif