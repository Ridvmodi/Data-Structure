#include<iostream>

using namespace std;

#define V 9

int findMinVertex(int distance[], bool included[]) {
	int minNo = 32768, minVertexIndex = 0;
	for(int i = 0;i<V;i++) {
		if(!included[i] && distance[i] <= minNo) {
		 	minNo = distance[i];
			minVertexIndex = i;
		}
	}
	return minVertexIndex;
}

void fnc(int graph[V][V], int src) {

	int distance[V];
	bool included[V];
	for(int i = 0;i<V;i++) {
		distance[i] = 32768;
		included[i] = false;
	}
	distance[src] = 0;

	for(int i = 0;i<V-1;i++) {
		int minVertex = findMinVertex(distance, included);
		included[minVertex] = true;
		for(int j = 0;j<V;j++) {
			if(!included[j] && graph[minVertex][j] && distance[minVertex] != 32768
				 && distance[minVertex] + graph[minVertex][j] < distance[j]) 
				distance[j] = distance[minVertex] + graph[minVertex][j];
		}
	}	

	cout<<"Distance from "<<src<<" to :"<<endl;
	for(int i = 0;i<V;i++)
		cout<<i<<" is "<<distance[i]<<endl;
}


int main() {

	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	fnc(graph, 0);

	return 0;
}
