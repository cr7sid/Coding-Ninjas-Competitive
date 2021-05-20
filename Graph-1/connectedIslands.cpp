#include<iostream>
#include<queue>
using namespace std;

void DFS(int** edges, int n, int sv, bool* visited) {

	visited[sv] = true;
 
	for(int i = 0; i < n; i++) {

		if(i == sv) {
            
            continue;
            
        }

		if(edges[sv][i] == 1) {

			if(visited[i]) {

				continue;

			}

			DFS(edges, n, i, visited);

		}

	}

}

void totalCount(int** edges, int n) {

	bool* visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }

    int count = 0;

    for(int i = 0; i < n; i++) {

    	if(!visited[i]) {

            count++;
            DFS(edges, n, i, visited);

    	}
 
    }

    cout << count;

    delete[] visited;

}

int main() {

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

    totalCount(edges, n);

    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;

}