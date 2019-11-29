#include<iostream>

using namespace std; 
  
#define V 5  

int findMinVertex(int distance[], bool included[]) {  
    // Initialize min value  
    int min = 32768, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (included[v] == false && distance[v] < min)  
            min = included[v], min_index = v;  
  
    return min_index;  
}  

void prims(int graph[V][V]) { 
    int parent[V];  
    int distance[V];  
    bool included[V];  

    for (int i = 0; i < V; i++)  
        distance[i] = 32768, included[i] = false;  
  
    distance[0] = 0;  
    parent[0] = -1; // First node is always root
  
    for (int count = 0; count < V - 1; count++) {  

        int minVertex = findMinVertex(distance, included);  
        included[minVertex] = true;  
        for (int v = 0; v < V; v++)  
            if (graph[minVertex][v] && included[v] == false && graph[minVertex][v] < distance[v])  
                parent[v] = minVertex, distance[v] = graph[minVertex][v];  
    }  
  

    cout<<"Result is"<<endl;  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  

int main() {  
    int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
  
    prims(graph);  
    return 0;  
}  
  
