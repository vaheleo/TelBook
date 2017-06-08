/*
 * contact.h
 *
 *  Created on: Jun 6, 2017
 *      Author: Vahe
 */

#ifndef CONTACT_H_
#define CONTACT_H_
#include"Header.h"
class contact
{
	string name;
	string tel;
	int group;
	contact* next;
public:
	contact();
	contact* getNext();
	void setNext(contact*);
	string getName();
	string getTel();
	int getGroup();
	void setName(string);
	void setTel(string);
	void setGroup(int);
	void print();

};
#endif /* CONTACT_H_ */
