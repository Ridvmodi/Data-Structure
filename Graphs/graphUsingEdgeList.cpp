#include<iostream>
#include<stdlib.h>
using namespace std;

struct Edge {

	int startV;
	int endV;
};

int main() {

	int noOfVerticies;
	cout<<"Enter the no of Verticies"<<endl;
	cin>>noOfVerticies;
	int verticies[noOfVerticies];
	cout<<"Enter the verticies name"<<endl;
	for(int i = 0;i<noOfVerticies;i++) {
		cin>>verticies[i];
	}

	struct Edge *edgeList = (struct Edge*)malloc(sizeof(struct Edge));

	if(edgeList == NULL) 
		cout<<"Memory not allocated"<<endl;

	int choice, noOfEdges = 0;
	while(true) {
		cout<<"Enter 1 to add Edge or 0 to exit"<<endl;
		cin>>choice;
		if(choice == 0)
			break;
		int a, b;
		cin>>a>>b;
		edgeList[noOfEdges].startV = a;
		edgeList[noOfEdges].endV = b;
		noOfEdges++;
		edgeList = realloc(edgeList, noOfEdges * sizeof(struct Edge));
	}
	cout<<"Edges are "<<endl;
	for(int i = 0;i<noOfEdges;i++) {
		cout<<verticies[edgeList[i].startV]<<"-"<<verticies[edgeList[i].endV]<<endl;
	}
	return 0;
}
