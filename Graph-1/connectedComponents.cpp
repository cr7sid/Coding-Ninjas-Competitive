#include<iostream>
#include<queue>
using namespace std;

void addComponent(int** edges, int n, int sv, bool* visited, vector<int> &oneComponent) {

    oneComponent.push_back(sv);
	visited[sv] = true;
 
	for(int i = 0; i < n; i++) {

		if(i == sv) {
            
            continue;
            
        }

		if(edges[sv][i] == 1) {

			if(visited[i]) {

				continue;

			}

			addComponent(edges, n, i, visited, oneComponent);

		}

	}

}

void DFS(int** edges, int n) {

	bool* visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }

    vector<vector<int>> components;

    for(int i = 0; i < n; i++) {

    	if(!visited[i]) {

            vector<int> oneComponent;
    		addComponent(edges, n, i, visited, oneComponent);
            components.push_back(oneComponent);

    	}
 
    }

    for (int i = 0; i < components.size(); i++) {

        for (int j = 0; j < components[i].size(); j++) {

            cout << components[i][j] << " ";

        }   
        
        cout << endl;

    }

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

    DFS(edges, n);

    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;

}