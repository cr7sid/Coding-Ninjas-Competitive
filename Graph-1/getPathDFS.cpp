#include<iostream>
#include<queue>
using namespace std;

vector<int> getPath(int** edges, int n, bool* visited, int sv, int ev) {

    if(sv == ev) {

        vector<int> path;
        path.push_back(sv);
        visited[ev] = true;
        return path;

    }

    visited[sv] = true;

    for(int i = 0; i < n; i++) {

        if(edges[sv][i] == 1 && !visited[i]) {

            vector<int>path = getPath(edges, n, visited, i, ev);

            if(!path.empty()) {

                path.push_back(sv);
                return path;

            }
 
        }

    }

    return {};

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

    int sv, ev;

    cin >> sv;
    cin >> ev;

    bool* visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }

   vector<int> path = getPath(edges, n, visited, sv, ev);

   for(int i = 0; i < path.size(); i++) {

       cout << path[i] << " ";

   }

    delete[] visited;

    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;
    
}