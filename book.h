/*
 * book.h
 *
 *  Created on: Jun 6, 2017
 *      Author: Vahe
 */

#ifndef BOOK_H_
#define BOOK_H_

#include"contact.h"


class book{
	contact* headPointer;
	int counter;
public:
	book();
	bool add(contact*);
	bool remove(contact*);
	int getCounter();
	bool search(string);
	contact* search2(string);
	void printAll();
	bool save(string);

};



#endif /* BOOK_H_ */
