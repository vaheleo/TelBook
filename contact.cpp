/*
 * contact.cpp
 *
 *  Created on: Jun 6, 2017
 *      Author: Vahe
 */

#include"contact.h"
	contact::contact():name(""),tel(),group(0),next(nullptr){};
	contact* contact::getNext(){return next;}
	void contact::setNext(contact* _next){next=_next;}
	string contact:: getName(){return name;}
	string contact:: getTel(){return tel;}
	int contact::getGroup(){
		return group;
	}
	void contact::setName(string _name){name=_name;}
	void contact::setTel(string _tel){tel=_tel;}
	void contact::setGroup(int _group){group=_group;}
	void contact:: print(){
			string groupName;
			switch(group){
				case 1:
					groupName= "Friends";
							break;
				case 2:
					groupName= "Family";
					break;
				case 3:
					groupName=  "Business";
					break;
				default:
					groupName=  "Default";
					break;
				}
			cout<<"\n"<<setfill('-')<<left<<setw(13)<<name<<"||"<<
					setw(15)<<right<<tel<<"||"<<setw(10)<<right<<groupName<<"||";
	}






