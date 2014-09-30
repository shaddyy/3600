//Functions


#include <iostream>
#include <string>
#include "header.h"
using namespace std;

hash::hash(){

	for(int i=0;i<buckets;i++){
		HashTable[i] = new node;
		HashTable[i]->num=-99;
		HashTable[i]->next=NULL;
	}
}

int hash::Hash(int num){
	int x;
	x=(num*num)%7;
	return x;
}

void hash::Add(int data){
	int index = Hash(data);

	if(HashTable[index]->num==-99){ //If the bucket is empty
		HashTable[index]->num=data;
	}
	else{ //If the bucket has data 
		node* Ptr = HashTable[index];
		if(Ptr->num!=data){ //No Duplicates
			node* n = new node;
			n->num=data;
			n->next=NULL;
			while(Ptr->next != NULL){
				Ptr = Ptr->next;
			}
			Ptr->next = n;
		}
		else
			cout<<"WARNING: duplicate input: "<<data<<endl;
	}
}

void hash::Show(){ //Calls ShowAll
	int itemnum;
	int x=0;
	for(int i=0; i<buckets; i++)
		ShowAll(i);
	cout<<endl;
}

void hash::ShowAll(int index){ //Prints according to rubric
	node* Ptr = HashTable[index];
	cout<<"(";
	if(Ptr->num!=-99){		
			while(Ptr!=NULL){
				cout<<Ptr->num;
				if(Ptr->next!=NULL)
					cout<<",";
				Ptr=Ptr->next;
			}
	}
	cout<<")";
	if(index<6)
		cout<<"-";	
}

void hash::Search(int data){//Uses boolean value to recognize if found
	int index = Hash(data);
	bool found = false;

	node* Ptr = HashTable[index];
	while(Ptr != NULL){
		if(Ptr->num==data){
			found=true;
		}
		Ptr=Ptr->next;
	}

	if(found==true){
		cout<<"true"<<endl;
	}
	else
		cout<<"false"<<endl;
}

void hash::Delete(int data){ //4 cases for deletion
	int index = Hash(data);
	
	node* del;
	node* x;
	node* y;

	//Bucket is empty
	if(HashTable[index]->num==-99)
		cout<<"WARNING: target value not found: "<<data<<endl;
	//First item matches no other items
	else if(HashTable[index]->num==data && HashTable[index]->next == NULL)
		HashTable[index]->num=-99;
	//First item matches but there are more
	else if(HashTable[index]->num==data){
		del=HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete del;
	}
	//Item is not first
	else{
		y=HashTable[index];
		x=HashTable[index]->next;

		while(x != NULL && x->num != data){
			y=x;
			x= x->next;
		}
		if(x == NULL){ //Never found
			cout<<"WARNING: target value not found: "<<data<<endl;
		}
		else{ //Found somewhere in list
			del = x;
			x=x->next;
			y->next=x;
			delete del;
		}
	}
}