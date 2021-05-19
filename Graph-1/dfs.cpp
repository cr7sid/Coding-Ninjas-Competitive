//Works for connected graph only!
#include <stdio.h>
#include<iostream>
#include <stdlib.h>

using namespace std;

void print(int** edges, int n,int sv, bool* visited) {
    
    cout << sv << endl;
    visited[sv] = true;
    
    for(int i = 0; i < n; i++) {
        
        if(i == sv) {
            
            continue;
            
        }
        
        if(edges[sv][i] == 1) {
            
            if(visited[i] == true){
                
                continue;
                
            }
            
            print(edges, n, i, visited);
            
        }    
        
    }
    
}



int main()
{
    int n,e;
    cout << "Vertices: ";
    cin >> n;
    cout << "Edges: ";
    cin >> e;
    int** edges = new int*[n];
    
    for(int i = 0; i < n; i++) {
        
        edges[i] = new int[n];
        
        for(int j = 0; j < n; j++) {
            
            edges[i][j] = 0;
            
        }
        
    }
    
    
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }
    
    print(edges, n, 0, visited);

    delete[] visited;
    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;
    
}