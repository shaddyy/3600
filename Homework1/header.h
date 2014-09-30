//Header


#include <iostream>
#include <string>
using namespace std;

class hash{
public:
	hash();
	int Hash(int num);
	void Add(int data);
	void Show();
	void ShowAll(int index);
	void Search(int data);
	void Delete(int data);
private:
	static const int buckets = 7;
	struct node{
		int num;
		node* next;
	};

	node* HashTable[buckets];
};