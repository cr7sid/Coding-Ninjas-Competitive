#include<iostream>
#include<queue>
using namespace std;

bool hasPath(int** edges, int n, int sv, int ev) {

    if(sv == ev) {

        return true;

    }

    if(edges[sv][ev] == 1) {

        return true;

    }

    queue<int> pendingVertices;
    bool* visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        
        visited[i] = false;
        
    }
	
	pendingVertices.push(sv);
	visited[sv] = true;

	while(!pendingVertices.empty()) {

		int currentVertex = pendingVertices.front();
		pendingVertices.pop();

        if(currentVertex == ev) {

            return true;

        }

		for(int i = 0; i < n; i++) {

			if(currentVertex == i) {

				continue;

			}

			if(edges[currentVertex][i] == 1 && !visited[i]) {

				pendingVertices.push(i);
				visited[i] = true;

			}

		}

	}

    return false;

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

    if(hasPath(edges, n, sv, ev)) {

        cout << "true";

    } else {

        cout << "false";

    }

    for(int i = 0; i < n; i++) {

        delete[] edges[i];

    }

    delete[] edges;
    
}