
#include"Header.h"
#include"contact.h"
#include"book.h"
void menu();
int main(){
	char choice;
	int newGroup;
	string newName,newTel;
	book newBook;
	string fileName;
	do
	{
		menu();
		cin>>choice;
		switch(choice){
		case '1':
		{
			contact* newItem=new contact;
			string line,data;
			int counter=0,group;
			cout<<"Enter the file name to load contacts?";
			cin>>fileName;
			ifstream myFile (fileName);
			if (myFile.is_open()){
			while ( getline(myFile,line) ){
				stringstream stream(line);
				stream>>data;
				newItem->setName(data);
				stream>>data;
				newItem->setTel(data);
				stream>>group;
				newItem->setGroup(group);
				newBook.add(newItem);
				counter++;
			}
			cout<<"\n"<<counter<<" contacts added successfully"<<endl;
			newBook.printAll();
			}
			else cout<<"\nUnable to open the file!!!";
			break;
		}


		case '2':{
			contact* newItem=new contact;
			cout<<"Enter contact name:";
			cin>>newName;
			newItem->setName(newName);
			cout<<"Enter phone number:";
			cin>>newTel;
			newItem->setTel(newTel);
			do{
			cout<<"Enter Group(1-family 2-friends 3-business):";
			cin>>newGroup;
			if(newGroup<1||newGroup>3)cout<<"Group should be between 1 and 3!";
			}while(newGroup<1||newGroup>3);
			newItem->setGroup(newGroup);
			if(newBook.add(newItem)){
				newItem->print();
				cout<<"\nContact added successfully.";
			}
			delete newItem;
			break;}
		case '3':{
			newBook.printAll();
			break;
		}
		case '4':{
			string searchIndex;
			cout<<"\nEnter a name or a letter to search:";
			cin>>searchIndex;
			if(!newBook.search(searchIndex))cout<<"\nThere are no matching results!!";
			break;
		}
		case '5':
		{
			string newName,newTel;
			int editC;

			cout<<"\nEnter contact name to edit:";
			cin>>newName;
			contact* editContact=newBook.search2(newName);
			if(editContact){
				editContact->print();
			cout<<"\nEdit contact menu\n1-Edit name\t2-Edit contact number\t3-Edit Group\t4-Delete contact\n";
			cin>>editC;
			switch(editC){
			case 1:
				cout<<"\nEnter new Name:";
				cin>>newName;
				editContact->setName(newName);
				cout<<"\n Contact has been updated!";
				editContact->print();
				break;
			case 2:
				cout<<"\nEnter new number:";
				cin>>newTel;
				editContact->setTel(newTel);
				cout<<"\n Contact has been updated!";
				editContact->print();
				break;
			case 3:
				cout<<"\nEnter new group:(1-family 2-Friends 3-Business)";
				cin>>newGroup;
				editContact->setGroup(newGroup);
				cout<<"\n Contact has been updated successfully.";
				editContact->print();
				break;
			case 4:{
				char c;
				cout<<"are you sure?";
				cin>>c;
				c=='y'?newBook.remove(editContact):0;
				cout<<"\n Contact has been deleted successfully.";
				break;
			}
			default:
				break;
			}
			}
			else cout<<"\nThere is no contact with this name!";
			break;
		}
		case '6':{
			string fileName;
			cout<<"Enter file name to save:";
			cin>>fileName;
			newBook.save(fileName);
			  return 0;}
		default:
			break;

		}
	}while(choice!='6');
}
void menu(){
	cout<<"\n"<<setw(15)<<setfill('*')<<"TEL BOOK\n"<<setw(15)<<"Menu\n"
			<<"1-Enter a file name to load contacts..\n"
			<<"2-Add contact\n"
			<<"3-Show all contacts\n"
			<<"4-Search\n"
			<<"5-Edit contact\n"
			<<"6-Save and exit\n";
}





