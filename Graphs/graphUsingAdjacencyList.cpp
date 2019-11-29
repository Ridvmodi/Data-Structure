#include<iostream>
using namespace std;

struct List {
	struct List *next;
	int data;
};

int main() {

	int noOfVerticies;
	cout<<"Enter the no of Verticies"<<endl;
	cin>>noOfVerticies;
	struct List verticies[noOfVerticies];
	cout<<"Enter the verticies"<<endl;
	for(int i = 0;i<noOfVerticies;i++) {
		cin>>verticies[i].data;
		verticies[i].next = NULL;
	}
	int choice;
	while(true) {
		cout<<"Enter 1 to add Edge and 0 to exit"<<endl;
		cin>>choice;
		if(choice == 0)
			break;
		int a, b;
		cin>>a>>b;
		if(verticies[a - 1].next == NULL) {
			verticies[a - 1].next = (struct List*)malloc(sizeof(struct List));
			verticies[a - 1].next->data = b;
			verticies[a - 1].next->next = NULL;
		} else {
			struct List *ptr = verticies[a - 1].next;
			while(ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = (struct List*)malloc(sizeof(struct List));
			ptr->next->next = NULL;
			ptr->next->data = b;
		}	
	}

	cout<<"Edges are"<<endl;
	for(int i = 0;i<noOfVerticies;i++) {
		cout<<"Edges from "<<verticies[i].data<<" are "<<endl;
		struct List *ptr = verticies[i].next;
		while(ptr != NULL) {
			cout<<verticies[i].data<<" -> "<<ptr->data<<endl;
			ptr = ptr->next;
		}
	}
	return 0;
}
