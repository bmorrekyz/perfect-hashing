/*****************************************
** File:    PrimaryHash.h
** Project: CMSC 341 Project 5, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/30/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains an interface of the PrimaryHashTable class.
	Overloaded == and != operators. 
	Global function unsigned int hash(const Object &key);
***********************************************/


#ifndef PRIMARY_HASH_TABLE_H
#define PRIMARY_HASH_TABLE_H

#include <vector>

using namespace std;

template <typename Object>
class PrimaryHashTable
{
public:

	PrimaryHashTable();
	
	void makeEmpty();

	Object find(Object &item);

	void insert(Object &x);

	void remove(Object &x);

	enum TYPE { OCCUPIED, EMPTY, DELETED };

private:

	struct HashItem
	{
		string item;
		TYPE data;

		HashItem( string key, TYPE choice )
			: item(key), data(choice) 
			{	/* empty constructor body */ }
	};

	vector<HashItem> array;
	int occupied;

	bool isActive(int currentPos);

	int findPos(const Object &x);

	void rehash();
	
};

#include "PrimaryHashTable.cpp"
#endif