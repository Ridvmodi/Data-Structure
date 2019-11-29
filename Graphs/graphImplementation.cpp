#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void printGraph(int v, int **graph) {
	for(int i = 0;i<v;i++) {
		for(int j = 0;j<v;j++) {
			if(graph[i][j]) {
				cout<<i<<"->"<<j<<endl;
			}
		}	
	}
}

int main() {

	int v;
	cout<<"Enter no of verticies"<<endl;
	cin>>v;
	int **graph = (int**)malloc(sizeof(int*) * v);
	for(int i = 0;i<v;i++) 
		graph[i] = (int*) malloc(sizeof(int) * v);
	int choice;
	do {
		cout<<"Enter 1 to add edge and 0 to exit"<<endl;
		cin>>choice;
		if(choice == 0)
			break;
		int a, b;
		cout<<"Enter the two verticies of edge"<<endl;
		cin>>a>>b;
		graph[a][b] = 1;

	} while (choice == 1);

	printGraph(v, graph);

}
