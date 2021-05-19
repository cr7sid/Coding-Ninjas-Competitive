#include <stdio.h>
#include<iostream>
#include <stdlib.h>

using namespace std;

void DFS(int** edges, int n,int sv, bool* visited) {
    
    visited[sv] = true;
    
    for(int i = 0; i < n; i++) {
        
        if(i == sv) {
            
            continue;
            
        }
        
        if(edges[sv][i] == 1) {
            
            if(visited[i] == true){
                
                continue;
                
            }
            
            DFS(edges, n, i, visited);
            
        }    
        
    }
    
}



int main()
{
    int n;
	cin >> n;
	int e;
	cin >> e;
	int** edges = new int*[n];
	
	for(int i = 0; i < n; i++)  {

		edges[i] = new int[n];

		for(int j = 0; j < n; j++)
			edges[i][j] = 0;

	}

	for(int i = 0; i < e; i++) {
        
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
        
    }
        
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }
    
    DFS(edges, n, 0, visited);

    int flag = 1;

    for(int i = 0; i < n; i++) {

        if(!visited[i]) {

            cout << "false";
            flag = 0;
            break;

        }

    }

    if(flag == 1) {

        cout << "true";

    }

    delete[] visited;
    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;
    
}