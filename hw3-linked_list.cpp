//============================================================================
// Name        : Homework3.cpp
// Author      : Ali Karakoç
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int d, Node* n = nullptr) {
		data = d;
		next = n;
	}

};

struct list {
	Node* head;
	Node* last;
	list(Node* h = nullptr, Node* l = nullptr){
		head=h;
		last=l;
	}


	//random generator module
	 int randomgen(){
     return (int)rand()%30;
     }
    //append list with randomly generated numbers
	 void append(){

		    int d=randomgen();
			if (head == nullptr) {
				head = new Node(d, nullptr);
				last = head;
			}
			else {
				last->next = new Node(d, nullptr);
				last = last->next;
			}

	 }

    //operator overloading
	void operator*=(int val){
		for (Node* p=head; p != nullptr; p = p->next )
			p->data = p->data*val;
	}
};

ostream& operator<<(ostream& os, list& l){
	for (Node* p=l.head; p != nullptr; p = p->next ){
		os << p->data << " ";
	}
	return os;
}

//initialization function
void initialize(int  N) {
	for(int i=0; i<N; i++){
	    list app;
	    app.append();
	    cout << app << " --> ";
	    app*=7;
	    cout << app << endl;
	}
}

int main() {
	int N = 10;
	initialize(N);
    return 0;
}
