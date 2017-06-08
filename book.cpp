/*
 * book.cpp
 *
 *  Created on: Jun 6, 2017
 *      Author: Vahe
 */
#include"book.h"
	book::book():headPointer(nullptr),counter(0){};
	bool book::add(contact* _newItem){
		contact* newItem=new contact;
		newItem->setName(_newItem->getName());
		newItem->setTel(_newItem->getTel());
		newItem->setGroup(_newItem->getGroup());
			newItem->setNext(headPointer);
			headPointer=newItem;
			counter++;
			return true;
	}

	bool book::remove(contact* entryP){
		contact* currentP=headPointer;
		contact* tempP;
		if(currentP==entryP){
			headPointer=currentP->getNext();
			delete currentP;
			currentP=nullptr;
			return true;
		}
		else{
		while(currentP){
			tempP=currentP->getNext();
			if(tempP==entryP){
				currentP->setNext(tempP->getNext());
				delete tempP;
				tempP=nullptr;
				return true;
			}
			currentP=currentP->getNext();

		}return false;
		}
	}

	void book::printAll(){
			cout<<"PrintBook\n"<<setfill('-')<<left<<setw(13)<<"Contact Name"<<"||"<<setw(15)<<right<<"Tel Number"<<"||"<<setw(10)<<right<<"Catagory"<<"||";
			contact* currentP=headPointer;
			while(currentP){
				currentP->print();
				currentP=currentP->getNext();
			}
			delete currentP;
	}


	bool book::search(string nameEntry){
	bool check=false,check2=false;
	contact* currentP=headPointer;
	cout<<"PrintBook\n"<<setfill('-')<<left<<setw(13)<<"Contact Name"<<
			"||"<<setw(15)<<right<<"Tel Number"<<"||"<<setw(10)<<right<<"Catagory"<<"||";
	while(currentP){
		string name=currentP->getName();
		//if(nameEntry.size()>name.size())break;
		for(unsigned int s=0;s<nameEntry.size();s++){
			if(tolower(name[s])==tolower(nameEntry[s])){check=true;check2=true;}
			else{check=false;break;}
		}
		if(check)currentP->print();
		currentP=currentP->getNext();
	}
	return check2;
	}

	contact* book::search2(string nameEntry){
	contact* currentP=headPointer;
	while(currentP){
		string name=currentP->getName();
		if(name==nameEntry)return currentP;
		currentP=currentP->getNext();
	}
	return nullptr;
	}


	bool book::save(string _fileName){
		ofstream myFile;
		  myFile.open (_fileName);
		  if(myFile.is_open())
		  {
			contact* currentP=headPointer;
			while(currentP){
			myFile<<currentP->getName()<<" "<<currentP->getTel()<<" "<<currentP->getGroup()<<endl;
			currentP=currentP->getNext();
			}
			cout<<"File saved.";
			return true;
			}else return false;

	}




