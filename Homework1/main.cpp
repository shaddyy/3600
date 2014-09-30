//Shaddy Zayour
//CSCE 2110
//Burke
//I have tested all possible situations of delete. Whether the item is first,in the middle, or last the program takes care
//of the situation accordingly. I have also tested larger integers and it takes care of reasonably sized integers.
//To my knowledge there are no errors or faults that can occur under any circumstances while operating the program.
//
#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main(){ //Will take care of all user input and will call appropriate functions
	bool val=true;
	int num;
	string user;
	hash Hash;
	do{
		cout<<"set> ";
		cin>>user;

		if(user=="add"){
			cin>>num;
			Hash.Add(num);
		}
		else if(user=="show"){
			Hash.Show();
		}
		else if(user=="search"){
			cin>>num;
			Hash.Search(num);
		}
		else if(user=="delete"){
			cin>>num;
			Hash.Delete(num);
		}
		else if(user=="quit")
			val=false;
		else
			cout<<"Error! Command not recognized"<<endl;
	}while(val);

}

